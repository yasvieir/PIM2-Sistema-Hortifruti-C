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
            ListarCarrinhosGuardados();
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

    int count = 0; // Contador de produtos

    // Lê os dados do arquivo binário.
    while(fread(&produto, sizeof(produto), 1, arquivo) == 1){
        if(produto.ID != 0){ // Pula a impressão do usuário administrador.
            printf("\t");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(" [%i] %s ", produto.ID, produto.nome);
            SetConsoleTextAttribute(hConsole, saved_attributes);

            count++; // Incrementa o contador

            // Se já exibimos 5 produtos, pula uma linha
            if(count % 5 == 0){
                printf("\n\n\t"); // Pula uma linha extra
            }
        }
    }

    // Se o último grupo de produtos não tiver 5 itens, pula uma linha no final
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
        fclose(arquivoCarrinho); // Fecha o arquivo após limpar
    }else{
        printf("Erro ao criar o arquivo do carrinho!\n");
        return; // Sai da função se não conseguir criar o arquivo
    }

    // Verifica se o arquivo do carrinho existe
    arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "rb");
    if(arquivoCarrinho != NULL){
        fclose(arquivoCarrinho); // Fecha o arquivo se já existia
    }else{
        printf("Erro ao abrir o arquivo do carrinho!\n");
        return; // Sai da função se não conseguir abrir o arquivo
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
            return; // Sai da função se não conseguir abrir o arquivo
        }

        // Lê os dados do arquivo binário.
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf("\t %-10s | %-50s | %-15s | %-18s\n", "Item:", "Produto:", "Quantidade:", "Valor:");
        printf("\t------------|----------------------------------------------------|-----------------|-------------------\n"); // 119 caracteres

        ItemCarrinho itemAtual; // Estrutura para armazenar temporariamente os dados lidos
        float valorTotal = 0.0; // Variável para calcular o valor total do carrinho

        while (fread(&itemAtual, sizeof(ItemCarrinho), 1, arquivo) == 1){
            if(itemAtual.quantidade > 0){ // Verifica se a quantidade é válida
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
            case 3:
                telaLimpa();
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
                printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
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
    if(quantidade <= 0 || quantidade > produtoSelecionado.qtd_peso){
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
    ItemCarrinho itemCarrinho;

    // Gera um ID sequencial único para o novo item
    int novoId = 1;
    Carrinho *itemAtual = *carrinho;
    while(itemAtual != NULL){
        novoId = itemAtual->item.id + 1;
        itemAtual = itemAtual->proximo;
    }

    itemCarrinho.id = novoId; // Atribui o ID sequencial único
    itemCarrinho.produto = produtoSelecionado; // Copia o produto para o item
    itemCarrinho.quantidade = quantidade; // Atribui a quantidade comprada

    // Cria um novo nó para o item
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

    // Salva as alterações no arquivo de estoque
    FILE *arquivoEstoque = fopen("dados\\produtos\\produtos.bin", "rb+");
    if(arquivoEstoque != NULL){
        Produto cadastro;
        while(fread(&cadastro, sizeof(Produto), 1, arquivoEstoque)){
            if(cadastro.ID == produtoSelecionado.ID){
                // Posiciona o ponteiro no início do cadastro encontrado
                fseek(arquivoEstoque, -sizeof(Produto), SEEK_CUR);
                // Escreve as alterações no arquivo
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
        fclose(arquivoCarrinho); // Fecha o arquivo após a escrita
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

    // Lê os dados do arquivo binário.
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf("\t %-10s | %-50s | %-15s | %-18s\n", "Item:", "Produto:", "Quantidade:", "Valor:");
    printf("\t------------|----------------------------------------------------|-----------------|-------------------\n"); // 119 caracteres

    // Lê os itens do carrinho
    Carrinho *itemAtual = *carrinho; // Começa do início da lista
    while(itemAtual != NULL){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf("\t %-10i | %-50s | %-12.3f kg | R$ %-15.2f\n",
               itemAtual->item.id,
               itemAtual->item.produto.nome,
               itemAtual->item.quantidade,
               itemAtual->item.produto.preco * itemAtual->item.quantidade);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        itemAtual = itemAtual->proximo; // Avança para o próximo item
    }

    // Solicitar ao usuário o ID do item a ser removido
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf("\n\tDigite o ID do produto que deseja remover do carrinho: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    scanf("%i", &idItemRemover);
    fflush(stdin);
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Encontrar o item no carrinho
    Carrinho *itemAnterior = NULL;
    itemAtual = *carrinho; // Reinicia para o início da lista
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

    // Liberar a memória do item removido
    free(itemAtual); // Libera a memória do item que foi removido

    // Atualiza os IDs dos itens restantes
    int novoId = 1; // Começa a partir de 1
    itemAtual = *carrinho; // Reinicia para o início da lista
    while(itemAtual != NULL){
        itemAtual->item.id = novoId; // Atualiza o ID do item
        novoId++; // Incrementa o ID para o próximo item
        itemAtual = itemAtual->proximo; // Avança para o próximo item
    }

    // Salvar as alterações no arquivo do carrinho
    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinho.bin", "wb");
    if(arquivoCarrinho != NULL){
        itemAtual = *carrinho;
        while(itemAtual != NULL){
            fwrite(&itemAtual->item, sizeof(ItemCarrinho), 1, arquivoCarrinho);
            itemAtual = itemAtual->proximo;
        }
        fclose(arquivoCarrinho); // Fecha o arquivo após a escrita
    }
}

void SalvarCarrinho(Carrinho **carrinho){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*carrinho == NULL){
        bold(1);
        printf(RED "\n\n                                            [!] Carrinho vazio. Não há nada para salvar!\n\a");
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

    // Iterar sobre os itens do carrinho e salvá-los
    Carrinho *itemAtual = *carrinho; // Começa do início da lista
    while(itemAtual != NULL){
        CarrinhoGuardado carrinhoGuardado;
        carrinhoGuardado.id = idCarrinho; // Atribui o ID do carrinho guardado
        carrinhoGuardado.item = itemAtual->item; // Salva o item atual
        carrinhoGuardado.proximo = NULL; // Para simplificação, não estamos implementando uma lista encadeada aqui

        // Escrever no arquivo
        fwrite(&carrinhoGuardado, sizeof(CarrinhoGuardado), 1, arquivoCarrinho);
        itemAtual = itemAtual->proximo; // Avança para o próximo item
    }

    fclose(arquivoCarrinho);

    // Atualiza o último ID de carrinho no arquivo
    salvarUltimoID_Carrinho(ultimoID_Carrinho); // Salva o último ID de carrinho

    bold(1);
    printf(GREEN "\n\n                                        [!] Carrinho salvo com sucesso! ID do carrinho: %d\n\a\a", idCarrinho);
    bold(0);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    Sleep(800);
    telaLimpa();

    // Encerrar o carrinho
    free(*carrinho); // Liberar a memória do carrinho
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
        printf(RED "\n\n                                            [!] Não há itens no carrinho para cancelar!\n\a");
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

            // Salva as alterações no arquivo de estoque
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
        printf(                                           "  Escolha uma opção para continuar: ");

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
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();

}

void ListarCarrinhosGuardados(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salvar estado atual
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                     CARRINHOS                                                        \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    FILE *arquivoCarrinho = fopen("dados\\vendas\\carrinhos_guardados.bin", "rb");
    if(arquivoCarrinho == NULL){
        printf("Nenhum carrinho guardado encontrado.\n");
        return; // Sai da função se o arquivo não puder ser aberto
    }

    CarrinhoGuardado carrinhoGuardado; // Estrutura para armazenar temporariamente os dados lidos
    float valorTotal = 0.0; // Variável para calcular o valor total do carrinho

    while(fread(&carrinhoGuardado, sizeof(CarrinhoGuardado), 1, arquivoCarrinho) == 1){

        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                         %-61i", carrinhoGuardado.id);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        // Lê os dados do arquivo binário.
        printf("\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" %-10s | %-50s | %-15s | %-18s", "Item:", "Produto:", "Quantidade:", "Valor:");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf("------------|----------------------------------------------------|-----------------|-------------------"); // 119 caracteres
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\t");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" %-10i | %-50s | %-12.3f kg | R$ %-15.2f",
               carrinhoGuardado.item.id, // ID do item no carrinho
               carrinhoGuardado.item.produto.nome,
               carrinhoGuardado.item.quantidade,
               carrinhoGuardado.item.produto.preco * carrinhoGuardado.item.quantidade);
        valorTotal += carrinhoGuardado.item.produto.preco * carrinhoGuardado.item.quantidade; // Acumula o valor total
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");
        printf("\n\t\t\t\t\t\t");
        // Exibe o valor total do carrinho
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_GREEN);
        printf(" Valor total: R$ %.2f ", valorTotal);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");
    }
    fclose(arquivoCarrinho);

    telaPause();
}
