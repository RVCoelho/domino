//control
//funcoes do domino



void Domino(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao principal do jogo

void geraPeca(pecas Tpecas[28]);//funcao que gera todas as pecas do jogo

void embaralha(pecas Tpecas[28]);//funcao que embaralha as pecas

void distribui(pecas Tpecas[28]);//funcao que distribui as pecas para cada jogador e para o monte

void compraPeca(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao para comprar uma peca dentro do jogo

int PrimeiraJogada(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao para realizar a primeira jogada do jogo

void adicionaNaMesa(int x, char a, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao que adiciona a peca selecionada na mesa

int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao que verifica se a peca selecionada pode entrar na mesa

int AcabaJogo(int y, pecas Tpecas[28]);//funcao que verifica se o jogo acabou

int Empate(pecas Tpecas[28], Variaveis VA[1]);//funcao que verifica se ouve um empate no jogo

void GravaJogo(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao que grava o jogo

void LerJogoSalvo(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao que le o jogo salvo

void ComputadorJogando(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1]);//funcao que faz as jogadas para o computador

int AcabaJogoVScomputador( int y, pecas Tpecas[28]);//funcao que verifica se o jogo acabou qunado jogando contra o computador

int EmpateVScomputador(pecas Tpecas[28], Variaveis VA[1]);//funcao que verifica um empata no jogo quando jogando contra o computador

void Domino(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//funcao principal do jogo
{
	int o, y, h=0;
	while (o!=5)
	{
		o=menu();
		switch(o)
		{
			case 1://novo jogo pessoa vs pessoa
				geraPeca(Tpecas);
				embaralha(Tpecas);
				distribui(Tpecas);
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
				exit(NULL);
				break;

			case 2://novo jogo contra o computador
				geraPeca(Tpecas);
				embaralha(Tpecas);
				distribui(Tpecas);
				mostraPrimeiroJogadorVScomputador(Tpecas, pecaMesa, VA);
				apresentaMesa(Tpecas, pecaMesa, VA);
				while(h!=2)
				{
					pecasJogadorVScomputador(Tpecas, pecaMesa, VA);
					h=EmpateVScomputador(Tpecas, VA);
					if(h==2)
						break;
					JogadasVScomputador(Tpecas,pecaMesa, VA);
					h=AcabaJogoVScomputador(VA[0].qualJogador, Tpecas);
				}
				exit(NULL);
				break;
			
			case 3://comeca o jogo a partir da leitura de um jogo salvo
				LerJogoSalvo(Tpecas, pecaMesa, VA);
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
			case 4://regras do jogo
				regras();

				break;
			case 5://sai fo jogo
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
		Tpecas[i].local='a';//se estiver jogando contra o computador a=computador
		else
		Tpecas[i].local='d';
	}
}

int verifica(int y, pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//funcao que verifica se a peca escolhida pode ser jogada na mesa
{
	int x, a;
	a=VA[0].qualJogador;
	if(a%2!=0)
	{
		if(Tpecas[y].local=='j')
		{
			if(Tpecas[y].peca[0]==VA[0].extremidadeD || Tpecas[y].peca[1]==VA[0].extremidadeD)
			{
				x=1; //1 = peca que pode ser jogada na mesa
			}
			else if(Tpecas[y].peca[0]==VA[0].extremidadeE|| Tpecas[y].peca[1]==VA[0].extremidadeE)
			{
				x=1;
			}
			else
			{
				x=2; //2 = peca que nao pode ser jogada
			}
		}
		else
		{
			x=2;//a peca que ele escolheu nao e dele
		}
	}
	else
	{
		if(Tpecas[y].local=='a')
		{
			if(Tpecas[y].peca[0]==VA[0].extremidadeD || Tpecas[y].peca[1]==VA[0].extremidadeD)
			{
				x=1; //1 = peca que pode ser jogada na mesa
			}
			else if(Tpecas[y].peca[0]==VA[0].extremidadeE|| Tpecas[y].peca[1]==VA[0].extremidadeE)
			{
				x=1;
			}
			else
			{
				x=2; //2 = peca que nao pode ser jogada
			}
		}
		else
		{
			x=2;//a peca que ele escolheu nao e dele
		}
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

int AcabaJogoVScomputador( int y, pecas Tpecas[28])//funcao que verifica se resta alguma peca na mao do jogador que acabou de jogar
{									   //caso o jogador esteja sem pecas, entao a funcao retorna 2 que encerra o jogo e o declara como vencedor	
	int cont=0, i, cont2=0;	
	y=y-1;
	if(y%2!=0)
	{
		cont2=1;
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
		cont=1;
		for(i=0;i<28;i++)
		{
			if(Tpecas[i].local=='a')
			{
				cont2++;
			}
		}
	}

	if(cont==0)
	{
		printf("\nVOCE GANHOU O JOGO, PARABENS\n");
		return 2;//para encerrar o jogo
	}
	else if(cont2==0)
	{
		printf("o COMPUTADOR ganhou de voce, parabens");
		return 2;//para continuar o jogo
	}
	else
	{
		return 1;
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

int Empate(pecas Tpecas[28], Variaveis VA[1])//funcao que verifica possivel empate
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

int EmpateVScomputador(pecas Tpecas[28], Variaveis VA[1])//funcao que verifica possivel empate entre o jogador e o computador
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
				printf("o jogador ganhou o jogo");
				return 2;
			}
			else if(result2>result1)
			{
				printf("o COMPUTADOR ganhou o jogo");
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

void GravaJogo(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//nao esta funciando
{
	
	int i, y;
	y=VA[0].rodadas;
	if((ap=fopen("PecasJ", "w")) == NULL)// if((ap = fopen("PecasJ", "w")) == NULL)//pecasJ sao as pecas dos jogadores
	{
		printf("O arquivo PecasJ nao pode ser aberto para gravacao");
		//return;
	}
	for(i=0;i<28;i++)
	{
		if(fwrite(&Tpecas[i], sizeof(pecas),1,ap) != 1)
		{
			printf("erro na gravacao do arquivo pecasJ\n");
			//return;
		}
	}

	fclose(ap);

	if((am=fopen("PecasM", "w"))==NULL)//pecasM sao as pecas da mesa
	{
		printf("O arquivo PecasM nao pode ser aberto para gravacao");
		return;
	}
	for(i=0;i<y;i++)
	{
		if(fwrite(&pecaMesa[i], sizeof(mesa),1,am)!=1)
		{
			printf("erro na gravacao do arquivo pecasM");
			return;
		}
	}
	fclose(am);

	if((av=fopen("variaveis", "w"))==NULL)//variaveis sao as variaveis do jogo
	{
		printf("o arquivo variaveis nao pode ser aberto para gravacao");
	}
	if(fwrite(&VA[0], sizeof(Variaveis),1,av)!=1)
	{
		printf("erro na gravacao do arquivo variaveis");
	}
	fclose(av);
}

void LerJogoSalvo(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//nao esta funcionado
{

	int i;

	if((ap=fopen("PecasJ", "r"))==NULL)
	{
		printf("o arquivo PecasJ nao pode ser aberto para leitura");
	}
	for(i=0;i<28;i++)
	{
		if(fread(&Tpecas[i], sizeof(pecas),1,ap)!=1)
		{
			printf("erro na leitura do arquivo pecasM");
		}
	}
	fclose(ap);

	if((av=fopen("variaveis", "r"))==NULL)
	{
		printf("o arquivo variaveis nao pode ser aberto para gravacao");
	}
	if(fread(&VA[0], sizeof(Variaveis),1,av)!=1)
	{
		printf("erro na gravacao do arquivo variaveis");
	}
	fclose(av);
	

	if((am=fopen("PecasM", "r"))==NULL)
	{
		printf("o arquivo PecasM nao pode ser aberto para leitura");
	}
	for(i=0;i<VA[0].rodadas;i++)
	{
		if(fread(&pecaMesa[i], sizeof(mesa),1,ap)!=1)
		{
			printf("erro na leitura do arquivo pecasM");
			
		}
	}
	fclose(am);


}

void ComputadorJogando(pecas Tpecas[28], mesa pecaMesa[28], Variaveis VA[1])//funcao que realiza as jogadas do computador
{
	int i, y, x=0, k, j=0, p=0, u=0, h=0, o=0;
	y=VA[0].rodadas;
	while(j!=2)//while para procurar as possiveis pecas que o computador pode jogar
	{
		if(Tpecas[x].local=='a')
		{
			if(Tpecas[x].peca[0]==VA[0].extremidadeE||Tpecas[x].peca[1]==VA[0].extremidadeE)//verifica se a peca pode ser jogada na extremidade esquerda
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
				printf("o computador jogou a peca [ %d | %d ]\n", Tpecas[x].peca[0], Tpecas[x].peca[1]);
				j=2;
				
			}
			else if(Tpecas[x].peca[0]==VA[0].extremidadeD||Tpecas[x].peca[1]==VA[0].extremidadeD)//verifica se a peca pode ser jogada do lado direito
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
				printf("o computador jogou a peca [ %d | %d ]\n", Tpecas[x].peca[0], Tpecas[x].peca[1]);
				j=2;
			}
		}
		x++;
		if(x>28)//caso ele n tenha nenhuma peca a ser jogada, ele entra nessa funcao para comprar uma peca
		{
			while(u!=2)
			{
				if(Tpecas[p].local=='d')
				{
					Tpecas[p].local='a';
					o=p;
					printf("\no computador comprou uma peca\n");
					h=verifica(p,Tpecas,pecaMesa,VA);//verifica se a peca que ele comprou pode ser jogada
					if(h==1)
					{
						u=2;
					}
				}
				p++;
				if(p>29)//caso nao tenha nenhuma peca para ser comprada
				{
					u=2;
				}
			}

			if(p>29)//faz com que o computador passe a vez
			{
				printf("\no computador passou a vez pois nao ha mais pecas para comprar\n");
				VA[0].qualJogador++;
				j=2;
			}
			else//faz com que o computador jogue a peca que acabou de comprar e que pode ser jogada
			{
				if(Tpecas[o].peca[0]==VA[0].extremidadeE||Tpecas[o].peca[1]==VA[0].extremidadeE)
				{
					for(i=y; i>0; i--)//joga a mesa para a direita para incerir uma peca na esquerda
					{
						pecaMesa[i].pecaJogada[0]=pecaMesa[i-1].pecaJogada[0];
						pecaMesa[i].pecaJogada[1]=pecaMesa[i-1].pecaJogada[1];
					}
					if(Tpecas[o].peca[1]==VA[0].extremidadeE)//caso a peca esteja virada do lado certo
					{
						pecaMesa[0].pecaJogada[0]=Tpecas[o].peca[0];
						pecaMesa[0].pecaJogada[1]=Tpecas[o].peca[1];
						VA[0].extremidadeE=Tpecas[o].peca[0];
						VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];
					}
					else//caso a peca esteja virada do lado errado
					{
						pecaMesa[0].pecaJogada[1]=Tpecas[o].peca[0];
						pecaMesa[0].pecaJogada[0]=Tpecas[o].peca[1];
						VA[0].extremidadeE=Tpecas[o].peca[1];
						VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//
					}
					Tpecas[o].local='m';//muda o local da peca para a mesa
					VA[0].rodadas=VA[0].rodadas+1;//aumenta o numero de rodadas 
					VA[0].qualJogador++;//passa a vez para o proximo jogador
					printf("o computador jogou a peca [ %d | %d ]\n", Tpecas[o].peca[0], Tpecas[o].peca[1]);
					j=2;
				
				}
				else if(Tpecas[o].peca[0]==VA[0].extremidadeD||Tpecas[o].peca[1]==VA[0].extremidadeD)//caso a peca tenha q ir para a extremidade direita da mesa
				{
					pecaMesa[y].pecaJogada[1]=Tpecas[o].peca[1];//so adicionando uma peca na extremidade direita
					pecaMesa[y].pecaJogada[0]=Tpecas[o].peca[0];//so adicionando uma peca na extremidade direita

					if(VA[0].extremidadeD!=pecaMesa[y].pecaJogada[0])//caso a peca esteja virada do lado errado
					{
						k=pecaMesa[y].pecaJogada[0];
						pecaMesa[y].pecaJogada[0]=pecaMesa[y].pecaJogada[1];
						pecaMesa[y].pecaJogada[1]=k;
					}
					Tpecas[o].local='m';
					VA[0].extremidadeD=pecaMesa[y].pecaJogada[1];//muda a extremidade da mesa para a nova peca
					VA[0].rodadas=VA[0].rodadas+1;//aumenta o numero de rodadas
					VA[0].qualJogador++;//passa a vez para o proximo jogador
					printf("o computador jogou a peca [ %d | %d ]\n", Tpecas[o].peca[0], Tpecas[o].peca[1]);
					j=2;
				}
			}	
		}
		
	}
	
}
