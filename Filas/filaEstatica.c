#include <stdio.h>
#include <stdlib.h>
#define m 10

struct fila{
int elem[m];
int comeco, tamanho, fim;
}F;
void inicia(){
    F.fim=0;
    F.tamanho=0;
    F.comeco=1;
}

void insere(int x){
    if(F.tamanho == m-1){
        printf("Fila cheia\n");
    }
    else{
        F.tamanho++;
        F.fim = (F.fim % (m-1) + 1);
        F.elem[F.fim] = x;
        printf("%d\n",x);
    }
}

void retira(){
    if(F.comeco == 0){
        printf("Fila vazia\n");
    }
    else{
        F.comeco = (F.comeco%(m-1)+1);
    }
}
int primeiro(){
    if(F.tamanho == 0){
        printf("Fila vazia \n");
    }
    else{
        return (F.elem[F.comeco]);
    }
}
void imprime(){
    for(int i=0; i<m; i++){
        int n=primeiro();
        printf("%3d",n);
        retira();
    }
}
/* int menu(){
    int x;
    printf("Algoritimo de fila estatica 1.0\n");
    printf("------->Menu<-------\n");
    printf("Opções:\n");
    printf("1-Criar Fila");
    printf("2-Inserir na Fila\n");
    printf("3-Remover da Fila\n");
    printf("4-Imprimir primeiro elemento da Fila\n");
    printf("5-Imprimir a Fila\n");
    scanf("%d",&x);
    return x;
}*/



void main(){
    inicia();
    insere(12);
    insere(12);
    insere(12);
    insere(12);
    insere(12);
    insere(12);
    retira();
    imprime();
}