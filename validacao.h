#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "add_na_lista.h"
#include "encomenda.h"

void trabalhadores_pre_cadastrados(){
    
    //Secretários Pré-Cadastrados
    add_usuario("Jorge", 's', 1111, 1234);
    add_usuario("Gabriela", 's', 2222, 1324);
    add_usuario("Renni", 's', 3333, 4132);

    //Tranportadores Pré-Cadastrados
    add_usuario("Leo", 't', 4444, 2845);
    add_usuario("Eduarda", 't', 5555, 4815);
    add_usuario("Mateus", 't', 6676, 2795);
    add_usuario("Joao", 't', 4594, 2345);
    add_usuario("Marcos", 't', 4784, 2961);
}

int validacao(int cpf, int senha, int tipo){
    usuario * aux = inicio;
    while (aux -> cpf != cpf){
        aux = aux -> prox;
    }
    if ((aux->cpf == cpf) && (aux -> tipo == tipo)){
        if (aux -> senha == senha){
            printf("SENHA CORRETA");
            int editar;
            visualizar_in_ordem(raiz);
            printf("QUAL IRA EDITAR: ");
            scanf("%d", &editar);

            add_na_lista(editar, raiz);
            raiz = remover_encomenda(raiz, editar); 
            
            char *nome_responsavel;
            return nome_responsavel = aux->nome;
        }else{
            printf("SENHA INCORRETA");
        }
    }else{
        if ((aux -> cpf == cpf) && (aux -> tipo == tipo)){
            if (aux -> senha == senha){
                printf("SENHA CORRETA");
                remover_na_fila();      
            }else{
                printf("SENHA INCORRETA");
            } 
        }
    }
}