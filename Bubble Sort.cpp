
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CHAMADA DA FUN��O
void ImprimirVetor(int *vet, int tamanho);
//---------------------------------------------
void OrdenarBubble(int *vet, int tamanho);
//---------------------------------------------
void GerarAleatorios(int *vet, int numeros);
//---------------------------------------------

int main() {
	int numeros = 15, z; 
    int vet[numeros];
    int VSelection[numeros], VInsertion[numeros], VBubble[numeros];  //Cria��o das vari�veis para receber os  vetores ordenados                  

    for (z = 0; z < numeros; z++) {
        vet[z] = z;						
    }

    srand(time(NULL));
    GerarAleatorios(vet, numeros);  		// Gera n�meros aleat�rios inicialmente
    printf("\n Numeros aleatorios: \n");
    ImprimirVetor(vet, numeros);  			// Imprime os n�meros aleat�rios gerados
    
    //---------------------------------------------------
	for (z = 0; z < numeros; z++) VBubble[z] = vet[z]; 
	OrdenarBubble(VBubble, numeros);				
	printf("\nVetor ordenado (Bubble Sort): ");
	ImprimirVetor(VBubble, numeros);  				// Ordena e imprime Bubble Sort
    //---------------------------------------------------

	return 0;
}

void ImprimirVetor(int *vet, int tamanho) { 		//Fun��o para imprimir o vetor
    int z;
	for (z = 0; z < tamanho; z++) {
        printf(" %d | ", vet[z]);
    }
    printf("\n");
}

void OrdenarBubble(int *vet, int tamanho) { 		//Fun��o para ordenar por Bubble Sort
    int z, w, temp;
	for (z = 0; z < tamanho - 1; z++) {
        for (w = 0; w < tamanho - z - 1; w++) {
            if (vet[w] > vet[w + 1]) {
                temp = vet[w];
                vet[w] = vet[w + 1];
                vet[w + 1] = temp;
            }
        }
    }
}
void GerarAleatorios(int *vet, int numeros) {		//Fun��o para gerar n�meros aleat�rios e n�o repetidos
    int z, w, temp;
	for (z = numeros - 1; z > 0; z--) {
        w = rand() % (z + 1);  		
        temp = vet[z];
        vet[z] = vet[w];
        vet[w] = temp;
    }
}


