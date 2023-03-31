#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	
	if (primeiro == NULL) {// se não a nada! qualquer um será o primeiro.
		primeiro = novo;
	}
	else if (primeiro->valor > novo->valor) { // verifica se o o primeiro elemente da lista atual é o primeiro.
		NO* aux = primeiro;
		primeiro = novo;
		novo->prox = aux;
	}
	/* else { adiciona o novo elemento de forma ordenada na lista.  *logica do pimenta*
		NO* aux = primeiro;
		while (aux->prox != NULL && novo->valor > aux->prox->valor) {		leg:
			aux = aux->prox;						&& = E
		}									|| = Ou
		novo->prox = aux->prox;
		aux->prox = novo;
	}*/
	else { //metodo claudio
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			if (aux->prox->valor > novo->valor) {
				break;
			} 
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void excluirElemento() /* para a explicação da função, vá para o fim do codigo*/
{
	NO* deletar = (NO*)malloc(sizeof(NO));
	cout << "Digite o numero a ser excluido:" << endl;
	cin >> deletar->valor;
	deletar->prox = NULL;
	if (primeiro == NULL) {
		cout << "Lista vazia";
	}
	else if (deletar == primeiro) {
		primeiro = primeiro->prox; /*primeiro passará a ser o proximo do primeiro, que no caso é NULL*/
		free(deletar); /*free é usado para liberar o espaço ocupado na memoria pelo ponteiro*/
	}
	else { /*deletar != primero */
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			if (aux->prox->valor == deletar->valor) {
				aux->prox = aux->prox->prox;
				free(deletar);
				break;
			}
		}
	}
}

void buscarElemento() {
    NO* busca = (NO*)malloc(sizeof(NO));
    cout << "Buscar: " << endl;
    cin >> busca->valor;
    busca->prox = NULL;
    
    if (primeiro == NULL) {
        cout << "Lista vazia!" << endl;
    }
    else {
        NO* aux = primeiro;
        int cont = 0;
        while (aux != NULL) {
            if (aux->valor == busca->valor) {
                cont++;
            }
            aux = aux->prox;
        }
        if (cont > 0) {
            cout << "Elemento encontrado " << cont << " vezes." << endl;
        }
        else {
            cout << "Numero nao encontrado." << endl;
        }
    }
    
    free(busca);
}


/*A função começa criando um novo nó deletar com o valor a ser excluído e apontando seu ponteiro prox para NULL.
Em seguida, a função verifica se a lista está vazia. Se estiver vazia, a função imprime "Lista vazia".

Se a lista não estiver vazia, a função verifica se o nó a ser excluído é a cabeça da lista (deletar == primeiro).

Se for, a função atualiza primeiro para apontar para o próximo elemento da lista e libera a memória alocada para o nó deletar usando "free()".

Se o nó a ser excluído não for a cabeça da lista, a função percorre a lista com um ponteiro "aux" e verifica se o próximo nó em relação a "aux" tem o valor a ser excluído.
Se tiver, a função atualiza o ponteiro prox de aux para pular o nó a ser excluído e libera a memória alocada para o nó deletar usando "free()".

Note que a função percorre a lista enquanto "aux->prox != NULL".*/
