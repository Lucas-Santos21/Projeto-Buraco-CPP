#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	
	string baralho[2][52];
	string mao[4][11];
	bool sorteadas[104] = {false};
	
	srand(time(0));
	
	//popular o baralho
	
	for(int b = 0; b <= 1; b++){
		
		int carta_index = 0;
		
		for(int naipe = 1; naipe <= 4; naipe++){
			
			for(int numero =1; numero <= 13; numero++){
				
				baralho[b][carta_index] = to_string(naipe) + (numero < 10 ? "0":"") + to_string(numero) + to_string(b + 1);
				
				carta_index++;
				
			}
			
		}
		
	}
	
	   //distribuir as maos	
	
	for(int j= 0; j < 4; j++){
		
		for(int c=0; c < 11; c++){
			
			int carta;
			
			do{
				
				carta = rand()%104;
				
			}while(sorteadas[carta]);
			
			sorteadas[carta] = true;
			
			int baralho_id = carta / 52;
			int carta_id = carta % 52;
			
			mao[j][c] = baralho[baralho_id][carta_id];
			
		}
		
	}
	
	//mostra a mao dos jogadores
	
	for(int l=0;l<4; l++){

		cout << "Jogador " << l + 1 << ": ";
				
		for(int m=0; m < 11; m++){
			
			cout << mao[l][m] << " ";
			
		}
		
		cout << endl;
	}
	
	
	return 0;
}