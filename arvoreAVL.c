#include<stdio.h>
#include<stdlib.h>
#include "arvoreAVL.h"

struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

struct NO *procuramenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
};

int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->alt;
    }
}

int fatorBalanceamento_NO(struct NO *no){
        return labs(alt_no(no->esq) - alt_no(no->dir));
}

int maior(int x,int y){
    if(x>y){
        return(x);
    }else{
        return(y);
    }
}

void rotacaoLL(arvAvl *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt + 1);
    *raiz = no;
}

void rotacaoLR(arvAvl *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRR(arvAvl *raiz){
    struct NO *no;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_no(no->dir), (*raiz)->alt)+1;
    (*raiz) = no;
}

void rotacaoRL(arvAvl *raiz){
    rotacaoLL(&(*raiz)->esq);
    rotacaoRR(raiz);
}



arvAvl *cria_arvAvl(){
    arvAvl *raiz = (arvAvl*) malloc(sizeof(arvAvl));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

void liberar_arvAvl(arvAvl *raiz){
        if(raiz == NULL){
            return;
        }
        libera_NO(*raiz);   /*libera cada nó*/
        free(raiz);/*libera a raiz*/
}
void libera_NO(struct NO *no){
        if(no == NULL){
            return;
        }
        libera_NO(no->esq);
        libera_NO(no->dir);/*percorre por recursão todos os nós esquerdos e direitos*/
        free(no);
        no = NULL; /*Armazena Null em Nó para não ter problemas*/
}

int vazia_arvAvl(arvAvl *raiz){
    if( raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_arvAvl(arvAvl *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0; /*Quando a recursão descer no nó folha ela retorna 0.Neste caso altura 0*/
    }
    int alt_esq = altura_arvAvl(&((*raiz)->esq));
    int alt_dir = altura_arvAvl(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_arvAvl(arvAvl *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_arvAvl(&((*raiz)->esq));
    int alt_dir = totalNO_arvAvl(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

void preOrdem_arvAvl(arvAvl * raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_arvAvl(&((*raiz)->esq));
        preOrdem_arvAvl(&((*raiz)->dir));
    }
}

void emOrdem_arvAvl(arvAvl *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_arvAvl(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_arvAvl(&((*raiz)->dir));
    }
}

void posOrdem_arvAvl(arvAvl * raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_arvAvl(&((*raiz)->esq));
        posOrdem_arvAvl(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int insere_arvAvl(arvAvl *raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_arvAvl(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_NO(atual) >=2){
                if(valor < (*raiz)->esq->info){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insere_arvAvl(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_NO(atual) >=2){
                    if((*raiz)->dir->info < valor){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor Duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;
    return res;
}

int remove_arvAvl(arvAvl *raiz, int valor){

    if(*raiz == NULL){
        return 0;
    }
    int res;
    if(valor <(*raiz)->info){
        if((res = remove_arvAvl(&(*raiz)->esq, valor)) ==1){
            if(fatorBalanceamento_NO(*raiz) >=2){
                if(alt_no(((*raiz)->dir->esq)<= alt_no((*raiz)->dir->dir))){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->info < valor){
        if((res = remove_arvAvl(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >=2 ){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoRR(raiz);
                }
            }
        }
    }
    if((*raiz)->info == valor){
        if(((*raiz)->esq == NULL) || (*raiz)->dir == NULL){
            struct NO *no_velho = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            } else{
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        }else{
            struct NO *temp = procuramenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_arvAvl((*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz)>=2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoRR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) +1;
        }
        return 1;
    }
    if(*raiz != NULL){
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    }
    return res;
}


int consulta_arvAvl(arvAvl *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}
