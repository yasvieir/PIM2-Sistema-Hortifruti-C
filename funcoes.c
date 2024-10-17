#include "funcoes.h"

int verificaLogin(char *ent_usuario, char *ent_senha){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo = fopen("cadastros.bin", "rb");
    if (arquivo == NULL){
        //Se o arquivo não existe, cria um novo e adiciona o cadastro do Administrador.
        arquivo = fopen("cadastros.bin", "wb");
        if(arquivo == NULL){
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!"); bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return;
            }
            //Cria cadastro do Administrador.
            pessoa.ID = 0;
            strcpy(pessoa.nome, "Administrador\0");
            strcpy(pessoa.login.usuario, "admin\0");
            strcpy(pessoa.login.senha, "admin123\0");
            strcpy(pessoa.cargo, "ADMINISTRADOR\0");

            //Escreve cadastro Administrador no arquivo.
            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);

            fclose(arquivo);
    }

    while (fread(&pessoa, sizeof(Pessoa), 1, arquivo)) {
        if (pessoa.ID != 1 && strcmp(pessoa.login.usuario, ent_usuario) == 0 && strcmp(pessoa.login.senha, ent_senha) == 0) {
            fclose(arquivo);
            return 1; // Usuário encontrado.
        }
    }
    fclose(arquivo);
    return 0; // Usuário não encontrado.
}

void mascSenha(char ent_senha, char *senha[TAM_user]){

    char senha_usuario[TAM_user] = "0";
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

int usuarioExiste(char *usuario){

    FILE *arquivo;

    //Abre um arquivo binário (cria de não existe).
    arquivo = fopen("cadastros.bin", "rb");

    if(arquivo == NULL){
        return 0; //Arquivo não existe, ou não pode ser aberto;
    }

    Pessoa pessoa;
    while(fread(&pessoa, sizeof(Pessoa), 1, arquivo)){
        if(pessoa.ID != 1 && strcmp(pessoa.login.usuario, usuario) == 0){
            fclose(arquivo);
            return 1; //Usuário encontrado.
        }
    }
    fclose(arquivo);
    return 0;
}

void verificaSenhas(char ent_senha1[], char ent_senha2[], int *comparador){

    int compSenha;

    compSenha = strcmp(ent_senha1, ent_senha2);

    if(compSenha == 0){
        *comparador = 0;
    }else{
        *comparador = 1;
    }
}
