#include "cadastros.h"
#include "structs.h"
#include "estilos.h"
#include "funcoes.h"

void TelaCadastro(){

    system("title Cadastros");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n\n\n\n\n\n\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                 MENU                ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [0] - Voltar                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [1] - Novo Cadastro              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Listar Cadastros           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Buscar e Editar Cadastro   ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [4] - Sair                       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "  Escolha uma opção para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 1:
            telaLimpa();
            NovoCadastro();
            break;
        case 2:
            telaLimpa();
            ListarCadastros();
            break;
        case 3:
            telaLimpa();
            EditarCadastro();
            break;
        case 4:
            telaLimpa();
            DadosUsuario();
            break;
        case 0:
            telaLimpa();
            break;
        default :
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!"); bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();
}

void NovoCadastro(){

    system("title Novo Cadastro");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo;

    //Verifica se o arquivo existe.
    arquivo = fopen("cadastros.bin", "rb");
    if(arquivo == NULL){
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
    }else{
        fclose(arquivo);
    }

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                                                                                                      \n"
             "                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(  " ID: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Gera um novo ID incremental.
    pessoa.ID = gerarID();
    //Mostra ID atual.
    printf(" %i", pessoa.ID);

    printf("\n\n");
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Campo de inserção - Nome:
    while(1){
        printf("\n                                           ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                              " Nome: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nome) == 0){
            bold(1);
            printf(RED "\n\n                                       [!] O campo nome não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de Inserção - Usuário:
    while(1){
        printf("\n                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           " Usuário: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
        pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        while(usuarioExiste(pessoa.login.usuario)){
            bold(1);
            printf(RED "\n\n                                 [!] O Usuário já existe, por favor escolha outro!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);

        }

        if(strlen(pessoa.login.usuario) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo usuário não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de insersão - Senha:
    char ent_senha1, senha1[TAM_user],
         ent_senha2, senha2[TAM_user];
    while(1){
        printf("\n                                          ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                             " Senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha1 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha1[i] = '\0';
        }

        mascSenha(ent_senha1, &senha1);
        fflush(stdin);

        if(strlen(senha1) < 8){
            bold(1);
            printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de insersão - Confirmação de Senha:
    while(1){
        printf("\n                             ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                " Confirme sua senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha2 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha2[i] = '\0';
        }

        mascSenha(ent_senha2, &senha2);
        fflush(stdin);

        if(strlen(senha2) < 8){
            bold(1);
            printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Senha: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", senha1);
        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    int comparador;
    //Verifica se senhas são iguais:
    verificaSenhas(senha1, senha2, &comparador);
    if(comparador == 1){
        comparador = 0;
        bold(1);
        printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(1000);
        telaLimpa();
        do{
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

            //Campo de insersão - Senha:
            while(1){
                printf("\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha1 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha1[i] = '\0';
                }

                mascSenha(ent_senha1, &senha1);
                fflush(stdin);

                if(strlen(senha1) < 8){
                    bold(1);
                    printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(  "                                                                                                                      \n"
                             "                                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                                " ID: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %i\n\n ", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);

                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de insersão - Confirmação de Senha:
            while(1){
                printf("\n                             ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                " Confirme sua senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha2 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha2[i] = '\0';
                }

                mascSenha(ent_senha2, &senha2);
                fflush(stdin);

                if(strlen(senha2) < 8){
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(  "                                                                                                                      \n"
                             "                                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                                " ID: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %i\n\n ", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);
                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Verifica se senhas são iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                telaLimpa();
            }
        }while(comparador == 1);
    }else{
        senha2[strcspn(senha2, "\n")] = 0;
        strcpy(pessoa.login.senha, senha2);
    }
    //Campo de Inserção - E-mail:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " E-mail: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.email, sizeof(pessoa.email), stdin);
        pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.email) == 0){
            bold(1);
            printf(RED "\n\n\t\t\t [!] O campo e-mail não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(  "                                                                                                                      \n"
                             "                                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                                " ID: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %i\n\n ", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);
                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                    printf("\n                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                " Confirme sua senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha2);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    telaLimpa();
    //Campo de seleção - Cargo:
    int escolhaCargo;
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                                                                                                      \n"
             "                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                " ID: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %i\n\n ", pessoa.ID);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                        CARGO:                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                 ");
    while(1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(                                  " Digite o número correspondente ao cargo escolhido: ");
        scanf("%i", &escolhaCargo);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        fflush(stdin);

        switch(escolhaCargo){
        case 1:
            strcpy(pessoa.cargo, "GERENTE\0");
            break;
        case 2:
            strcpy(pessoa.cargo, "OPERADOR DE CAIXA\0");
            break;
        case 3:
            strcpy(pessoa.cargo, "ESTOQUISTA\0");
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t [!] Opção inválida! Tente novamente.\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                        CARGO:                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "\n                              ");
        }
        telaLimpa();
        if(escolhaCargo >= 1 && escolhaCargo <= 4){
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                        CARGO:                                                        \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break; //Sai do loop se a opção for válida
        }
    }
    //Campo de inserção - Data de nascimento:
    while(1){
        printf(  "\n                 ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                        " Data de Nascimento(00/00/0000): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.nasc, sizeof(pessoa.nasc), stdin);
        pessoa.nasc[strcspn(pessoa.nasc, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nasc) == 0){
            bold(1);
            printf(RED "\n\n                                 [!] O campo Data de Nascimento não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - CPF:
    while(1){
        printf(  "\n                            ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                 " CPF(000.000.000/00): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.documentos.cpf, sizeof(pessoa.documentos.cpf), stdin);
        pessoa.documentos.cpf[strcspn(pessoa.documentos.cpf, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.cpf) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CPF não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                 ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                    " Data de Nascimento(00/00/0000): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nasc);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - RG:
    while(1){
        printf("\n                                ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                   " RG(00.000.000-0: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.documentos.rg, sizeof(pessoa.documentos.rg), stdin);
        pessoa.documentos.rg[strcspn(pessoa.documentos.rg, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.rg) == 0){
            bold(1);
            printf(RED "\n\n                                         [!] O campo RG não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                 ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                    " Data de Nascimento(00/00/0000): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nasc);
            printf("\n                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                               " CPF(000.000.000/00): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.documentos.cpf);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    telaLimpa();
    //Campo de inserção - Rua:
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                                                                                                      \n"
             "                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                " ID: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %i\n\n ", pessoa.ID);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                      ENDEREÇO:                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    while(1){
        printf("\n                                            ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                               " Rua: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.rua, sizeof(pessoa.endereco.rua), stdin);
        pessoa.endereco.rua[strcspn(pessoa.endereco.rua, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.rua) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo Rua não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Número:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " Número: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.num_resid, sizeof(pessoa.endereco.num_resid), stdin);
        pessoa.endereco.num_resid[strcspn(pessoa.endereco.num_resid, "\n")] = 0; // Remove a nova linha
        fflush(stdin);

        if(strlen(pessoa.endereco.num_resid) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Número não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                               " Rua: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Bairro:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " Bairro: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.bairro, sizeof(pessoa.endereco.bairro), stdin);
        pessoa.endereco.bairro[strcspn(pessoa.endereco.bairro, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.bairro) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Bairro não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                               " Rua: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - CEP:
    while(1){
        printf("\n                                 ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                    " CEP(00000-000): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.cep, sizeof(pessoa.endereco.cep), stdin);
        pessoa.endereco.cep[strcspn(pessoa.endereco.cep, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.cep) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CEP não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                               " Rua: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Bairro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.bairro);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Complemento:
    while(1){
        printf("\n                                    ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                       " Complemento: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.complemento, sizeof(pessoa.endereco.complemento), stdin);
        pessoa.endereco.complemento[strcspn(pessoa.endereco.complemento, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.complemento) == 0){
            bold(1);
            printf(RED "\n\n                                [!] O campo Complemento não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                               " Rua: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Bairro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.bairro);
            printf("\n                                 ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                    " CEP(00000-000):");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                     " %s\n", pessoa.endereco.cep);
        }else{
            break; //Sai do loop se o nome for válido.
        }
    }
    telaLimpa();

    //Mostra todos os campos inseridos.
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                                                                                                      \n"
             "                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                " ID: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %i\n", pessoa.ID);
    printf("\n                                           ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                              " Nome: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.nome);
    printf("\n                                        ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                           " Usuário: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.login.usuario);
    printf("\n                                          ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                             " Senha: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", senha1);
    printf("\n                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " E-mail: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.email);
    printf(" ");
    printf("\n                                          ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                             " Cargo: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.cargo);
    printf("\n                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                " Data de Nascimento: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.nasc);
    printf("\n                                            ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                               " CPF: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.documentos.cpf);
    printf("\n                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                " RG: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.documentos.rg);
    printf("\n                                            ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                               " Rua: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.rua);
    printf("\n                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " Número: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.num_resid);
    printf("\n                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " Bairro: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.bairro);
    printf("\n                                            ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                               " CEP: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                     " %s\n", pessoa.endereco.cep);
    printf("\n                                    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                       " Complemento: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                     " %s\n", pessoa.endereco.complemento);

    int escolha;
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                         [1] SALVAR | [2] EDITAR | [3] CANCELAR                                       ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" \n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n                                                  ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(                                                     " Escolha uma opção: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    scanf("%i", &escolha);
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    switch(escolha){
    case 1:
        //Abre arquivo para escrita binária.
        arquivo = fopen("cadastros.bin", "wb");

        //Verifica se o arquivo foi encontrado.
        if(arquivo == NULL){
            bold(1);
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return;
        }

        //Escreve dados inseridos no arquivo.
        fwrite(&pessoa,sizeof(Pessoa), 1, arquivo);

        //Fecha arquivo.
        fclose(arquivo);

        //Salva o último ID.
        salvarUltimoID(pessoa.ID);

        //Mensagem de cadastro realizado.
        bold(1);
        printf(GREEN "\n\n                                            Cadastro realizado com sucesso!\a\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);

        telaLimpa();
        TelaCadastro();

    case 2:
        telaLimpa();
        printf(  "\n                                          #===============================#                                             \n"
                   "                                          |           CADASTRO            |                                             \n"
                   "                                          #===============================#                                             \n"
                   "                                                                                                                        \n"
                   "                                            ID: %i", pessoa.ID);
        printf("\n\n                                                  DADOS DO USUÁRIO:"
                 "\n                                          Nome: %s", pessoa.nome);
        printf(  "\n                                       Usuário: %s", pessoa.login.usuario);
        printf(  "\n                                         Senha: %s", senha1);
        printf(  "\n                            Confirme sua senha: %s", senha2);
        printf(  "\n                                        e-mail: %s", pessoa.email);
        printf("\n\n                                                       CARGO:"
                 "\n                                         Cargo: %s", pessoa.cargo);
        printf("\n\n                                                     DOCUMENTOS:"
                 "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc);
        printf(  "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf);
        printf(  "\n                               RG(00.000.000-0: %s", pessoa.documentos.rg);
        printf("\n\n                                                      ENDEREÇO:"
                 "\n                                           Rua: %s", pessoa.endereco.rua);
        printf(  "\n                                        Número: %s", pessoa.endereco.num_resid);
        printf(  "\n                                        Bairro: %s", pessoa.endereco.bairro);
        printf(  "\n                                CEP(00000-000): %s", pessoa.endereco.cep);
        printf(  "\n                                   Complemento: %s", pessoa.endereco.complemento);
        printf("\n\n                                                    INFORMAÇÕES: \n"
               "\n\n                                                  DADOS DO USUÁRIO:"
                 "\n                                     [1] Nome | [2] Usuário | [3] Senha | [4] e-mail"
               "\n\n                                                       CARGO:"
                 "\n                                                       [5] cargo"
               "\n\n                                                     DOCUMENTOS:"
                 "\n                                         [6] Data Nascimento | [7] CPF | [8] RG"
               "\n\n                                                      ENDEREÇO:"
                 "\n                             [9] Rua | [10] Número | [11] Bairro | [12] CEP | [13] Complemento"
               "\n\n                                          Qual informação deseja editar: \n");
        int opcao;
        scanf("%i", opcao);
        fflush(stdin);

        telaLimpa();
        printf("\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |            EDITAR             |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                                                                                                        \n");

        switch(opcao){
        case 1:
            //Campo de inserção - Nome:
            while(1){
                printf("\n                                          Nome: ");
                fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.nome) == 0){
                    bold(1);
                    printf(RED "\n\n                                       [!] O campo nome não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n\n\n\n\n\n\n"
                           "\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }

            //Mensagem de alteração realizada.
            bold(1);
            printf(GREEN "\n\n                                          Alteração realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 2:
            //Campo de Inserção - Usuário:
            while(1){
                printf("\n                                       Usuário: ");
                fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
                pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                while(usuarioExiste(pessoa.login.usuario)){
                    printf("\n\n                              [!] O Usuário já existe, por favor escolha outro!\a");
                    printf("\n                                       Usuário: ");
                    fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
                    pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
                    fflush(stdin);

                }

                if(strlen(pessoa.login.usuario) == 0){
                    bold(1);
                    printf(RED "\n\n                                     [!] O campo usuário não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n\n\n\n\n\n\n"
                           "\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }

            //Mensagem de alteração realizada.
            bold(1);
            printf(GREEN "\n\n                                          Alteração realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 3:
            //Campo de insersão - Senha:
            while(1){
                printf("\n                                         Senha: ");

                fflush(stdin);

                if(strlen(senha1) == 0){
                    bold(1);
                    printf(RED "\n\n                                      [!] O campo senha não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");

                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de insersão - Confirmação de Senha:
            while(1){
                printf("\n                            Confirme sua senha: ");

                fflush(stdin);

                if(strlen(senha2) == 0){
                    bold(1);
                    printf(RED "\n\n                               [!] O campo confirme sua senha não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n"
                           "\n                                         Senha: %s", senha1);
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            int comparador;
            //Verifica se senhas são iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                do{
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                    //Campo de insersão - Senha:
                    while(1){
                        printf("\n                                         Senha: ");

                        fflush(stdin);

                        if(strlen(senha1) == 0){
                            bold(1);
                            printf(RED "\n\n                                      [!] O campo senha não pode estar vazio!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            printf("\n                                          #===============================#                                             \n"
                                     "                                          |            EDITAR             |                                             \n"
                                     "                                          #===============================#                                             \n"
                                     "                                                                                                                        \n");

                        }else{
                            break; //Sai do loop se o nome for válido
                        }
                    }
                    //Campo de insersão - Confirmação de Senha:
                    while(1){
                        printf("\n                            Confirme sua senha: ");

                        fflush(stdin);

                        if(strlen(senha2) == 0){
                            bold(1);
                            printf(RED "\n\n                               [!] O campo confirme sua senha não pode estar vazio!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            printf("\n                                          #===============================#                                             \n"
                                     "                                          |            EDITAR             |                                             \n"
                                     "                                          #===============================#                                             \n"
                                     "                                                                                                                        \n"
                                   "\n                                         Senha: %s", senha1);
                        }else{
                            break; //Sai do loop se o nome for válido
                        }
                    }
                }while(comparador == 1);
            }else{
                senha1[strcspn(senha1, "\n")] = 0;
                strcpy(pessoa.login.senha, senha1);
            }

            //Mensagem de alteração realizada.
            bold(1);
            printf(GREEN "\n\n                                          Alteração realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 4:
            //Campo de Inserção - E-mail:
            while(1){
                printf("\n                                         e-mail: ");
                fgets(pessoa.email, sizeof(pessoa.email), stdin);
                pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.email) == 0){
                    bold(1);
                    printf(RED "\n\n\t\t\t [!] O campo e-mail não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");

                }else{
                    break; //Sai do loop se o nome for válido
                }
            }

            //Mensagem de alteração realizada.
            bold(1);
            printf(GREEN "\n\n                                          Alteração realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
        break;
        }
    case 3:
        telaLimpa();
        TelaCadastro();
        }
}

void ListarCadastros(){

}

void EditarCadastro(){

}

void DadosUsuario(){

}
