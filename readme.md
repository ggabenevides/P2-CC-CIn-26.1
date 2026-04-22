# CC 26.1 @ CIn-UFPE 

Este repositório contém os exercícios e projetos desenvolvidos para as disciplinas do segundo período do curso de bacharelado em Ciência da Computação: de Estrutura de Dados Orientadas a Objetos (EDOO), Arquitetura de Computadores e Sistemas Operacionais (ACS0) e CS50's Introduction to Web Development with Python and JavaScript (WCS50), utilizando o ambiente **WSL (Ubuntu)**.

## Estrutura do Repositório

A organização segue uma lógica de pastas por disciplina e módulos para manter o ambiente limpo:

```text
.
├── WCS50/              # Atividades do curso CS50's Introduction to Web Development with Python and JavaScript
├── EDOO/               # Atividades da cadeira Estrutura de Dados Orientadas a Objetos
│   └── AP3/            # Atividade Prática 3 (Exemplo)
|       └── ap3-1.cpp   # Exercício 1 da AP3 (exemplo) 
├── ACSO/              # Atividades da cadeira Arquitetura de Computadores e Sistemas Operacionais
├── bin/                # Executáveis (Pasta ignorada pelo Git)
├── .gitignore          # Regras para manter o repo limpo
└── README.md           # Este arquivo
```

## Instruções gerais

### Compilação de códigos C++
```
g++ -g Cadeira/Módulo/arquivo.cpp -o bin/arquivo
```

### Debugging C++
Executar esse comando no bash:
```
g++ -g arquivo.cpp -o a.out
```
E depois usar f5 para abrir o debugger.

### Execução de códigos C++
```
./bin/arquivo
