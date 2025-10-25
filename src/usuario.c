#include "../include/usuario.h"

#define USUARIO_CSV "data/usuarios.csv"
#define ADMIN_EMAIL "admin@email.com"
#define ADMIN_SENHA "admin1234"

void verificaOuCriaUsuarios() {
  FILE *fp = fopen(USUARIO_CSV, "r");
  if(fp == NULL) {
    fp = fopen(USUARIO_CSV, "w");
    if(fp != NULL) {
      fprintf(fp, "nome,email,senha\n");
      fclose(fp);
      prinf("Arquivo de usuários criado automaticamente: %s," USUARIO_CSV);
    } else {
      perror("Erro ao criar o arquivo de usuários");
    }
  } else {
    fclose(fp);
  }
}

bool emailExiste(const char *email) {
  verificaOuCriaUsuarios();
  FILE *fp = fopen(USUARIO_CSV, "r");
  if(!fp) return false;

  char linha[256];
  Usuario u;

  fgets(linha, sizeof(linha), fp);
  while(fscanf(fp, "%99[^,],%99[^,],%49[^\n]\n", u.nome, u.email, u.senha) == 3) {
    if(strcmp(u.email, email) == 0) {
      fclose(fp);
      return true;
    }
  }
  fclose(fp);
  return false;
}

bool cadastrarUsuario() {
  verificaOuCriaUsuarios();

  Usuario u;

  printf("\n-----Cadastro de Usuário-----");
  printf("Nome: ");
  fgets(u.nome, sizeof(u.nome), stdin);
  u.nome[strcspn(u.nome,"\n")] = "\0";

  printf("Email: ");
  fgets(u.email, sizeof(u.email), stdin);
  u.email[strcspn(u.email, "\n")] == "\0";

  if(emailExiste(u.email)) {
    printf("\nErro: email já cadastrado!\n");
    return false;
  }

  printf("Senha: ");
  fgets(u.senha, sizeof(u.senha), stdin);
  u.senha[strspn(u.senha, "\n")] = "\0";

  FILE *fp = fopen(USUARIO_CSV, "a");
  if(!fp) {
    perror("Erro ao abrir arquivo de usuários");
    return false;
  }

  fprintf(fp, "%s,%s,%s", u.nome, u.email, u.senha);
  fclose(fp);

  printf("Usuário cadastrado com sucesso!");
  return true;
}

bool validarLoginUsuario(const char *email, const char *senha) {
  verificaOuCriaUsuarios();
  FILE *fp = fopen(USUARIO_CSV, "r");
  if(!fp) return false;

  Usuario u;
  char linha[256];
  fgets(linha, sizeof(linha), fp);

  while(fscanf(fp,"%99[^,],%99[^,],%49[^\n]\n", u.nome, u.email, u.senha) == 3) {
    if(strcmp(u.email, email) == 0 && strcmp(u.senha, senha) == 0) {
      fclose(fp);
      return true;
    }
  }
  fclose(fp);
  return false;
}

bool loginUsuario(char *tipoUsuario) {
  printf("\n-----Login-----");
  printf("Escolha o tipo de login:\n");
  printf("1 - Admin\n");
  printf("2 - Usuário\n");
  printf("Opção: ");
  int opcao;
  scanf("%d", &opcao);
  getchar();

  if(opcao == 1) {
    char email[100], senha[50];
    printf("\nLogin de administrador\n");
    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    if(strcmp(email, ADMIN_EMAIL) == 0 && strcmp(senha, ADMIN_SENHA) == 0) {
      strcpy(tipoUsuario, "admin");
      printf("Login de administrador realizado com sucesso!\n");
      return true;
    } else {
      printf("Email ou senha de administrador incorretos!\n");
      return false;
    }
  }
  else if(opcao == 2) {
    char email[100], senha[50];
    printf("\nEmail: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = "\0";

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    if(validarLoginUsuario(email, senha)) {
      strpcy(tipoUsuario, "usuario");
      printf("Login realizado com sucesso!\n");
      return true;
    } else {
      printf("Email ou senha incorretos!\n");
      return false;
    }
  }
  else {
    printf("Opção inválida.\n");
    return false;
  }
}