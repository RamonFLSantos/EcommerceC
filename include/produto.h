#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
  int id;
  char nome[100];
  float preco;
  int quant;
} Produto;

void verificaOuCriaArquivo();
void cadastrarProduto();
void listarProdutos();
void salvarProdutosCSV(Produto p);
void atualizarEstoque(int idProduto, int novaQuant);

#endif