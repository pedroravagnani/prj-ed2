#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Ribrary.h"
#define MAX 100
int preenche_massa(massa *li){
    FILE *f;
    massa l;
    int cont=0, cont2=0,s=0,i=0;
    char cod[6], nome[50], idade[3], emp[50], dept[50], sal[15];
    char c[150];
    f=fopen("massaDados.csv","r");
    while(fgets(c,150,f)){

    strtok(c,"/");
    strcpy(cod, c);

    strcpy(nome,strtok(NULL,"/"));
    strcpy(idade,strtok(NULL,"/"));
    strcpy(emp,strtok(NULL,"/"));
    strcpy(dept,strtok(NULL,"/"));
    strcpy(sal,strtok(NULL,"\n"));


    strreplace(sal, ',','.');
    l.cod=atoi(cod);
    l.idade=atoi(idade);
    l.sal = atof(sal);


    strcpy(l.nome,nome);
    strcpy(l.empresa,emp);
    strcpy(l.departamento, dept);

    li[i]= l;
    i++;
    }
    return i;

}

massa *cria_lista_massa(){

    massa *li;
    li = (massa*) malloc(sizeof(massa)* 15005);

    if(li != NULL){

        li->qtd = 0;

    }

    return li;

}

void strreplace(char *s, char chr, char repl_chr){
     int i=0;
     while(s[i]!='\0')
     {
           if(s[i]==chr)
           {
               s[i]=repl_chr;
           }
           i++;
     }
    return;
}





void ordena_quicksort(massa *v, int inicio, int fim){
    int pivo;
    //Se o fim for maior que o inicio
    if(fim >inicio){
        //pivo chama a função de particionar o vetor para achar a posição central
        pivo = particiona (v,inicio,fim);
        //Ordena a parte da esquerda do vetor
        ordena_quicksort(v,inicio,pivo - 1);
        //Ordena a parte direita do vetor
        ordena_quicksort(v,pivo + 1,fim);
    }

}

int particiona(massa *v, int inicio, int fim){
    int  esq, dir;
    massa aux, pivo;
    esq =inicio; // recebe a primeira posição do vetor
    dir = fim;  // recebe ultima posição do vetor
    pivo = v[inicio];//recebe o o valor da primeira posição do vetor
    while(esq < dir){ //Nesse momento faz a comparação das posições do vetor

    //Compara o valor da posição esquerda com o pivo,
    //caso satisfaça a comparação a posicação esquerda
    //anda para a direita e compara novamente o valor
        while (v[esq].cod<= pivo.cod){
            esq++;
        }
    /*Quando o valor da posição esquerda for maior que o pivo,ele vem para essa condição, e executa:
      O valor da posição da direita for maior que o pivo, a poisição direita anda para esquerda fazendo a mesma comparação*/
         while (v[dir].cod > pivo.cod){
            dir--;
        }
    /*Momento da troca quando a posição esquerda for menor que o direito uma variavel auxiliar recebe o valor de onde a
    posição esquerda está O valor de esquerdo recebe o valor da posição direita e a posição direita recebe o valor de
    auxiliar*/

        if (esq < dir){
        aux = v[esq];
        v[esq] = v[dir];
        v[dir] = aux;
        }
    }
   /*Nesse momento é quando a posição do esquerdo é maior que o direito então o valor que está no inicio
   recebe o valor que esta na posição direita, e o valor da posição direita recebe o valor do Pivo e
   retorna posição direita*/
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}


