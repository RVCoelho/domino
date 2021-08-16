//control
//funcoes do domino



void Domino(pecas Tpecas[28], mesa pecaMesa[28]);
void geraPeca(pecas Tpecas[28]);
void embaralha(pecas Tpecas[28]);
void distribui(pecas Tpecas[28]);
//int Maiorpeca(pecas Tepcas[28]);




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
			Maiorpeca(Tpecas);
			printf("-----------\n");
			printf("\n%d", Maiorpeca(Tpecas));
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
	//faz a distribuicao das pecas para a mao do j=jogador, a=adversario, d=deposito
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

/*int Maiorpeca(pecas Tpecas[28])
{
	int i, x=0, maior=0;
	
	for(i=0;i<28;i++)
	{
		if(Tpecas[i].local=='j')
			printf("%d- (%d | %d ) ", i,  Tpecas[i].peca[0], Tpecas[i].peca[1]);
	}
	printf("\n");
	for(i=0;i<28;i++)
	{
		if(Tpecas[i].local=='a')
			printf("%d-  (%d | %d ) ", i, Tpecas[i].peca[0], Tpecas[i].peca[1]);
	}
	
	printf("\n");
	for(i=0;i<28;i++)
	{
		if(Tpecas[i].local=='j'||Tpecas[i].local=='a')
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
	return x;
}*/
