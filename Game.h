#ifndef GAME
#define GAME

class Game
{
private:
	
	int cerillas; // numero de cerillas iniciales
	
	void actualizar(int movimiento);
	bool validMove(int move);
	
	int digitoAutomata();
	int botFacil();
	int botDificil()_;
	int botImposible();
	bool minimax(int total, bool turno);
	
	
public:

	Game(int cerillasIni): cerillas(cerillasIni) {};

	void Single(Game game);
	void Double(Game game);
};
