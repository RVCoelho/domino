//arquivo model

//arquivo model

FILE *ap;
FILE *am;
FILE *av;

typedef struct MaoJogador
{
	int peca[2];
	char local;
	
}pecas;

typedef struct tabuleiro
{
	int ladoE;
	int ladoD;
	int pecaJogada[2];
}mesa;

typedef struct Tvariaveis
{
	int qualJogador;
	int extremidadeD;
	int extremidadeE;
	int rodadas;	

} Variaveis;


pecas Tpecas[28];
mesa pecaMesa[28];
Variaveis VA[1];	
