#include "estoque.h"
#include "structs.h"
#include "estilos.h"
#include "funcoes.h"

void TelaEstoque(){

    system("title Produtos");

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
        printf(                                           "    [1] - Mostrar Estoque            ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Buscar e Adicionar Item    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Sair                       ");
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
        case 0:
            telaLimpa();
            // Aqui você pode usar o cargo para redirecionar o usuário
            if(strcmp(usuarioLogado.cargo, "ADMINISTRADOR") == 0){
                telaMenuAdmin(); // Chama a tela do menu do administrador
            }else if(strcmp(usuarioLogado.cargo, "GERENTE") == 0){
                telaGerente(); // Chama a tela do gerente
            }else if(strcmp(usuarioLogado.cargo, "OPERADOR DE CAIXA") == 0 || strcmp(usuarioLogado.cargo, "ESTOQUISTA") == 0){
                telaFuncionario(); // Chama a tela do funcionário
            }
            break; // Sai do loop se o login for bem-sucedido
        case 1:
            telaLimpa();
            MostrarEstoque();
            break;
        case 2:
            telaLimpa();
            BuscarEstoque();
            break;
        case 3:
            telaLimpa();
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
            animacao_de_saida();
            SetConsoleTextAttribute(hConsole, saved_attributes);

            telaLimpa();
            telaSaida();
            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();
}

void ListarEstoque(Produto produto){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: %i                                                          ", produto.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n \t\t\t");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                    " Nome: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                            " %s\t\t", produto.nome);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                  " Preço (por kg): ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                           " R$ %.2f\t", produto.preco);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                      " Quantidade: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                              " %.3f kg", produto.qtd_peso);
}

void MostrarEstoque(){

    system("title Estoque");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Produto produto;
    FILE *arquivo;

    //Abre arquivo para pesquisas binárias
    arquivo = fopen("dados\\produtos\\produtos.bin", "rb");
    if(arquivo == NULL){
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Nenhum produto encontrado!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       ESTOQUE                                                        \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Lê os dados do arquivo binário.
    while(fread(&produto, sizeof(produto), 1, arquivo) == 1){
        if(produto.ID != 0){ // Pula a impressão do usuário administrador.
            printf("\n");
            ListarEstoque(produto);

        }
        printf("\n");
    }

    //Fecha o arquivo.
    fclose(arquivo);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                             PRESSIONE ENTER PARA VOLTAR                                              ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    telaPause();
    return;
}

void BuscarEstoque(){

system("title Buscar Produto");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int idBuscado;

    while(1){

        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                   BUSCAR PRODUTO                                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        printf("   ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" Digite o ID do produto que deseja buscar: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        scanf("%i", &idBuscado);
        fflush(stdin);

        Produto produto = buscarProdutoPorID(idBuscado);

        //Verifica se o ID é igual a zero.
        if (idBuscado == 0) {
            bold(1);
            printf(RED "\n\n                                                [ERRO:] Nenhum produto encontrado!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            return; //Encerra a função.
        }

        if(produto.ID != -1){

            bold(1);
            printf(GREEN "\n\n                                             Produto encontrado com sucesso!\n\n");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                  BUSCA DE PRODUTO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n");
            //Mostrando dados do cadastro.
            ListarEstoque(produto);

            //Dando opção de editar
            int escolha;

            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                               Deseja editar quantidade do produto? [1] Sim | [0] Não                                 ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                                  ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(                                                     " Escolha uma opção: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);

            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            scanf("%i", &escolha);
            fflush(stdin);
            SetConsoleTextAttribute(hConsole, saved_attributes);

            if(escolha == 1){
                telaLimpa();
                EditarEstoque(produto);
            }
            break;

        }else{
            bold(1);
            printf(RED "\n\n                                                [ERRO:] Nenhum cadastro encontrado!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            return;
        }
    }
}

void AdicionarQuantidade(Produto *produto, float quantidade){
    if(quantidade < 0){
        printf(RED "\n\n                                       [!] A quantidade a ser adicionada não pode ser negativa!\a");
        telaLimpa();
        return;
    }

    produto -> qtd_peso += quantidade;
}

void SubtrairQuantidade(Produto *produto, float quantidade){
    if(quantidade < 0){
        printf(RED "\n\n                                       [!] A quantidade a ser subtraída não pode ser negativa!\a");
        telaLimpa();
        return;
    }

    if(quantidade > produto -> qtd_peso){
        printf(RED "\n\n                                       [!] Não há quantidade suficiente para subtrair!\a");
        telaLimpa();
        return;
    }

    produto -> qtd_peso -= quantidade;
}

void EditarEstoque(Produto produto){

    system("title Editar Quantidade do Produto");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int opcao;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                   EDITAR PRODUTO                                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                  ESCOLHA UMA OPÇÃO                                                   ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                     [1] Adicionar | [2] Retirar | [3] CANCELAR                                       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n                                                ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(                                                   " Escolha uma opção: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        scanf("%i", &opcao);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        float quantidade;

        switch(opcao){
        case 1:
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                ADICIONAR QUANTIDADE                                                  ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n");

            printf("                               ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                " Quantidade (em kg): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            scanf("%f", &quantidade);
            fflush(stdin);

            AdicionarQuantidade(&produto, quantidade);

            //Salvando as alterações no arquivo.
            FILE *arquivo1 = fopen("dados\\produtos\\produtos.bin", "rb+");
            if(arquivo1 != NULL){
                //Posicionando o ponteiro no início do arquivo.
                fseek(arquivo1, 0, SEEK_SET);

                Produto cadastro;
                int encontrado = 0;

                //Lendo os cadastros até encontrar o ID.
                while(fread(&cadastro, sizeof(Produto), 1, arquivo1)){
                    if (cadastro.ID == produto.ID) {
                        encontrado = 1;
                        //Posicionando o ponteiro no início do cadastro encontrado.
                        fseek(arquivo1, -sizeof(Produto), SEEK_CUR);
                        //Escreva as alterações no arquivo.
                        fwrite(&produto, sizeof(Produto), 1, arquivo1);
                        break; //Encerrando o loop se o ID for encontrado.
                    }
                }

                fclose(arquivo1); //Fecha o arquivo.

                if(encontrado){
                    bold(1);
                    printf(GREEN "\n\n                                             Quantidade adicionada com sucesso!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaEstoque();
                    break;
                }else{
                    bold(1);
                    printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o quantidade!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaEstoque();
                    break;
                }
            }else{
                bold(1);
                printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                TelaEstoque();
                break;
            }
            break;
        case 2:
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                 RETIRAR QUANTIDADE                                                   ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n");

            printf("                               ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                " Quantidade (em kg): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            scanf("%f", &quantidade);
            fflush(stdin);

            SubtrairQuantidade(&produto, quantidade);

            //Salvando as alterações no arquivo.
            FILE *arquivo = fopen("dados\\produtos\\produtos.bin", "rb+");
            if(arquivo != NULL){
                //Posicionando o ponteiro no início do arquivo.
                fseek(arquivo, 0, SEEK_SET);

                Produto cadastro;
                int encontrado = 0;

                //Lendo os cadastros até encontrar o ID.
                while(fread(&cadastro, sizeof(Produto), 1, arquivo)){
                    if (cadastro.ID == produto.ID) {
                        encontrado = 1;
                        //Posicionando o ponteiro no início do cadastro encontrado.
                        fseek(arquivo, -sizeof(Produto), SEEK_CUR);
                        //Escreva as alterações no arquivo.
                        fwrite(&produto, sizeof(Produto), 1, arquivo);
                        break; //Encerrando o loop se o ID for encontrado.
                    }
                }

                fclose(arquivo); //Fecha o arquivo.

                if(encontrado){
                    bold(1);
                    printf(GREEN "\n\n                                             Quantidade adicionada com sucesso!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaEstoque();
                    break;
                }else{
                    bold(1);
                    printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o quantidade!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaEstoque();
                    break;
                }
            }else{
                bold(1);
                printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                TelaEstoque();
                break;
            }
            break;
        case 3:
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaPause();
    }while(opcao != 3);
    telaLimpa();
}
