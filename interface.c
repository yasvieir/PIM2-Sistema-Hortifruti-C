//o arquivo interface.c, ficam as telas, onde o usuário poderá ver as opções do que ele pode interagir
#include "interface.h"
#include "structs.h"
#include "funcoes.h"
#include "estilos.h"
#include "cadastros.h"


void telaTamanho(){
    system("MODE con cols=168 lines=60");// configura a quantidad de colunas e linhas que o console terá;
}

void telaLimpa(){
    system("cls");// limpa a tela;
}

void telaPause(){
    system("pause > NULL");// pausa a tela sem mostrar o texto padrão da função;
}

void telaEstilo(){
    system("color F0");// define a cor "f" verde para o fundo e a cor "0" preto para o texto
}

void telaInicio(){

    system("title Início");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
    animacao_de_carregamento();
    SetConsoleTextAttribute(hConsole, saved_attributes);

    telaLimpa();

    printf("\n\n\n\n\n\n\n\n\n\n\n\n"
           "                                                    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
    bold(1);
    animacao_de_aparecimento("HORTIFRUT FRESH\n\n");
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n                                           Pressione Enter para continuar...");


    telaPause();
    telaLimpa();
    telaLogin();
}

void telaLogin(){

    system("title Login");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    char usuario[TAM_user], ent_senha, senha[TAM_user];
    int comparador;

    do{
        printf("\n\n\n\n\n\n\n"
               "\n                                         ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        printf(                                            "                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                   "                                         \n"
                 "                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        bold(1);
        printf(                                            "                Login                 ");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                   "                                         \n"
                 "                                         ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        printf(                                            "                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                   "                                         \n\n"
               "\n                                                ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                                " Usuário: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        gets(usuario);
        fflush(stdin);

        printf("\n                                                ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                                " Senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        mascSenha(ent_senha, &senha);
        fflush(stdin);

        verificaLogin(usuario, senha, &comparador);

        if(comparador == 1){
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t  [!] Login incorreto!\n"
                       "\t\t\t\t\t   Usuário ou senha estão incorretos!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
        }else{
            telaLimpa();
            telaMenuAdmin();
            break;
        }

    }while(comparador == 1);
}

void telaMenuAdmin(){

    system("title Menu Administrador");

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
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "              MENU                  ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [1] - Tela do Gerente           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Tela do Funcionário       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [0] - Sair                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           " Escolha uma opção para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 1:
            telaLimpa();
            telaGerente();
            break;
        case 2:
            telaLimpa();
            telaFuncionario();
            break;
        case 0:
            telaLimpa();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
            animacao_de_saida();
            SetConsoleTextAttribute(hConsole, saved_attributes);

            telaLimpa();
            telaSaida();
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

void telaGerente(){

    system("title Menu Gerencia");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |             MENU              |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          |   [1] - Cadastros             |                                             \n"
                 "                                          |   [2] - Pedidos               |                                             \n"
                 "                                          |   [3] - Estoque               |                                             \n"
                 "                                          |   [0] - Sair                  |                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          #===============================#                                             \n"
               "\n                                         Escolha uma opção para continuar: ");

        scanf("%i", &escolha);

        switch(escolha){
        case 1:
            telaLimpa();
            TelaCadastro();
            break;
        case 2:
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

void telaFuncionario(){

    system("title Menu Funcionário");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |             MENU              |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          |   [1] - Pedidos               |                                             \n"
                 "                                          |   [2] - Estoque               |                                             \n"
                 "                                          |   [3] - Minhas Informações    |                                             \n"
                 "                                          |   [0] - Sair                  |                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          #===============================#                                             \n"
               "\n                                         Escolha uma opção para continuar: ");

        scanf("%i", &escolha);

        switch(escolha){
        case 1:
            telaLimpa();

            break;
        case 2:
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

void telaSaida(){

    system("title Menu");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n\n\n\n\n\n\n\n\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                MENU                ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "      [1] - Voltar ao Início        ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "      [2] - Login                   ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "      [0] - Encerrar Programa       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           " Escolha uma opção para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 1:
            telaLimpa();
            telaInicio();
            break;
        case 2:
            telaLimpa();
            telaLogin();
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
