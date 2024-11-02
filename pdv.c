#include "pdv.h"
#include "structs.h"
#include "estilos.h"
#include "funcoes.h"
#include "estoque.h"

void TelaPDV(){

    system("title Ponto de Venda");

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
        printf(                                           "    [1] - Iniciar Venda              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Buscar Venda               ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Histórico de Venda         ");
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
            MontarCarrinho();
            break;
        case 2:
            telaLimpa();

            break;
        case 3:
            telaLimpa();

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

void ListaDeProdutos(){

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

    //Lê os dados do arquivo binário.
    while(fread(&produto, sizeof(produto), 1, arquivo) == 1){
        if(produto.ID != 0){ // Pula a impressão do usuário administrador.
            printf("\n\t");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(" [%i] %s ", produto.ID, produto.nome);
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        printf("\n");
    }
    fclose(arquivo);
}

void MontarCarrinho(){

    system("title Carrinho");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Carrinho carrinho;
    carrinho.totalProdutos = 0;
    carrinho.valor_total = 0.0;

    int escolha;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                       CARRINHO                                                       \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                       ID: ");

        //Gerando id do carrinho
        carrinho.ID = gerarID_Carrinho();

        // Mostra ID atual
        printf(                                                              " %03i                                                      ", carrinho.ID);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        Carrinho carrinhoLista;
        Produto itens;
        FILE *arquivo;

        //Abre arquivo para pesquisas binárias
        arquivo = fopen("dados\\vendas\\carrinho.bin", "rb");
        if(arquivo == NULL){
            arquivo = fopen("dados\\vendas\\carrinho.bin", "wb");
            fclose(arquivo);
        }

        //Lê os dados do arquivo binário.
        while(fread(&itens, sizeof(itens), 1, arquivo) == 1){
            if(itens.ID != 0){ // Pula a impressão do usuário administrador.
                printf("\t");
                printf("Item: %i | Produto: %s | Quantidade: %.3f kg | Valor: R$ %.2f\n",
                       itens.ID,
                       itens.nome,
                       itens.qtd_peso,
                       itens.preco * itens.qtd_peso);
            }
            printf("\t-------------------------------------------------------------------------------------------------------\n");
        }
        fclose(arquivo);

        printf("\n\t\t\t\t\t\tValor total: R$ %.2f\n", carrinho.valor_total);

        printf("\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "               OPÇÕES               ");
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
        printf(                                           "    [1] - Adicionar Item            ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Remover Item              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Finalizar Venda           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [0] - Voltar                    ");
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
        case 0:
            telaLimpa();
            return;
            break;
        case 1:
            telaLimpa();
            AdicionarItemCarrinho(&carrinho);
            break;
        case 2:
            telaLimpa();
            RemoverItemCarrinho(&carrinho);
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

void AdicionarItemCarrinho(Carrinho *carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int idProduto;
    float quantidade;

    // Exibir lista de produtos
    ListaDeProdutos();

    printf("\n\t");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(" Digite o ID do produto que deseja adicionar ao carrinho: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    scanf("%i", &idProduto);
    fflush(stdin);

    // Encontrar o produto no estoque
    Produto produtoSelecionado;
    FILE *arquivo = fopen("dados\\produtos\\produtos.bin", "rb");
    if (arquivo != NULL) {
        while (fread(&produtoSelecionado, sizeof(Produto), 1, arquivo)) {
            if (produtoSelecionado.ID == idProduto) {
                fclose(arquivo); // Certifique-se de fechar o arquivo
                break; // Produto encontrado
            }
        }
    }

    if (produtoSelecionado.ID != idProduto) {
        bold(1);
        printf(RED "\n\n                                            [!] produto não encontrado!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    printf("\n\t");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(" Quantidade (em kg): ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    scanf("%f", &quantidade);
    fflush(stdin);

    // Verifica se a quantidade está disponível no estoque
    if (quantidade <= 0 || quantidade > produtoSelecionado.qtd_peso) {
        bold(1);
        printf(RED "\n\n                                  [!] Quantidade inválida ou maior que o disponível em estoque!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    // Calcula o valor do item
    float valorItem = produtoSelecionado.preco * quantidade;
    printf("Valor do item: R$ %.2f\n", valorItem);

    // Adiciona o item ao carrinho
    FILE *carrinhoArquivo = fopen("dados\\vendas\\carrinho.bin", "ab");
    if (carrinhoArquivo != NULL) {
        Produto itemCarrinho = produtoSelecionado; // Copia o produto para o carrinho
        itemCarrinho.qtd_peso = quantidade; // Armazena a quantidade comprada
        fwrite(&itemCarrinho, sizeof(Produto), 1, carrinhoArquivo);
        fclose(carrinhoArquivo);
    }

    // Atualiza o estoque
    SubtrairQuantidade(&produtoSelecionado, quantidade);

    //Salvando as alterações no arquivo.
    FILE *arquivoEstoque = fopen("dados\\produtos\\produtos.bin", "rb+");
    if (arquivoEstoque != NULL) {
        Produto cadastro;
        int encontrado = 0;

        // Lendo os cadastros até encontrar o ID.
        while (fread(&cadastro, sizeof(Produto), 1, arquivoEstoque)) {
            if (cadastro.ID == produtoSelecionado.ID) {
                encontrado = 1;
                // Posicionando o ponteiro no início do cadastro encontrado.
                fseek(arquivoEstoque, - sizeof(Produto), SEEK_CUR);
                // Escreva as alterações no arquivo.
                fwrite(&produtoSelecionado, sizeof(Produto), 1, arquivoEstoque);
                break; // Encerrando o loop se o ID for encontrado.
            }
        }

        fclose(arquivoEstoque); // Fecha o arquivo.
    }

    bold(1);
    printf(GREEN "\n\n                                         Item adicionado ao carrinho com sucesso!\a\a");
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    Sleep(800);
}

void RemoverItemCarrinho(Carrinho *carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // Exibir itens no carrinho
    Carrinho carrinhoLista;
    Produto itens;
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "rb");
    if(arquivoCarrinho == NULL){
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Carrinho vazio!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        return;
    }

    printf("\n\tItens no Carrinho:\n");
    while(fread(&itens, sizeof(Produto), 1, arquivoCarrinho) == 1){
        if (itens.ID != 0) { // Pula o item se for um ID inválido
            printf("Item: %i | Produto: %s | Quantidade: %.3f kg | Valor: R$ %.2f\n",
                   itens.ID,
                   itens.nome,
                   itens.qtd_peso,
                   itens.preco * itens.qtd_peso);
        }
    }
    fclose(arquivoCarrinho);

    // Solicitar ao usuário o ID do item a ser removido
    int idProdutoRemover;
    printf("\nDigite o ID do produto que deseja remover do carrinho: ");
    scanf("%i", &idProdutoRemover);
    fflush(stdin);

    // Reabrir o arquivo para modificar
    arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "rb+");
    if(arquivoCarrinho == NULL){
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Não foi possível abrir o carrinho!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        return;
    }

    Produto produtoRemovido;
    int encontrado = 0;

    // Criar um novo arquivo temporário para armazenar os itens que não foram removidos
    FILE *tempArquivo = fopen("dados\\vendas\\carrinho_temp.bin", "wb");
    if(tempArquivo == NULL){
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Não foi possível criar arquivo temporário!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        fclose(arquivoCarrinho);
        return;
    }

    // Lê os itens do carrinho
    while(fread(&itens, sizeof(Produto), 1, arquivoCarrinho) == 1){
        if(itens.ID == idProdutoRemover){
            encontrado = 1;
            produtoRemovido = itens; // Armazena o produto que será removido
            continue; // Não escreve o item removido no arquivo temporário
        }
        fwrite(&itens, sizeof(Produto), 1, tempArquivo); // Copia os itens que não foram removidos
    }

    fclose(arquivoCarrinho);
    fclose(tempArquivo);

    // Substitui o arquivo original pelo temporário
    remove("dados\\vendas\\carrinho.bin");
    rename("dados\\vendas\\carrinho_temp.bin", "dados\\vendas\\carrinho.bin");

    // Atualiza o estoque
    if(encontrado){
        FILE *arquivoEstoque = fopen("dados\\produtos\\produtos.bin", "rb+");
        if(arquivoEstoque != NULL){
            Produto cadastro;
            // Lê os cadastros até encontrar o ID.
            while(fread(&cadastro, sizeof(Produto), 1, arquivoEstoque)){
                if(cadastro.ID == produtoRemovido.ID){
                    // Posicionando o ponteiro no início do cadastro encontrado.
                    fseek(arquivoEstoque, -sizeof(Produto), SEEK_CUR);
                    // Adiciona a quantidade de volta ao estoque
                    cadastro.qtd_peso += produtoRemovido .qtd_peso;
                    // Escreva as alterações no arquivo.
                    fwrite(&cadastro, sizeof(Produto), 1, arquivoEstoque);
                    break; // Encerrando o loop se o ID for encontrado.
                }
            }
            fclose(arquivoEstoque); // Fecha o arquivo.
        }
    }

    if(encontrado){
        bold(1);
        printf(GREEN "\n\n                                         Item removido do carrinho com sucesso!\a\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
    }else{
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Item não encontrado no carrinho!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
    }
}
