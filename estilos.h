#ifndef ESTILOS_H_INCLUDED
#define ESTILOS_H_INCLUDED

//Definições de cores com valor hexadecimal:
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

//Protótipo de funções:
void bold(int status);

void italic(int status);

void toca_som_de_digitacao();

void animacao_de_carregamento();

void animacao_de_aparecimento(char* texto);

void animacao_de_saida();

#endif // ESTILOS_H_INCLUDED
