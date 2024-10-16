#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para trabalhar com cadeia de caracteres do tipo string.
#include <locale.h> //Permite que o código entenda caracteres especiais.
#include <windows.h> //Uso de funções do sistema.
#include <conio.h> //Para personalizar as definições de cores.
#include <ctype.h> //Uso de funções para classificar e modificar caracteres.

//As funções principais que foram feitas, ficam no arquivo funcoes.c
#include "interface.c"
#include "funcoes.c"
#include "estilos.c"
#include "cadastros.c"

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "Portuguese"); /* Definindo configuração padrão do sistema */

    telaTamanho();
    telaEstilo();
    telaInicio();

    return 0;
}
