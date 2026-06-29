# APS 05 - algoritmos de escalonamento de processos
# (round robin com quantum fixo e escalonamento por prioridade)

# imports
from copy import deepcopy
from heapq import heappush, heappop 


# estrutura de dados do processo
class Processo:
    def __init__(self, pid, tch, prio, tcpu):
        self.pid      = pid
        self.tch      = tch    # tempo de chegada
        self.prio     = prio   # prioridade
        self.tcpu     = tcpu   # tempo total de cpu necessário
        self.restante = tcpu   # tempo de cpu ainda necessário
        self.inicio   = None   # 1o instante em que usou a cpu
        self.fim      = None   # instante em que terminou


# round robin com quantum fixo
def round_robin(processos_orig, quantum, t_troca):
    processos = [deepcopy(p) for p in processos_orig]
    processos.sort(key=lambda p: (p.tch, p.pid))

    linha_tempo = []
    fila = []
    tempo = 0
    idx = 0
    atual = None
    quantum_restante = 0

    while True:

        # adiciona processos que chegaram até agora
        while idx < len(processos) and processos[idx].tch <= tempo:
            fila.append(processos[idx])
            idx += 1

        # cpu ociosa
        if atual is None and not fila:
            if idx >= len(processos):
                break
            tempo = processos[idx].tch
            continue

        # pega próximo da fila se cpu está livre
        if atual is None:
            atual = fila.pop(0)
            quantum_restante = quantum

            # troca de contexto (só se já houve algum processo antes)
            if linha_tempo:
                for t in range(tempo, tempo + t_troca):
                    linha_tempo.append((t, "Escalonador"))
                tempo += t_troca

                # processos que chegaram durante a troca
                while idx < len(processos) and processos[idx].tch <= tempo:
                    fila.append(processos[idx])
                    idx += 1

            if atual.inicio is None:
                atual.inicio = tempo

        # roda 1 ms
        linha_tempo.append((tempo, f"P{atual.pid}"))
        tempo += 1
        atual.restante -= 1
        quantum_restante -= 1

        # processos que chegaram nesse ms
        while idx < len(processos) and processos[idx].tch <= tempo:
            fila.append(processos[idx])
            idx += 1

        # processo terminou
        if atual.restante == 0:
            atual.fim = tempo
            atual = None
            quantum_restante = 0

        # quantum expirou e processo ainda tem trabalho
        elif quantum_restante == 0:
            fila.append(atual)
            atual = None

    linha_tempo.append((tempo, linha_tempo[-1][1] if linha_tempo else ""))
    return processos, linha_tempo

# escalonamento por prioridade (preemptivo)
def escalonamento_prioridade(processos_orig, t_troca):

    fila_pendentes = [deepcopy(p) for p in processos_orig]
    fila_pendentes.sort(key=lambda p: p.tch)

    linha_tempo      = []
    fila_prontos     = []   # heap: (prio, pid, Processo)
    fila_finalizados = []
    tempo_atual      = 0
    indice           = 0
    chaveamento      = 0
    processo_atual   = None

    while True:

        # adiciona processos que chegaram
        while indice < len(fila_pendentes) and fila_pendentes[indice].tch <= tempo_atual:
            p = fila_pendentes[indice]
            heappush(fila_prontos, (p.prio, p.pid, p))
            indice += 1

        if processo_atual is None:

            if fila_prontos:
                processo_atual = heappop(fila_prontos)[2]
                if processo_atual.inicio is None:       # FIX 5: registra início
                    processo_atual.inicio = tempo_atual

            else:
                if indice >= len(fila_pendentes):
                    break
                tempo_atual = fila_pendentes[indice].tch
                continue

        # desempate por pid na verificação de preempção
        elif fila_prontos and (fila_prontos[0][0], fila_prontos[0][1]) < (processo_atual.prio, processo_atual.pid):

            heappush(fila_prontos, (processo_atual.prio, processo_atual.pid, processo_atual))
            processo_atual = None

            for t in range(tempo_atual, tempo_atual + t_troca):
                linha_tempo.append((t, "Escalonador"))
            tempo_atual += t_troca
            chaveamento += 1

            while indice < len(fila_pendentes) and fila_pendentes[indice].tch <= tempo_atual:
                p = fila_pendentes[indice]
                heappush(fila_prontos, (p.prio, p.pid, p))
                indice += 1

        else:

            linha_tempo.append((tempo_atual, f"P{processo_atual.pid}"))
            tempo_atual            += 1
            processo_atual.restante -= 1

            if processo_atual.restante == 0:

                processo_atual.fim = tempo_atual
                fila_finalizados.append(processo_atual)
                processo_atual = None

                if fila_prontos:
                    for t in range(tempo_atual, tempo_atual + t_troca):
                        linha_tempo.append((t, "Escalonador"))
                    tempo_atual += t_troca
                    chaveamento += 1

                    while indice < len(fila_pendentes) and fila_pendentes[indice].tch <= tempo_atual:
                        p = fila_pendentes[indice]
                        heappush(fila_prontos, (p.prio, p.pid, p))
                        indice += 1

    linha_tempo.append((tempo_atual, linha_tempo[-1][1] if linha_tempo else ""))
    return fila_finalizados, linha_tempo, chaveamento, tempo_atual


# funções auxiliares
def formatar_linha_tempo(linha_tempo):
    """
    compacta a linha do tempo ms-a-ms em blocos
    ex.: (0,"P1"),(1,"P1"),(2,"Esc") → [(0,2,"P1"),(2,3,"Esc")]

    para usar na geração do relatório:
        blocos = formatar_linha_tempo(linha_tempo)
        for (ti, tf, quem) in blocos:
            linhas.append(f"  [{ti:>5} ms – {tf:>5} ms]  {quem}")
    """
    if not linha_tempo:
        return []
    resultado = []
    t_inicio, quem = linha_tempo[0]
    for t, q in linha_tempo[1:]:
        if q != quem:
            resultado.append((t_inicio, t, quem))
            t_inicio, quem = t, q
    resultado.append((t_inicio, linha_tempo[-1][0], quem))
    return resultado


def ler_entrada(caminho_arquivo):
    processos = []

    with open(caminho_arquivo, "r", encoding="utf-8") as f:
        linhas = f.readlines()

    primeira = linhas[0].strip().split(",")
    n_proc  = int(primeira[0])
    quantum = int(primeira[1])
    t_troca = int(primeira[2])

    lidos = 0
    for linha in linhas[1:]:
        linha = linha.strip()
        if not linha:
            continue
        partes = linha.split(",")
        if len(partes) < 4:
            continue
        try:
            pid  = int(partes[0])
            tch  = int(partes[1])
            prio = int(partes[2])
            tcpu = int(partes[3])
        except ValueError:
            continue

        processos.append(Processo(pid, tch, prio, tcpu))
        lidos += 1
        if lidos == n_proc:
            break

    return processos, quantum, t_troca


def calcular_metricas(processos_finalizados, linha_tempo):
    retornos = {}
    for p in processos_finalizados:
        if p.fim is not None:
            retornos[p.pid] = p.fim - p.tch

    retorno_medio = sum(retornos.values()) / len(retornos) if retornos else 0.0

    # conta blocos contíguos de "Escalonador" (não ms individuais)
    n_chaveamentos = 0
    em_troca = False
    for _, quem in linha_tempo:
        if quem == "Escalonador":
            if not em_troca:
                n_chaveamentos += 1
                em_troca = True
        else:
            em_troca = False

    tempo_escalonador = sum(1 for _, quem in linha_tempo if quem == "Escalonador")
    tempo_total       = linha_tempo[-1][0] if linha_tempo else 0
    overhead          = tempo_escalonador / tempo_total if tempo_total > 0 else 0.0

    return {
        "retornos"         : retornos,
        "retorno_medio"    : retorno_medio,
        "n_chaveamentos"   : n_chaveamentos,
        "tempo_escalonador": tempo_escalonador,
        "tempo_total"      : tempo_total,
        "overhead"         : overhead,
    }


def escrever_saida(caminho_arquivo, nome_algoritmo,
                   processos_finalizados, linha_tempo, modo="a"):
    metricas = calcular_metricas(processos_finalizados, linha_tempo)
    blocos   = formatar_linha_tempo(linha_tempo)

    linhas = []
    linhas.append("=" * 60)
    linhas.append(f"  ALGORITMO: {nome_algoritmo}")
    linhas.append("=" * 60)
    linhas.append("")

    linhas.append("Tempo de retorno por processo:")
    for p in sorted(processos_finalizados, key=lambda x: x.pid):
        tr = metricas["retornos"].get(p.pid, "N/A")
        linhas.append(f"  P{p.pid}: {tr} ms")
    linhas.append("")

    linhas.append(f"Tempo médio de retorno     : {metricas['retorno_medio']:.2f} ms")
    linhas.append(f"Número de chaveamentos     : {metricas['n_chaveamentos']}")
    linhas.append(f"Tempo gasto em chaveamentos: {metricas['tempo_escalonador']} ms")
    linhas.append(f"Tempo total da simulação   : {metricas['tempo_total']} ms")
    linhas.append(f"Overhead de chaveamento    : {metricas['overhead']*100:.2f}%"
                  f"  ({metricas['tempo_escalonador']} / {metricas['tempo_total']})")
    linhas.append("")

    linhas.append("Linha do tempo de ocupação da CPU:")
    for (ti, tf, quem) in blocos:
        linhas.append(f"  [{ti:>5} ms – {tf:>5} ms]  {quem}")
    linhas.append("")
    linhas.append("")

    with open(caminho_arquivo, modo, encoding="utf-8") as f:
        f.write("\n".join(linhas))


#main

#compatível com Colab E execução local
try:
    from google.colab import files
    print("Selecione o arquivo EntradaProcessos.txt:")
    uploaded = files.upload()
    ARQUIVO_ENTRADA = list(uploaded.keys())[0]
except ImportError:
    # execução local: passa o nome do arquivo como argumento
    # ex.: python escalonador_corrigido.py entrada1.txt
    import sys
    ARQUIVO_ENTRADA = sys.argv[1] if len(sys.argv) > 1 else "entrada1.txt"

ARQUIVO_SAIDA = "SaidaProcessos.txt"

processos, quantum, t_troca = ler_entrada(ARQUIVO_ENTRADA)
print(f"Lidos {len(processos)} processos | quantum={quantum}ms | tTroca={t_troca}ms")

# Round Robin
proc_rr, tempo_rr = round_robin(processos, quantum, t_troca)
escrever_saida(
    ARQUIVO_SAIDA,
    f"Round Robin (quantum={quantum}ms, tTroca={t_troca}ms)",
    proc_rr, tempo_rr,
    modo="w"
)

# desempacota os 4 valores retornados pela função
proc_prio, tempo_prio, _, _ = escalonamento_prioridade(processos, t_troca)
escrever_saida(
    ARQUIVO_SAIDA,
    f"Escalonamento por Prioridade (tTroca={t_troca}ms)",
    proc_prio, tempo_prio,
    modo="a"
)

print(f"\nArquivo de saída gerado: {ARQUIVO_SAIDA}")

try:
    files.download(ARQUIVO_SAIDA)
except NameError:
    pass  # fora do Colab, o arquivo já está salvo localmente