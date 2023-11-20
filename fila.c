#include <stdio.h>
#include <stdlib.h>

struct pessoa
{
    int senha;
    struct pessoa *prox;
};

typedef struct pessoa Pessoa;

Pessoa *primeiroElemento;

// Só se pode adicionar no final em uma fila
void add(int senha)
{
    Pessoa *p = malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if (primeiroElemento == NULL)
    {
        primeiroElemento = p;
    }
    else
    {
        Pessoa *filaAux = primeiroElemento;
        while (filaAux->prox != NULL)
        {
            filaAux = filaAux->prox;
        }
        filaAux->prox = p;
    }
}

void removeElement()
{
    if (primeiroElemento == NULL)
    {
        printf("Fila vazia!");
    }
    else
    {
        Pessoa *aux = primeiroElemento;
        primeiroElemento = primeiroElemento->prox;
        free(aux);
    }
}

void imprime(Pessoa *f)
{
    if (f != NULL)
    {
        printf("\nSenha da Pessoa: %d", f->senha);
        imprime(f->prox);
    }
}

int main()
{
    primeiroElemento = NULL;

    add(583484);
    add(457324);
    add(10);
    add(5637);
    add(10);

    Pessoa *filaAux = primeiroElemento;
    imprime(filaAux);

    removeElement();
    printf("\n");

    filaAux = primeiroElemento; // Atualize filaAux após a remoção
    imprime(filaAux);

    return 0;
}