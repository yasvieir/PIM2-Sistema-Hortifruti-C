#include "funcoes.h"

void verificaLogin(char ent_usuario[], char ent_senha[], int *comparador){

    char usuario[TAM_user] = {"admin"},
         senha[TAM_user] = {"admin123"};
    int compUsuario, compSenha;

    compUsuario = strcmp(usuario, ent_usuario);
    compSenha = strcmp(senha, ent_senha);

    if(compUsuario == 0 && compSenha == 0){
        *comparador = 0;
    }else{
        *comparador = 1;
    }
}

void mascSenha(char ent_senha, char *senha[TAM_user]){

    char senha_usuario[TAM_user] = {0};
    int pos = 0;
    int comparador;

    do{
        ent_senha = getch();

        if(isprint(ent_senha)){
            senha_usuario[pos++] = ent_senha;
            printf("%c", '*');
        }
        else if(ent_senha == 8 && pos){
            senha_usuario[pos--] = '\0';
            printf("%s", "\b \b");
        }
        strcpy(senha, senha_usuario);
    }while(ent_senha != 13);
}
