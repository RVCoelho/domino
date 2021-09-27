//arquivo model


typedef struct MaoJogador		// estrutura que guarda todas as pecas do jogo
{
	int peca[2];				//variavel para guardar os dois valores de uma peca
	char local;					//para guardar o local onde a peca se encontra, ex j1, j2, mesa ou pote de compra
	
} pecas;

typedef struct tabuleiro		//estrutura para guardar as  pecas que sao jogadas na mesa
{
	int pecaJogada[2];			//variavel para guardar os dois valores de uma peca jogada na mesa

} mesa;

typedef struct Tvariaveis		//estrutura para guardar as variaveis usadas na logica do jogo
{
	int qualJogador;			//variavel que guarda a vez do jogador que esta jogando
	int extremidadeD;			//variavel que guarda a extremidade diretira da mesa
	int extremidadeE;			//variavel que guarda a extremidade direita da mesa
	int rodadas;				//variavel que guarda o numero de rodadas ja realizadas no jogo

} Variaveis;


	FILE *ap;					//arquivo para salvar a estrutra pecas
	FILE *am;					//arquivo para salvar a estrutura mesa
	FILE *av;					//arquivo para salvar a estrutura variaveis

pecas Tpecas[28];
mesa pecaMesa[28];
Variaveis VA[1];	
