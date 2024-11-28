#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CHAMADA DA FUNÇÃO
void ImprimirVetor(int *vet, int tamanho);
//---------------------------------------------
void OrdenarSelection(int *vet, int tamanho);
//---------------------------------------------
void GerarAleatorios(int *vet, int numeros);
//---------------------------------------------

int main() {
	int numeros = 15, z; 
    int vet[numeros];
    int VSelection[numeros], VInsertion[numeros], VBubble[numeros];	//Criação das variáveis para receber os vetores ordenados

    for (z = 0; z < numeros; z++) {
        vet[z] = z;
    }

    srand(time(NULL));
    GerarAleatorios(vet, numeros);  							// Gera números aleatórios inicialmente
    
    printf("\nNumeros aleatorios: ");
    ImprimirVetor(vet, numeros);  								// Imprime os números aleatórios gerados
    
    //---------------------------------------------------
	for (z = 0; z < numeros; z++) VSelection[z] = vet[z];
	OrdenarSelection(VSelection, numeros);
	printf("\nVetor ordenado (Selection Sort): ");
	ImprimirVetor(VSelection, numeros);  						// Ordena e imprime Selection Sort
    //---------------------------------------------------

	return 0;
}

void ImprimirVetor(int *vet, int tamanho) { 		//Função para imprimir o vetor
    int z;
	for (z = 0; z < tamanho; z++) {
        printf(" %d |", vet[z]);
    }
    printf("\n");
}

void OrdenarSelection(int *vet, int tamanho) { 		//Função para ordenar por Selection Sort
    int z, w, temp, numIndex;
	for (z = 0; z < tamanho - 1; z++) {
        numIndex = z;								
        for (w = z + 1; w < tamanho; w++) {
            if (vet[w] < vet[numIndex]) {
                numIndex = w;
            }
        }
        temp = vet[numIndex];
        vet[numIndex] = vet[z];
        vet[z] = temp;
    }
}

void GerarAleatorios(int *vet, int numeros) {		//Função para gerar números aleatórios e não repetidos
    int z, w, temp;
	for (z = numeros - 1; z > 0; z--) {
        w = rand() % (z + 1);  		
        temp = vet[z];
        vet[z] = vet[w];
        vet[w] = temp;
    }
}
