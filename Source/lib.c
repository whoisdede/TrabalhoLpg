#include <stdio.h>
#include <locale.h>
void menu(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n[1] - Criar Novo Conjunto");
    printf("\n[2] - Inserir Dados Conjunto");
    printf("\n[3] - Remover Conjunto");
    printf("\n[4] - Realizar União Conjuntos");
    printf("\n[5] - Realizar Intersecção Conjuntos");
    printf("\n[6] - Mostrar Conjunto");
    printf("\n[7] - Mostrar Todos Conjuntos");
    printf("\n[8] - Buscar Valor");
    printf("\n[9] - Sair Programa\n");

}