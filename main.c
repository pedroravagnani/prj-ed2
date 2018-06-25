#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Ribrary.h"
#include "arvALV.h"
#include "arvLLRB.h"

int main()
{
    massa *li;
    arvAVL *raiz;
    arvoreLLRB *raizLLRB;
    int i, x;
    int nElems;
    float time[2];
    float timefinal[2];
    int escolha;


    while(escolha!=3){
    for(i=0;i<2;i++){
        time[i]=0;
        timefinal[i]=0;
    }
        printf("/ / / PROJETO DE ED MAROTO \\ \\ \\ \n");
    printf("Acho uma das maiores conquistas do Brasil.\nEu acho que a importancia da bola e justamente essa, o simbolo da capacidade que nos distingue como...\nNos somos do genero humano, da especie Sapiens. Entao, para mim essa bola e um simbolo da nossa evolucao. Quando nos criamos uma bola dessas, nos nos transformamos em Homo sapiens ou mulheres sapiens. - Dilma Rouseff \n\n");

    printf("\n\nEscolha sua opcao\n1.Teste Ordenado\n2.Teste Desordenado\n3.Sair\n\nOpcao:  ");
    scanf("%d",&escolha);
    switch(escolha){
    case 1:

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

    free(li);
    liberar_arvAVL(raiz);
    free(raiz);

    time[0] = clock();
    li = cria_lista_massa();
    nElems = preenche_massa(li);
    raizLLRB = cria_arvoreLLRB();
    ordena_quicksort(li,0,nElems);
     for(i=0;i<nElems;i++){
        x = insere_arvoreLLRB(raizLLRB, li[i]);
        if(x==0){
            printf("ERRO!");
            system("pause");
        }

    }
    timefinal[0] = clock();

    printf("\nTempo de execucao da arvore AVL  ordenada: %.2f MS, %.2f S \n",(timefinal[1]-time[1])/10, ((timefinal[1]-time[1])/10)/1000);
    printf("Tempo de execucao da arvore Rubro Negra ordenada: %.2f MS, %.2f S \n",(timefinal[0]-time[0])/10, ((timefinal[0]-time[0])/10)/1000);
    system("pause");
     system("clear");


        break;

    case 2:

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
    raizLLRB = cria_arvoreLLRB();
     for(i=0;i<nElems;i++){
        x = insere_arvoreLLRB(raizLLRB, li[i]);
        if(x==0){
            printf("ERRO!");
            system("pause");
        }

    }
    timefinal[1] = clock();


    printf("\nTempo de execucao da arvore AVL ordenada: %.2f MS, %.2f S  \n",(timefinal[0]-time[0])/10, ((timefinal[0]-time[0])/10)/1000);
    printf("Tempo de execucao da arvore Rubro negra ordenada: %.2f MS, %.2f S  \n",(timefinal[1]-time[1])/10, ((timefinal[1]-time[1])/10)/1000);
    system("pause");
    system("clear");
        break;
    case 3:
        printf("saindo!\n");
    }
    }













    system("pause");
    return 0;
}
