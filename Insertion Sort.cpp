#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CHAMADA DA FUNÇÃO
void ImprimirVetor(int *vet, int tamanho);
//---------------------------------------------
void OrdenarInsertion(int *vet, int tamanho);
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

    for (z = 0; z < numeros; z++) VInsertion[z] = vet[z];
    OrdenarInsertion(VInsertion, numeros); 
    printf("\nVetor ordenado (Insertion Sort): ");
    ImprimirVetor(VInsertion, numeros);  						// Ordena e imprime Insertion Sort
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

void OrdenarInsertion(int *vet, int tamanho) { 		//Função para ordenar por Insertion Sort
    int z, w, chaves;
	for (z = 1; z < tamanho; z++) {
        chaves = vet[z];
        w = z - 1;
        while (w >= 0 && vet[w] > chaves) {
            vet[w + 1] = vet[w];
            w--;
        }
        vet[w + 1] = chaves;
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
