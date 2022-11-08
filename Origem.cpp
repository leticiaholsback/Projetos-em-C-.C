#include<stdio.h>
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void InserirFim(int num);
void InserirMeio(int num, int posicao);
int Remover(int num);
void Listar();

struct ElementoDaLista_Simples {
	int dado;
	ElementoDaLista_Simples *prox; //* indicaa inicializacao de uma variavel tipo ponteiro
} *Head; // variavel global

int main()
{
	int op, num, pos, c;
	while (1) {
		op = menu();
		switch (op) {
		case 1: // inserir no inicio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			InserirInicio(num);
			break;
		case 2: // inserir no fuim da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			InserirFim(num);
			break;
		case 3: // inserir no meio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num); 
			while ((c = getchar()) != '\n' && c != EOF) {} // buffer de limpeza de teclado, usar apos cada scanf
			printf("Digite a posicao desejada: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // buffer de limpeza de teclado, usar apos cada scanf
			InserirMeio(num, pos);
			break;
		case 4: // remover da lista
			int res;
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 5: // mostrar toda a lista
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido/n");
		}
	}
	return 0;
}

int menu() {
	int op, c;
	system("C1s");

	printf("1. Inserir no INICIO da lista encadeada simples\n");
	printf("2. Inserir no FIM da lista encadeada simples\n");
	printf("3. Inserir no MEIO da lista encadeada simples\n");
	printf("4. REMOVER da lista encadeada simples\n");
	printf("5. MOSTRAR lista encadeada simples\n");
	printf("6. SAIR da lista\n");
	printf("Digite sua escolha:\n");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}

	system("C1s");
	return op;
}

void InserirInicio(int num) // lista simples nao cuircular
{
	ElementoDaLista_Simples *NovoElemento;
	//alocar o elemento na memria
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	NovoElemento->dado = num; // num vai para NovoElemento dado

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}
void InserirFim(int num)  // lista FIM
{
	ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));

	NovoElemento->dado = num;
	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;

	}
	else
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL) // != (( diferente))
			ElementoVarredura = ElementoVarredura->prox; //transforma o elemento em proximo elemento da lista encadeada

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}
void InserirMeio(int num, int posicao) // lista MEIO
{
	ElementoDaLista_Simples *NovoElemento;
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples *ElementoAuxiliar;
	ElementoAuxiliar = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples));
	
	 NovoElemento->dado = num;
	if (posicao == 0) 
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}
int Remover(int num) //Lista 4. REMOVER
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));
	ElementoDaLista_Simples* Anterior;
	Anterior = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

void Listar()  // Lista 5. Mostrar
{
	ElementoDaLista_Simples* ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples*)malloc(sizeof(struct ElementoDaLista_Simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d", ElementoVarredura->dado);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}

