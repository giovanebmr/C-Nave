#include <stdio.h>   //para printf
#include <stdlib.h>  //para system pause cls e etc
#include <conio.h>   //para leitura do teclado   kbhit() e getch()
#include <unistd.h>	 //para sleep (segundos) e usleep (microsegundos)
#include <windows.h> //para sons

//Configurações iniciais
#define TAMANHO_X 20 //largura utilizável da tela
#define TAMANHO_Y 20 //altura utilizável da tela
const char ESPACO = '*'; //forma dos espaços na matriz


int main(){
	
	char tela [TAMANHO_Y][TAMANHO_X];
	
	//Inicializando a matriz com o caracter definido
	for( int y = 0 ; y < TAMANHO_Y ; y++ ){
		for( int x = 0 ; x < TAMANHO_X ; x++ ){
			tela[y][x] = ESPACO;
		}	
	}
	
	int i = 0;
	
	//Loop principal do jogo
	while( i < 5 ){
		
		//Imprime a matriz na tela
		for( int y = 0 ; y < TAMANHO_Y ; y++ ){
			for( int x = 0 ; x < TAMANHO_X ; x++ ){
				printf("%c", tela[y][x] = ESPACO);
			}	
		}
		i++;
	}//end while
	
	
	
	
	
	return 0;
}
