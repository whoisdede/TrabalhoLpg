#include <stdio.h>
#include "lib.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    menu();

    return 0;
}
