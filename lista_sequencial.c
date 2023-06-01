#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

#define MAX 1000



void inicializar(struct lista *l) {
    l->particao = 0;
}


//INSERÇÕES (QUESTÃO 1, 2, 3 e 4):

int inserir_inicio(struct lista *l, int valor) {
    //movimentação de todos os valores para a direita
    //repetição do fim para o início
    int i;
    if(l->particao < MAX) {
        for(i=l->particao; i >0; i--) {
        l->elementos[i] = l->elementos[i-1];
        }

        l->elementos[0] = valor;
        l->particao++;

        return 1;
    } else {
        return 0;
    }
}

int inserir_fim(struct lista *l, int valor) {
    if(l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    } else {
        return 0;
    }
}

int inserir_posicao(struct lista *l, int valor, int posicao) {
     if (posicao < 0 || posicao >= l->particao)
        return 0; // Posição inválida

    if (l->particao == MAX)
        return 0; // Lista cheia

    // Deslocar os elementos à direita a partir da posição indicada
    for (int i = l->particao; i > posicao; i--) {
        l->elementos[i] = l->elementos[i - 1];
    }

    l->elementos[posicao] = valor;
    l->particao++;
    return 1; // Inserção bem-sucedida
}

void ordenar(struct lista *l) {
    // Utilizando o algoritmo de ordenação bubble sort
    for (int i = 0; i < l->particao - 1; i++) {
        for (int j = 0; j < l->particao - i - 1; j++) {
            if (l->elementos[j] > l->elementos[j + 1]) {
                int temp = l->elementos[j];
                l->elementos[j] = l->elementos[j + 1];
                l->elementos[j + 1] = temp;
            }
        }
    }
}

int inserir_ordem(struct lista *l, int valor) {
    if (l->particao < MAX) {
        l->elementos[l->particao] = valor;
        l->particao++;

        // Ordenando a lista após a inserção
        for (int i = 0; i < l->particao - 1; i++) {
            for (int j = i + 1; j < l->particao; j++) {
                if (l->elementos[i] > l->elementos[j]) {
                    int temp = l->elementos[i];
                    l->elementos[i] = l->elementos[j];
                    l->elementos[j] = temp;
                }
            }
        }

        return 1; // Sucesso ao inserir o valor
    } else {
        return 0; // Falha ao inserir o valor (lista cheia)
    }
}


//EXIBIÇÕES (QUESTÃO 5 e 6):

void exibir_lista(struct lista *l){
    int i;
    for(i=0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int concatenar(struct lista *l1, struct lista *l2){
    int i;
    if(l1->particao + l2->particao < MAX) {
        for(i=0; i < l2->particao; i++) {
            inserir_fim(l1, l2->elementos[i]);
        }
        return 1;
    } else {
        return 0;
    }
}

void exibir_reversa(struct lista *l) {
    int i;
    for(i = l->particao - 1; i >= 0; i--) {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}


//REMOÇÕES (QUESTÃO 7, 8, 9 e 10):

int remover_inicio(struct lista *l) {
    if (l->particao > 0) {
        // Deslocar os elementos para a esquerda
        for (int i = 1; i < l->particao; i++) {
            l->elementos[i - 1] = l->elementos[i];
        }

        l->particao--;

        return 1; // Sucesso ao remover o primeiro elemento
    } else {
        return 0; // Falha ao remover primeiro elemento (lista vazia)
    }
}

int remover_fim(struct lista *l) {
    if (l->particao > 0) {
        l->particao--;

        return 1; // Sucesso ao remover o último elemento
    } else {
        return 0; // Falha ao remover último elemento (lista vazia)
    }
}

int remover_posicao(struct lista *l, int posicao) {
    if (posicao < 0 || posicao >= l->particao)
        return 0; // Posição inválida

    // Deslocar os elementos à esquerda a partir da posição indicada
    for (int i = posicao; i < l->particao - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    l->particao--;
    return 1; // Remoção bem-sucedida
}

int remover_valor(struct lista *l, int valor) {
    int posicao = -1; // Variável para armazenar a posição do valor na lista

    // Encontrar a posição do valor na lista
    for (int i = 0; i < l->particao; i++) {
        if (l->elementos[i] == valor) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        return 0; // Valor não encontrado na lista
    }

    // Deslocar os elementos à esquerda a partir da posição indicada
    for (int i = posicao; i < l->particao - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    l->particao--;
    return 1; // Remoção bem-sucedida
}


//BUSCA (QUESTÃO 11):

int procurar(struct lista *l, int n) {
    for (int i = 0; i < l->particao; i++) {
        if (l->elementos[i] == n) {
            return i; // Retorna a posição do valor na lista
        }
    }

    return -1; // Valor não encontrado na lista
    
}


//SOMATÓRIO (QUESTÃO 12):

int somatorio(struct lista *l) {
    int somatorio = 0;

    for (int i = 0; i < l->particao; i++) {
        somatorio += l->elementos[i]; // Incrementa o valor na variável somatorio
    }
    printf("O somatorio da lista e = %d", somatorio);
    printf("\n");

}


//TAMANHO (QUESTÃO 13):

int tamanho(struct lista *l) {
   printf("O tamanho da lista e = %d", l->particao);
   printf("\n");
}


//ELEVAÇÃO DE LISTA AO QUADRADO (QUESTÃO 14):

void quadrado_da_lista(struct lista *l) {
    for (int i = 0; i < l->particao; i++) {
        l->elementos[i] = l->elementos[i] * l->elementos[i]; // Elevar ao quadrado o elemento atual
    }
}

int contar_primos(struct lista *l) {
    int quantidadePrimos = 0;
    for (int i = 0; i < l->particao; i++) {
        int numero = l->elementos[i];
        if (numero <= 1) {
            continue; // Ignora números menores ou iguais a 1
        }
        int divisores = 0;
        for (int j = 2; j <= numero / 2; j++) {
            if (numero % j == 0) {
                divisores++;
                break; // Encontrou um divisor, interrompe o loop
            }
        }
        if (divisores == 0) {
            quantidadePrimos++;
        }
    }
    printf("a quantidade de primos na lista e = %d", quantidadePrimos);
    printf("\n");;
}
