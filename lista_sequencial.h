#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 1000

struct lista{
        int elementos[MAX];
        int particao;
};

void inicializar(struct lista *l);

int inserir_inicio(struct lista *l, int valor);
int inserir_fim(struct lista *l, int valor);
int inserir_posicao(struct lista *l, int valor, int posicao);

void ordenar(struct lista *l);
int inserir_ordem(struct lista *l, int valor);

void exibir_lista(struct lista *l);
int concatenar(struct lista *l1, struct lista *l2);

void exibir_reversa(struct lista *l);

int remover_inicio(struct lista *l);
int remover_fim(struct lista *l);
int remover_posicao(struct lista *l, int posicao);
int remover_valor(struct lista *l, int valor);

int procurar(struct lista *l, int n);

int somatorio(struct lista *l);

int tamanho(struct lista *l);

void quadrado_da_lista(struct lista *l);

int contar_primos(struct lista *l);

#endif
