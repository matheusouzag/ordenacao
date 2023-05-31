#include "selecao.h"
#include <stdio.h>
#include <stdlib.h>

int geraAleatorios(char *nomeArquivo, int qtd, int semente)
{
    int i, *p;
    p = NULL;
    FILE *arq;
    srand(semente);

    p = (int *)(malloc(qtd * sizeof(int)));

    // Caso não de certo a alocação
    if (p == NULL)
    {
        return 1;
    }

    arq = fopen(nomeArquivo, "w");

    if (arq == NULL)
    {
        printf("Erro de abertura!");
    }

    fprintf(arq, "%d\n", qtd);
    // Recebendo dados aleatórios para o vetor
    for (i = 0; i < qtd; i++)
    {
        fprintf(arq, "%d ", rand() % 1000);
    }
    fclose(arq);

    return 0;
}
// Esta função gera 'qtd' números aleatórios e os escreve no arquivo 'nomeArquivo'
// Os numeros devem variar entre 0 e 1000 e devem ser inicializados com a semente
// A função retorna 0 se funcionou corretamente. Retorna 1 se houve algum erro no processo.
// Pesquisem pelas funções rand() e srand().

int *leArquivo(char *nomeArquivo, int qtd)
{
    int i, *p;
    FILE *arq;
    arq = fopen(nomeArquivo, "r");

    fscanf(arq, "%d\n", &qtd);

    p = (int *)malloc(qtd * sizeof(int));

    if (qtd == 0)
    {
        return NULL;
    }

    for (i = 0; i <= qtd; i++)
    {
        fscanf(arq, "%d\n", &p[i]);
    }

    return p;
}
// Esta função lê 'qtd' dados do arquivo 'nomeArquivo' e os insere em um vetor de inteiros
// A função retorna NULL caso haja algum erro no processo.

void selecao(int *vet, int tam)
{
    int marc = 0;
    int menor;
    int aux;

    while (marc < tam - 1)
    {

        menor = marc + 1;
        for (int i = marc + 2; i < tam; i++)
        {
            if (vet[i] < vet[menor])
            {
                menor = i;
            }
        }
        if (vet[menor] < vet[marc])
        {
            aux = vet[menor];
            vet[menor] = vet[marc];
            vet[marc] = aux;
        }
        marc++;
    }
}
// Esta função recebe um vetor de inteiros de tamanho 'tam' e o ordena (ordem crescente) utilizando o método seleção

void insercao(int *vet, int tam)
{
    int marc;
    int aux;
    int pos;

    for (marc = 1; marc < tam; marc++)
    {
        pos = marc - 1;
        aux = vet[marc];
        while ((aux < vet[pos]) && (pos >= 0))
        {
            vet[pos + 1] = vet[pos];
            pos = pos - 1;
        }
        vet[pos + 1] = aux;
    }
}
// Esta função recebe um vetor de inteiros de tamanho 'tam' e o ordena utilizando o método insercao

void buscaBinaria(int *vet, int inicio, int fim, int valor, int *res)
{

    int meio;

    res[1]++; // Incrementa chamada

    if (inicio > fim)
    {
        res[0] = 0;
        return;
    }

    meio = (inicio + fim) / 2;

    if (vet[meio] == valor)
    {
        res[0] = 1; // Encontrado
        return;
    }
    else if (vet[meio] < valor)
    {
        buscaBinaria(vet, meio + 1, fim, valor, res);
    }
    else
    {
        buscaBinaria(vet, inicio, meio - 1, valor, res);
    }
}
// Esta função implementa a busca binária e sua saída é salva no vetor res
// res[0] recebe 1 se encontrou o elemento buscado e 0 caso contrário
// res[1] informa quantas vezes a função buscaBinaria foi chamada, uma vez que ela é recursiva
// ou seja, sempre que a função é chamada res[1] é incrementado

void imprimeVet(int *vet, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
// Esta função recebe um vetor e o imprime na tela
// A impressão é em linha -> printf("%d ", ...);
// Antes de encerrar, a função imprime uma linha em branco
