#include "Game.h"

class Game {
	int cerillas; // numero de cerillas iniciales



public:

	int cerillasRestantes(int cerillas, int movimiento) {
		return (cerillas - movimiento);
	}

	Game() {
		cerillas = 0; // numero defauls de cerillas
	}

	void funcionPrincipal(int cerillas) { // funcion donde ocurre el juego en si
		int round = 0; // This is the current round that is being played. Initilize in 0 to start in 1.
		while (cerillas > 0) {
			round++;
			/* 
			player = getPlayer(round);
			int movimiento = getMovimiento(player);
			cerillas = cerillasRestantes(cerillas, movimiento);
			*/

		}
	}
};