#ifndef GAME
#define GAME

class Game
{
private:
	
	int cerillas; // numero de cerillas iniciales
	
	void actualizar(int movimiento);
	bool validMove(int move);
	
	
public:

	Game(int cerillasIni): cerillas(cerillasIni) {};

	void Single(Game game);
	void Double(Game game);
};
