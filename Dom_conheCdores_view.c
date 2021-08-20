//view
//#include<stdio.h>


int menu();
void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28]);
void Jogada(pecas Tpecas[28], mesa pecaMesa[28]);
int PrimeiraJogada(pecas Tepcas[28], mesa pecaMesa[28]);
void mostraPrimeiroJogador(pecas Tpecas[28], mesa pecaMesa[28]);

int menu()
{
	int x;
	printf("    Jogo DOMINO\n");
	printf("menu:\n");
	printf("1- iniciar novo jogo 1 VS 1\n");
	printf("2- iniciar novo jogo 1 VS computador\n");
	printf("3- carregar um jogo antigo\n");
	printf("4- regras do jogo\n");
	printf("5- sair do jogo\n");
	printf("\nopcao: ");
	scanf("%d", &x);
	
	return x;
	
}


void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28])
{
	int y, i;
	
	printf("\n-------------\n");
	printf("MESA: [ %d | %d ]\n", pecaMesa[0].pecaJogada[0], pecaMesa[0].pecaJogada[1]);
	printf("-------------\n");
	
}

void Jogada(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i, x;
	x=PrimeiraJogada(Tpecas, pecaMesa);
	if(x==1)
	{
		printf("Jogador 1 pecas:");
		for(i=0;i<28;i++)
		{
		if(Tpecas[i].local=='j')
			printf(" %d- (%d | %d ) ", i+1,  Tpecas[i].peca[0], Tpecas[i].peca[1]);
		}
	}
	else
	{
		printf("Jogador 2 pecas:");
		for(i=0;i<28;i++)
		{
		if(Tpecas[i].local=='a')
			printf(" %d- (%d | %d ) ", i+1,  Tpecas[i].peca[0], Tpecas[i].peca[1]);
		}
	}
	printf("\n");
	
	
}

int PrimeiraJogada(pecas Tpecas[28], mesa pecaMesa[28]) //retorna o y=1 ou y=2,1 peca foi do jogador 1 ou 2 
{	
														
	int i, x=0, maior=0, y;

	for(i=0;i<28;i++)
	{
		if(Tpecas[i].local!='d')
		{
			if(Tpecas[i].peca[0]==Tpecas[i].peca[1])
			{
				if(Tpecas[i].peca[0]>maior)
				{
					maior=Tpecas[i].peca[1];
					x=i;
				}
			}
		}
	}
	if(maior==0)
	{
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].peca[0]+Tpecas[i].peca[1]>maior)
			{
				maior=Tpecas[i].peca[0]+Tpecas[i].peca[1];
				x=i;
			}
		}
	}
	if(x<6)
	{
		y=1;
	}
	else
	{
		y=2;
	}
	pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
	pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
	Tpecas[x].local='m';
	
	return y;
}

void mostraPrimeiroJogador(pecas Tpecas[28], mesa pecaMesa[28])
{
	int y;
	y=PrimeiraJogada(Tpecas, pecaMesa);
	if(y==1)
	{
		printf("\na primeira jogada foi jogador 1, pois tem a maior peca\n");
	}
	else
	{
		printf("\na primeira jogada foi jogador 2, pois tem a maior peca\n");
	}
	printf("\n");
}
