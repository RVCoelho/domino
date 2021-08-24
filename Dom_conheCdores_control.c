//control
//funcoes do domino



void Domino(pecas Tpecas[28], mesa pecaMesa[28]);
void geraPeca(pecas Tpecas[28]);
void embaralha(pecas Tpecas[28]);
void distribui(pecas Tpecas[28]);
void compraPeca(pecas Tpecas[28], mesa pecaMesa[28]);


void Domino(pecas Tpecas[28], mesa pecaMesa[28])
{
	int o, y;
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
			pecasJogador(Tpecas, pecaMesa);
			Jogadas(Tpecas,pecaMesa);
			break;
			
		case 2:
			printf("");	
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

void compraPeca(pecas Tpecas[28], mesa pecaMesa[28])
{
	int i=0, x, k, cont;
	x=PrimeiraJogada(Tpecas, pecaMesa);
	if(x==2)
	{
		do
		{
			for(i=0; i<28; i++)
			{
				if(Tpecas[i].local=='d')
				{
					for(k=28; k>=0; k--)
					{
						if(Tpecas[k].local=='a')
							cont++;
						else if(Tpecas[k].local=='j')
						{
							if(Tpecas[k+1].local=='d')
							{
								Tpecas[k+1].local='j';
								printf("\n%d- ( %d | %d )", k+1, Tpecas[k+1].peca[0], Tpecas[k+1].peca[1]);
								if(Tpecas[k+1].peca[0] != pecaMesa[28].ladoD || Tpecas[k+1].peca[0] != pecaMesa[28].ladoE || Tpecas[k+1].peca[1] != pecaMesa[28].ladoD || Tpecas[k+1].peca[1] != pecaMesa[28].ladoE)
									printf("\nA peca comprada nao pode ser jogada. Outra peca sera comprada!");
									k--;
								if(Tpecas[k+1].peca[0] == pecaMesa[28].ladoD || Tpecas[k+1].peca[0] == pecaMesa[28].ladoE || Tpecas[k+1].peca[1] == pecaMesa[28].ladoD || Tpecas[k+1].peca[1] == pecaMesa[28].ladoE)
									printf("\nEssa peca pode ser jogada!");
							}
							else if(Tpecas[k+1].local=='a')
								Tpecas[k+cont+1].local='j';
								printf("\n%d- ( %d | %d )", k+cont+1, Tpecas[k+cont+1].peca[0], Tpecas[k+cont+1].peca[1]);
								if(Tpecas[k+cont+1].peca[0] != pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[0] != pecaMesa[28].ladoE || Tpecas[k+cont+1].peca[1] != pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[1] != pecaMesa[28].ladoE)
									printf("\nA peca comprada nao pode ser jogada. Outra peca sera comprada!");
									k--;
								if(Tpecas[k+cont+1].peca[0] == pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[0] == pecaMesa[28].ladoE || Tpecas[k+cont+1].peca[1] == pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[1] == pecaMesa[28].ladoE)
									printf("\nEssa peca pode ser jogada!");
						}
					}
				}
			}
		}while(Tpecas[i].peca[0] != pecaMesa[28].ladoD || Tpecas[i].peca[0] != pecaMesa[28].ladoE || Tpecas[i].peca[1] != pecaMesa[28].ladoD || Tpecas[i].peca[1] != pecaMesa[28].ladoE);
		//while(Tpecas[i].peca[0] != pecaMesa[28].ladoD || Tpecas[i].peca[0] != pecaMesa[28].ladoE || Tpecas[i].peca[1] != pecaMesa[28].ladoD || Tpecas[i].peca[1] != pecaMesa[28].ladoE);
		//faz o loop de comprar peça até possuir uma peça que possui um número que pode ser jogado
	}
	else if(x==1)
	{
		do
		{
			for(i=0; i<28; i++)
			{
				if(Tpecas[i].local=='d')
				{
					for(k=28; k>=0; k--)
					{
						if(Tpecas[k].local=='j')
							cont++;
						else if(Tpecas[k].local=='a')
						{
							if(Tpecas[k+1].local=='d')
							{
								Tpecas[k+1].local='a';
								printf("\n%d- ( %d | %d )", k+1, Tpecas[k+1].peca[0], Tpecas[k+1].peca[1]);
								if(Tpecas[k+1].peca[0] != pecaMesa[28].ladoD || Tpecas[k+1].peca[0] != pecaMesa[28].ladoE || Tpecas[k+1].peca[1] != pecaMesa[28].ladoD || Tpecas[k+1].peca[1] != pecaMesa[28].ladoE)
									printf("\nA peca comprada nao pode ser jogada! voce tem que comprar outra peca!");
									k--;
								if(Tpecas[k+1].peca[0] == pecaMesa[28].ladoD || Tpecas[k+1].peca[0] == pecaMesa[28].ladoE || Tpecas[k+1].peca[1] == pecaMesa[28].ladoD || Tpecas[k+1].peca[1] == pecaMesa[28].ladoE)
									printf("\nEssa peca pode ser jogada!");
							}
							else if(Tpecas[k+1].local=='j')
								Tpecas[k+cont+1].local='a';
								printf("\n%d- ( %d | %d )", k+cont+1, Tpecas[k+cont+1].peca[0], Tpecas[k+cont+1].peca[1]);
								if(Tpecas[k+cont+1].peca[0] != pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[0] != pecaMesa[28].ladoE || Tpecas[k+cont+1].peca[1] != pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[1] != pecaMesa[28].ladoE)
									printf("\nA peca comprada nao pode ser jogada! voce tem que comprar outra peca!");
									k--;
								if(Tpecas[k+cont+1].peca[0] == pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[0] == pecaMesa[28].ladoE || Tpecas[k+cont+1].peca[1] == pecaMesa[28].ladoD || Tpecas[k+cont+1].peca[1] == pecaMesa[28].ladoE)
									printf("\nEssa peca pode ser jogada!");
						}
					}
				}
			}
		}while(Tpecas[i].peca[0] != pecaMesa[28].ladoD || Tpecas[i].peca[0] != pecaMesa[28].ladoE || Tpecas[i].peca[1] != pecaMesa[28].ladoD || Tpecas[i].peca[1] != pecaMesa[28].ladoE);
		//faz o loop de comprar peça até possuir uma peça que possui um número que pode ser jogado
	}
}
