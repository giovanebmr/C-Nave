//Autor: Giovane B M Reis, e-mail: giovanebmr@gmail.com

	#include <stdio.h>   //para printf
	#include <stdlib.h>  //para system pause cls e etc
	#include <conio.h>   //para leitura do teclado   kbhit() e getch()
	#include <unistd.h>	 //para sleep (segundos) e usleep (microsegundos)
	#include <windows.h> //para sons
	
	//Configuracoes iniciais............................................
	const int TAMANHO_X = 40; //largura utilizavel da tela
	const int TAMANHO_Y = 40; //altura utilizavel da tela
	const char ESPACO = '.'; //forma dos espacos na matriz
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
			
			if( kbhit() ){
				tecla_pressionada = getch();
				//apaga a nave da posição atual
				tela[POSICAO_NAVE_Y][POSICAO_NAVE_X] = ESPACO;
				//atualiza a posicao da nave
				POSICAO_NAVE_Y = movimenta_nave_Y(POSICAO_NAVE_Y, tecla_pressionada, TAMANHO_Y);
				POSICAO_NAVE_X = movimenta_nave_X(POSICAO_NAVE_X, tecla_pressionada, TAMANHO_X);
				tela[POSICAO_NAVE_Y][POSICAO_NAVE_X] = FORMATO_NAVE;
				//pressione 'p' para sair
				if(tecla_pressionada == 'p'){ 
					break;
				}
			}
			//Imprime a matriz na tela
			for( int y = 0 ; y < TAMANHO_Y ; y++ ){
				printf("\t\t");
				for( int x = 0 ; x < TAMANHO_X ; x++ ){
					printf("%c", tela[y][x]);
				}	
				printf("\n");
			}
			usleep(200000); //pausa de meio segundo
			system("cls");
		}//end while
		
		return 0;
	}//end main..................................................................................
	
	//Movimenta a nave no eixo X, devolve a nova posição da nave no eixo
	int movimenta_nave_X( int posicao_nave_X, char tecla_presionada, int tamanho_X_tela ){
		int POSICAO = posicao_nave_X;
			//movimento horizontal para a direita
			if( tecla_presionada == 'd' && ( ++posicao_nave_X  < tamanho_X_tela ) ){
					return posicao_nave_X;
			}else if( tecla_presionada == 'a' && ( --posicao_nave_X  >= 0 ) ){
				//movimento horizontal para a esquerda
				return posicao_nave_X;
			}else{
				return POSICAO;
			}
	}
	
	//Movimenta a nave no eixo Y, devolve a nova posição da nave no eixo
	int movimenta_nave_Y(int posicao_nave_Y, char tecla_presionada, int tamanho_Y_tela){
		int POSICAO = posicao_nave_Y;
			//movimento vertical para a base
			if( tecla_presionada == 's' && ( ++posicao_nave_Y  < tamanho_Y_tela ) ){
					return posicao_nave_Y;
			}else if( tecla_presionada == 'w' && ( --posicao_nave_Y  >= 0 ) ){
				//movimento vertical para o topo
				return posicao_nave_Y;
			}else{
				return POSICAO;
			}
	}
	
	

