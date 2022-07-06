#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"

typedef struct pedido{
    typedef struct pedido{
    int identificador, matricula;
    char * campus_onde_esta_o_livro;
    char * campus_onde_esta_o_aluno;
    char * nome_do_aluno;
    char detalhe[300];
    char * nome_responsavel_secr;
    int nivel_prioridade;// de 0 a 100

    DADOS_TRANSPORTADOR * d;
    struct pedido * prox;
}pedido;

pedido * inicio_f = NULL;
pedido * fim_f = NULL;
int tam = 0;

void add_na_lista(int identificador, int matricula, char * nome_do_aluno, int * nome_responsavel_secr){
    char * campus_onde_esta_o_livro;
    char * campus_onde_esta_o_aluno;
    int nivel_prioridade;
    printf("Qual o campus onde esta o livro do pedido?");scanf("%s", &campus_onde_esta_o_livro);
    printf("\nQual o campus onde esta o aluno?");scanf("%s", &campus_onde_esta_o_aluno);
    printf("\nDe 0 a 100 qual o nivel de prioridade desse pedido?");scanf("%d", &nivel_prioridade);
    pedido * novo_ped = (pedido *)malloc(sizeof(pedido));
    novo_ped -> identificador = identificador;
    novo_ped -> matricula = matricula;
    novo_ped -> campus_onde_esta_o_livro = campus_onde_esta_o_livro;
    novo_ped -> campus_onde_esta_o_aluno = campus_onde_esta_o_aluno;
    novo_ped -> nome_do_aluno = nome_do_aluno;
    novo_ped -> nivel_prioridade = nivel_prioridade;
    novo_ped -> nome_responsavel_secr = nome_responsavel_secr;

    if(inicio_f == NULL){//se a lista estiver vazia
        inicio_f = novo_ped;
        fim_f = novo_ped;
    }else if(inicio_f -> nivel_propriedade < novo_ped -> nivel_propriedade){//se o nivel de propriedade do novo_ped for maior q o inicio da fila
        novo_ped -> prox = inicio_f;
        inicio_f = novo_ped;
    }else if(fim_f -> nivel_propriedade > novo_ped -> nivel_propriedade){//se o nivel de propriedade do novo_ped for menor que o fim da lista
        fim_f -> prox = novo_ped;
        fim_f = novo_ped;
    }else{//se o nivel da propriedade no novo_ped for menor que o inicio da fila e for maior que o fim da mesma, achar um lugar do valor ideial para ela no meio
        pedido * aux = inicio_f;
        while(aux -> nivel_propriedade > novo_ped -> nivel_propriedade){
            aux = aux -> prox;
        }
        novo_ped -> prox = aux -> prox;
        aux -> prox = novo_ped;
    }
    tam++;

}

pedido remover_fila(){
    pedido pedido;
        if(inicio_f != NULL){  
            pedido * lixo = inicio_f;
            inicio_f = inicio_f -> prox;
            pedido.identificador = lixo->p->identificador;

            free(lixo);
            tam--;
            if(tam == 1){
                fim_f = NULL;
            }
        printf("Nome do TRANSPORTADOR responsavel: %d\n", aux->d->nome_transportador);                   
        }         
    return pedido;
}
