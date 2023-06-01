#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

int main(int argc, char *argv) {

    //DECLARAÇÃO DA LISTA
    struct lista *l1, *l2;
    l1 = (struct lista *) malloc(sizeof(struct lista));
    l2 = (struct lista *) malloc(sizeof(struct lista));
    
    //INICIALIZAÇÃO 
    inicializar(l1);
    inicializar(l2);

    //INSERÇÃO (QUESTÃO 1, 2, 3 e 4)
    inserir_fim(l1, 10);
    inserir_fim(l1, 15);
    inserir_fim(l1, 20);
    inserir_inicio(l1, 7);

    inserir_fim(l2, 11);
    inserir_fim(l2, 12);

    concatenar(l2, l1);
    exibir_lista(l2);
    
    inserir_posicao(l2, 2, 0);
    inserir_ordem(l2, 9);
    
    //EXIBIÇÃO (QUESTÃO 5 e 6)
    exibir_lista(l2);
    exibir_reversa(l2);
    
    //REMOÇÃO (QUESTÃO 7, 8, 9 e 10)
    remover_inicio(l2);
    exibir_lista(l2);

    remover_fim(l2);
    exibir_lista(l2);

    remover_posicao(l2, 1);
    exibir_lista(l2);

    remover_valor(l2, 11);
    exibir_lista(l2);

    //BUSCA (QUESTÃO 11)
    int posicao = procurar(l2, 7);
    printf("O valor informado esta na posicao %d da lista.\n", posicao);

    //SOMATÓRIO (QUESTÃO 12)
    somatorio(l2);
    
    //TAMANHO (QUESTÃO 13)
    tamanho(l2);

    //ELEVAÇÃO DE LISTA ATUAL AO QUADRADO (QUESTÃO 14)
    quadrado_da_lista(l2);
    exibir_lista(l2);
     
    //QUANTIDADE DE NÚMERO PRIMOS NA LISTA (QUESTÃO 15)
    inserir_inicio(l2, 7); //INSERINDO UM NÚMERO PRIMO NA LISTA PARA TESTAR A FUNÇÃO
    exibir_lista(l2); //EXIBINDO A LISTA COM ATUAL COM A INSERÇÃO DE UM NÚMERO PRIMO
    contar_primos(l2); //TESTANDO A FUNÇÃO QUE DEVE RETORNAR "1" COMO QUANTIDADE DE NÚMEROS PRIMOS

    //ENCERRAMENTO DO PROGRAMA (QUESTÃO 16)
    exit(0);
}
