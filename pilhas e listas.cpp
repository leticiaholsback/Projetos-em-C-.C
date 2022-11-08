// fila acrescenta no final e remove no inicio, pilha acrescenta no inicio retira do fim
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct STACK
{
	int dado;
	STACK* prox;
}*top = NULL;

void push(int value);
void pop();
void display(); 

int main()
{
	int op, value, c;

	while (1) {
		system("cls");
		printf("\n-*-*-*-*- MENU DAS PILHAS DA LETICIA -*-*-*-*-*-\n");
		printf("1. Empilhar(Push)\n2. Desempilhar(Pop)\n3. Listar\n4. Sair\n");

		printf("Escolha a sua opcao: ");
		scanf_s("%d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {}

		switch (op) {
		case 1: //empilhar
			printf("Digite um valor para ser inserido: ");
			scanf_s("%d", &value);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpeza de buufer de teclado
			push(value); //empilha
			break;
		case 2:
			pop(); //desempilha
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("\nDigite outra opcao.\n");
		}
	}

	system("pause");
	return 0;

}
void push(int value)// empilhar
{
	STACK *NovoElemento; // stack é uma struct
	NovoElemento = (struct STACK*)malloc(sizeof(struct STACK));
	NovoElemento->dado = value;

	if (top == NULL) // insercao no inicio, como se fosse o head, acima do head
		NovoElemento->prox = NULL;
	else
		NovoElemento->prox = top;
	top = NovoElemento;
	printf("\nInserido certinho.\n");
}
void pop() //desempilhar oque esta no topo
{
	if (top == NULL)
		printf("\nPilha vazia, nao tem nada.\n");
	else {
		STACK *temp = top;
		printf("\nElemento Deletado, voce excluiu o elemento escolhido: %d", temp->dado);
		top = temp->prox;
		free(temp); // limpando variavel da memória
	}
	printf("\n");
	system("pause");
}
void display() // ela passa elemento por elemento e escreve na tela
{
	STACK* ElementoVarredura = top;

	if (top == NULL)
		printf("\nPilha vazia!!!\n");
	else {

		while (ElementoVarredura->prox != NULL)
		{
			printf("%d\n", ElementoVarredura->dado);
			ElementoVarredura = ElementoVarredura->prox;
		}
		printf("%d\n", ElementoVarredura->dado);
	}
	system("pause");

} 