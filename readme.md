# Segundo período do curso de Ciência da Computação @ CIn-UFPE 

Este repositório contém os exercícios e projetos desenvolvidos para as disciplinas de Estrutura de Dados Orientadas a Objetos (EDOO), Arquitetura de Computadores e Sistemas Operacionais (ACS0) e CS50's Introduction to Web Development with Python and JavaScript (WCS50), utilizando o ambiente **WSL (Ubuntu)**.

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

### Compilação para Debugging 
```
g++ -g arquivo.cpp -o a.out
```

### Execução de códigos C++
```
./bin/arquivo