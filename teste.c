#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void exibirMenu() {
    printf("Selecione uma opcao:\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no fim\n");
    printf("3. Inserir em uma posicao\n");
    printf("4. Ordenar a lista\n");
    printf("5. Inserir em ordem\n");
    printf("6. Exibir lista\n");
    printf("7. Exibir lista reversa\n");
    printf("8. Remover do inicio\n");
    printf("9. Remover do fim\n");
    printf("10. Remover de uma posicao\n");
    printf("11. Remover por valor\n");
    printf("12. Procurar valor na lista\n");
    printf("13. Calcular somatorio\n");
    printf("14. Obter tamanho da lista\n");
    printf("15. Elevar lista ao quadrado\n");
    printf("Opcao: ");
}

int main() {
    // DECLARAÇÃO DAS LISTAS
    struct lista l1;
    inicializar(&l1);

    int opcao, valor, posicao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido no inicio: ");
                scanf("%d", &valor);
                if (inserir_inicio(&l1, valor)) {
                    printf("Valor inserido no inicio da lista.\n");
                } else {
                    printf("A lista esta cheia. Nao foi possivel inserir.\n");
                }
                break;

            case 2:
                printf("Digite o valor a ser inserido no fim: ");
                scanf("%d", &valor);
                if (inserir_fim(&l1, valor)) {
                    printf("Valor inserido no fim da lista.\n");
                } else {
                    printf("A lista esta cheia. Nao foi possivel inserir.\n");
                }
                break;

            case 3:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                if (inserir_posicao(&l1, valor, posicao)) {
                    printf("Valor inserido na posicao %d da lista.\n", posicao);
                } else {
                    printf("Posicao invalida. Nao foi possivel inserir.\n");
                }
                break;

            case 4:
                ordenar(&l1);
                printf("Lista ordenada.\n");
                break;

            case 5:
                printf("Digite o valor a ser inserido em ordem: ");
                scanf("%d", &valor);
                if (inserir_ordem(&l1, valor)) {
                    printf("Valor inserido em ordem na lista.\n");
                } else {
                    printf("A lista esta cheia. Nao foi possivel inserir.\n");
                }
                break;

            case 6:
                printf("Lista:\n");
                exibir_lista(&l1);
                break;

            case 7:
                printf("Lista reversa:\n");
                exibir_reversa(&l1);
                break;

            case 8:
                if (remover_inicio(&l1)) {
                    printf("Elemento removido do inicio da lista.\n");
                } else {
                    printf("A lista esta vazia. Nao foi possivel remover.\n");
                }
                break;

            case 9:
                if (remover_fim(&l1)) {
                    printf("Elemento removido do fim da lista.\n");
                } else {
                    printf("A lista esta vazia. Nao foi possivel remover.\n");
                }
                break;

            case 10:
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                if (remover_posicao(&l1, posicao)) {
                    printf("Elemento removido da posicao %d da lista.\n", posicao);
                } else {
                    printf("Posicao invalida. Nao foi possivel remover.\n");
                }
                break;

            case 11:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                if (remover_valor(&l1, valor)) {
                    printf("Elemento %d removido da lista.\n", valor);
                } else {
                    printf("Elemento nao encontrado. Nao foi possivel remover.\n");
                }
                break;

            case 12:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                posicao = procurar(&l1, valor);
                if (posicao != -1) {
                    printf("O valor %d esta na posição %d da lista.\n", valor, posicao);
                } else {
                    printf("O valor %d nao foi encontrado na lista.\n", valor);
                }
                break;

            case 13:
                printf("Somatorio: %d\n", somatorio(&l1));
                break;

            case 14:
                printf("Tamanho da lista: %d\n", tamanho(&l1));
                break;

            case 15:
                quadrado_da_lista(&l1);
                printf("Lista elevada ao quadrado.\n");
                break;
            
            
            exit(0);

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
