#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Ribrary.h"
#include "arvALV.h"

int main()
{
    massa *li;
    arvAVL *raiz;
    int i, x;
    int nElems;
    float time[4];
    float timefinal[4];


    time[0] = clock();
    li = cria_lista_massa();
    nElems = preenche_massa(li);
    raiz = cria_arvAVL();

    for(i=0;i<nElems;i++){
        x = insere_arvAVL(raiz, li[i]);
        if(x==0){
            printf("ERRO!");
            system("pause");
        }
    }
    timefinal[0] = clock();

    free(li);
    liberar_arvAVL(raiz);
    free(raiz);

    time[1] = clock();
    li = cria_lista_massa();
    nElems = preenche_massa(li);
    raiz = cria_arvAVL();
    ordena_quicksort(li,0,nElems);
    for(i=0;i<nElems;i++){
        x = insere_arvAVL(raiz, li[i]);
        if(x==0){
            printf("ERRO!");
            system("pause");
        }
    }
    timefinal[1] = clock();




    printf("Tempo de execucao da arvore AVL ordenada: %.2f MS, %.2f S  \n",timefinal[0]-time[0]/10, (timefinal[0]-time[0]/10)/1000);
    printf("Tempo de execucao da arvore AVL nao ordenada: %.2f MS, %.2f S \n",timefinal[1]-time[1]/10, (timefinal[1]-time[1]/10)/1000);






    system("pause");
    return 0;
}
