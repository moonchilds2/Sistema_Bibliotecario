#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "encomenda.h"

void trabalhadores_pre_cadastrados(){
    
    //Secretários Pré-Cadastrados
    add_usuario("Jorge", 's', 1111, 1234);
    add_usuario("Gabriela", 's', 2222, 1324);
    add_usuario("Rennis", 's', 3333, 4132);

    //Tranportadores Pré-Cadastrados
    add_usuario("Leo", 't', 4444, 2845);
    add_usuario("Eduarda", 't', 5555, 4815);
    add_usuario("Mateus", 't', 6676, 2795);
    add_usuario("Joao", 't', 4594, 2345);
    add_usuario("Marcos", 't', 4784, 2961);
    //imprimir_usuarios();
}

void validacao(){
    usuario * aux = inicio;
    int cpf, senha;
    
    printf("Digite o cpf: ");
    scanf("%d", &cpf);
    printf("Digite a senha: ");
    scanf("%d", &senha);
    
    
    while (aux != NULL && aux -> cpf != cpf){
        aux = aux -> prox;
    }
    
    if(aux != NULL){
        if ((aux->cpf == cpf) && (aux -> tipo == 's')){
            if (aux -> senha == senha){
                printf("\nSENHA CORRETA\n");
                printf("Encomendas existentes: \n");
                int editar;
                visualizar_in_ordem(raiz);
                printf("\nDigite o ID da encomenda a ser removida: ");
                scanf("%d", &editar);

                raiz = remover_encomenda(editar, raiz, aux->nome);
            
            }else{
                printf("Insercao invalida, tente novamente.\n");
            }
        }else if ((aux->cpf == cpf) && (aux->tipo == 't')){
            if (aux->senha == senha){
                printf("SENHA CORRETA\n");
                printf("\nPedido a ser removido:");
                remover_fila();
                printf("\n\nPedido removido com sucesso!\n\n");
            }else{
                printf("Insercao invalida, tente novamente\n");
            }
        }
    }
}
