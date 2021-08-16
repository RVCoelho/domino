//view

//#include<stdio.h>


int menu();
void apresentaMesa(pecas Tpecas[28], mesa pecaMesa[28]);
int Maiorpeca(pecas Tepcas[28]);

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
	int y;
	y=Maiorpeca(Tpecas);
	printf("%d", y);
	
}
int Maiorpeca(pecas Tpecas[28])
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
}
