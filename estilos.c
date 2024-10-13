//o arquivo estilo.c fica as funções de sons, animações, e personalizações de textos
#include "estilos.h"

//Declarando funções:
void bold(int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
 printf("%s", seq[!!status]);
}

void italic(int status) {
 static const char *seq[] = {"\x1b[0m", "\x1b[3m"};
 printf("%s", seq[!!status]);
}

void toca_som_de_digitacao(){
    Beep(200, 50); // Som de tecla pressionada
    Sleep(20); // Pausa entre as teclas
}

void animacao_de_carregamento(){
    int i;
    char animacao[] = {'|', '/', '-', '\\'};
    for(i = 0; i < 100; i++){
        printf("\rCarregando... %c", animacao[i % 4]);
        fflush(stdout);
        usleep(10000); // pausa de 50 milissegundos
    }
    printf("\n");
}

void animacao_de_aparecimento(char* texto){
    int i;
    for(i = 0; i < strlen(texto); i++){
        printf("%c", texto[i]);
        toca_som_de_digitacao();
        Sleep(50); // pausa de 50 milissegundos
        fflush(stdout);
    }
}

void animacao_de_saida(){
    int i;
    char animacao[] = {'|', '/', '-', '\\'};
    for(i = 0; i < 100; i++){
        printf("\rSaindo... %c", animacao[i % 4]);
        fflush(stdout);
        usleep(50000); // pausa de 50 milissegundos
    }
    printf("\n");
}
