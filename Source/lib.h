#ifndef _LIB_H
#define _LIB_H

void menu();
int criarconj(int lin, int cont);
void zerarmatriz(int lin, int col,int m[lin][col]);
int busca(int lin, int col, int m[lin][col], int x, int index);
void fillconj(int lin, int col, int m[lin][col],int cont);
int validindex(int cont);
int findzero(int lin, int col , int m[lin][col], int index);
void showone(int lin, int col,int m[lin][col], int cont);
void showall(int lin, int col,int m[lin][col], int cont);
void search(int lin, int col, int m[lin][col], int cont);
void removecon(int lin, int col, int m[lin][col], int cont);
int sameconj(int lin, int col, int m[lin][col],int index1,int index2);
int sumsamenum(int lin, int col, int m[lin][col],int index1,int index2);
int sizeconj(int lin, int col, int m[lin][col], int index);
void unionconj(int lin, int col,int m[lin][col], int cont);
void interconj(int lin, int col,int m[lin][col], int cont);
#endif
