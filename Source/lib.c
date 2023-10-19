#include <stdio.h>
#include <locale.h>

// printar o menu
void menu(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n");
    printf("\n[1] - Criar Novo Conjunto");
    printf("\n[2] - Inserir Dados Conjunto");
    printf("\n[3] - Remover Conjunto");
    printf("\n[4] - Realizar Uni�o Conjuntos");
    printf("\n[5] - Realizar Intersec��o Conjuntos");
    printf("\n[6] - Mostrar Conjunto");
    printf("\n[7] - Mostrar Todos Conjuntos");
    printf("\n[8] - Buscar Valor");
    printf("\n[9] - Sair Programa\n");

}

// iniciar matriz toda zerada
void zerarmatriz(int lin, int col,int m[lin][col]){
    int i,j;
    for(i=0; i < lin; i++){
        for(j=0; j< col; j++){
            m[i][j] = 0;
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}


// criar conjuntos
int criarconj(int lin, int cont){
    if(lin > cont){
        cont++;
        printf("\nNovo conjunto adicionado\n");
        return cont;
    }else{
        printf("\nOpera��o cancelada");
        printf("\nA quantidade de conjuntos execede capacidade m�xima\n");
        return cont;
    }
}

// Procurar os valores repetidos
int busca(int lin, int col, int m[lin][col], int x, int index){ 
    int cont,j;
    cont = 0;
    j = 0;
    while ((m[index][j] != 0) && ( j < col)){
        if(m[index][j] == x){
            cont++;
        }
        j++;
    }
    return cont;
}


// Verificação para o usuário selecionar corretamente o conjunto que deseja
int validindex(int cont){
    int index;
        do{
            printf("\nQual conjunto deseja interagir = ");
            scanf("%i",&index);
            if((index > cont) || (index < 0) || (cont == index)){
                printf("\nConjunto Inexistente\n Tente outro");
            }
        }while((index > cont) || (index < 0) || (cont == index));
    return index;
}

// Achar o zero em uma linha fixa
int findzero(int lin, int col , int m[lin][col], int index){
    int cont,j;
    cont = 0;
    while(m[index][cont] != 0){
        cont++;
    }
    return cont;
}

// Colocar valores nos conjuntos
void fillconj(int lin, int col, int m[lin][col],int cont){
    int j,x,index;
    j = 0;
        if(cont > 0){
        index = validindex(cont);
        j = findzero(lin,col,m,index);
        if(j < col){
            printf("\nInsira os valores para o conjunto %i\n", index);
            do{
                scanf("%i",&x);
                    if(busca(lin, col, m, x, index) >0 ){
                        printf("Valor %i já encontrado no conjunto\n",x);
                    }else{
                        m[index][j]=x;
                        j++;
                    }
            }while((j < col) && (x != 0));
        }else{
            printf("\nConjunto já está cheio\nTente criar um novo");
        }   
    }else{
        printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
    }
    
}

// Mostrar um conjunto
void showone(int lin, int col,int m[lin][col], int cont){
    int j,index;
    j = 0;
    if(cont > 0){
        index = validindex(cont);
        if(m[index][0] == 0){
             printf("\n%i - Conjunto = Vazio\n",index);
         }else{
                printf("\n%i - Conjunto = ",index);
                while((m[index][j] != 0) && (j < col)){
                    printf("%i ", m[index][j]);
                    j++;
                }
        }
        
    }else{
        printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
    }
}


// Mostrar todos os conjuntos
void showall(int lin, int col, int m[lin][col], int cont){
    int i, j;
    j = 0;
    if(cont > 0){
        for(i=0 ; i < cont; i++){
            if(m[i][0] == 0){
                printf("\n%i - Conjunto = Vazio",i);
            }else{
                printf("\n%i - Conjunto = ",i);
                while((m[i][j] != 0) && (j < col)){
                    printf("%i ",m[i][j]);
                    j++;
                }
            }
            j = 0;
        }
    }else{
        printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
    }
}

void search(int lin, int col, int m[lin][col], int cont){
    int i,j,x,y;
    if(cont > 0){
        printf("Qual valor deseja buscar");
        scanf("%i",&x);
        for(i = 0; i < cont; i++){
            if(busca(lin,col,m,x,i) > 0){
                printf("\n%i - Encontrado no conjunto = %i",x,i);
                y++;
            }
        }if(y == 0){
            printf("Valor não está presente em nenhum conjunto");
        }

    }else{
         printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
    }
}