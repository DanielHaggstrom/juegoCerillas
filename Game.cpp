#include "Game.h"

bool Game::validMove(int move)
{
	if(cerillas >= move) return true;
	
	else return false;
}

void Game::actualizar(int move)
{
	cerillas -= move;
}

int Game::digitoAutomata()
{
	return (rand() % 3) + 1;
}

int Game::botFacil()
{
	return digitoAutomata();
}

int Game::BotDificil(int restantes)
{
	if (restantes == 4) return botFacil();
	
	else
	{
		if (restantes < 4) return restantes;
		
		else
		{
			for(int i = 1; i <= 3)
			{
				if((restantes - i) == 4) return i;
			}
			return botFacil();
		}
	}
}

int Game::botImposible()
{
	int move = 0;
	
	for(int i = 1; i <= 3)
	{
		if(validMove(i))
		{
			if(minimax(i, cerillas, true)) return i;
		}
	}
	return botDificil();
}

bool Game::minimax(int move, int total, bool turno)
{
	if(total <= 0) return turno;
	
	if(turno)
	{
		bool bestValue = false;
		int i = 1;
		
		while(i <= 3 &&!bestValue)
		{
			if(validMove(i) bestValue = minimax(i, total - i, false);
			
			i++;
		}
		return bestValue;
	}
	if(!turno)
	{
		bool worstValue = true;
		int j = 1;
		
		while(j <= 3 && worstValue)
		{
			if(validMove(i) worstValue = minimax(i, total - i, true);
			
			j++;
		}
		return worstValue;
	}
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
					move = botFacil();
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
