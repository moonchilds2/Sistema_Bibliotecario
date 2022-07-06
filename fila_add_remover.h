#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"

typedef struct pedido{
    int identificador, matricula;
    char * campus_onde_esta_o_livro;
    char * campus_onde_esta_o_aluno;
    char * nome_do_aluno;
    char * nome_do_livro;
    char * nome_do_autor;
    int nivel_propriedade;

    DADOS_TRANSPORTADOR * d;
    struct pedido * prox;
}pedido;

pedido * inicio_f = NULL;
pedido * fim_f = NULL;
int tam = 0;

void add_na_lista(int identificador, int matricula, char * campus_onde_esta_o_livro, char * campus_onde_esta_o_aluno,
                  char * nome_do_aluno, char * nome_do_livro, char * nome_do_autor, int nivel_propriedade){
    pedido * novo_ped = (pedido *)malloc(sizeof(pedido));
    novo_ped -> identificador = identificador;
    novo_ped -> matricula = matricula;
    novo_ped -> campus_onde_esta_o_livro = campus_onde_esta_o_livro;
    novo_ped -> campus_onde_esta_o_aluno = campus_onde_esta_o_aluno;
    novo_ped -> nome_do_aluno = nome_do_aluno;
    novo_ped -> nome_do_livro = nome_do_livro;
    novo_ped -> nome_do_autor = nome_do_autor;
    novo_ped -> nivel_propriedade = nivel_propriedade;

    if(inicio_f == NULL){
        inicio_f = novo_ped;
        fim_f = novo_ped;
    }else if(inicio_f -> nivel_propriedade < novo_ped -> nivel_propriedade){
        novo_ped -> prox = inicio_f;
        inicio_f = novo_ped;
    }else if(fim_f -> nivel_propriedade > novo_ped -> nivel_propriedade){
        fim_f -> prox = novo_ped;
        fim_f = novo_ped;
    }else{
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
