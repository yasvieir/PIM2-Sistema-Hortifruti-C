//os arquivos .h são para criar as definições e as prototipagens de funções
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//Início de dados para cadastro de funcionários;
#define TAM_user 13
#define TAM_nome 101
#define TAM_comp 11
#define TAM_cep 10
#define TAM_cpf 15
#define TAM_rg 13
#define TAM_cargo 18
#define TAM_nasc 11

typedef struct login_pessoa{
    char usuario[TAM_user],
         senha[TAM_user];
}Login;

typedef struct endereco_pessoa{
    char rua[TAM_nome],
         bairro[TAM_nome],
         cep[TAM_cep],
         complemento[TAM_comp],
         num_resid[TAM_comp];
}Endereco;

typedef struct documentos_pessoa{
    char cpf[TAM_cpf],
         rg[TAM_rg];
}Documentos;

typedef struct dados_pessoa{
    int ID;
    char nome[TAM_nome];
    Login login;
    char email[TAM_nome],
         cargo[TAM_cargo],
         nasc[TAM_nasc];
    Documentos documentos;
    Endereco endereco;
}Pessoa;

int ultimoID = 0; // Variável para armazenar o último ID gerado

// Inicio de dados para cadastro de produtos
#define TAM_nomeProduto 51

typedef struct dados_produto{
    int ID;
    char nome[TAM_nomeProduto];
    float preco,
          qtd_peso;
}Produto;

int ultimoID_Produto = 0;

typedef struct dados_venda{
    int ID;
    ItemCarrinho item; // Item do carrinho
    struct dados_carrinho_guardado *proximo; // Ponteiro para o próximo item
    float valor_total;
}Venda;

int ultimoID_Venda = 0;

// Estrutura para armazenar itens no carrinho
typedef struct item_carrinho {
    int id; // ID sequencial do item no carrinho
    Produto produto; // Produto associado ao item
    float quantidade; // Quantidade comprada
} ItemCarrinho;

// Estrutura para o carrinho de compras
typedef struct dados_carrinho {
    int ID; // ID do carrinho
    ItemCarrinho item; // Item atual no carrinho
    struct dados_carrinho *proximo; // Ponteiro para o próximo item no carrinho
    int totalProdutos; // Total de produtos no carrinho
    float valor_total; // Valor total da compra
} Carrinho;

typedef struct {
    int id; // ID do carrinho guardado
    ItemCarrinho item; // Item do carrinho
    struct dados_carrinho_guardado *proximo; // Ponteiro para o próximo item
} CarrinhoGuardado;

int ultimoID_Carrinho = 0;

//Fim

#endif // STRUCTS_H_INCLUDED
