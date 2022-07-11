#include <stdio.h>
#include <stdlib.h>

typedef struct usuario{

    char* nome;
    char tipo;
    int cpf;
    int senha;

    struct usuario* prox;

}usuario;


usuario* inicio = NULL;
int tamanho = 0;

void add_usuario(char * nome, char tipo, int cpf, int senha){

    usuario* novo = (usuario*)malloc(sizeof(usuario));
    novo->nome = nome;
    novo->tipo = tipo;
    novo->cpf = cpf;
    novo->senha = senha;
    novo->prox = NULL;

    if(inicio == NULL){
        inicio = novo;
    }else{
        novo->prox = inicio;
        inicio = novo;
    }
    tamanho++;
}