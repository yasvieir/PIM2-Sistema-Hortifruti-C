#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void verficaLogin(char ent_usuario[TAM_user], char ent_senha[TAM_user], int *user_existe);

void mascSenha(char ent_senha, char *senha[TAM_user]);

int lerUltimoID();

#endif // FUNCOES_H_INCLUDED
