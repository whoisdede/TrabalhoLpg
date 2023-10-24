#include <stdio.h>
#include <locale.h>

// printar o menu
void menu(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("\n");
    printf("\n[1] - Criar Novo Conjunto");
    printf("\n[2] - Inserir Dados Conjunto");
    printf("\n[3] - Remover Conjunto");
    printf("\n[4] - Realizar União Conjuntos");
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
    return cont; //retorna >0 se achar e qntde de ocorrências.
}


// Verificação para o usuário selecionar corretamente o conjunto que deseja
int validindex(int cont){
    int index;
    index = 0;
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

void removecon(int lin, int col, int m[lin][col], int cont){
    int index=0;
    int temp=0;
    if(cont > 0){
        index = validindex(cont);
        int r1=index;
        int r2=index+1;
        int a = index;
        for(int i=0; i < col; i++){
            m[index][i] = 0;
        }
        while(a+1 < cont){ 
            for (int i = 0; i < cont; ++i) {  
                temp = m[r1][i]; 
                m[r1][i] = m[r2][i];         
                m[r2][i] = temp; 
                }
            a++;   
            r1++;
            r2++;
        }
        cont--;
    }else{
        printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
    }
}

    int sumsamenum(int lin, int col, int m[lin][col],int index1,int index2){
        int x, cont;
        x = cont = 0;
        for(int j = 0; j < col; j++ ){
                x = m[index2][j];
                cont += busca(lin,col,m,x,index1);
            }
        return cont; // quantidade de numeros semelhantes entre index1 e index1
    }

    // Verifica a posição do proximo zero se existir
    // Tamanho total do conjunto
    int sizeconj(int lin, int col, int m[lin][col], int index){
        int cont = 0;
        while ((m[index][cont] != 0) && ( cont < col)){
            cont++;
        }
        return cont;
    }

    // Une dois conjuntos utilizando index de suas linhas
    int unionconj(int lin, int col,int m[lin][col], int cont){
        int index1,index2,tam1,tam2,x,i,j,same; 
        index1 = index2 = tam1 = tam2 = x = i = j = same = 0;
        if(cont > 0){
            do{
                index1 = validindex(cont);
                index2 = validindex(cont);
            }while (index1 == index2);
                tam1 = sizeconj(lin,col,m,index1);
                tam2 = sizeconj(lin,col,m,index2);
                same = sumsamenum(lin,col,m,index1,index2);
            if((tam1+tam2-same) > col){
                    printf("A união dos conjuntos ultrapassa o tamanho limite");
                    return 1;
            }else{
                
                for(int j = 0; j < tam1; j++){
                    m[cont][j] = m[index1][j];
                }
                i = tam1;
                for(int j = 0; j < tam2; j++){
                    x = m[index2][j];
                    if(busca(lin,col,m,x,index1)==0){
                        m[cont][tam1]=x;
                        tam1++;
                    }
                }
                return 0;   
            }

        }else{
            printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
            return 1;
        }
    }
    // :)
    int interconj(int lin, int col,int m[lin][col], int cont){
        if(cont > 0){
            int index1 = validindex(cont);
            int index2 = validindex(cont);
            int temp=0;
            for(int i =0; i<col; i++){
                if(busca(lin, col, m , m[index1][i], index2)>0){
                    m[cont][i]=m[index1][i];
                    temp++;
                }
            }
            cont++;
            if(temp!=0){
                return 1;
            }
        }
        else{
            printf("\nNenhum Conjunto criado\nTente pela opção 1\n");
        }
    }

        

