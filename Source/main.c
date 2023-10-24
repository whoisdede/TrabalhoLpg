#include <stdio.h>
#include "lib.h"
#include <locale.h>

int main(){
    int x, cont, lin, col,index;
    cont = 0;
    setlocale(LC_ALL, "Portuguese_Brazil");
        

        printf("\nInsira quantos conjuntos você deseja armazenar\n");
        scanf("%i",&lin);
        printf("\nInsira qual tamanho dos conjuntos\n");
        scanf("%i",&col);
        int m[lin][col];
        zerarmatriz(lin,col,m);

        while(x != 9){
        
        printf("\n");
        printf("\nEscolha uma entre as operações oferecidas");
        menu();
        
        
        scanf("%i",&x);
        
        switch (x)
        {
        case 1:
            cont = criarconj(lin,cont);
            break;
        case 2:
            fillconj(lin,col,m,cont);
            break;
        
        case 3:
            printf("oi");
            removecon(lin, col, m, cont);
            break;
        
        case 4:
            if(cont < 2){
                printf("Operação cancelada\nEssa operação precisa de dois conjuntos criados");
            }else if((cont+1 > lin)){
                printf("Operação cancelada\nCriar um novo conjunto ultrapassa o limite maximo");
            }else{
                unionconj(lin,col,m,cont);
            }
            
            break;
        
        case 5:
            interconj(lin, col, m, cont);
            break;
        
        case 6:
            showone(lin,col,m,cont);
            break;
        
        case 7:
            showall(lin,col,m,cont);
            break;
        
        case 8:
            search(lin,col,m,cont);
            break;
        case 9:
            printf("\nPrograma Encerrado\n");
            break;
        default:
            printf("\nOperação Inválida\n");
            break;
        }
    }

    return 0;
}
