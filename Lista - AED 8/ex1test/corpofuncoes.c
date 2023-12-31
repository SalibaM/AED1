#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    Aluno valor;
    struct no *prox;

}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;

}

int listaVazia(Lista *l){
    if(l==NULL)
        return 2;
    if(l->inicio==NULL)
        return 0;
    return 1;
}

int inserirInicio(Lista *l,Aluno it){
    if(l==NULL)
        return 2;
    No *no = (No *)malloc(sizeof(No));

    no->valor = it;
    no->prox = l->inicio;
    l->inicio = no;

    return 0;

}

int inserirFim(Lista *l,Aluno it){

    if(l==NULL)
        return 2;
    if(listaVazia(l)==0)
        return inserirInicio(l,it);

    No *noLista = l->inicio;
    while(noLista->prox  != NULL)
        noLista = noLista->prox;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;

}

int inserirPosicao(Lista *l,Aluno it,int pos){

    if(l==NULL) return 2;
    if(pos<0) return 3;
    if((listaVazia(l)==0)||(pos==0))
        return inserirInicio(l,it);
    No *noLista = l->inicio;
    int p = 1;
    while((noLista->prox != NULL)&&(p != pos)){
        p++;
        noLista=noLista->prox;
    }

    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;


}

int removerInicio(Lista *l){
    if(l==NULL)
        return 2;
    if(listaVazia(l)==0)
        return 1;

    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int removerFim(Lista *l){

    if(l==NULL)
        return 2;
    if(listaVazia(l)==0)
        return 1;

    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while(noLista->prox != NULL){
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }

    if(noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int buscarItemChave(Lista *l,int chave,Aluno *retorno){

    if(l==NULL)
        return 2;
    No *noLista = l->inicio;
    while((noLista!=NULL)){
        if((noLista->valor).mat == chave){
            *retorno = noLista->valor;
            return 0;
        }
        noLista = noLista->prox;
    }

    return 1;

}

void limpar(Lista *l){
    while(listaVazia(l)!=0){
        removerInicio(l);
    }
}

void mostrar(Lista *l){

    if(l!=NULL){
        printf("[");
        No *noLista = l->inicio;
        while(noLista != NULL){
                printf(" {%d",noLista->valor.mat);
                printf("%s, ",noLista->valor.nome);
                printf("%.2f",noLista->valor.n1);
                noLista = noLista->prox;
        }

        printf("]\n");

    }

}

int removerPosicao(Lista *l, int pos){

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    if(pos<0){
        return 3;
    }

    int p=0;

    No *noAux = NULL;
    No *noLista = l->inicio;

    while((noLista->prox!=NULL) && (p!=pos)){
        noAux = noLista;
        noLista = noLista->prox; //Acha posi��o desejada e a anterior
        p++;

    }

    if(noAux == NULL){
        removerInicio(l);
    } else {

        noAux->prox = noLista->prox; //Aponta a posi��o anterior para a pr�xima da encontrada,excluindo a posi��o informada com o free seguinte.
    }

    free(noLista);


    return 0;
}


int removerItem(Lista *l,Aluno it){

    if(l==NULL){
        return 2;
    }
    if(listaVazia(l)==0){
        return 1;
    }

    int p=0;

    No* noLista = l->inicio;

    while(noLista->prox != NULL){
        if(noLista->valor.mat==it.mat){
            removerPosicao(l,p);
        } else {
            p++;
            noLista = noLista->prox;
        }
    }

    return 0;

}

int buscarPosicao(Lista *l,int posicao,Aluno *retorno){

    if(l==NULL){
        return 2;
    }

    if(listaVazia(l)==0){
        return 1;
    }

    int p=0;

    No *noLista = l->inicio;

    while((noLista->prox != NULL) && (p!=posicao)){

        if(p==posicao){
            retorno->mat = noLista->valor.mat;
            strcpy(retorno->nome,noLista->valor.nome); //Pode precisar, talvez...
            retorno->n1 = noLista->valor.n1;
        } else {

            p++;
            noLista = noLista->prox;
        }
    }

    return 0;
}




















