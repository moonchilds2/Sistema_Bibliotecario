#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila_add_remover.h"

typedef struct encomenda{

    int id;
    char aluno[50];
    int matricula;
    char detalhes[100];

    struct encomenda* esq;
    struct encomenda* dir;

}encomenda;


encomenda* busca(int id, encomenda* aux){

    if(aux != NULL){

        if(id == aux->id){
            return aux;
        }

        else if(id < aux->id){
            
            if(aux->esq != NULL){
                return busca(id, aux->esq);
            }else{
                return aux;
            }

        }

        else if(id > aux->id){

            if(aux->dir != NULL){
                return busca(id, aux->dir);
            }else{
                return aux;
            }
        }

    }else{
        return NULL;
    }

}

encomenda* raiz = NULL;

int buscar_id(int id, encomenda* aux){
    if(aux != NULL){
        if(aux->id == id){
            return 1;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar_id(id, aux->esq);
            }else{
                return 0;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar_id(id, aux->dir);
            }else{
                return 0;
            }
        }
    }else{
        return 0;
    }
}

int idaleatorio(){ 
    int i;
    int buscarid = 1;
    srand(time(NULL));
    while(buscarid == 1){
        i = (rand()%1000);
        buscarid = buscar_id(i, raiz);
        //printf("%d\n", rand());
    }
    //getch();
    return i;
}

void add_encomenda(int id){



    encomenda* novo = (encomenda*)malloc(sizeof(encomenda));



    printf("Digite o nome do aluno: ");
    scanf(" %50[^\n]s", novo->aluno);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo->matricula);

    printf("De mais detalhes sobre a obra: ");
    scanf(" %200[^\n]s", novo->detalhes);

    novo->id = id;
    novo->esq = NULL;
    novo->dir = NULL;

    encomenda* aux = busca(id,raiz);

    
    if(aux == NULL){
        raiz = novo;
    }else{

        if(id == aux->id){
            printf("Insercao Invalida, tente novamente.\n");
        }
        
        else if(id < aux->id){
            aux->esq = novo;
        }

        else if(id > aux->id){
            aux->dir = novo;
        }
    }

}


void visualizar_in_ordem(encomenda* aux){

    if(aux->esq != NULL){
        visualizar_in_ordem(aux->esq);
    }

    printf("\n");
    printf("ID: %d\n", aux->id);
    printf("Aluno: %s\n", aux->aluno);
    printf("Matricula: %d\n", aux->matricula);
    printf("Detalhes: %s\n", aux->detalhes);

    if(aux->dir != NULL){
        visualizar_in_ordem(aux->dir);
    }

}


encomenda* remover_encomenda(int id, encomenda* aux, char* nome_responsavel){

    if(aux == NULL){
        return NULL;
    }

    else{
        if(id < aux->id){
        aux->esq = remover_encomenda(id, aux->esq, nome_responsavel);
        }

        else if(id > aux->id){
        aux->dir = remover_encomenda(id, aux->dir, nome_responsavel);
        }
        else{

            add_na_fila(aux->id, aux->matricula, aux->aluno, aux->detalhes, nome_responsavel);

            if(aux->esq == NULL && aux->dir == NULL){ //folha
                aux = NULL;
            }
            else if(aux -> esq != NULL && aux->dir != NULL){ //2 filho
                encomenda* aux2 = aux->esq;

                while(aux2->dir != NULL){
                    aux2 = aux2->dir;
                }

                aux->id = aux2->id;
                aux2->id = id;
                aux->esq = remover_encomenda(id, aux->esq, nome_responsavel);
            }

            else{ // 1 filho
                if(id < aux->id){
                aux->esq = remover_encomenda(id, aux->esq, nome_responsavel);
                }

                else if(id > aux->id){
                    aux->dir = remover_encomenda(id, aux->dir, nome_responsavel);
                }
                

            }
        }
        return aux;
    }
}