#include "Game.h"

bool Game::validMove(int move)
{
	if(cerillas >= move) reuturn true;
	
	else return false;
}

void Game::actualizar(int move)
{
	cerillas -= move;
}

void Game::Single(Game game) 
{ // funcion donde ocurre el juego en si
	std::string user = GraphInter::get()->validUser("Jugador");
	Dificultad nivel = nivel();
	Turno turno = TurnoSimple();
	int move = 0;
	
	do
	{
		if(turno == Jugador)
		{
			move = playermove(user);	
		}
		if(turno == Automata)
		{
			switch(nivel)
			{
				case Facil:
					move = automove();
					break;
				case Dificil:
					move = botDificil();
					break;
				case Imposible:
					move = botImposible();
					break;	
			}	
		}
		actualizar(move);
		
	} while(cerillas > META);
	
	despedirseSimple(turno);
}

void Game::Double(Game game)
{
	std::string user1 = GraphInter::get()->validUser("Jugador 1");
	std::string user2 = GraphInter::get()->validUser("Jugador 2");
	Turno turno = TurnoDoble();
	int move = 0;
	
	do
	{
		if(turno == Jugador1)
		{
			move = playermove(user1);	
		}
		if(turno == Jugador2)
		{
			move = playermove(user2);
		}
		actualizar(move);
		
	} while(cerillas > META);
	
	despedirseDoble(turno);
}
