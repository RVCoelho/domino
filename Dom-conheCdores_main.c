// jogo DOMINO 
//Grupo: conheCdores
//integrantes:
	//Victor Padilha
	//Arthur Bonjardim
	//Ricardo Veiga
	//Joao Antonio Malheiros


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Dom_conheCdores_model.c"
#include "Dom_conheCdores_view.c"
#include "Dom_conheCdores_control.c"


int main()

{
	pecas Tpecas[28];
	mesa pecaMesa[28];
	Variaveis VA[1];
	
	Domino(Tpecas, pecaMesa, VA);
	
return 0;
}

