//control
//funcoes do domino



void Domino(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void geraPeca(pecas Tpecas[28]);

void embaralha(pecas Tpecas[28]);

void distribui(pecas Tpecas[28]);

void compraPeca(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

int PrimeiraJogada(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

void adicionaNaMesa(int x, char a, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);

int AcabaJogo(int y, pecas Tpecas[28]);

int Empate(pecas Tpecas[28], Variaveis VA[1]);

void GravaJogo(pecas Tpecas[28], mesa pecaMesa[28]);


void Domino(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int o, y, h=0;
	while (o!=5)
	{
		o=menu();
		switch(o)
		{
			case 1://novo jogo
				geraPeca(Tpecas);
				embaralha(Tpecas);
				distribui(Tpecas);
				//PrimeiraJogada(Tpecas, pecaMesa,VA);
				mostraPrimeiroJogador(Tpecas, pecaMesa, VA);
				apresentaMesa(Tpecas, pecaMesa, VA);
				while(h!=2)
				{
					pecasJogador(Tpecas, pecaMesa, VA);
					h=Empate(Tpecas, VA);
					if(h==2)
						break;
					Jogadas(Tpecas,pecaMesa, VA);
					h=AcabaJogo(VA[0].qualJogador, Tpecas);
				}
				printf("\nOBRIGADO POR JOGAR\n");
				break;

			case 2:
				geraPeca(Tpecas);
				embaralha(Tpecas);
				distribui(Tpecas);
				mostraPrimeiroJogadorVScomputador(Tpecas, pecaMesa, VA);
				apresentaMesa(Tpecas, pecaMesa, VA);
				pecasJogadorVScomputador(Tpecas, pecaMesa, VA);
				break;
			
			case 3:	

				break;
			case 4:
				regras();

				break;
			case 5:
				printf("OBRIGADO POR JOGAR");
				break;
		}
	}	
}

void geraPeca(pecas Tpecas[28])
{
	 int i, k, j=0;

    for(i=0;i<=6;i++)
    {

        for(k=i;k<=6;k++)

        {

            Tpecas[j].peca[0]=i;

            Tpecas[j].peca[1]=k;

            j++;

        }

    }
    
}

void embaralha(pecas Tpecas[28])
{
	int t, i, x, y;
 	pecas aux;
	
	//semente para numero aleatorio
	srand( (unsigned)time(NULL) );
	
	//funcao que embaralha as pecas
	for(i=0;i<28;i++)
	{
		x=(rand()%28);
		aux=Tpecas[i];
		Tpecas[i]=Tpecas[x];
		Tpecas[x]=aux;
	}
	
}

void distribui(pecas Tpecas[28])
{
	int i;
	//para limpar todas as pecas
	for(i=0;i<28;i++)
	{
		Tpecas[i].local='n';
	}
	//faz a distribuicao das pecas para a mao do j=jogador, a=adversario, d=deposito, m=mesa
	for(i=0;i<28;i++)
	{
		if(i<7)
		Tpecas[i].local='j';
		else if(i<14)
		Tpecas[i].local='a';
		else
		Tpecas[i].local='d';
	}
}



int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//funcao que verifica se a peca escolhida pode ser jogada na mesa
{
	int x;
	
	if(Tpecas[y].peca[0]==VA[0].extremidadeD || Tpecas[y].peca[0]==VA[0].extremidadeE)
	{
		x=1; //1 = peca que pode ser jogada na mesa
	}
	else if(Tpecas[y].peca[1]==VA[0].extremidadeD || Tpecas[y].peca[1]==VA[0].extremidadeE)
	{
		x=1;
	}
	else
	{
		x=2; //2 = peca que nao pode ser jogada
	}
	
	return x;
}

int PrimeiraJogada(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]) //retorna o y=1 ou y=2,1 peca foi do jogador 1 ou 2 
{	//funcao que realiza a primeira jogada do jogo, pois a primeira jogada é automatica
														
	int i, x=0, maior=0, y;

	for(i=0;i<28;i++)//descobre a maior peca se tiver alguma com numero igual
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
		for(i=0;i<28;i++)//descobre a maior peca pela soma dos numeros dos lados
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
		VA[0].qualJogador=2; //variavel para saber qual é o jogador que esta na vez
	}
	else
	{
		y=2;
		VA[0].qualJogador=1;
	}
	//passa a peca da mao do jogador para a mesa
	pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
	pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];

	//define o locar da 1 peca para a mesa
	Tpecas[x].local='m';

	//aumenta o numero de rodadas para 1
	VA[0].rodadas=1;

	//define os lados da peca jogada
	VA[0].extremidadeE=pecaMesa[0].pecaJogada[0];
	VA[0].extremidadeD=pecaMesa[0].pecaJogada[1];

	//retorna quem foi o primeiro jogador
	return y;
}

void adicionaNaMesa(int x, char a, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])
{
	int y, i, k;
	y=VA[0].rodadas;
	if(a=='o')
	{
		if(Tpecas[x].peca[0]==VA[0].extremidadeE||Tpecas[x].peca[1]==VA[0].extremidadeE)
		{
			for(i=y; i>0; i--)//joga a mesa para a direita para incerir uma peca na esquerda
			{
				pecaMesa[i].pecaJogada[0]=pecaMesa[i-1].pecaJogada[0];
				pecaMesa[i].pecaJogada[1]=pecaMesa[i-1].pecaJogada[1];
			}
			if(Tpecas[x].peca[1]==VA[0].extremidadeE)//caso a peca esteja virada do lado certo
			{
				pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
				pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
				VA[0].extremidadeE=Tpecas[x].peca[0];
				VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];
			}
			else//caso a peca esteja virada do lado errado
			{
				pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[0];
				pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[1];
				VA[0].extremidadeE=Tpecas[x].peca[1];
				VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//
			}
			Tpecas[x].local='m';//muda o local da peca para a mesa
			VA[0].rodadas=VA[0].rodadas+1;//aumenta o numero de rodadas 
			VA[0].qualJogador++;//passa a vez para o proximo jogador
		}
		else if(Tpecas[x].peca[0]==VA[0].extremidadeD||Tpecas[x].peca[1]==VA[0].extremidadeD)//caso a peca tenha q ir para a extremidade direita da mesa
		{
			pecaMesa[y].pecaJogada[1]=Tpecas[x].peca[1];//so adicionando uma peca na extremidade direita
			pecaMesa[y].pecaJogada[0]=Tpecas[x].peca[0];//so adicionando uma peca na extremidade direita

			if(VA[0].extremidadeD!=pecaMesa[y].pecaJogada[0])//caso a peca esteja virada do lado errado
			{
				k=pecaMesa[y].pecaJogada[0];
				pecaMesa[y].pecaJogada[0]=pecaMesa[y].pecaJogada[1];
				pecaMesa[y].pecaJogada[1]=k;
			}
			Tpecas[x].local='m';
			VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//muda a extremidade da mesa para a nova peca
			VA[0].rodadas=VA[0].rodadas+1;//aumenta o numero de rodadas
			VA[0].qualJogador++;//passa a vez para o proximo jogador
		}


	}
	else if(a=='e')//caso o jogador escolha jogar no lado esquerdo
	{
		for(i=y; i>0; i--)//joga a mesa para a direita para incerir uma peca na esquerda
		{
			pecaMesa[i].pecaJogada[0]=pecaMesa[i-1].pecaJogada[0];
			pecaMesa[i].pecaJogada[1]=pecaMesa[i-1].pecaJogada[1];
		}
		if(Tpecas[x].peca[1]==VA[0].extremidadeE)
		{
			pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
			pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
			VA[0].extremidadeE=Tpecas[x].peca[0];
			VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//nao sei
		}
		else if(Tpecas[x].peca[1]!=VA[0].extremidadeE)
		{
			pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[0];
			pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[1];
			VA[0].extremidadeE=pecaMesa[0].pecaJogada[0];
			VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//nao sei
		}
		Tpecas[x].local='m';
		VA[0].rodadas=VA[0].rodadas+1;
		VA[0].qualJogador++;
	}
	else if(a=='d')//caso o jogador escolha jogar no lado direito
	{
		pecaMesa[y].pecaJogada[0]=Tpecas[x].peca[0];
		pecaMesa[y].pecaJogada[1]=Tpecas[x].peca[1];

		if(VA[0].extremidadeD!=pecaMesa[y].pecaJogada[0])//caso a peca esteja virada do lado errado
		{
			k=pecaMesa[y].pecaJogada[0];
			pecaMesa[y].pecaJogada[0]=pecaMesa[y].pecaJogada[1];
			pecaMesa[y].pecaJogada[1]=k;
		}
		VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];
		Tpecas[x].local='m';
		VA[0].rodadas=VA[0].rodadas+1;
		VA[0].qualJogador++;

	}	
}

int AcabaJogo( int y, pecas Tpecas[28])//funcao que verifica se resta alguma peca na mao do jogador que acabou de jogar
{									   //caso o jogador esteja sem pecas, entao a funcao retorna 2 que encerra o jogo e o declara como vencedor	
	int cont=0, i;	
	y=y-1;
	if(y%2!=0)
	{
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].local=='j')
			{
				cont++;
			}		
		}
	}
	else
	{
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].local=='a')
			{
				cont++;
			}
		}
	}

	if(cont==0)
	{
		printf("\nVOCE GANHOU O JOGO, PARABENS\n");
		return 2;//para encerrar o jogo
	}
	else
	{
		return 1;//para continuar o jogo
	}
}	


void compraPeca(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//funcao que compra pecas da mesa e insere na mao do jogador q a comprou
{
	int i, x, k, cont;
	x=VA[0].qualJogador;
	if(x%2!=0)
	{
		for(i=0; i<28; i++)
		{
			if(Tpecas[i].local=='d')
			{
				Tpecas[i].local='j';
				break;
			}
			else
			{

			}
		}
	}
	else
	{
		for(i=0; i<28; i++)
		{
			if(Tpecas[i].local=='d')
			{
				Tpecas[i].local='a';
				break;
			}
		}
	}
}

int Empate(pecas Tpecas[28], Variaveis VA[1])
{
	int i, cont=0, x=0, result1=0, result2=0;;

	for(i=0;i<28;i++)
	{
		if(Tpecas[i].local=='d')
		{
			cont++;
		}
	}
	if(cont==0)
	{
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].local=='j')
			{
				if(Tpecas[i].peca[0]==VA[0].extremidadeD || Tpecas[i].peca[0]==VA[0].extremidadeE)
				{
					x++;
				}
				else if(Tpecas[i].peca[1]==VA[0].extremidadeD || Tpecas[i].peca[1]==VA[0].extremidadeE)
				{
					x++;
				}
			}
		}
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].local=='a')
			{
				if(Tpecas[i].peca[0]==VA[0].extremidadeD || Tpecas[i].peca[0]==VA[0].extremidadeE)
				{
					x++;
				}
				else if(Tpecas[i].peca[1]==VA[0].extremidadeD || Tpecas[i].peca[1]==VA[0].extremidadeE)
				{
					x++;
				}
			}
		}
		if(x==0)
		{
			for(i=0;i<28;i++)
			{
				if(Tpecas[i].local=='j')
				{
					result1=result1+Tpecas[i].peca[0]+Tpecas[i].peca[1];
				}
			}
			for(i=0;i<28;i++)
			{
				if(Tpecas[i].local=='a')
				{
					result2=result2+Tpecas[i].peca[0]+Tpecas[i].peca[1];
				}
			}
			if(result1>result2)
			{
				printf("o jogador 1 ganhou o jogo");
				return 2;
			}
			else if(result2>result1)
			{
				printf("o jogador 2 ganhou o jogo");
				return 2;
			}
			else if(result1==result2)
			{
				printf("o jogo empatou");
				return 2;
			}
		}
	}
	else
	{
		return 1;
	}	
}

/*void GravaJogo(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i, y;
	y=rodadas;
	if(ap=fopen("PecasJ", "w")==NULL)
	{
		printf("O arquivo PecasJ nao pode ser aberto para gravacao");
	}
	for(i=0;i<28;i++)
	{
		if(fwrite(&Tpecas[i], sizeof(pecas),1,ap))
		{
			printf("erro na gravacao do arquivo pecasJ");
		}
	}

	if(am=fopen("PecasM", "w")==NULL)
	{
		printf("O arquivo PecasM nao pode ser aberto para gravacao");
	}
	for(i=0;i<y;i++)
	{
		if(fwrite(&pecaMesa[i], sizeof(mesa),1,ap))
		{
			printf("erro na gravacao do arquivo pecasM");
		}
	}
}*/


