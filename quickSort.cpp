//Quick sort crescente e decrescente. A ordenaçaõ deveser feita em um valor de dimensão N (onde N é escolhido pelo usuário)
//Preencha o vetor com avalores numericos gerados aleatoriamente. Criar função separada para fazer ordenação.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//define um valor pivo, a partir do meio da posição 10 ee comparar com todoso os valores a esquerda
//e a direita, esquera menor que ele e direita maior que ele

#define TAMANHOVETOR 10

void quicksort(int vet[], int p, int u);
int particao(int vet[], int p, int u);
void troca(int vet[], int i, int j);

int main()
{
	int vet[TAMANHOVETOR] = { 0 };
	srand(time(NULL));

	//INSERÇÃO DE DADOS
	for (int i = 0; i < TAMANHOVETOR; i++)
		vet[i] = rand() % 100;

	printf("VETOR NAO ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME NÃO ORDENADO
		printf("%d\n", vet[i]);

	quicksort (vet, 0, TAMANHOVETOR -1);

	//IMPRESSÃO DE RESULTADOS
	printf("VETOR ORDENADO:\n");
	for (int i = 0; i < TAMANHOVETOR; i++) //IMPRIME ORDENADO
		printf("%d\n", vet[i]);

	system("pause");
	return 0;
}

void quicksort(int vet[], int p, int u)
{
	int m;
	if (p < u)
	{
		m = particao(vet, p, u);
		quicksort(vet, p, m); //esquerdo
		quicksort(vet, m + 1, u); //direito
	}
}
int particao (int vet[], int p, int u)
{
	int pivo, pivo_pos, i, j;

	pivo_pos = (p + u) /2;
	pivo = vet[pivo_pos];

	i = p - 1;
	j = u + 1;

	while (i < j) // laco de repeticao enquanto i for menor que j
	{
		do //testa o lado direiro
		{
			j--;
		} while (vet[j] > pivo);
		do //testa o lado esquerdo
		{
			i++;
		} while (vet[j] > pivo);

		if (i < j)
			troca(vet, i, j);
	}
	return j;
}
void troca(int vet[], int i, int j)
{
	int aux;
	aux = vet[i];
	vet [i] = vet[j];
	vet[j] = aux;
}