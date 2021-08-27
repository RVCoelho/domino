//control
//funcoes do domino



void Domino(pecas Tpecas[28], mesa pecaMesa[28]);
void geraPeca(pecas Tpecas[28]);
void embaralha(pecas Tpecas[28]);
void distribui(pecas Tpecas[28]);
void compraPeca(pecas Tpecas[28], mesa pecaMesa[28]);
int PrimeiraJogada(pecas Tpecas[28], mesa pecaMesa[28]);
void adicionaNaMesa(int x, char a, pecas Tpecas[28], mesa pecaMesa[28]);
int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28]);
int AcabaJogo(int y, pecas Tpecas[28]);

void Domino(pecas Tpecas[28], mesa pecaMesa[28])
{
	int o, y, h=0;
	o=menu();
	switch(o)
	{
		case 1://novo jogo
			geraPeca(Tpecas);
			embaralha(Tpecas);
			distribui(Tpecas);
			PrimeiraJogada(Tpecas, pecaMesa);
			mostraPrimeiroJogador(Tpecas, pecaMesa);
			apresentaMesa(Tpecas, pecaMesa);
			while(h!=2)
			{
				pecasJogador(Tpecas, pecaMesa);
				Jogadas(Tpecas,pecaMesa);
				h=AcabaJogo(qualJogador, Tpecas);
			}
			printf("\nOBRIGADO POR JOGAR\n");
			break;
			
		case 2:
			printf("");	
			break;
				
		case 4:
			regras();

			break;
		case 5:
			printf("OBRIGADO POR JOGAR");
			break;
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



int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28])
{
	int x;
	
	if(Tpecas[y].peca[0]== extremidadeD || Tpecas[y].peca[0]== extremidadeE)
	{
		x=1; //1 = peca que pode ser jogada na mesa
	}
	else if(Tpecas[y].peca[1]== extremidadeD || Tpecas[y].peca[1]== extremidadeE)
	{
		x=1;
	}
	else
	{
		x=2; //2 = peca que nao pode ser jogada
	}
	
	return x;
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
	if(x<7)
	{
		y=1;
		qualJogador=2;
	}
	else
	{
		y=2;
		qualJogador=1;
	}
	//passa a peca da mao do jogador para a mesa
	pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
	pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];

	//define o locar da 1 peca para a mesa
	Tpecas[x].local='m';

	//aumenta o numero de rodadas para 1
	pecaMesa[0].rodadas=1;

	//define os lados da peca jogada
	extremidadeE=pecaMesa[0].pecaJogada[0];
	extremidadeD=pecaMesa[0].pecaJogada[1];

	//retorna quem foi o primeiro jogador
	return y;
}

void adicionaNaMesa(int x, char a, pecas Tpecas[28], mesa pecaMesa[28])
{
	int y, i, k;
	y=pecaMesa->rodadas;
	if(a=='o')
	{
		if(Tpecas[x].peca[0]==extremidadeE||Tpecas[x].peca[1]==extremidadeE)
		{
			for(i=y; i>0; i--)//joga a mesa para a direita para incerir uma peca na esquerda
			{
				pecaMesa[i].pecaJogada[0]=pecaMesa[i-1].pecaJogada[0];
				pecaMesa[i].pecaJogada[1]=pecaMesa[i-1].pecaJogada[1];
			}
			if(Tpecas[x].peca[1]==extremidadeE)//caso a peca esteja virada do lado certo
			{
				pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
				pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
				extremidadeE=Tpecas[x].peca[0];
				extremidadeD=pecaMesa[y].pecaJogada[1];//
			}
			else//caso a peca esteja virada do lado errado
			{
				pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[0];
				pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[1];
				extremidadeE=Tpecas[x].peca[1];
				extremidadeD=pecaMesa[y].pecaJogada[1];//
			}
			Tpecas[x].local='m';
			pecaMesa[0].rodadas=pecaMesa[0].rodadas+1;
			qualJogador++;
		}
		else if(Tpecas[x].peca[0]==extremidadeD||Tpecas[x].peca[1]==extremidadeD)
		{
			pecaMesa[y].pecaJogada[1]=Tpecas[x].peca[1];
			pecaMesa[y].pecaJogada[0]=Tpecas[x].peca[0];

			if(extremidadeD!=pecaMesa[y].pecaJogada[0])//caso a peca esteja virada do lado errado
			{
				k=pecaMesa[y].pecaJogada[0];
				pecaMesa[y].pecaJogada[0]=pecaMesa[y].pecaJogada[1];
				pecaMesa[y].pecaJogada[1]=k;
			}
			Tpecas[x].local='m';
			extremidadeD=pecaMesa[y].pecaJogada[1];
			pecaMesa[0].rodadas=pecaMesa[0].rodadas+1;
			qualJogador++;
		}


	}
	else if(a=='e')
	{
		for(i=y; i>0; i--)//joga a mesa para a direita para incerir uma peca na esquerda
		{
			pecaMesa[i].pecaJogada[0]=pecaMesa[i-1].pecaJogada[0];
			pecaMesa[i].pecaJogada[1]=pecaMesa[i-1].pecaJogada[1];
		}
		if(Tpecas[x].peca[1]==extremidadeE)
		{
			pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[0];
			pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[1];
			extremidadeE=Tpecas[x].peca[0];
			extremidadeD=pecaMesa[y].pecaJogada[1];//nao sei
		}
		else if(Tpecas[x].peca[1]!=extremidadeE)
		{
			pecaMesa[0].pecaJogada[1]=Tpecas[x].peca[0];
			pecaMesa[0].pecaJogada[0]=Tpecas[x].peca[1];
			extremidadeE=pecaMesa[0].pecaJogada[0];
			extremidadeD=pecaMesa[y].pecaJogada[1];//nao sei
		}
		Tpecas[x].local='m';
		pecaMesa[0].rodadas=pecaMesa[0].rodadas+1;
		qualJogador++;
	}
	else if(a=='d')
	{
		pecaMesa[y].pecaJogada[0]=Tpecas[x].peca[0];
		pecaMesa[y].pecaJogada[1]=Tpecas[x].peca[1];

		if(extremidadeD!=pecaMesa[y].pecaJogada[0])//caso a peca esteja virada do lado errado
		{
			k=pecaMesa[y].pecaJogada[0];
			pecaMesa[y].pecaJogada[0]=pecaMesa[y].pecaJogada[1];
			pecaMesa[y].pecaJogada[1]=k;
		}
		extremidadeD=pecaMesa[y].pecaJogada[1];
		Tpecas[x].local='m';
		pecaMesa[0].rodadas=pecaMesa[0].rodadas+1;
		qualJogador++;

	}	
}

int AcabaJogo( int y, pecas Tpecas[28])
{
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


void compraPeca(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i, x, k, cont;
	x=qualJogador;
	if(x%2!=0)
	{
		for(i=0; i<28; i++)
		{
			if(Tpecas[i].local=='d')
			{
				Tpecas[i].local='j';
				break;
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
	
