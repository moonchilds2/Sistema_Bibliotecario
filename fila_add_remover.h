#include <stdio.h>
#include <stdlib.h>

typedef struct pedido{
    int identificador, matricula;
    char campus_onde_esta_o_livro[100];
    char campus_onde_esta_o_aluno[100];
    char* nome_do_aluno;
    char* detalhe;
    char* nome_responsavel;
    int nivel_prioridade;

    struct pedido * prox;
}pedido;

pedido * inicio_f = NULL;
pedido * fim_f = NULL;
int tam = 0;

void add_na_fila(int identificador, int matricula, char * nome_aluno, char * detalhes, char* nome_responsavel){
    
    pedido * novo_ped = (pedido *)malloc(sizeof(pedido));
    printf("Qual o campus onde esta o livro do pedido?");scanf(" %100[^\n]s", novo_ped->campus_onde_esta_o_livro);
    printf("\nQual o campus onde esta o aluno?");scanf(" %100[^\n]s", novo_ped->campus_onde_esta_o_aluno);
    printf("\nDe 0 a 100 qual o nivel de prioridade desse pedido?");scanf("%d", &novo_ped->nivel_prioridade);
    novo_ped -> identificador = identificador;
    novo_ped -> matricula = matricula;
    novo_ped -> nome_do_aluno = nome_aluno;
    novo_ped -> nome_responsavel = nome_responsavel;
    novo_ped -> detalhe = detalhes;

    if(inicio_f == NULL){
        inicio_f = novo_ped;
        fim_f = novo_ped;
    }else if(inicio_f -> nivel_prioridade < novo_ped -> nivel_prioridade){
        novo_ped -> prox = inicio_f;
        inicio_f = novo_ped;
    }else if(fim_f -> nivel_prioridade > novo_ped -> nivel_prioridade){
        fim_f -> prox = novo_ped;
        fim_f = novo_ped;
    }else{
        pedido * aux = inicio_f;
        while(aux -> nivel_prioridade > novo_ped -> nivel_prioridade){
            aux = aux -> prox;
        }
        novo_ped -> prox = aux -> prox;
        aux -> prox = novo_ped;
    }
    tam++;

}

void remover_fila(){
    
    if(inicio_f != NULL){  
        pedido * lixo = inicio_f;
        inicio_f = inicio_f -> prox;
        printf("\n\nIdentificador: %d", lixo -> identificador);
        printf("\nNome do aulo: %s", lixo -> nome_do_aluno);
        printf("\nMatricula: %d", lixo -> matricula);
        printf("\nNome do responsavel: %s", lixo -> nome_responsavel);
        printf("\nDetalhe do livro: %s", lixo -> detalhe);
        printf("\nCampus onde esta o livro: %s", lixo -> campus_onde_esta_o_livro);
        printf("\nCampus onde esta o aluno: %s", lixo -> campus_onde_esta_o_aluno);

        free(lixo);
        tam--;
        }else{
            printf("Fila de pedidos vazia!!");
        }
                    
    }         
