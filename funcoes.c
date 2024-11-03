#include "funcoes.h"

Pessoa usuarioLogado; // Definindo uma estrutura global para armazenar os dados do usuário logado.

int verificaLogin(char *ent_usuario, char *ent_senha, char *cargo){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    if(arquivo == NULL){
        // Se o arquivo não existe, cria um novo e adiciona o cadastro do Administrador.
        arquivo = fopen("dados\\funcionarios\\cadastros.bin", "wb");
        if(arquivo == NULL){
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
            bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return 0; // Retorna 0 em caso de erro
        }
        // Cria cadastro do Administrador.
        pessoa.ID = 0;
        strcpy(pessoa.nome, "Administrador\0");
        strcpy(pessoa.login.usuario, "admin\0");
        strcpy(pessoa.login.senha, "admin123\0");
        strcpy(pessoa.cargo, "ADMINISTRADOR\0");

        // Escreve cadastro Administrador no arquivo.
        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
        fclose(arquivo);
    }

    // Reabre o arquivo para leitura
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    while (fread(&pessoa, sizeof(Pessoa), 1, arquivo)) {
        if (strcmp(pessoa.login.usuario, ent_usuario) == 0 && strcmp(pessoa.login.senha, ent_senha) == 0) {
            fclose(arquivo);
            strcpy(cargo, pessoa.cargo); // Armazena o cargo do usuário
            // Pega informações do usuário
            usuarioLogado = pessoa; // Armazena os dados do usuário logado
            return 1; // Usuário encontrado.
        }
    }
    fclose(arquivo);
    return 0; // Usuário não encontrado.
}

void mascSenha(char ent_senha, char *senha[TAM_user]){

    char senha_usuario[TAM_user] = "0";
    int pos = 0;
    int comparador;

    do{
        ent_senha = getch();

        if(isprint(ent_senha)){
            senha_usuario[pos++] = ent_senha;
            printf("%c", '*');
        }
        else if(ent_senha == 8 && pos){
            senha_usuario[pos--] = '\0';
            printf("%s", "\b \b");
        }
        strcpy(senha, senha_usuario);
    }while(ent_senha != 13);
}

int lerUltimoID(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\funcionarios\\ultimo_id.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID, sizeof(int), 1, arquivo); // Lê o último ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo não existir, inicializa ultimoID com 0
        ultimoID = 0;
    }

    return ultimoID;
}

int salvarUltimoID(int ultimoID){

    FILE *arquivo;

    //Abre um arquivo binário (cria de não existe).
    arquivo = fopen("dados\\funcionarios\\ultimo_id.bin", "wb");
    if(arquivo != NULL){
        //Escreve o último ID no arquivo.
        fwrite(&ultimoID, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID(){

    static int ultimoID; // Remove a inicialização com lerUltimoID().

    //Verificando se é a primeira vez que a função é chamada.
    if(ultimoID == 0){
        // Lê o último ID do arquivo.
        ultimoID = lerUltimoID();
    }
    return ++ultimoID; // Retorna o próximo ID incremental.
}

int usuarioExiste(char *usuario){

    FILE *arquivo;

    //Abre um arquivo binário (cria de não existe).
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");

    if(arquivo == NULL){
        return 0; //Arquivo não existe, ou não pode ser aberto;
    }

    Pessoa pessoa;
    while(fread(&pessoa, sizeof(Pessoa), 1, arquivo)){
        if(pessoa.ID != 1 && strcmp(pessoa.login.usuario, usuario) == 0){
            fclose(arquivo);
            return 1; //Usuário encontrado.
        }
    }
    fclose(arquivo);
    return 0;
}

void verificaSenhas(char ent_senha1[], char ent_senha2[], int *comparador){

    int compSenha;

    compSenha = strcmp(ent_senha1, ent_senha2);

    if(compSenha == 0){
        *comparador = 0;
    }else{
        *comparador = 1;
    }
}

Pessoa buscarCadastroPorID(int id){
    FILE *arquivo;
    Pessoa cadastro;
    int encontrado = 0;

    //Abre o arquivo para leitura.
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return cadastro; //Retorna um cadastro vazio em caso de erro.
    }

    //Lê os cadastros até encontrar o ID
    while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
        if (cadastro.ID == id) { //Compara com o ID de entrada, não Pessoa.ID.
            encontrado = 1;
            break; //Encerra o loop se o ID for encontrado.
        }
    }

    fclose(arquivo); //Fecha o arquivo.

    if(!encontrado){
        cadastro.ID = -1; //Indica que não foi encontrado.
    }

    return cadastro; //Retorna o cadastro encontrado ou vazio.
}

int lerUltimoID_Produto(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\produtos\\ultimo_id_produto.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID_Produto, sizeof(int), 1, arquivo); // Lê último ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo não existir, inicializa ultimoID_Produto com 0
        ultimoID_Produto = 0;
    }

    return ultimoID_Produto;
}

int salvarUltimoID_Produto(int ultimoID_Produto){

    FILE *arquivo;

    //Abre um arquivo binário (cria se não existir)
    arquivo = fopen("dados\\produtos\\ultimo_id_produto.bin", "wb");
    if(arquivo != NULL){
        // Escreve o último ID no arquivo
        fwrite(&ultimoID_Produto, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID_Produto(){

    static int ultimoID_Produto; //Remove a inicialização com lerUltimoID_Produto()

    // Verifica se é a primeira vez que a função é chamada
    if(ultimoID_Produto == 0){
        // Lê o último ID do arquivo
        ultimoID_Produto = lerUltimoID_Produto();
    }

    return ++ultimoID_Produto; //Retorna o próximo ID incremental.
}

Produto buscarProdutoPorID(int id){
    FILE *arquivo;
    Produto produto;
    int encontrado = 0;

    //Abre o arquivo para leitura.
    arquivo = fopen("dados\\produtos\\produtos.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return produto; //Retorna um produto vazio em caso de erro.
    }

    //Lê os cadastros até encontrar o ID
    while(fread(&produto, sizeof(Produto), 1, arquivo)){
        if (produto.ID == id) { //Compara com o ID de entrada, não produto.ID.
            encontrado = 1;
            break; //Encerra o loop se o ID for encontrado.
        }
    }

    fclose(arquivo); //Fecha o arquivo.

    if(!encontrado){
        produto.ID = -1; //Indica que não foi encontrado.
    }

    return produto; //Retorna o produto encontrado ou vazio.
}

int lerUltimoID_Venda(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\vendas\\ultimo_id_venda.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID_Venda, sizeof(int), 1, arquivo); // Lê último ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo não existir, inicializa ultimoID_Venda com 0
        ultimoID_Venda = 0;
    }
    return ultimoID_Venda;
}

int salvarUltimoID_Venda(int ultimoID_Venda){

    FILE *arquivo;

    //Abre um arquivo binário (cria se não existir)
    arquivo = fopen("dados\\vendas\\ultimo_id_vendas.bin", "wb");
    if(arquivo != NULL){
        // Escreve o último ID no arquivo
        fwrite(&ultimoID_Venda, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID_Venda(){

    static int ultimoID_Venda; //Remove a inicialização com lerUltimoID_Venda()

    // Verifica se é a primeira vez que a função é chamada
    if(ultimoID_Venda == 0){
        // Lê o último ID do arquivo
        ultimoID_Venda = lerUltimoID_Venda();
    }
    return ++ultimoID_Venda; //Retorna o próximo ID incremental.
}

Venda buscarVendaPorID(int id){
    FILE *arquivo;
    Venda venda;
    int encontrado = 0;

    //Abre o arquivo para leitura.
    arquivo = fopen("dados\\vendas\\vendas.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return venda; //Retorna uma venda vazia em caso de erro.
    }

    //Lê os cadastros até encontrar o ID
    while(fread(&venda, sizeof(Venda), 1, arquivo)){
        if (venda.ID == id) { //Compara com o ID de entrada, não venda.ID.
            encontrado = 1;
            break; //Encerra o loop se o ID for encontrado.
        }
    }

    fclose(arquivo); //Fecha o arquivo.

    if(!encontrado){
        venda.ID = -1; //Indica que não foi encontrado.
    }

    return venda; //Retorna a venda encontrada ou vazia.
}

int lerUltimoID_Carrinho(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\vendas\\ultimo_id_carrinho.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID_Carrinho, sizeof(int), 1, arquivo); // Lê último ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo não existir, inicializa ultimoID_Carrinho com 0
        ultimoID_Carrinho = 0;
    }
    return ultimoID_Carrinho;
}

int salvarUltimoID_Carrinho(int ultimoID_Carrinho){

    FILE *arquivo;

    //Abre um arquivo binário (cria se não existir)
    arquivo = fopen("dados\\vendas\\ultimo_id_vendas.bin", "wb");
    if(arquivo != NULL){
        // Escreve o último ID no arquivo
        fwrite(&ultimoID_Carrinho, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID_Carrinho(){

    static int ultimoID_Carrinho; //Remove a inicialização com lerUltimoID_Carrinho()

    // Verifica se é a primeira vez que a função é chamada
    if(ultimoID_Carrinho == 0){
        // Lê o último ID do arquivo
        ultimoID_Carrinho = lerUltimoID_Carrinho();
    }
    return ++ultimoID_Carrinho; // Retorna o próximo ID incremental
}

CarrinhoGuardado buscarCarrinhoPorID(int id){
    FILE *arquivo;
    CarrinhoGuardado carrinho;
    int encontrado = 0;

    //Abre o arquivo para leitura.
    arquivo = fopen("dados\\vendas\\carrinho.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return carrinho; //Retorna um carrinho vazio em caso de erro.
    }

    //Lê os cadastros até encontrar o ID
    while(fread(&carrinho, sizeof(CarrinhoGuardado), 1, arquivo)){
        if(carrinho.ID == id){ //Compara com o ID de entrada, não carrinho.ID.
            encontrado = 1;
            break; //Encerra o loop se o ID for encontrado.
        }
    }

    fclose(arquivo); //Fecha o arquivo.

    if(!encontrado){
        carrinho.ID = -1; //Indica que não foi encontrado.
    }

    return carrinho; //Retorna o carrinho encontrado ou vazio.
}
