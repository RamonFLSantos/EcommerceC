#include "../include/produto.h"
#include <string.h>

#define ARQUIVO_CSV "data/produtos.csv"

void verificaOuCriaArquivo() {
  FILE *fp = fopen(ARQUIVO_CSV, "r");

  if(fp == NULL) {
    fp = fopen(ARQUIVO_CSV, "w");
    if(fp != NULL) {
      fprintf(fp, "id,nome,preco,estoque\n");
      fclose(fp);
      printf("Arquivo criado automaticamente: %s", ARQUIVO_CSV);
    } else {
      perror("Erro ao criar o arquivo de produtos");
    }
  } else {
    fclose(fp);
  }
}

static int idExiste(int idBuscado) {
  FILE *fp = fopen(ARQUIVO_CSV, "r");
  if (fp == NULL) return 0;

  Produto p;
  char linha[256];

  fgets(linha, sizeof(linha), fp);

  while(fscanf(fp, "%d, %99[^,],%f,%d\n", &p.id, &p.nome, &p.preco, &p.quant) == 4) {
    if(p.id == idBuscado) {
      fclose(fp);
      return 1;
    }
  }

  fclose(fp);
  return 0;
}

void cadastrarProduto() {
  Produto p;
  verificaOuCriaArquivo();

  printf("\n-----Cadastro de Produto-----\n");
  printf("ID: ");
  scanf("%d", &p.id);
  getchar();

  if(idExiste(p.id)) {
    printf("Já existe um produto com esse ID! Tente novamente.\n");
    return;
  }

  printf("Nome: ");
  fgets(p.nome, sizeof(p.nome), stdin);
  p.nome[strcspn(p.nome, "\n")] = "\0";

  printf("Preço: ");
  scanf("%f", &p.preco);

  printf("Quantidade: ");
  scanf("%d", &p.quant);

  salvarProdutosCSV(p);

  printf("\nProduto cadastrado com sucesso!\n");
}

void listarProdutos() {
  verificaOuCriaArquivo();

  FILE *fp = fopen(ARQUIVO_CSV, "r");

  if(fp == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  Produto p;
  char linha[256];

  printf("\n-----Lista de Produtos-----\n");
  printf("%-5s | %-30s | %-10s | %-8s\n", "ID", "Nome", "Preço", "Estoque");
  printf("---------------------------------------------------------------\n");

  fgets(linha, sizeof(linha), fp);

  while (fscanf(fp, "%d,%99[^,],%f,%d\n", &p.id, p.nome, &p.preco, &p.quant) == 4) {
    printf("%-5d | %-30s | %-10.2f | %-8d\n", p.id, p.nome, p.preco, p.quant);
  }
  fclose(fp);
}

void salvarProdutosCSV(Produto p) {
  verificaOuCriaArquivo();

  FILE *fp = fopen(ARQUIVO_CSV, "a");

  if(fp == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  fprintf(fp, "%d,%s,%.2f,%d\n", p.id, p.nome, p.preco, p.quant);
  fclose(fp);
}

void atualizarEstoque(int idProduto, int novaQuant) {
  verificaOuCriaArquivo();

  FILE *fp = fopen(ARQUIVO_CSV, "r");

  if(fp == NULL) {
    perror("Erro ao abrir o arquivo de produtos");
    return;
  }

  Produto lista[200];
  int count = 0;
  char linha[256];

  fgets(linha, sizeof(linha), fp);
  while(fscanf(fp, "%d, %99[^,]%f, %d\n", &lista[count].id, lista[count].nome, &lista[count].preco, &lista[count].quant) == 4) {
    if(lista[count].id == idProduto) {
      lista[count].quant = novaQuant;
    }
    count++;
  }
  fclose(fp);

  fp = fopen(ARQUIVO_CSV, "w");
  if(fp == NULL) {
    perror("Erro ao abrir o arquivo para atualização");
    return;
  }

  fprintf(fp, "id,nome,preco,estoque");
  for(int i = 0; i < count; i++) {
    fprintf(fp, "%d,%s,%.2f,%d\n", lista[i].id, lista[i].nome, lista[i].preco, lista[i].quant);
  }

  fclose(fp);

  printf("\nEstoque do produto %d atualizado para %d unidades.\n", idProduto, novaQuant);
}

void excluirProduto() {
  verificaOuCriaArquivo();

  int idExcluir;
  printf("Digite o ID do produto que deseja excluir: ");
  scanf("%d", &idExcluir);

  FILE *fp = fopen(ARQUIVO_CSV, "r");
  if(fp == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  Produto lista[200];
  int count = 0;
  char linha[256];

  fgets(linha, sizeof(linha), fp);
  while(fscanf(fp, "%d,%99[^,],%f,%d\n", &lista[count].id, lista[count].nome, lista[count].preco, lista[count].quant) == 4) {
    count++;
  }
  fclose(fp);

  fp = fopen(ARQUIVO_CSV, "w");
  if(fp == NULL) {
    perror("Erro ao abrir o arquivo para escrita");
    return;
  }

  fprintf(fp, "id,nome,preco,estoque\n");
  int encontrado = 0;
  for(int i = 0; i < count; i++) {
    if(lista[i].id != idExcluir) {
      fprintf(fp, "%d,%s,%.2f,%d\n", lista[i].id, lista[i].nome, lista[i].preco, lista[i].quant);
    } else {
      encontrado = 1;
    }
  }

  fclose(fp);

  if(encontrado) {
    printf("Produto com ID %d excluído com sucesso!\n", idExcluir);
  } else {
    printf("Nenhum produto encontrado!");
  }
}