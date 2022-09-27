#include <stdio.h>
void zerarMat (int *vet, int tam){
	int k;
	for(k=0;k<tam;k++){
		vet[k]=0;
	}
}
void imprimir (int *vet, int tam, int col){
	int k, cont=0;
	for(k=0;k<tam;k++){
		if(cont<col-1){
			printf("%d\t", vet[k]);
			cont++;
		}
		else{
			printf("%d\n", vet[k]);
			cont=0;
		}
	}
}
void adcionarNum (int *vet, int valor, int lin, int col, int total){
	int k;
	k= lin*total+col;
	vet[k]= valor;
} 
int buscaNum (int *vet, int lin, int col, int total){
	int k;
	k= lin*total+col;
	return vet[k];
}
void main(){
	int lin, col;
	printf("\nInforme a qunatidade linhas desejada:");
	scanf("%d", & lin);
	printf("\nInforme a qunatidade colunas desejada:");
	scanf("%d", & col);
	int tam= lin * col;
	int vet[tam];
	zerarMat(vet, tam);
	imprimir(vet, tam, col);
	int escolha, valor, adcLin, adcCol, bscLin, bscCol;
	do{
		printf("\n\n1_Para adicionar um numero;\n2_Para procurar uma posicao;\n3_Para encerrar o programa\n");
		scanf("%d", & escolha);
		if(escolha==1){
			printf("\nInforme o valor que deseja adicionar:");
			scanf("%d", & valor);
			printf("\nInforme a linha a que deseja adcionar o valor %d:", valor);
			scanf("%d", & adcLin);
			printf("\nInforme a coluna a que deseja adcinoar o valor %d:", valor);
			scanf("%d", & adcCol);
			adcionarNum (vet, valor, adcLin-1, adcCol-1, col);
		}
		else if(escolha==2){
			printf("\nInforme a linha e a coluna que deseja produrar:");
			scanf("%d%d", & bscLin, & bscCol);
			printf("\nO valor da linha %d coluna %d eh: %d", bscLin, bscCol, buscaNum (vet, bscLin-1, bscCol-1, col));
		}
		else if(escolha!=1 && escolha!=2 && escolha!=3){
			printf("\n!!!!NUMERO INCORRETO. Tente novamente:\n");
			printf("1_Para adicionar um numero;\n2_Para procurar uma posicao;\n3_Para encerrar o programa\n");
			scanf("%d", & escolha);
		}
	}while(escolha!=3);
	printf("\n\nImprimindo a matriz:\n");
	imprimir(vet, tam, col);
}
