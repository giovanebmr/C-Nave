//Autor: Giovane B M Reis, e-mail: giovanebmr@gmail.com

#include <stdio.h>   //para printf
#include <stdlib.h>  //para system pause cls e etc
#include <conio.h>   //para leitura do teclado   kbhit() e getch()
#include <unistd.h>	 //para sleep (segundos) e usleep (microsegundos)
#include <windows.h> //para sons

//Configuracoes iniciais............................................
const int TAMANHO_X = 40; //largura utilizavel da tela
const int TAMANHO_Y = 40; //altura utilizavel da tela
const char ESPACO = '*'; //forma dos espacos na matriz
const char FORMATO_NAVE = 'T'; //forma da nave
const char SUBIR = 'w'; //movimento vertical para o topo
const char DESCER = 's'; //movimento vertical para a base
const char ESQUERDA = 'a'; //movimento horizontal para esquerda
const char DIREITA = 'd'; //movimento horizontal para a direita
int POSICAO_NAVE_X = TAMANHO_X / 2; //posicao x da nave
int POSICAO_NAVE_Y = TAMANHO_Y - 1; //POSICAO y da nave

//Prototipo das funcoes..............................................
int movimenta_nave_X(int posicao_nave_X, char tecla_presionada, int tamanho_X_tela);
int movimenta_nave_Y(int posicao_nave_Y, char tecla_presionada, int tamanho_Y_tela);


int main(){
	
	char tela [TAMANHO_Y][TAMANHO_X];
	int tecla_pressionada = 0;
	
	//Inicializando a matriz com o caracter definido
	for( int y = 0 ; y < TAMANHO_Y ; y++ ){
		for( int x = 0 ; x < TAMANHO_X ; x++ ){
			tela[y][x] = ESPACO;
		}	
	}
	
	//coloca a nave no jogo
	tela[POSICAO_NAVE_Y][POSICAO_NAVE_X] = FORMATO_NAVE;
	
	//Loop principal do jogo
	while( true ){
		//verifica tecla pressionada
		
		if(kbhit()){
			tecla_pressionada = getch();
			POSICAO_NAVE_Y = movimenta_nave_Y(POSICAO_NAVE_Y, tecla_pressionada, TAMANHO_Y);
			POSICAO_NAVE_X = movimenta_nave_X(POSICAO_NAVE_X, tecla_pressionada, TAMANHO_X);
			//atualiza a posicao da nave
			tela[POSICAO_NAVE_Y][POSICAO_NAVE_X] = FORMATO_NAVE;
			//pressione 'p' para sair
			if(tecla_pressionada == 'p'){ 
				break;
			}
		}
		printf("\n\n\n\n\n\n%d", tecla_pressionada);
		//Imprime a matriz na tela
		for( int y = 0 ; y < TAMANHO_Y ; y++ ){
			printf("\t\t");
			for( int x = 0 ; x < TAMANHO_X ; x++ ){
				printf("%c", tela[y][x]);
			}	
			printf("\n");
		}
		system("pause");
		system("clear");
	}//end while
	
	return 0;
}//end main..................................................................................

//Movimenta a nave no eixo X, devolve a nova posição da nave no eixo
int movimenta_nave_X(int posicao_nave_X, char tecla_presionada, int tamanho_X_tela){
	int POSICAO = posicao_nave_X;
	if(posicao_nave_X > 0 && posicao_nave_X < tamanho_X_tela - 1){
		//movimento horizontal para a direita
		if(tecla_presionada == DIREITA){
			POSICAO = posicao_nave_X + 1;
		}
		//movimento horizontal para a esquerda
		if(tecla_presionada == ESQUERDA){
			POSICAO = posicao_nave_X - 1;
		}
	}
	printf("%d", POSICAO);
	return POSICAO;
}
//Movimenta a nave no eixo Y, devolve a nova posição da nave no eixo
int movimenta_nave_Y(int posicao_nave_Y, char tecla_presionada, int tamanho_Y_tela){
	int POSICAO = posicao_nave_Y;
	if(posicao_nave_Y > 0 && posicao_nave_Y < tamanho_Y_tela - 1){
		//movimento vertical para o topo
		if(tecla_presionada == SUBIR){
			POSICAO = posicao_nave_Y - 1;
		}
		//movimento vertical para a base
		if(tecla_presionada == DESCER){
			POSICAO = posicao_nave_Y + 1;
		}	
	}
	printf("%d", POSICAO);
	return POSICAO;
}



