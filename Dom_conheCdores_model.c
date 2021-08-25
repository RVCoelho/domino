//arquivo model

int qualJogador;
int extremidadeD;
int extremidadeE;

typedef struct gera
{
	int peca[2];
	char local;
	
}pecas;

typedef struct tabuleiro
{
	int ladoE;
	int ladoD;
	int pecaJogada[2];
	int rodadas;	
	
}mesa;
