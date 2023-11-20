#include <stdio.h>
#include <stdlib.h>

struct prato
{
    char cor;
    struct prato *prox;
};

typedef struct prato Prato;

Prato *topo = NULL;

void add(char cor)
{
    Prato *p = (Prato *)malloc(sizeof(Prato));
    if (p == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    p->cor = cor;
    p->prox = topo;
    topo = p;
}

void rem()
{
    if (topo == NULL)
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        Prato *temp = topo;
        topo = topo->prox;
        free(temp);
    }
}

void imprime(Prato *p)
{
    if (p != NULL)
    {
        printf("\nCor do prato: %c", p->cor);
        imprime(p->prox);
    }
}

int main()
{
    // Exemplo de uso:
    add('A');
    add('B');
    add('C');

    printf("Pilha antes da remocao:\n");
    imprime(topo);

    rem();

    printf("\nPilha apos a remocao:\n");
    imprime(topo);

    return 0;
}
