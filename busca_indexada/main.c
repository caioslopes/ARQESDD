#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE  1000000
#define INTERVAL 1000
#define TRUE 1
#define FALSE 0

struct Tabela{
    
    int pos;
    int value;

};

void gerar_arquivo_ordenado(int arq[], int tamanho);
void exibir_arquivo(int arq[], int tamanho);
void gerar_tabela(int arq[], struct Tabela tab[], int tamanho, int intervalo);
int busca_indexada(int arq[], int tamanho, int intervalo, int key);

int main (){

    int arquivo[MAXSIZE];
    int key = 1000005;
    int exec;

    gerar_arquivo_ordenado(arquivo, MAXSIZE);

    /* Exibe o vetor por completo, para fins de comparação */
    /* exibir_arquivo(arquivo, MAXSIZE); */

    exec = busca_indexada(arquivo, MAXSIZE, INTERVAL, key);

    if(exec >= 0){
        printf("\n***** Saída *****\n");
        printf("A chave %d existe no arquivo, sua posição é: arquivo[%d]\n\n", key, exec);
    }else{
        printf("\n***** Saída *****\n");
        printf("A chave %d não existe no arquivo\n\n", key);
    }

    return 0;
}

void gerar_arquivo_ordenado(int arq[], int tamanho){

    /* srand(time(NULL)); */

    arq[0] = rand() % 10;

    for(int i = 1; i < tamanho; i++){
        arq[i] = arq[i-1] + rand() % 10;
    }

}

void exibir_arquivo(int arq[], int tamanho){

    for(int i = 0; i < tamanho; i++){
        printf("vetor[%d] = %d\n", i, arq[i]);
    }

}

void gerar_tabela(int arq[], struct Tabela tab[], int tamanho, int intervalo){

    for(int i = 0; i <= tamanho; i++){
        tab[i].pos = i * intervalo;
        tab[i].value = arq[i*intervalo];
    }

}

int busca_indexada(int arq[], int tamanho, int intervalo, int key){

    int retorno = -1;
    int tam = tamanho/intervalo;
    struct Tabela kindex[tam];

    /* Resultado da busca na tabela auxiliar */
    int pos = 0;

    gerar_tabela(arq, kindex, tam, intervalo);

    for(int i = 0; i < tam && retorno == -1; i++){

        if(key == kindex[i].value){
            retorno = kindex[i].pos;
        }

        if(key > kindex[i].value){
            pos = i;
        }

    }

    for(int i = kindex[pos].pos; i < kindex[pos+1].pos; i++){

        if(key == arq[i]){
            retorno = i;
        }

        /* Exibe o intervalo selecionado para a busca da chave */
        /* printf("arq[%d] = %d\n",i, arq[i]); */
        
    }

    return retorno;

}