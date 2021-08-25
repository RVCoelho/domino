//view
//#include<stdio.h>

//view
//#include<stdio.h>


int menu();
void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28]);

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28]);


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
	printf("MESA:   ");
	for(i=0;i<pecaMesa->rodadas;i++)
	{
		printf("[ %d | %d ]", pecaMesa[i].pecaJogada[0], pecaMesa[i].pecaJogada[1]);
	}
	printf("\n-------------\n");
	
}

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i, x;
	x=qualJogador;
	if(x%2!=0)
	{
		printf("Jogador 1 pecas:");
		for(i=0;i<28;i++)
		{
		if(Tpecas[i].local=='j')
			printf(" %d- [ %d | %d ] ", i+1,  Tpecas[i].peca[0], Tpecas[i].peca[1]);
		}
	}
	else
	{
		printf("Jogador 2 pecas:");
		for(i=0;i<28;i++)
		{
		if(Tpecas[i].local=='a')
			printf(" %d- [ %d | %d ] ", i+1,  Tpecas[i].peca[0], Tpecas[i].peca[1]);
		}
	}
	printf("\n------------\n");
}

//funcao para definir a primeira peca a ser jogada

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
	int x=0, y;
		
	c=opcoesPjogar(pecaMesa);
	
	switch (c)
	{

		case 'j':
			while(x!=1)
			{
				printf("escolha a peca que deseja jogar:");
				scanf("%d", &y);
				y=y-1;
				x=verifica(y, Tpecas, pecaMesa);
				printf("%d\n", x);
				if(x==2)
					printf("\nA peca escolhida nao pode ser jogada.\n");
			}
			adicionaNaMesa(y, Tpecas, pecaMesa);
			apresentaMesa(Tpecas, pecaMesa);
			break;
		case 'c':
			compraPeca(Tpecas, pecaMesa);
			pecasJogador(Tpecas, pecaMesa);
			break;
	}
}
