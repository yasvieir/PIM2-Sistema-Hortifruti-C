#include "produtos.h"
#include "structs.h"
#include "estilos.h"
#include "funcoes.h"

void TelaProdutos(){

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
        printf(                                           "    [1] - Novo Produto               ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Listar Produtos            ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Buscar e Editar Produtos   ");
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
        case 0:
            telaLimpa();
            telaGerente();
            break;
        case 1:
            telaLimpa();
            NovoProduto();
            break;
        case 2:
            telaLimpa();
            ListarProdutos();
            break;
        case 3:
            telaLimpa();
            BuscaProduto();
            break;
        case 4:
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

void ListarProduto(Produto produto){

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
    printf(                            " %s\t\t\t", produto.nome);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                  " Preço (por kg): ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                           " R$ %.2f\t", produto.preco);
}

void NovoProduto(){

    system("title Novo Produto");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Produto produto;

    FILE *arquivo;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       PRODUTO                                                        \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: ");

    // Gera ID incremental.
    produto.ID = gerarID_Produto();

    // Mostra ID atual
    printf(                                                              " %i                                                         ", produto.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    //Campo de inserção - Nome:
    while(1){
        printf("\n                                           ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                              " Nome: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        fgets(produto.nome, sizeof(produto.nome), stdin);
        produto.nome[strcspn(produto.nome, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(produto.nome) == 0){
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
            printf(  "                                                       PRODUTO                                                        \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %i                                                          ", produto.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
        }else{
            break; //Sai do loop se o nome for válido
        }
    }

    // Campo de inserção - Preço:
    while (1) {
        printf("\n                                           ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" Preço (por kg): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" R$ ");

        // Lê o preço
        scanf("%f", &produto.preco);
        fflush(stdin);

        // Valida se o preço é válido (não pode ser negativo)
        if (produto.preco < 0) {
            bold(1);
            printf(RED "\n\n                                       [!] O preço não pode ser negativo!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            continue; // Volta para o início do loop
        } else {
            break; // Sai do loop se o preço for válido
        }
    }
    telaLimpa();

    //Mostra todos os campos inseridos.
    int escolha;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                       PRODUTO                                                        \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");

        ListarProduto(produto);

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
            arquivo = fopen("dados\\produtos\\produtos.bin", "ab");

            //Verifica se o arquivo foi encontrado.
            if(arquivo == NULL){
                bold(1);
                printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                return;
            }

            //Escreve dados inseridos no arquivo.
            fwrite(&produto,sizeof(Produto), 1, arquivo);

            //Fecha arquivo.
            fclose(arquivo);

            //Salva o último ID.
            salvarUltimoID_Produto(produto.ID);

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
            //Abre arquivo para escrita binária.
            arquivo = fopen("dados\\produtos\\produtos.bin", "ab");

            //Verifica se o arquivo foi encontrado.
            if(arquivo == NULL){
                bold(1);
                printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                return;
            }

            //Escreve dados inseridos no arquivo.
            fwrite(&produto,sizeof(Produto), 1, arquivo);

            //Fecha arquivo.
            fclose(arquivo);

            //Salva o último ID.
            salvarUltimoID(produto.ID);
            EditarProduto(produto);
            break;
        case 3:
            telaLimpa();
            TelaCadastro();
            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
        }
    }while(escolha != 0);
}

void ListarProdutos(){

    system("title Lista de Produtos");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Produto produto;
    FILE *arquivo;
}

void BuscaProduto(){
}

void BuscarProduto(){
}

void EditarProduto(Produto produto){
}
