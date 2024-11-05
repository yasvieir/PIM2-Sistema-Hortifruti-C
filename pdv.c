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
        printf(                                           "    [3] - Hist�rico de Venda         ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [4] - Carrinho Guardado          ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "  Escolha uma op��o para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 0:
            telaLimpa();
            // Aqui voc� pode usar o cargo para redirecionar o usu�rio
            if(strcmp(usuarioLogado.cargo, "ADMINISTRADOR") == 0){
                telaMenuAdmin(); // Chama a tela do menu do administrador
            }else if(strcmp(usuarioLogado.cargo, "GERENTE") == 0){
                telaGerente(); // Chama a tela do gerente
            }else if(strcmp(usuarioLogado.cargo, "OPERADOR DE CAIXA") == 0 || strcmp(usuarioLogado.cargo, "ESTOQUISTA") == 0){
                telaFuncionario(); // Chama a tela do funcion�rio
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
            ListarCarrinhosGuardados();
            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!");
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

    //Abre arquivo para pesquisas bin�rias
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

    int count = 0; // Contador de produtos

    // L� os dados do arquivo bin�rio.
    while(fread(&produto, sizeof(produto), 1, arquivo) == 1){
        if(produto.ID != 0){ // Pula a impress�o do usu�rio administrador.
            printf("\t");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(" [%i] %s ", produto.ID, produto.nome);
            SetConsoleTextAttribute(hConsole, saved_attributes);

            count++; // Incrementa o contador

            // Se j� exibimos 5 produtos, pula uma linha
            if(count % 5 == 0){
                printf("\n\n\t"); // Pula uma linha extra
            }
        }
    }

    // Se o �ltimo grupo de produtos n�o tiver 5 itens, pula uma linha no final
    if(count % 5 != 0){
        printf("\n\n");
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

    // Inicializa o ponteiro do carrinho como NULL
    Carrinho *carrinho = NULL;

    // Limpa o arquivo do carrinho ao iniciar um novo
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "wb");
    if(arquivoCarrinho != NULL){
        fclose(arquivoCarrinho); // Fecha o arquivo ap�s limpar
    }else{
        printf("Erro ao criar o arquivo do carrinho!\n");
        return; // Sai da fun��o se n�o conseguir criar o arquivo
    }

    // Verifica se o arquivo do carrinho existe
    arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "rb");
    if(arquivoCarrinho != NULL){
        fclose(arquivoCarrinho); // Fecha o arquivo se j� existia
    }else{
        printf("Erro ao abrir o arquivo do carrinho!\n");
        return; // Sai da fun��o se n�o conseguir abrir o arquivo
    }

    int escolha;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                       CARRINHO                                                       \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        // Abre o arquivo para leitura
        FILE *arquivo = fopen("dados\\vendas\\carrinho.bin", "rb");
        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo do carrinho!\n");
            return; // Sai da fun��o se n�o conseguir abrir o arquivo
        }

        // L� os dados do arquivo bin�rio.
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("\t %-10s | %-50s | %-15s | %-18s\n", "Item:", "Produto:", "Quantidade:", "Valor:");

        ItemCarrinho itemAtual; // Estrutura para armazenar temporariamente os dados lidos
        float valorTotal = 0.0; // Vari�vel para calcular o valor total do carrinho

        while (fread(&itemAtual, sizeof(ItemCarrinho), 1, arquivo) == 1){
            if(itemAtual.quantidade > 0){ // Verifica se a quantidade � v�lida
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf("\t %-10i | %-50s | %-12.3f kg | R$ %-15.2f\n",
                       itemAtual.id, // ID do item no carrinho
                       itemAtual.produto.nome,
                       itemAtual.quantidade,
                       itemAtual.produto.preco * itemAtual.quantidade);
                valorTotal += itemAtual.produto.preco * itemAtual.quantidade; // Acumula o valor total
                SetConsoleTextAttribute(hConsole, saved_attributes);
            }
        }
        fclose(arquivo);

        // Exibe o valor total do carrinho
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
        printf("\n\t\t\t\t\t\tValor total: R$ %.2f\n", valorTotal);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        printf("\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "               OP��ES               ");
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
        printf(                                           "    [4] - Guardar Carrinho          ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [5] - Cancelar Carrinho         ");
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
        printf(                                           " Escolha uma op��o para continuar: ");

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
            case 3:
                telaLimpa();
                FinalizarCarrinho(&carrinho);
                break;
            case 4:
                telaLimpa();
                SalvarCarrinho(&carrinho);
                TelaPDV();
                break;
            case 5:
                telaLimpa();
                CancelarCarrinho(&carrinho);
                break;
            default:
                bold(1);
                printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();
}

void AdicionarItemCarrinho(Carrinho **carrinho) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int idProduto;
    float quantidade;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                   ADICIONAR PRODUTO                                                  \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\t");

    // Exibir lista de produtos
    ListaDeProdutos();

    printf("\t\t    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(" Digite o ID do produto que deseja adicionar ao carrinho: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    scanf("%i", &idProduto);
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Encontrar o produto no estoque
    Produto produtoSelecionado;
    FILE *arquivo = fopen("dados\\produtos\\produtos.bin", "rb");
    if(arquivo != NULL){
        while(fread(&produtoSelecionado, sizeof(Produto), 1, arquivo)){
            if(produtoSelecionado.ID == idProduto){
                fclose(arquivo); // Certifique-se de fechar o arquivo
                break; // Produto encontrado
            }
        }
    }

    if(produtoSelecionado.ID != idProduto){
        bold(1);
        printf(RED "\n\n                                            [!] produto n�o encontrado!\a");
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

    // Verifica se a quantidade est� dispon�vel no estoque
    if(quantidade <= 0 || quantidade > produtoSelecionado.qtd_peso){
        bold(1);
        printf(RED "\n\n                                  [!] Quantidade inv�lida ou maior que o dispon�vel em estoque!\a");
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
    ItemCarrinho itemCarrinho;

    // Gera um ID sequencial �nico para o novo item
    int novoId = 1;
    Carrinho *itemAtual = *carrinho;
    while(itemAtual != NULL){
        novoId = itemAtual->item.id + 1;
        itemAtual = itemAtual->proximo;
    }

    itemCarrinho.id = novoId; // Atribui o ID sequencial �nico
    itemCarrinho.produto = produtoSelecionado; // Copia o produto para o item
    itemCarrinho.quantidade = quantidade; // Atribui a quantidade comprada

    // Cria um novo n� para o item
    Carrinho *novoItem = (Carrinho *) malloc(sizeof(Carrinho));
    novoItem->item = itemCarrinho;
    novoItem->proximo = NULL;

    // Insere o novo item no carrinho
    if(*carrinho == NULL){
        *carrinho = novoItem;
    }else{
        Carrinho *ultimoItem = *carrinho;
        while (ultimoItem->proximo != NULL){
            ultimoItem = ultimoItem->proximo;
        }
        ultimoItem->proximo = novoItem;
    }

    // Atualiza o estoque
    produtoSelecionado.qtd_peso -= quantidade; // Subtrai a quantidade do estoque

    // Salva as altera��es no arquivo de estoque
    FILE *arquivoEstoque = fopen("dados\\produtos\\produtos.bin", "rb+");
    if(arquivoEstoque != NULL){
        Produto cadastro;
        while(fread(&cadastro, sizeof(Produto), 1, arquivoEstoque)){
            if(cadastro.ID == produtoSelecionado.ID){
                // Posiciona o ponteiro no in�cio do cadastro encontrado
                fseek(arquivoEstoque, -sizeof(Produto), SEEK_CUR);
                // Escreve as altera��es no arquivo
                fwrite(&produtoSelecionado, sizeof(Produto), 1, arquivoEstoque);
                break; // Encerrando o loop se o ID for encontrado
            }
        }
        fclose(arquivoEstoque); // Fecha o arquivo
    }

    // Salva o item no arquivo do carrinho
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "ab");
    if(arquivoCarrinho != NULL){
        fwrite(&itemCarrinho, sizeof(ItemCarrinho), 1, arquivoCarrinho);
        fclose(arquivoCarrinho); // Fecha o arquivo ap�s a escrita
    }
}

void RemoverItemCarrinho(Carrinho **carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int idItemRemover;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                    REMOVER PRODUTO                                                   \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    // L� os dados do arquivo bin�rio.
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("\t %-10s | %-50s | %-15s | %-18s\n", "Item:", "Produto:", "Quantidade:", "Valor:");
    printf("\n");

    // L� os itens do carrinho
    Carrinho *itemAtual = *carrinho; // Come�a do in�cio da lista
    while(itemAtual != NULL){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf("\t %-10i | %-50s | %-12.3f kg | R$ %-15.2f\n",
               itemAtual->item.id,
               itemAtual->item.produto.nome,
               itemAtual->item.quantidade,
               itemAtual->item.produto.preco * itemAtual->item.quantidade);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        itemAtual = itemAtual->proximo; // Avan�a para o pr�ximo item
    }

    // Solicitar ao usu�rio o ID do item a ser removido
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("\n\tDigite o ID do produto que deseja remover do carrinho: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    scanf("%i", &idItemRemover);
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Encontrar o item no carrinho
    Carrinho *itemAnterior = NULL;
    itemAtual = *carrinho; // Reinicia para o in�cio da lista
    while(itemAtual != NULL){
        if(itemAtual->item.id == idItemRemover){
            break; // Item encontrado
        }
        itemAnterior = itemAtual;
        itemAtual = itemAtual->proximo;
    }

    if(itemAtual == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Nenhum item encontrado!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    // Remover o item do carrinho
    if(itemAnterior == NULL){
        *carrinho = itemAtual->proximo; // Atualiza o ponteiro do carrinho
    }else{
        itemAnterior->proximo = itemAtual->proximo; // Atualiza o ponteiro do item anterior
    }

    // Liberar a mem�ria do item removido
    free(itemAtual); // Libera a mem�ria do item que foi removido

    // Atualiza os IDs dos itens restantes
    int novoId = 1; // Come�a a partir de 1
    itemAtual = *carrinho; // Reinicia para o in�cio da lista
    while(itemAtual != NULL){
        itemAtual->item.id = novoId; // Atualiza o ID do item
        novoId++; // Incrementa o ID para o pr�ximo item
        itemAtual = itemAtual->proximo; // Avan�a para o pr�ximo item
    }

    // Salvar as altera��es no arquivo do carrinho
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "wb");
    if(arquivoCarrinho != NULL){
        itemAtual = *carrinho;
        while(itemAtual != NULL){
            fwrite(&itemAtual->item, sizeof(ItemCarrinho), 1, arquivoCarrinho);
            itemAtual = itemAtual->proximo;
        }
        fclose(arquivoCarrinho); // Fecha o arquivo ap�s a escrita
    }
}

void FinalizarCarrinho(Carrinho **carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*carrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Carrinho vazio. N�o h� nada para finalizar!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        return;
    }

    // Gerar um novo ID para a venda
    int idVenda = gerarID_Venda();

    // Abrir o arquivo para adicionar a venda
    FILE *arquivoVenda = fopen("dados\\vendas\\vendas.bin", "ab");
    if(arquivoVenda == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Erro ao abrir o arquivo para salvar a venda!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        return;
    }

    // Iterar sobre os itens do carrinho e salv�-los
    Carrinho *itemAtual = *carrinho; // Come�a do in�cio da lista
    Venda venda;
    venda.ID = idVenda; // Atribui o ID da venda
    venda.proximo = NULL; // Inicializa o pr�ximo como NULL
    venda.valor_total = 0.0; // Inicializa o valor total da venda

    while(itemAtual != NULL){
        // Salva cada item na venda
        venda.item = itemAtual->item; // Salva o item atual
        fwrite(&venda, sizeof(Venda), 1, arquivoVenda); // Escreve no arquivo
        venda.valor_total += itemAtual->item.produto.preco * itemAtual->item.quantidade; // Acumula o valor total
        itemAtual = itemAtual->proximo; // Avan�a para o pr�ximo item
    }

    // Salvar o valor total da venda
    fseek(arquivoVenda, -sizeof(Venda), SEEK_CUR); // Volta para o in�cio do �ltimo registro
    fwrite(&venda, sizeof(Venda), 1, arquivoVenda); // Atualiza o valor total da venda
    fclose(arquivoVenda);

    // Atualiza o �ltimo ID de venda no arquivo
    salvarUltimoID_Venda(idVenda); // Salva o �ltimo ID de venda

    bold(1);
    printf(GREEN "\n\n                                   [!] Carrinho finalizado com sucesso! ID da venda: %d\n\a\a", idVenda);
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    Sleep(800);
    telaLimpa();

    // Encerrar o carrinho
    TelaVendaAtual(carrinho); // Passa o carrinho para a tela de venda atual
    free(*carrinho); // Liberar a mem�ria do carrinho
    *carrinho = NULL; // Definir o ponteiro como NULL
}

void MostrarCarrinho(Carrinho **carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // Exibir os itens do carrinho
    printf("\n\t");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(" %-10s | %-50s | %-15s | %-18s", "Item:", "Produto:", "Quantidade:", "Valor:");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    Carrinho *itemAtual = *carrinho; // Come�a do in�cio da lista
    float valorTotal = 0.0; // Valor total sem descontos
    float valorDescontos = 0.0; // Valor total dos descontos

    while(itemAtual != NULL){
        printf("\n\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        float valorItem = itemAtual->item.produto.preco * itemAtual->item.quantidade;
        printf(" %-10i | %-50s | %-12.3f kg | R$ %-15.2f",
               itemAtual->item.id, // ID do item no carrinho
               itemAtual->item.produto.nome,
               itemAtual->item.quantidade,
               valorItem);
        valorTotal += valorItem; // Acumula o valor total
        SetConsoleTextAttribute(hConsole, saved_attributes);
        itemAtual = itemAtual->proximo; // Avan�a para o pr�ximo item
    }
    printf("\n");

    // Exibir os descontos aplicados
    Desconto *descontoAtual = (*carrinho)->descontos;
    while(descontoAtual != NULL){
        printf("\n\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" %-10s | %-65s | R$ %-15.2f", "Desconto:", descontoAtual->tipo, descontoAtual->valor);
        valorDescontos += descontoAtual->valor; // Acumula o valor dos descontos
        SetConsoleTextAttribute(hConsole, saved_attributes);
        descontoAtual = descontoAtual->proximo; // Avan�a para o pr�ximo desconto
    }

    // Exibir o valor total do carrinho considerando os descontos
    float valorTotalFinal = valorTotal - valorDescontos; // Calcula o total final
    printf("\n\t");
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
    printf(" %-81s | R$ %-15.2f", "Total:", valorTotalFinal);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");
}

void TelaVendaAtual(Carrinho **carrinho){

    system("title Finalizar Venda");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                    FINALIZAR VENDA                                                   \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");

        // Exibir os itens do carrinho
        MostrarCarrinho(carrinho);

        printf("\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "               OP��ES               ");
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
        printf(                                           "    [1] - Metodo Pagamento          ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Aplicar Desconto          ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Finalizar Venda           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [4] - Cancelar Venda            ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           " Escolha uma op��o para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }

    }while(escolha != 4);
    telaLimpa();
}

void AplicarDesconto(Carrinho **carrinho){

    system("title Aplicar Desconto");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*carrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Carrinho vazio. N�o h� nada para aplicar desconto!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        return;
    }

    int tipoDesconto;
    float valorDesconto;

    do{
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                    APLICAR DESCONTO                                                  \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf("                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");

        Desconto *descontoAtual = (*carrinho)->descontos;
        float totalDescontos = 0.0;

        while (descontoAtual != NULL) {
            printf("\n\t");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(" %-10s | %-65s | R$ %-15.2f", "Desconto:", descontoAtual->tipo, descontoAtual->valor);
            totalDescontos += descontoAtual->valor; // Acumula o valor dos descontos
            SetConsoleTextAttribute(hConsole, saved_attributes);
            descontoAtual = descontoAtual->proximo; // Avan�a para o pr�ximo desconto
        }

        // Calcular e exibir o valor total do carrinho
        float valorTotalCarrinho = (*carrinho)->valor_total; // Valor total original do carrinho
        float valorTotalFinal = valorTotalCarrinho - totalDescontos; // Calcula o total final

        printf("\n\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
        printf(" %-81s | R$ %-15.2f", "Valor total do carrinho:", valorTotalCarrinho);
        printf("\n\t");
        printf(" %-81s | R$ %-15.2f", "Valor total ap�s descontos:", valorTotalFinal);

        printf("\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "               OP��ES               ");
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
        printf(                                           "    [0] - Voltar                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [1] - Pre�o Errado              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Desconto do Gerente       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Cancelar                  ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           " Escolha uma op��o para continuar: ");

        scanf("%i", &tipoDesconto);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(tipoDesconto){
        case 0:
            telaLimpa();
            TelaVendaAtual(carrinho);
            break;
        case 1:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                    APLICAR DESCONTO                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            // Solicitar ao usu�rio o ID do item a ser removido
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("\n\tDigite o valor do desconto: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" R$ ");
            scanf("%f", &valorDesconto);
            fflush(stdin);

            // Verificar se o valor do desconto � v�lido
            if (valorDesconto < 0) {
                bold(1);
                printf(RED "\n\n                                            [!] Valor do desconto inv�lido!\n\a");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                return;
            }

            // Atualiza o valor total do carrinho
            (*carrinho)->valor_total -= valorDesconto;

            // Criar um novo desconto
            Desconto *novoDesconto1 = (Desconto *)malloc(sizeof(Desconto));
            novoDesconto1->valor = valorDesconto;
            strcpy(novoDesconto1->tipo, "Pre�o Errado");
            novoDesconto1->proximo = (*carrinho)->descontos; // Adiciona no in�cio da lista
            (*carrinho)->descontos = novoDesconto1; // Atualiza o ponteiro do carrinho

            // Exibir confirma��o
            bold(1);
            printf(GREEN "\n\n                                        [!] Desconto de Pre�o Errado aplicado com sucesso!\n\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            TelaVendaAtual(carrinho);
            break;
        case 2:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                    APLICAR DESCONTO                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            // Solicitar ao usu�rio o ID do item a ser removido
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf("\n\tDigite o valor do desconto: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" R$ ");
            scanf("%f", &valorDesconto);
            fflush(stdin);

            // Verificar se o valor do desconto � v�lido
            if (valorDesconto < 0) {
                bold(1);
                printf(RED "\n\n                                            [!] Valor do desconto inv�lido!\n\a");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                return;
            }

            // Atualiza o valor total do carrinho
            (*carrinho)->valor_total -= valorDesconto;

            // Criar um novo desconto
            Desconto *novoDesconto2 = (Desconto *)malloc(sizeof(Desconto));
            novoDesconto2->valor = valorDesconto;
            strcpy(novoDesconto2->tipo, "Desconto do Gerente");
            novoDesconto2->proximo = (*carrinho)->descontos; // Adiciona no in�cio da lista
            (*carrinho)->descontos = novoDesconto2; // Atualiza o ponteiro do carrinho

            // Exibir confirma��o
            bold(1);
            printf(GREEN "\n\n                                        [!] Desconto do Gerente aplicado com sucesso!\n\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            TelaVendaAtual(carrinho);
            break;
        case 4:
            // Cancelar todos os descontos
            while ((*carrinho)->descontos != NULL) {
                Desconto *temp = (*carrinho)->descontos;
                (*carrinho)->descontos = (*carrinho)->descontos->proximo; // Avan�a para o pr�ximo desconto
                free(temp); // Libera a mem�ria do desconto
            }
            // Restaura o valor total do carrinho
            (*carrinho)->valor_total += totalDescontos; // Adiciona todos os descontos de volta ao total
            bold(1);
            printf(GREEN "\n\n                                        [!] Todos os descontos foram cancelados com sucesso!\n\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            TelaVendaAtual(carrinho);
            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }

    }while(tipoDesconto != 0);
    telaLimpa();
}

void SalvarCarrinho(Carrinho **carrinho) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*carrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Carrinho vazio. N�o h� nada para salvar!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    // Gerar um novo ID para o carrinho
    int idCarrinho = gerarID_Carrinho();

    // Abrir o arquivo para adicionar o carrinho
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinhos_guardados.bin", "ab");
    if(arquivoCarrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Erro ao abrir o arquivo para salvar o carrinho!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        return;
    }

    // Iterar sobre os itens do carrinho e salv�-los
    Carrinho *itemAtual = *carrinho; // Come�a do in�cio da lista
    CarrinhoGuardado carrinhoGuardado;
    carrinhoGuardado.id = idCarrinho; // Atribui o ID do carrinho guardado
    carrinhoGuardado.proximo = NULL; // Inicializa o pr�ximo como NULL

    while(itemAtual != NULL){
        // Salva cada item no carrinho guardado
        carrinhoGuardado.item = itemAtual->item; // Salva o item atual
        fwrite(&carrinhoGuardado, sizeof(CarrinhoGuardado), 1, arquivoCarrinho); // Escreve no arquivo
        itemAtual = itemAtual->proximo; // Avan�a para o pr�ximo item
    }

    fclose(arquivoCarrinho);

    // Atualiza o �ltimo ID de carrinho no arquivo
    salvarUltimoID_Carrinho(idCarrinho); // Salva o �ltimo ID de carrinho

    bold(1);
    printf(GREEN "\n\n                                        [!] Carrinho salvo com sucesso! ID do carrinho: %d\n\a\a", idCarrinho);
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    Sleep(800);
    telaLimpa();

    // Encerrar o carrinho
    free(*carrinho); // Liberar a mem�ria do carrinho
    *carrinho = NULL; // Definir o ponteiro como NULL
}

void CancelarCarrinho(Carrinho **carrinho){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*carrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] N�o h� itens no carrinho para cancelar!\n\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        TelaPDV();
    }

    // Iterar pelos itens do carrinho e devolver ao estoque
    Carrinho *itemAtual = *carrinho;
    while(itemAtual != NULL){
        // Atualiza o estoque
        Produto produtoEstoque = buscarProdutoPorID(itemAtual->item.produto.ID);
        if(produtoEstoque.ID != -1){
            produtoEstoque.qtd_peso += itemAtual->item.quantidade; // Devolve a quantidade ao estoque

            // Salva as altera��es no arquivo de estoque
            FILE *arquivoEstoque = fopen("dados\\produtos\\produtos.bin", "rb+");
            if(arquivoEstoque != NULL){
                fseek(arquivoEstoque, -sizeof(Produto), SEEK_CUR);
                fwrite(&produtoEstoque, sizeof(Produto), 1, arquivoEstoque);
                fclose(arquivoEstoque);
            }
        }
        itemAtual = itemAtual->proximo;
    }

    // Limpa o carrinho
    free(*carrinho);
    *carrinho = NULL;

    bold(1);
    printf(GREEN "\n\n                                            [!] Carrinho cancelado e itens devolvidos ao estoque!\n\a\a");
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    Sleep(800);
    telaLimpa();
    TelaPDV();
}

void TelaCarrinhos(){

    system("title Carrinhos");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
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
        printf(                                           "    [1] - Listar Carrinhos           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Buscar Carrinho            ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "  Escolha uma op��o para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 0:
            telaLimpa();
            TelaPDV();
            break;
        case 1:
            telaLimpa();
            ListarCarrinhosGuardados();
            break;
        case 2:
            telaLimpa();

            break;
        default :
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();

}

void ListarCarrinhosGuardados(){

    system("title Lista de Carrinhos");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                     CARRINHOS                                                        \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinhos_guardados.bin", "rb");
    if(arquivoCarrinho == NULL){
        bold(1);
        printf(RED "\n\n\t\t\t\t\t [!] Nenhum carrinho guardado encontrado!");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaPause();
        return; // Sai da fun��o se o arquivo n�o puder ser aberto
    }

    CarrinhoGuardado carrinhoGuardado; // Estrutura para armazenar temporariamente os dados lidos
    int idCarrinhoAtual = -1; // ID do carrinho atual
    float valorTotal = 0.0;

    // Loop para ler m�ltiplos carrinhos
    while(fread(&carrinhoGuardado, sizeof(CarrinhoGuardado), 1, arquivoCarrinho) == 1){
        // Exibir o carrinho, ignorando IDs inv�lidos
        if(carrinhoGuardado.id != 0){ // Ajuste aqui se voc� deseja ignorar IDs espec�ficos
            // Verifica se � um novo carrinho
            if(carrinhoGuardado.id != idCarrinhoAtual){
                // Exibe o ID do carrinho
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf("                                                       ID: %-59i", carrinhoGuardado.id);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n\n\t");

                // Reinicia o valor total para cada carrinho
                valorTotal = 0.0;

                // Exibe o cabe�alho dos itens do carrinho
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(" %-10s | %-50s | %-15s | %-18s", "Item:", "Produto:", "Quantidade:", "Valor:");
                SetConsoleTextAttribute(hConsole, saved_attributes);

                idCarrinhoAtual = carrinhoGuardado.id; // Atualiza o ID do carrinho atual
            }

            // Exibir o item do carrinho guardado
            printf("\n\t");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(" %-10i | %-50s | %-12.3f kg | R$ %-15.2f",
                   carrinhoGuardado.item.id, // ID do item no carrinho
                   carrinhoGuardado.item.produto.nome,
                   carrinhoGuardado.item.quantidade,
                   carrinhoGuardado.item.produto.preco * carrinhoGuardado.item.quantidade);
            valorTotal += carrinhoGuardado.item.produto.preco * carrinhoGuardado.item.quantidade; // Acumula o valor total
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
    }

    // Ap�s o loop, exibe o valor total do �ltimo carrinho
    if(idCarrinhoAtual != -1){
        printf("\n\n\t\t\t\t\t\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
        printf(" Valor total: R$ %.2f ", valorTotal); // Exibe o total do �ltimo carrinho
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");
    }

    // Fecha o arquivo.
    fclose(arquivoCarrinho);

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                             PRESSIONE ENTER PARA VOLTAR                                              ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("                                                                                                                      ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    telaPause();
    return;
}
