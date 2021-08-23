//view
//#include<stdio.h>


int menu();
void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28]);

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28]);

int PrimeiraJogada(pecas Tepcas[28], mesa pecaMesa[28]);

void mostraPrimeiroJogador(pecas Tpecas[28], mesa pecaMesa[28]);

char opcoesPjogar(mesa pecaMesa[28]);

void Jogadas(pecas Tpeca[28], mesa pecaMesa[28]);


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
	for(i=0;i<pecaMesa->rodadas;i++)
	{
		printf("MESA: [ %d | %d ]\n", pecaMesa[0].pecaJogada[0], pecaMesa[0].pecaJogada[1]);
	}
	printf("-------------\n");
	
}

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i, x;
	x=PrimeiraJogada(Tpecas, pecaMesa);
	if(x==2)
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
	printf("\n------------\n");
	
	
}

//funcao para definir a primeira peca a ser jogada
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
	if(x<7)
	{
		y=1;
	}
	else
	{
		y=2;
	}
	//passa a peca da mao do jogador para a mesa
	pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
	pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
	//define o locar da 1 peca para a mesa
	Tpecas[x].local='m';
	//aumenta o numero de rodadas para 1
	pecaMesa[0].rodadas=1;
	//define os lados da peca jogada
	pecaMesa[0].ladoE=Tpecas[x].peca[0];
	pecaMesa[0].ladoD=Tpecas[x].peca[1];
	//retorna quem foi o primeiro jogador
	return y;
}

//funcao apenas para mostrar de quem foi a primeira peca a ser jogada
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

char opcoesPjogar( mesa pecaMesa[28])
{
	char c;
	
	printf(" j- jogar(possiveis: %d ou %d)\n", pecaMesa[0].ladoE, pecaMesa[0].ladoD);
	printf(" c- Comprar\n");
	printf(" p- Passar a vez\n");
	printf(" s- Sair(interromper o jogo)\n");
	printf(" Opcao:");
	scanf("%s", &c);
	
	
	return (c);
}

void Jogadas(pecas Tpecas[28], mesa pecaMesa[28])
{
	char c;
	int y;
		
	c=opcoesPjogar(pecaMesa);
	
	switch (c)
	{

		case 'j':
			printf("escolha a peca que deseja jogar:");
			scanf("%d", &y);
			printf("teste\n");
			
				
			
				
			break;
		case 'c':
			
			
			break;
	}
	
	
}
