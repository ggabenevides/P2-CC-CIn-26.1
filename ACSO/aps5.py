# APS 05 - algoritmos de escalonamento de processos 
# (round robin com quantum fixo e escalonamento por prioridade)

#imports
from copy import deepcopy 

# estrutura de dados do processo
class Processo:
    def __init__(self, pid, tch, prio, tcpu):
        self.pid = pid
        self.tch = tch # tempo de chegada
        self.prio = prio # prioridade
        self.tcpu = tcpu # tempo total de cpu necessário
        self.restante = tcpu # tempo de cpu ainda necessário
        self.inicio = None # 1o instante em que usou a cpu
        self.fim = None # instante em que terminou 

""" 
algoritmo de escalonamento round robin com quantum fixo
ENTRADAS:
processos_orig: lista dos processos recebidos na entrada -> precisa implementar o tratamento de entrada pra organizar essa lista
quantum: isso vai ser fornecido na entrada na primeira linha, então o tratamento de entrad é só pegar e passar na chamada na função na main
t_troca: mesma coisa do quantum
SAÍDAS:
processos: lista de processos atualizada após fim do escalonamento
linha_tempo: lista que contem as tuplas com os dados de cada ms em que o algoritmo trabalhou (histórico da cpu dizendo quem rodou o processo naquele instante)
"""
def round_robin (processos_orig, quantum, t_troca):
    # primeiro passo é fazer uma deep copy da lista dos processos, pra não corroer os dados já que o algoritmo vai alterar os atributos restante, inicio e fim
    processos = [deepcopy(p) for p in processos_orig]

    # ordenando os processos primeiro por tempo de chegada, em caso de empate por pid (menor pid ganha)
    processos.sort(key=lambda p : (p.tch, p.pid))

    #inicializando variáveis que serão usadas/retornadas
    linha_tempo = [] # lista de tuplas que registra o histórico da cpu por ms (instante, quem_está_rodando) -> ex.: (5, "Escalonador")
    fila = [] #fila de prontos
    tempo = 0
    idx = 0 # aponta para o próximo processo que ainda não chegou na fila
    atual = None
    quantum_restante = 0

    while True:

        #adicionando processos que chegaram até agr
        while idx < len(processos) and processos[idx].tch <= tempo:
            fila.append(processos[idx])
            idx += 1
        
        #avançar tempo se não tem nada rodando e fila de prontos ta vazia (CPU ociosa)
        if atual is None and not fila:
            if idx >= len(processos): 
                break # condição de saída do loop principal = acabaram os processos

            #pula p chegada do proximo processo
            tempo = processos[idx].tch
            continue
        
        # puxando próximo processo da fila se não tem nenhum rodando
        if atual is None:
            atual = fila.pop(0)
            quantum_restante = quantum

            #troca de contexto (se já houve algum processo antes)
            if linha_tempo:
                for t in range(tempo, tempo + t_troca):
                    linha_tempo.append((t, "Escalonador"))
                tempo += t_troca

                #adicionando processos que chegaram durante a troca
                while idx < len(processos) and processos[idx].tch <= tempo:
                    fila.append(processos[idx])
                    idx += 1
                
                #registrando momento de inicio 
                if atual.inicio is None:
                    atual.inicio = tempo

        # roda 1ms      
        linha_tempo.append((tempo, f"P{atual.pid}"))
        tempo += 1
        atual.restante -= 1
        quantum_restante -= 1

        # novos processos q chegaram
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

    # Marca o instante final
    linha_tempo.append((tempo, linha_tempo[-1][1] if linha_tempo else ""))
    return processos, linha_tempo

"""
função auxiliar que faz a seguinte transformação:
(0, "P1"), (1, "P1"), (2, "P1"), ... (19, "P1"), (20, "Escalonador"), (21, "P2"), ...
vira isso:
[0 ms - 20 ms]  P1
[20 ms - 21 ms]  Escalonador
[21 ms - 36 ms]  P2

PRA USAR NA GERAÇÃO DO RELATÓRIO: 
    blocos   = formatar_linha_tempo(linha_tempo)
    for (ti, tf, quem) in blocos:
            linhas.append(f"  [{ti:>5} ms – {tf:>5} ms]  {quem}")
usando esses comando vai gerar o relatóriozinho como tá logo aqui em cima
"""
def formatar_linha_tempo(linha_tempo):
    if not linha_tempo:
        return []
    resultado = []
    t_inicio, quem = linha_tempo[0]
    for t,q in linha_tempo[1:]:
        if q != quem:
            resultado.append((t_inicio, t, quem))
            t_inicio, quem = t, q
    resultado.append((t_inicio, linha_tempo[-1][0], quem))
    return resultado


        
    