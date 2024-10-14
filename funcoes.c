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

int lerUltimoID(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("ultimo_id.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID, sizeof(int), 1, arquivo); // Lê o último ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo não existir, inicializa ultimoID com 0
        ultimoID = 0;
    }

    return ultimoID;
}

int salvarUltimoID(int ultimoID){

    FILE *arquivo;

    //Abre um arquivo binário (cria de não existe).
    arquivo = fopen("ultimo_id.bin", "wb");
    if(arquivo != NULL){
        //Escreve o último ID no arquivo.
        fwrite(&ultimoID, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID(){

    static int ultimoID; // Remove a inicialização com lerUltimoID().

    //Verificando se é a primeira vez que a função é chamada.
    if(ultimoID == 0){
        // Lê o último ID do arquivo.
        ultimoID = lerUltimoID();
    }
    return ++ultimoID; // Retorna o próximo ID incremental.
}
