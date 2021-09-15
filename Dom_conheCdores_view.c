//view



int menu();
void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void mostraPrimeiroJogador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

char opcoesPjogar(mesa pecaMesa[28], Variaveis VA[1]);

void Jogadas(pecas Tpeca[28], mesa pecaMesa[28], Variaveis VA[1]);

void regras();

void mostraPrimeiroJogadorVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void pecasJogadorVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void JogadasVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

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


void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int y, i;
	printf("\n-------------\n");
	printf("MESA:   ");
	for(i=0;i<VA[0].rodadas;i++)
	{
		printf(" [ %d | %d ]", pecaMesa[i].pecaJogada[0], pecaMesa[i].pecaJogada[1]);
	}
	printf("\n-------------\n");
	
}

void pecasJogador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int i, x;
	x=VA[0].qualJogador;
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

void pecasJogadorVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int i, x;
	x=VA[0].qualJogador;
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
		printf("\n");
		printf("o computador vai jogar agora");
	}
	printf("\n------------\n");
}

//funcao apenas para mostrar de quem foi a primeira peca a ser jogada
void mostraPrimeiroJogador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int y;
	y=PrimeiraJogada(Tpecas, pecaMesa, VA);
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

void mostraPrimeiroJogadorVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int y;
	y=PrimeiraJogada(Tpecas, pecaMesa, VA);
	if(y==1)
	{
		printf("\na primeira jogada foi jogador 1, pois tem a maior peca\n");
	}
	else
	{
		printf("\na primeira jogada foi do computador, pois tem a maior peca\n");
	}
	printf("\n");
}

char opcoesPjogar( mesa pecaMesa[28], Variaveis VA[1])
{
	char c;
	
	printf(" j- jogar(possiveis: %d ou %d)\n", VA[0].extremidadeE, VA[0].extremidadeD);
	printf(" c- Comprar\n");
	printf(" p- Passar a vez, se possivel\n");
	printf(" t- salvar e sair do jogo\n");
	printf(" s- Sair(interromper o jogo)\n");
	printf(" Opcao:");
	scanf("%s", &c);
	
	return (c);
}

void Jogadas(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	char c, a='o';
	int x=0, y, t, i, cont=0;
		
	c=opcoesPjogar(pecaMesa, VA);
	
	switch (c)
	{

		case 'J':
		case 'j':
			while(x!=1)
			{
				printf("escolha a peca que deseja jogar:");
				scanf("%d", &y);
				y=y-1;
				x=verifica(y, Tpecas, pecaMesa, VA);
				if(x==2)
				{
					printf("\nA peca escolhida nao pode ser jogada.\n");
					printf("se voce nao possui nenhuma peca que possa ser jogada\n");
					printf("digite 1 para escolher outra opcao\n");
					printf("caso voce tenha outra peca que possa ser jogada, digite 2\n");
					printf("opcao: ");
					scanf("%d", &t);
					if(t==1){
						break;
					}	
				}	
				
			}
			if(Tpecas[y].peca[0] == VA[0].extremidadeD && Tpecas[y].peca[0] == VA[0].extremidadeE)
			{
				printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
				scanf("%s", &a);
			}
			else if(Tpecas[y].peca[1] == VA[0].extremidadeD && Tpecas[y].peca[1] == VA[0].extremidadeE)
			{
				printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
				scanf("%s", &a);
			}
			else if(Tpecas[y].peca[0] == VA[0].extremidadeD && Tpecas[y].peca[1] == VA[0].extremidadeE)
			{
				printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
				scanf("%s", &a);
			}
			else if(Tpecas[y].peca[1] == VA[0].extremidadeD && Tpecas[y].peca[0] == VA[0].extremidadeE)
			{
				printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
				scanf("%s", &a);
			}
			adicionaNaMesa(y, a, Tpecas, pecaMesa, VA);
			apresentaMesa(Tpecas, pecaMesa, VA);
			break;

		case 'C':
		case 'c':

			compraPeca(Tpecas, pecaMesa, VA);
			break;

		case 'P':
		case 'p':

				for(i=0; i<28; i++)
				{
					if(Tpecas[i].local=='d')
					{
						cont++;
					}	
				}
				if(cont!=0)
				{
					printf("\nvoce ainda pode comprar uma peca, logo nao pode passar a vez\n");
				}
				else if(cont == 0)
				{
					VA[0].qualJogador++;
					apresentaMesa(Tpecas, pecaMesa, VA);
				}


			break;

		case 'S':
		case 's':
			printf("OBRIGADO POR JOGAR\n");
			exit(NULL);
			break;

		case 'T':
		case 't':
			GravaJogo(Tpecas, pecaMesa, VA);
			exit(NULL);
			break;

	}
}

void JogadasVScomputador(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	char c, a='o';
	int x=0, y, t, i, cont=0, J=VA[0].qualJogador;

	if(J%2!=0)
	{
		c=opcoesPjogar(pecaMesa, VA);
	
		switch (c)
		{

			case 'J':
			case 'j':
				while(x!=1)
				{
					printf("escolha a peca que deseja jogar:");
					scanf("%d", &y);
					y=y-1;
					x=verifica(y, Tpecas, pecaMesa, VA);
					if(x==2)
					{
						printf("\nA peca escolhida nao pode ser jogada.\n");
						printf("se voce nao possui nenhuma peca que possa ser jogada\n");
						printf("digite 1 para escolher outra opcao\n");
						printf("caso voce tenha outra peca que possa ser jogada, digite 2\n");
						printf("opcao: ");
						scanf("%d", &t);
						if(t==1){
							break;
						}	
					}	

				}
				if(Tpecas[y].peca[0] == VA[0].extremidadeD && Tpecas[y].peca[0] == VA[0].extremidadeE)
				{
					printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
					scanf("%s", &a);
				}
				else if(Tpecas[y].peca[1] == VA[0].extremidadeD && Tpecas[y].peca[1] == VA[0].extremidadeE)
				{
					printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
					scanf("%s", &a);
				}
				else if(Tpecas[y].peca[0] == VA[0].extremidadeD && Tpecas[y].peca[1] == VA[0].extremidadeE)
				{
					printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
					scanf("%s", &a);
				}
				else if(Tpecas[y].peca[1] == VA[0].extremidadeD && Tpecas[y].peca[0] == VA[0].extremidadeE)
				{
					printf("escolha o lado da mesa para jogar(d=direito, e=esquerdo):");
					scanf("%s", &a);
				}
				adicionaNaMesa(y, a, Tpecas, pecaMesa, VA);
				apresentaMesa(Tpecas, pecaMesa, VA);
				break;

			case 'C':
			case 'c':
				compraPeca(Tpecas, pecaMesa, VA);
			break;

			case 'P':
			case 'p':

					for(i=0; i<28; i++)
					{
						if(Tpecas[i].local=='d')
						{
							cont++;
						}	
					}
					if(cont!=0)
					{
						printf("\nvoce ainda pode comprar uma peca, logo nao pode passar a vez\n");
					}
					else if(cont == 0)
					{
						VA[0].qualJogador++;
					apresentaMesa(Tpecas, pecaMesa, VA);
					}


				break;
			
			case 'S':
			case 's':
				printf("OBRIGADO POR JOGAR\n");
				exit(NULL);
				break;

			case 'T':
			case 't':
				printf("voce nao pode salvar um jogo contra o computador");
				//GravaJogo(Tpecas, pecaMesa, VA);
				break;

		}
	}
	else
	{
		ComputadorJogando(Tpecas, pecaMesa, VA);
		apresentaMesa(Tpecas, pecaMesa, VA);

	}	
}

void regras()
{
	printf("o jogo e composto por 28 pecas, cada extremidade da peca possui 2 numeros de 0 a 6\n");
	printf("cada jogador comeca com 7 pecas em sua mao, e a pilha de compra tem 14 pecas\n");
	printf("o jogador com a maior pedra comeca, isso e feito automaticamente pelo computador\n");
	printf("Cada jogador deve tentar encaixar uma de suas pedras nas extremidades do jogo na mesa\n");
	printf("Quando o jogador consegue encaixar uma pedra ele passa a vez\n");
	printf("caso ele nao consiga ele deve comprar, se nao houver pedras no monte ele passara a vez\n");
	printf("ganha o jogador que ficar sem pecas primeiro\n"); 

}
