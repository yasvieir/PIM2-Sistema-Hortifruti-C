#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int verificaLogin(char *ent_usuario, char *ent_senha, char *cargo);

void mascSenha(char ent_senha, char *senha[TAM_user]);

int lerUltimoID();

int salvarUltimoID(int ultimoID);

int gerarID();

int usuarioExiste(char *usuario);

void verificaSenhas(char ent_senha1[], char ent_senha2[], int *comparador);

void exibirSenhaMascarada(const char *senha);

Pessoa buscarCadastroPorID(int id);

int lerUltimoID_Produto();

int salvarUltimoID_Produto(int ultimoID_Produto);

int gerarID_Produto();

#endif // FUNCOES_H_INCLUDED
