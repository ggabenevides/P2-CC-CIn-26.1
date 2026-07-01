# CC 26.1 @ CIn-UFPE

Este repositório contém os exercícios e projetos desenvolvidos para as disciplinas do **segundo período do curso de bacharelado em Ciência da Computação**: Estrutura de Dados Orientadas a Objetos (EDOO), Arquitetura de Computadores e Sistemas Operacionais (ACSO) e CS50's Introduction to Web Development with Python and JavaScript (WCS50), utilizando o ambiente **WSL (Ubuntu)**.

## Estrutura do Repositório

A organização segue uma lógica de pastas por disciplina e módulos para manter o ambiente limpo:

```text
.
├── EDOO/                # Estrutura de Dados Orientadas a Objetos (C++)
│   ├── AP1 a AP12/       # Atividades Práticas (listas, pilhas, filas, árvores, hashing, etc.)
│   ├── EP1 a EP3/        # Exercícios Práticos
│   ├── LE1 a LE3/        # Listas de exercícios
│   └── STL/              # Exercícios com a Standard Template Library
├── ACSO/                # Arquitetura de Computadores e Sistemas Operacionais (C/Python)
│   ├── APS5/             # Escalonamento de processos (Round Robin e Prioridade)
│   ├── labPTHREAD/       # Laboratório de concorrência com pthreads
│   └── *.c, *.s          # Exercícios avulsos de assembly e benchmarking
├── WCS50/               # CS50's Web Development (HTML/CSS/JS)
│   ├── Lecture1/          # Exercícios de HTML/CSS (flexbox, grid, formulários)
│   ├── Lecture2/          # Exercícios de JavaScript (DOM, localStorage, eventos)
│   └── Project0/          # Projeto de busca (clone da página do Google)
├── bin/                 # Executáveis (pasta ignorada pelo Git)
├── .gitignore           # Regras para manter o repo limpo
└── README.md            # Este arquivo
```

## Instruções gerais

### Compilação de códigos C++
```bash
g++ -g Cadeira/Módulo/arquivo.cpp -o bin/arquivo
```

### Debugging C++
Executar esse comando no bash:
```bash
g++ -g arquivo.cpp -o bin/a.out
```
E depois usar F5 para abrir o debugger.

### Execução de códigos C++
```bash
./bin/arquivo
```

### Execução de códigos Python (ACSO)
```bash
python3 ACSO/APS5/aps5.py
```

### Compilação com pthreads (ACSO)
```bash
cd ACSO/labPTHREAD
make
```
