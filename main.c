#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"

int main(){
    trabalhadores_pre_cadastrados();
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
            add_encomenda(idaleatorio());
        }else if(resp == 2){
            validacao();
        }else if(resp == 3){               
            validacao();
        }
    }
    
    return 0;
}
