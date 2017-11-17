#ifndef GAME
#define GAME

#include <string>
#include "GraphInter.h"

class Game
{
private:
	
	int cerillas; // numero de cerillas iniciales
	
	void actualizar(int movimiento); // Actualiza el número de cerillas en la mesa, después de llevar a cabo el movimiento
	bool validMove(int move); // Devuelve true si el movimiento es correcto, y false si no
	
	int digitoAutomata();
	int botFacil();
	int botDificil();
	int botImposible();
	bool minimax(int total, bool turno); // ? no se muy bien que hace. ¿Es true si el movimiento es el óptimo?
	
	
public:

	Game(int cerillasIni): cerillas(cerillasIni) {};

	void Single(Game game);
	void Double(Game game);
};
#endif