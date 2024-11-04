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
        printf(                                           "    [1] - Novo Cadastro              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Listar Cadastros           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Buscar e Editar Cadastro   ");
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
            NovoCadastro();
            break;
        case 2:
            telaLimpa();
            ListarCadastros();
            break;
        case 3:
            telaLimpa();
            BuscaCadastro();
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

void ListarCadastro(Pessoa pessoa){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: %-59i", pessoa.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n                                               ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
    printf(                                                 "   DADOS DO USUÁRIO   ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n                                           ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                              " Nome: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.nome);
    printf("                                        ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                           " Usuário: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.login.usuario);
    printf("                                          ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                             " Senha: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.login.senha);
    printf("                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " E-mail: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.email);
    printf(" ");
    printf(  "                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                             " Cargo: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.cargo);
    printf("\n                                                   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
    printf(                                                      "   DOCUMENTOS   ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                " Data de Nascimento: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.nasc);
    printf("                                            ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                               " CPF: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.documentos.cpf);
    printf("                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                                " RG: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.documentos.rg);
    printf("\n                                                    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
    printf(                                                       "   ENDEREÇO   ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n                                     ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                        " Logradouro: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.rua);
    printf("                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " Número: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.num_resid);
    printf("                                         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                            " Bairro: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                      " %s\n", pessoa.endereco.bairro);
    printf("                                            ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                               " CEP: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                     " %s\n", pessoa.endereco.cep);
    printf("                                    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(                                       " Complemento: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(                                                     " %s\n", pessoa.endereco.complemento);

}

void NovoCadastro(){

    system("title Novo Cadastro");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo;

    //Verifica se o arquivo existe.
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    if(arquivo == NULL){
        //Se o arquivo não existe, cria um novo e adiciona o cadastro do Administrador.
        arquivo = fopen("dados\\funcionarios\\cadastros.bin", "wb");
        if(arquivo == NULL){
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!"); bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return;
        }
        //Cria cadastro do Administrador.
        pessoa.ID = 0;
        strcpy(pessoa.nome, "Administrador\0");
        strcpy(pessoa.login.usuario, "admin\0");
        strcpy(pessoa.login.senha, "admin123\0");
        strcpy(pessoa.cargo, "ADMINISTRADOR\0");

        //Escreve cadastro Administrador no arquivo.
        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);

        fclose(arquivo);
    }else{
        fclose(arquivo);
    }

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: ");

    // Gera um novo ID incremental.
    pessoa.ID = gerarID();
    //Mostra ID atual.
    printf(                                                              " %-59i", pessoa.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n");
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Campo de inserção - Nome:
    while(1){
        printf("\n                                           ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                              " Nome: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nome) == 0){
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de Inserção - Usuário:
    while(1){
        printf("\n                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           " Usuário: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
        pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        while(usuarioExiste(pessoa.login.usuario)){
            bold(1);
            printf(RED "\n\n                                 [!] O Usuário já existe, por favor escolha outro!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);

        }

        if(strlen(pessoa.login.usuario) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo usuário não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de insersão - Senha:
    char ent_senha1, senha1[TAM_user],
         ent_senha2, senha2[TAM_user];
    while(1){
        printf("\n                                          ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                             " Senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha1 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha1[i] = '\0';
        }

        mascSenha(ent_senha1, &senha1);
        fflush(stdin);

        if(strlen(senha1) < 8){
            bold(1);
            printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de insersão - Confirmação de Senha:
    while(1){
        printf("\n                             ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                " Confirme sua senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha2 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha2[i] = '\0';
        }

        mascSenha(ent_senha2, &senha2);
        fflush(stdin);

        if(strlen(senha2) < 8){
            bold(1);
            printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Senha: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", senha1);
        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    int comparador;
    //Verifica se senhas são iguais:
    verificaSenhas(senha1, senha2, &comparador);
    if(comparador == 1){
        comparador = 0;
        bold(1);
        printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(1000);
        telaLimpa();
        do{
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usuário: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

            //Campo de insersão - Senha:
            while(1){
                printf("\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha1 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha1[i] = '\0';
                }

                mascSenha(ent_senha1, &senha1);
                fflush(stdin);

                if(strlen(senha1) < 8){
                    bold(1);
                    printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);

                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de insersão - Confirmação de Senha:
            while(1){
                printf("\n                             ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                " Confirme sua senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha2 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha2[i] = '\0';
                }

                mascSenha(ent_senha2, &senha2);
                fflush(stdin);

                if(strlen(senha2) < 8){
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);
                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Verifica se senhas são iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                telaLimpa();
            }
        }while(comparador == 1);
    }else{
        senha2[strcspn(senha2, "\n")] = 0;
        strcpy(pessoa.login.senha, senha2);
    }
    //Campo de Inserção - E-mail:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " E-mail: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.email, sizeof(pessoa.email), stdin);
        pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.email) == 0){
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] O campo e-mail não pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usuário: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);
                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                    printf("\n                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                " Confirme sua senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha2);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    telaLimpa();
    //Campo de seleção - Cargo:
    int escolhaCargo;
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: %-59i", pessoa.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                        CARGO:                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                 ");
    while(1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(                                  " Digite o número correspondente ao cargo escolhido: ");
        scanf("%i", &escolhaCargo);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        fflush(stdin);

        switch(escolhaCargo){
        case 1:
            strcpy(pessoa.cargo, "GERENTE\0");
            break;
        case 2:
            strcpy(pessoa.cargo, "OPERADOR DE CAIXA\0");
            break;
        case 3:
            strcpy(pessoa.cargo, "ESTOQUISTA\0");
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t [!] Opção inválida! Tente novamente.\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                        CARGO:                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "\n                              ");
        }
        telaLimpa();
        if(escolhaCargo >= 1 && escolhaCargo <= 4){
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                        CARGO:                                                        \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            break; //Sai do loop se a opção for válida
        }
    }
    //Campo de inserção - Data de nascimento:
    while(1){
        printf(  "\n                 ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                        " Data de Nascimento(00/00/0000): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.nasc, sizeof(pessoa.nasc), stdin);
        pessoa.nasc[strcspn(pessoa.nasc, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nasc) == 0){
            bold(1);
            printf(RED "\n\n                                 [!] O campo Data de Nascimento não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - CPF:
    while(1){
        printf(  "\n                            ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                 " CPF(000.000.000/00): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.documentos.cpf, sizeof(pessoa.documentos.cpf), stdin);
        pessoa.documentos.cpf[strcspn(pessoa.documentos.cpf, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.cpf) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CPF não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                 ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                    " Data de Nascimento(00/00/0000): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nasc);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - RG:
    while(1){
        printf("\n                               ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                  " RG(00.000.000-0): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.documentos.rg, sizeof(pessoa.documentos.rg), stdin);
        pessoa.documentos.rg[strcspn(pessoa.documentos.rg, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.rg) == 0){
            bold(1);
            printf(RED "\n\n                                         [!] O campo RG não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                         CARGO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Cargo: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n\n ", pessoa.cargo);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                 ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                    " Data de Nascimento(00/00/0000): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nasc);
            printf("\n                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                               " CPF(000.000.000/00): ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.documentos.cpf);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    telaLimpa();
    //Campo de inserção - Rua:
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                       ID: %-59i", pessoa.ID);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                      ENDEREÇO:                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    while(1){
        printf("\n                                     ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                        " Logradouro: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.rua, sizeof(pessoa.endereco.rua), stdin);
        pessoa.endereco.rua[strcspn(pessoa.endereco.rua, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.rua) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo Logradouro não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Número:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " Número: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.num_resid, sizeof(pessoa.endereco.num_resid), stdin);
        pessoa.endereco.num_resid[strcspn(pessoa.endereco.num_resid, "\n")] = 0; // Remove a nova linha
        fflush(stdin);

        if(strlen(pessoa.endereco.num_resid) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Número não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                     ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                        " Logradouro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Bairro:
    while(1){
        printf("\n                                         ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                            " Bairro: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.bairro, sizeof(pessoa.endereco.bairro), stdin);
        pessoa.endereco.bairro[strcspn(pessoa.endereco.bairro, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.bairro) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Bairro não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                     ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                        " Logradouro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - CEP:
    while(1){
        printf("\n                                 ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                    " CEP(00000-000): ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.cep, sizeof(pessoa.endereco.cep), stdin);
        pessoa.endereco.cep[strcspn(pessoa.endereco.cep, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.cep) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CEP não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                     ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                        " Logradouro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Bairro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.bairro);
        }else{
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de inserção - Complemento:
    while(1){
        printf("\n                                    ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                       " Complemento: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(pessoa.endereco.complemento, sizeof(pessoa.endereco.complemento), stdin);
        pessoa.endereco.complemento[strcspn(pessoa.endereco.complemento, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.complemento) == 0){
            bold(1);
            printf(RED "\n\n                                [!] O campo Complemento não pode estar vazio!\a");
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
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n                                     ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                        " Logradouro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.rua);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Número: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.num_resid);
            printf("\n                                         ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                            " Bairro: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.endereco.bairro);
            printf("\n                                            ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                               " CEP: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                     " %s\n", pessoa.endereco.cep);
        }else{
            break; //Sai do loop se o nome for válido.
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
        printf(  "                                                       CADASTRO                                                       \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      \n");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n");

        ListarCadastro(pessoa);

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
            arquivo = fopen("dados\\funcionarios\\cadastros.bin", "ab");

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
            fwrite(&pessoa,sizeof(Pessoa), 1, arquivo);

            //Fecha arquivo.
            fclose(arquivo);

            //Salva o último ID.
            salvarUltimoID(pessoa.ID);

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
            arquivo = fopen("dados\\funcionarios\\cadastros.bin", "ab");

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
            fwrite(&pessoa,sizeof(Pessoa), 1, arquivo);

            //Fecha arquivo.
            fclose(arquivo);

            //Salva o último ID.
            salvarUltimoID(pessoa.ID);
            EditarCadastro(pessoa);
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

void ListarCadastros(){

    system("title Lista de Cadastros");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;
    FILE *arquivo;

    //Abre o arquivo pra pesquisa binária.
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb"); //Modo "rb" pra leitura binária.
    if(arquivo == NULL){
        bold(1);
        printf(RED "\n\n                                                [ERRO:] Nenhum cadastro encontrado!");
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
    printf(  "                                                 LISTA DE CADASTROS                                                   \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Lê os dados do arquivo binário.
    while(fread(&pessoa, sizeof(pessoa), 1, arquivo) == 1){
        if(pessoa.ID != 0){ // Pula a impressão do usuário administrador.
            printf("\n");
            ListarCadastro(pessoa);

        }
        printf("\n");
    }

    //Fecha o arquivo.
    fclose(arquivo);
    printf(" ");
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

void BuscaCadastro(){

    system("title Buscar Cadastro");

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
        printf(  "                                                   EDITAR CADASTRO                                                    ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n\n");

        printf("   ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(" Digite o ID do cadastro que deseja buscar: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        scanf("%i", &idBuscado);
        fflush(stdin);

        Pessoa pessoa = buscarCadastroPorID(idBuscado);

        //Verifica se o ID é igual a zero.
        if (idBuscado == 0) {
            bold(1);
            printf(RED "\n\n                                                [ERRO:] Nenhum cadastro encontrado!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            return; //Encerra a função.
        }

        if(pessoa.ID != -1){

            bold(1);
            printf(GREEN "\n\n                                             Cadastro encontrado com sucesso!\n\n");
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
            printf(  "                                                  BUSCA DE CADASTRO                                                   ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n");
            //Mostrando dados do cadastro.
            ListarCadastro(pessoa);

            //Dando opção de editar
            int escolha;

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                    Deseja editar algum campo? [1] Sim | [0] Não                                      ");
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
                EditarCadastro(pessoa);
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

void EditarCadastro(Pessoa pessoa){

    system("title Editar Cadastro");

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
        printf(  "                                                   EDITAR CADASTRO                                                    ");
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
        printf(  "                                              QUAL CAMPO DESEJA EDITAR:                                               ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                                                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                  DADOS DO USUÁRIO:                                                   ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                          [1] Nome | [2] Senha | [3] E-mail                                           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                        CARGO:                                                        ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                      [4] Cargo                                                       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                      DOCUMENTOS:                                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                       [5] Data de Nascimento | [6] CPF | [7] RG                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                       ENDEREÇO:                                                      ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                     [8] Endereço                                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf("\n ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
        printf(  "                                                     [0] Cancelar                                                     ");
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

        switch(opcao){
            //DADOS DO USUÁRIO:
        //Nome:
        case 1:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de inserção - Nome:
            while(1){
                printf("\n                                           ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                              " Nome: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");
                fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.nome) == 0){
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
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }else{
                    //Salvando as alterações no arquivo.
                    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                    if(arquivo != NULL){
                        //Posicionando o ponteiro no início do arquivo.
                        fseek(arquivo, 0, SEEK_SET);

                        Pessoa cadastro;
                        int encontrado = 0;

                        //Lendo os cadastros até encontrar o ID.
                        while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                            if (cadastro.ID == pessoa.ID) {
                                encontrado = 1;
                                //Posicionando o ponteiro no início do cadastro encontrado.
                                fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                                //Escreva as alterações no arquivo.
                                fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                                break; //Encerrando o loop se o ID for encontrado.
                            }
                        }

                        fclose(arquivo); //Fecha o arquivo.

                        if(encontrado){
                            bold(1);
                            printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }else{
                            bold(1);
                            printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }
            }
            break;
        // Senha:
        case 2:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de insersão - Senha:
            char ent_senha1, senha1[TAM_user],
                 ent_senha2, senha2[TAM_user];
            while(1){
                printf("\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha1 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha1[i] = '\0';
                }

                mascSenha(ent_senha1, &senha1);
                fflush(stdin);

                if(strlen(senha1) < 8){
                    bold(1);
                    printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);

                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de insersão - Confirmação de Senha:
            while(1){
                printf("\n                             ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                " Confirme sua senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha2 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha2[i] = '\0';
                }

                mascSenha(ent_senha2, &senha2);
                fflush(stdin);

                if(strlen(senha2) < 8){
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            int comparador;
            //Verifica se senhas são iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                comparador = 0;
                bold(1);
                printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(1000);
                telaLimpa();
                do{
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);

                    //Campo de insersão - Senha:
                    while(1){
                        printf("\n                                          ");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                        printf(                                             " Senha: ");
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf(" ");

                        ent_senha1 = '\0';
                        for (int i = 0; i < TAM_user; i++) {
                            senha1[i] = '\0';
                        }

                        mascSenha(ent_senha1, &senha1);
                        fflush(stdin);

                        if(strlen(senha1) < 8){
                            bold(1);
                            printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(1000);
                            telaLimpa();

                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                                                                                      \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                   EDITAR CADASTRO                                                    ");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                                                                                      \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                            printf(  "                                                       ID: %-59i", pessoa.ID);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);

                        }else{
                            printf("\n");
                            break; //Sai do loop se o nome for válido
                        }
                    }
                    //Campo de insersão - Confirmação de Senha:
                    while(1){
                        printf("\n                             ");
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                        printf(                                " Confirme sua senha: ");
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        printf(" ");

                        ent_senha2 = '\0';
                        for (int i = 0; i < TAM_user; i++) {
                            senha2[i] = '\0';
                        }

                        mascSenha(ent_senha2, &senha2);
                        fflush(stdin);

                        if(strlen(senha2) < 8){
                            bold(1);
                            printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(1000);
                            telaLimpa();

                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                                                                                      \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                   EDITAR CADASTRO                                                    ");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                            printf(  "                                                                                                                      \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                            printf(  "                                                       ID: %-59i", pessoa.ID);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n\n ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf("\n                                          ");
                            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                            printf(                                             " Senha: ");
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            printf(                                                      " %s\n", senha1);
                        }else{
                            printf("\n");
                            break; //Sai do loop se o nome for válido
                        }
                    }
                    //Verifica se senhas são iguais:
                    verificaSenhas(senha1, senha2, &comparador);
                    if(comparador == 1){
                        telaLimpa();
                    }
                }while(comparador == 1);
            }else{
                senha2[strcspn(senha2, "\n")] = 0;
                strcpy(pessoa.login.senha, senha2);

                //Salvando as alterações no arquivo.
                FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                if(arquivo != NULL){
                    //Posicionando o ponteiro no início do arquivo.
                    fseek(arquivo, 0, SEEK_SET);

                    Pessoa cadastro;
                    int encontrado = 0;

                    //Lendo os cadastros até encontrar o ID.
                    while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                        if (cadastro.ID == pessoa.ID) {
                            encontrado = 1;
                            //Posicionando o ponteiro no início do cadastro encontrado.
                            fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                            //Escreva as alterações no arquivo.
                            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                            break; //Encerrando o loop se o ID for encontrado.
                        }
                    }

                    fclose(arquivo); //Fecha o arquivo.

                    if(encontrado){
                        bold(1);
                        printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }else{
                    bold(1);
                    printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaCadastro();
                    break;
                }
            }
        //E-mail:
        case 3:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de Inserção - E-mail:
            while(1){
                printf("\n                                         ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                            " E-mail: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.email, sizeof(pessoa.email), stdin);
                pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.email) == 0){
                    bold(1);
                    printf(RED "\n\n\t\t\t\t\t\t [!] O campo e-mail não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USUÁRIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                }else{
                    //Salvando as alterações no arquivo.
                    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                    if(arquivo != NULL){
                        //Posicionando o ponteiro no início do arquivo.
                        fseek(arquivo, 0, SEEK_SET);

                        Pessoa cadastro;
                        int encontrado = 0;

                        //Lendo os cadastros até encontrar o ID.
                        while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                            if (cadastro.ID == pessoa.ID) {
                                encontrado = 1;
                                //Posicionando o ponteiro no início do cadastro encontrado.
                                fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                                //Escreva as alterações no arquivo.
                                fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                                break; //Encerrando o loop se o ID for encontrado.
                            }
                        }

                        fclose(arquivo); //Fecha o arquivo.

                        if(encontrado){
                            bold(1);
                            printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }else{
                            bold(1);
                            printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                        break; //Sai do loop se o nome for válido
                }
            }
        //Cargo:
        case 4:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                        CARGO:                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                 ");

            int escolhaCargo;

            while(1){
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(                                  " Digite o número correspondente ao cargo escolhido: ");
            scanf("%i", &escolhaCargo);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            fflush(stdin);

            switch(escolhaCargo){
            case 1:
                strcpy(pessoa.cargo, "GERENTE\0");
                break;
            case 2:
                strcpy(pessoa.cargo, "OPERADOR DE CAIXA\0");
                break;
            case 3:
                strcpy(pessoa.cargo, "ESTOQUISTA\0");
                break;
            default:
                bold(1);
                printf(RED "\n\n\t\t\t [!] Opção inválida! Tente novamente.\a");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();

                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                                                                                      ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                   EDITAR CADASTRO                                                    ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                                                                                      ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf(  "                                                       ID: %-59i", pessoa.ID);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf(  "                                                        CARGO:                                                       \n");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf(  "                                 [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA                                \n");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(  "                                 ");
            }
            telaLimpa();
            if(escolhaCargo >= 1 && escolhaCargo <= 4){
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                                                                                      ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                   EDITAR CADASTRO                                                    ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf(  "                                                                                                                      ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf(  "                                                       ID: %-59i", pessoa.ID);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf("\n\n ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                printf(  "                                                        CARGO:                                                       \n");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(  "\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Cargo: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(                                                      " %s\n\n ", pessoa.cargo);

                //Salvando as alterações no arquivo.
                FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                if(arquivo != NULL){
                    //Posicionando o ponteiro no início do arquivo.
                    fseek(arquivo, 0, SEEK_SET);

                    Pessoa cadastro;
                    int encontrado = 0;

                    //Lendo os cadastros até encontrar o ID.
                    while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                        if (cadastro.ID == pessoa.ID) {
                            encontrado = 1;
                            //Posicionando o ponteiro no início do cadastro encontrado.
                            fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                            //Escreva as alterações no arquivo.
                            fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                            break; //Encerrando o loop se o ID for encontrado.
                        }
                    }

                    fclose(arquivo); //Fecha o arquivo.

                    if(encontrado){
                        bold(1);
                        printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }else{
                    bold(1);
                    printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaCadastro();
                    break;
                }
            }
        }
        //Data de Nascimento:
        case 5:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de inserção - Data de nascimento:
            while(1){
                printf(  "\n                 ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                        " Data de Nascimento(00/00/0000): ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.nasc, sizeof(pessoa.nasc), stdin);
                pessoa.nasc[strcspn(pessoa.nasc, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.nasc) == 0){
                    bold(1);
                    printf(RED "\n\n                                 [!] O campo Data de Nascimento não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      DOCUMENTOS:                                                    \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                }else{
                    //Salvando as alterações no arquivo.
                    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                    if(arquivo != NULL){
                        //Posicionando o ponteiro no início do arquivo.
                        fseek(arquivo, 0, SEEK_SET);

                        Pessoa cadastro;
                        int encontrado = 0;

                        //Lendo os cadastros até encontrar o ID.
                        while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                            if (cadastro.ID == pessoa.ID) {
                                encontrado = 1;
                                //Posicionando o ponteiro no início do cadastro encontrado.
                                fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                                //Escreva as alterações no arquivo.
                                fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                                break; //Encerrando o loop se o ID for encontrado.
                            }
                        }

                        fclose(arquivo); //Fecha o arquivo.

                        if(encontrado){
                            bold(1);
                            printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }else{
                            bold(1);
                            printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }
            }
        //CPF:
        case 6:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de inserção - CPF:
            while(1){
                printf(  "\n                            ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                 " CPF(000.000.000/00): ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.documentos.cpf, sizeof(pessoa.documentos.cpf), stdin);
                pessoa.documentos.cpf[strcspn(pessoa.documentos.cpf, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.documentos.cpf) == 0){
                    bold(1);
                    printf(RED "\n\n                                        [!] O campo CPF não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      DOCUMENTOS:                                                    \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                }else{
                    //Salvando as alterações no arquivo.
                    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                    if(arquivo != NULL){
                        //Posicionando o ponteiro no início do arquivo.
                        fseek(arquivo, 0, SEEK_SET);

                        Pessoa cadastro;
                        int encontrado = 0;

                        //Lendo os cadastros até encontrar o ID.
                        while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                            if (cadastro.ID == pessoa.ID) {
                                encontrado = 1;
                                //Posicionando o ponteiro no início do cadastro encontrado.
                                fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                                //Escreva as alterações no arquivo.
                                fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                                break; //Encerrando o loop se o ID for encontrado.
                            }
                        }

                        fclose(arquivo); //Fecha o arquivo.

                        if(encontrado){
                            bold(1);
                            printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }else{
                            bold(1);
                            printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }
            }
        //RG:
        case 7:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      DOCUMENTOS:                                                    \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de inserção - RG:
            while(1){
                printf("\n                               ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                  " RG(00.000.000-0): ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.documentos.rg, sizeof(pessoa.documentos.rg), stdin);
                pessoa.documentos.rg[strcspn(pessoa.documentos.rg, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.documentos.rg) == 0){
                    bold(1);
                    printf(RED "\n\n                                         [!] O campo RG não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      DOCUMENTOS:                                                    \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                }else{
                    //Salvando as alterações no arquivo.
                    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
                    if(arquivo != NULL){
                        //Posicionando o ponteiro no início do arquivo.
                        fseek(arquivo, 0, SEEK_SET);

                        Pessoa cadastro;
                        int encontrado = 0;

                        //Lendo os cadastros até encontrar o ID.
                        while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                            if (cadastro.ID == pessoa.ID) {
                                encontrado = 1;
                                //Posicionando o ponteiro no início do cadastro encontrado.
                                fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                                //Escreva as alterações no arquivo.
                                fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                                break; //Encerrando o loop se o ID for encontrado.
                            }
                        }

                        fclose(arquivo); //Fecha o arquivo.

                        if(encontrado){
                            bold(1);
                            printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }else{
                            bold(1);
                            printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            TelaCadastro();
                            break;
                        }
                    }else{
                        bold(1);
                        printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                        bold(0);
                        SetConsoleTextAttribute(hConsole, saved_attributes);
                        Sleep(800);
                        telaLimpa();
                        TelaCadastro();
                        break;
                    }
                }
            }
        //Endereço:
        case 8:
            telaLimpa();
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                   EDITAR CADASTRO                                                    ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                       ID: %-59i", pessoa.ID);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                      ENDEREÇO:                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n");

            //Campo de inserção - Rua:
            while(1){
                printf("\n                                     ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                        " Logradouro: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.endereco.rua, sizeof(pessoa.endereco.rua), stdin);
                pessoa.endereco.rua[strcspn(pessoa.endereco.rua, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.endereco.rua) == 0){
                    bold(1);
                    printf(RED "\n\n                                        [!] O campo Logradouro não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      ENDEREÇO:                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de inserção - Número:
            while(1){
                printf("\n                                         ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                            " Número: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.endereco.num_resid, sizeof(pessoa.endereco.num_resid), stdin);
                pessoa.endereco.num_resid[strcspn(pessoa.endereco.num_resid, "\n")] = 0; // Remove a nova linha
                fflush(stdin);

                if(strlen(pessoa.endereco.num_resid) == 0){
                    bold(1);
                    printf(RED "\n\n                                     [!] O campo Número não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      ENDEREÇO:                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                    printf("\n                                            ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                               " Rua: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.rua);
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de inserção - Bairro:
            while(1){
                printf("\n                                         ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                            " Bairro: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.endereco.bairro, sizeof(pessoa.endereco.bairro), stdin);
                pessoa.endereco.bairro[strcspn(pessoa.endereco.bairro, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.endereco.bairro) == 0){
                    bold(1);
                    printf(RED "\n\n                                     [!] O campo Bairro não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      ENDEREÇO:                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                    printf("\n                                            ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                               " Rua: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.rua);
                    printf("\n                                         ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                            " Número: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.num_resid);
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de inserção - CEP:
            while(1){
                printf("\n                                 ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                    " CEP(00000-000): ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.endereco.cep, sizeof(pessoa.endereco.cep), stdin);
                pessoa.endereco.cep[strcspn(pessoa.endereco.cep, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.endereco.cep) == 0){
                    bold(1);
                    printf(RED "\n\n                                        [!] O campo CEP não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      ENDEREÇO:                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                    printf("\n                                            ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                               " Rua: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.rua);
                    printf("\n                                         ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                            " Número: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.num_resid);
                    printf("\n                                         ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                            " Bairro: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.bairro);
                }else{
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de inserção - Complemento:
            while(1){
                printf("\n                                    ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                       " Complemento: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(pessoa.endereco.complemento, sizeof(pessoa.endereco.complemento), stdin);
                pessoa.endereco.complemento[strcspn(pessoa.endereco.complemento, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.endereco.complemento) == 0){
                    bold(1);
                    printf(RED "\n\n                                [!] O campo Complemento não pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                   EDITAR CADASTRO                                                    ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                       ID: %-59i", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                      ENDEREÇO:                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n");
                    printf("\n\n                                            ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                               " Rua: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.rua);
                    printf("\n                                         ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                            " Número: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.num_resid);
                    printf("\n                                         ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                            " Bairro: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.endereco.bairro);
                    printf("\n                                            ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                               " CEP: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                     " %s\n", pessoa.endereco.cep);
                }else{
                    break; //Sai do loop se o nome for válido.
                }
            }
            //Salvando as alterações no arquivo.
            FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
            if(arquivo != NULL){
                //Posicionando o ponteiro no início do arquivo.
                fseek(arquivo, 0, SEEK_SET);

                Pessoa cadastro;
                int encontrado = 0;

                //Lendo os cadastros até encontrar o ID.
                while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                    if (cadastro.ID == pessoa.ID) {
                        encontrado = 1;
                        //Posicionando o ponteiro no início do cadastro encontrado.
                        fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                        //Escreva as alterações no arquivo.
                        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                        break; //Encerrando o loop se o ID for encontrado.
                    }
                }

                fclose(arquivo); //Fecha o arquivo.

                if(encontrado){
                    bold(1);
                    printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaCadastro();
                    break;
                }else{
                    bold(1);
                    printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    TelaCadastro();
                    break;
                }
            }else{
                bold(1);
                printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                TelaCadastro();
                break;
            }
        case 0:
            telaLimpa();
            return;
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t\t\t\t [!] Opção Inválida!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }

        telaPause();
    }while(opcao != 0);
    telaLimpa();


}

void DadosUsuario(){

    system("title Informações");

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
        printf(                                           "             INFORMAÇÕES            ");
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
        printf(                                           "    [1] - Dados do Usuário          ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                "                                        \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Alterar Senha             ");
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
            InfoUser();
            break;
        case 2:
            telaLimpa();
            AlteraSenha(usuarioLogado);
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

void InfoUser(){

    system("title Informações do Usuário");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                  DADOS DO USUÁRIO                                                    \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("\n");

    int ID_pessoa = usuarioLogado.ID;

    Pessoa pessoa = buscarCadastroPorID(ID_pessoa);

    ListarCadastro(pessoa);

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

void AlteraSenha(Pessoa pessoa){

    system("title Alteração de Senha");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                 ALTERAÇÃO DE SENHA                                                   \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Campo de insersão - Senha:
    char ent_senha1, senha1[TAM_user],
         ent_senha2, senha2[TAM_user];
    while(1){
        printf("\n                                          ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                             " Senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha1 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha1[i] = '\0';
        }

        mascSenha(ent_senha1, &senha1);
        fflush(stdin);

        if(strlen(senha1) < 8){
            bold(1);
            printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();
        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    //Campo de insersão - Confirmação de Senha:
    while(1){
        printf("\n                             ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                " Confirme sua senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        ent_senha2 = '\0';
        for (int i = 0; i < TAM_user; i++) {
            senha2[i] = '\0';
        }

        mascSenha(ent_senha2, &senha2);
        fflush(stdin);

        if(strlen(senha2) < 8){
            bold(1);
            printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(1000);
            telaLimpa();

            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Senha: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", senha1);
        }else{
            printf("\n");
            break; //Sai do loop se o nome for válido
        }
    }
    int comparador;
    //Verifica se senhas são iguais:
    verificaSenhas(senha1, senha2, &comparador);
    if(comparador == 1){
        comparador = 0;
        bold(1);
        printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(1000);
        telaLimpa();
        do{
            telaLimpa();

            //Campo de insersão - Senha:
            while(1){
                printf("\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha1 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha1[i] = '\0';
                }

                mascSenha(ent_senha1, &senha1);
                fflush(stdin);

                if(strlen(senha1) < 8){
                    bold(1);
                    printf(RED "\n\n                             [!] A senha deve conter no mínimo 8 caracteres!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();
                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Campo de insersão - Confirmação de Senha:
            while(1){
                printf("\n                             ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                " Confirme sua senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                ent_senha2 = '\0';
                for (int i = 0; i < TAM_user; i++) {
                    senha2[i] = '\0';
                }

                mascSenha(ent_senha2, &senha2);
                fflush(stdin);

                if(strlen(senha2) < 8){
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas não coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(1000);
                    telaLimpa();

                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                }else{
                    printf("\n");
                    break; //Sai do loop se o nome for válido
                }
            }
            //Verifica se senhas são iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                telaLimpa();
            }
        }while(comparador == 1);
    }else{
        senha2[strcspn(senha2, "\n")] = 0;
        strcpy(pessoa.login.senha, senha2);

        //Salvando as alterações no arquivo.
        FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb+");
        if(arquivo != NULL){
            //Posicionando o ponteiro no início do arquivo.
            fseek(arquivo, 0, SEEK_SET);

            Pessoa cadastro;
            int encontrado = 0;

            //Lendo os cadastros até encontrar o ID.
            while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
                if (cadastro.ID == pessoa.ID) {
                    encontrado = 1;
                    //Posicionando o ponteiro no início do cadastro encontrado.
                    fseek(arquivo, -sizeof(Pessoa), SEEK_CUR);
                    //Escreva as alterações no arquivo.
                    fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
                    break; //Encerrando o loop se o ID for encontrado.
                }
            }

            fclose(arquivo); //Fecha o arquivo.

            if(encontrado){
                bold(1);
                printf(GREEN "\n\n                                             Cadastro atualizado com sucesso!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                return;
            }else{
                bold(1);
                printf(RED "\n\n                                                [ERRO:] Erro ao atualizar o cadastro.!");
                bold(0);
                SetConsoleTextAttribute(hConsole, saved_attributes);
                Sleep(800);
                telaLimpa();
                return;
            }
        }else{
            bold(1);
            printf(RED "\n\n                                                [ERRO:] Erro ao abrir o arquivo!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            return;
        }
    }
}
