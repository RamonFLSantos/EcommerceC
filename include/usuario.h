#ifndef USUARIO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct usuario {
  char nome[100];
  char email[100];
  char senha[50];
} Usuario;

void verificaOuCriaUsuarios();
bool cadastrarUsuario();
bool loginUsuario(char *tipoUsuario);
bool emailExiste(const char *email);
bool validarLoginUsuario(const char *email, const char *senha);

#endif