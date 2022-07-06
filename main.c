#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "fila_add_remover.h.h"
#include "encomenda.h"
#include "remover_na_lista.h"
#include "validacao.h"

int main(){
    printf("\nSISTEMA DE ENCOMENDA DE LIVRO\n");
    int resp = -1;
    while(resp != 0){
        printf(" 1 - Encomendar um livro.\n");
        printf(" 2 - Remover uma encomenda de livro.\n");
        printf(" 3 - Remover um pedido de livro.\n");
        printf(" 0 - Sair do sistema!\n");
        printf("Digite a funcionalidade desejada:");
        scanf("%d", &resp);
        if(resp == 1){
            add_encomenda();
        }else if(resp == 2){
            int retorno = verificar(cpf, senha); //verificar cpf e senha do secretario
            remover_encomenda(); // chamar a funcao para REMOVER A ENCOMENDA se nao REMOVER PEDIDO
            if(retorno == 1){
                remover_encomenda();
                add_dados();
                add_fila();
            }else if(resp == 3){               
                //verificar_usuario();
                    printf(" Digite seu cpf:\n");
                    char cpf[100];
                    scanf("%s", &cpf);
                    printf(" Digite sua senha:\n");
                    char senha[100];
                    scanf("%s", &senha);
                    //int retorno = verificar(cpf, senha);
                    if(retorno == 1){
                        remover_fila();
                        //remover da fila de prioridade
                    }
            }
        
        }*/
        
    }
    
    return 0;
}
Footer
