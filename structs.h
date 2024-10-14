//os arquivos .h são para criar as definições e as prototipagens de funções
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define TAM_user 13
#define TAM_nome 101
#define TAM_comp 11
#define TAM_cep 10
#define TAM_cpf 15
#define TAM_rg 13

typedef struct login_pessoa{
    char usuario[TAM_user],
         senha[TAM_user];
}Login;

typedef struct endereco_pessoa{
    char rua[TAM_nome],
         bairro[TAM_nome],
         cep[TAM_cep],
         complemento[TAM_comp];
    int num_resid;
}Endereco;

typedef struct dataNasc_pessoa{
    int dia, mes, ano;
}DataNasc;

typedef struct documentos_pessoa{
    char cpf[TAM_cpf],
         rg[TAM_rg];
}Documentos;

typedef struct dados_pessoa{
    int ID;
    char nome[TAM_nome];
    Login login;
    DataNasc datanasc;
    Documentos documentos;
    Endereco endereco;
}Pessoa;

#endif // STRUCTS_H_INCLUDED
