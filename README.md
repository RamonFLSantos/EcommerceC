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
ecommerce-terminal/ \\
├── src/ → Códigos-fonte (.c) \\
├── include/ → Headers (.h) \\
├── data/ → Arquivos persistentes (.csv) \\
├── build/ → Binários compilados \\
└── README.md

---

## ⚙️ Compilação e Execução

1. Compile:
   ```bash
   gcc src/*.c -I include -o build/ecommerce

2. Execute:
   ```bash
   ./build/ecommerce