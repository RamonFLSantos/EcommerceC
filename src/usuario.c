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
}