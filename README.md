# E-commerce no Terminal (C + Arquivos)

## Objetivo
Simular um sistema de e-commerce via terminal com persistência em arquivos `.txt` ou `.csv`, utilizando **C** e uma estrutura modular.

---

## Funcionalidades
- Cadastro e login de usuários.
- Menu de navegação interativo.
- Cadastro, edição e listagem de produtos.
- Controle de estoque e histórico de compras.
- Sistema de carrinho e pedidos.
- Usuário “admin” com permissões especiais.

---

## Estrutura de Pastas
ecommerce-terminal/ <br>
├── src/ → Códigos-fonte (.c) <br>
├── include/ → Headers (.h) <br>
├── data/ → Arquivos persistentes (.csv) <br>
├── build/ → Binários compilados <br>
└── README.md

---

## Compilação e Execução

1. Compile:
   ```bash
   gcc src/*.c -I include -o build/ecommerce

2. Execute:
   ```bash
   ./build/ecommerce

---

## Persistência

Os dados são salvos na pasta data/ em formato .csv, garantindo que o sistema possa ser fechado e reaberto sem perda de informações.

---

## Habilidades demonstradas

* Manipulação de arquivos (fopen, fprintf, fscanf)
* Modularização (uso de .h e .c)
* Structs e ponteiros
* Lógica procedural e controle de fluxo
* Simulação de persistência de dados

---

## Autor

Projeto desenvolvido por Ramon Felipe dos Santos, para fins de aprendizado e prática em linguagem C.
