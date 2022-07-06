#include "add_na_lista.h"
void remover_na_fila(){
    pedido * lixo = inicio_f;
    printf("\n\nIdentificador: %d", lixo -> identificador);
    printf("\nNome do aulo: %s", lixo -> nome_do_aluno);
    printf("\nMatricula: %d", lixo -> matricula);
    printf("\nNome do responsavel: %s", lixo -> nome_resposavel);
    printf("\nDetalhe do livro: %s", lixo -> detalhe);
    printf("\nCampus onde esta o livro: %s", lixo -> campus_onde_esta_o_livro);
    printf("\nCampus onde esta o aluno: %s", lixo -> campus_onde_esta_o_aluno);
    printf("\nNivel de prioridade: %d", lixo -> nivel_prioridade);
    inicio_f = inicio_f -> prox;
    free(lixo);
    tam--;
}