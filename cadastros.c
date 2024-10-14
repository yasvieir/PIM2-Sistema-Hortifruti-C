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

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
    animacao_de_carregamento();
    SetConsoleTextAttribute(hConsole, saved_attributes);

    int escolha;

    do{
        "\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |           CADASTRO            |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          |   [1] - Novo Cadastros        |                                             \n"
                 "                                          |   [2] - Listar Cadastros      |                                             \n"
                 "                                          |   [4] - Editar Cadastro       |                                             \n"
                 "                                          |   [4] - Meus Dados            |                                             \n"
                 "                                          |   [0] - Sair                  |                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          #===============================#                                             \n"
               "\n                                         Escolha uma opção para continuar: ");

        scanf("%i", &escolha);

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
        }
    }while(escolha != 0);
    telaLimpa();
}

void NovoCadastro(){

    Pessoa

}
