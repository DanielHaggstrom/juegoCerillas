#include "GraphInter.h"
#include "utilsWin.h
#include <algorithm>
#include <iostream>
#include <sstream>
#include <conio.h>

GraphInter* GraphInter::inter = nullptr;

int GraphInter::update(int key, int elem, int max_elems)
{
	if (key == UP) elem--;
	if (key == DOWN) elem++;

	if (elem < 0) elem = max_elems - 1;
	if (elem >= max_elems) elem = 0;

	if (key == ESCAPE) elem = max_elems - 1;
	return elem;
}

int GraphInter::menu(std::vector<std::string> elems)
{
	int key = UP, elem = 0;

	do
	{
		display("Which one do you choose?: ");

		for (int i = 0; i < elems.size(); i++)
		{
			tab_word(elems[i], i, elem);
		}

		key = getKey();
		elem = update(key, elem, elems.size());

		clearConsole();

	} while (key != ENTER && key != ESCAPE);

	return elem;
}

void GraphInter::tab_word(std::string word, int pos, int cont)
{
	if (pos == cont) word = "->" + word;

	else word = tab_word(word);

	display(word);
}

std::string GraphInter::tab_word(std::string word)
{
	std::ostringstream tab;

	tab << std::setw(word.size() + 2) << word;

	return tab.str();
}

GraphInter* GraphInter::get() {	return inter; }

void GraphInter::close()
{
	if (inter != nullptr)
	{
		delete inter;
		delete error;
	}
}

void GraphInter::load()
{
	if (inter == nullptr)
	{
		inter = new GraphInter;
		error = errorMail();
	}
}

int GraphInter::modeMenu()
{
	std::vector<std::string> elems;
	
	elems.push_back("Single");
	elems.push_back("Double");
	
	return menu(elems);
}

int GraphInter::difficulty()
{
	std::vector<std::string> elems;
	
	elems.push_back("Facil");
	elems.push_back("Dificil");
	elems.push_back("Experto");
	
	return menu(elems);
}

int GraphInter::playermove(std::string user)
{
	std::vector<std::string> elems;
	
	std::sout << "Tu turno, " << user << ", cuantas cerillas quieres quitar?:"
	
	for(int i = 1; i <= 3; i++)
	{
		if(game->validMove(i))
		{
			if(i == 1) elems.push_back("Quitar " + i + " cerilla");

			else elems.push_back("Quitar " + i + " cerillas");
		}
	}
	
	return (menu(elems) + 1);
}

std::string GraphInter::validUser(Turno jugador)
{
	std::string name = "";
	int i;
	
	do
	{
		switch(jugador)
		{
			case Jugador:
				std::cout << "Bienvenido jugador, como te llamas:";
				break;
			case Jugador1:
				std::cout << "Bienvenido jugador 1, como te llamas:";
				break;
			case Jugador2:
				std::cout << "Bienvenido jugador 2, como te llamas:";
				break;
		}
		std::cin >> name;
		
		if(name == "") std::cout << "Error, debes introducir un nombre" << std::endl;
		
		else if(name[0] < 65 || name[0] > 90)
		{
			std::cout << "Error, el nombre debe empezar por mayúscula" << std::endl;
			name = "";
		}
		else
		{
			i = 1;

			while(i < name.size() && name != "")
			{
				if(name[i] < 97 || name[i] > 122)
				{
					std::cout << "Error, el nombre debe estar formado por letras inusculas (excepto la primera)" << std::endl;
					name = "";
				}
				i++;
			}
		}
	} while(name == "");
	
	return name;
}

void GraphInter::mostrarCerillas(int cuantas)
{
	if (cuantas <= 5)
	{
		for(int i = 1; i <= cuantas; i++)
		{
			std::cout << "* ";
		}
	}
	else
	{
		for(int i = 1; i <= cuantas - 5; i++)
		{
			std::cout << " *";
		}
		std::cout << std::endl;
		
		for(int j = 1; j <= 5; j++)
		{
			std::cout << "* ";
		}
		
		std::cout << std::endl;
	}
}

std::string GraphInter::center_word(std::string word, int length, std::string arround)
{
	if (word.size() < length)
	{
		for (int i = word.size(); i <= length; i++)
		{
			if (word.size() % 2) word += arround;

			else word = arround + word;
		}
	}
	return word;
}

std::string GraphInter::linea()
{
	std::ostringstream line;

	line << std::setfill('-')
		<< std::setw(HORIZONTAL) << '-'
		<< std::setfill(' ');

	return line.str();
}

void GraphInter::clearConsole() { system("cls"); }

void GraphInter::pause()
{
	std::cin.sync();
	std::cin.get();
}

void GraphInter::display(std::string error)
{
	std::cout << error << std::endl;
}

void GraphInter::display(char sign)
{
	std::cout << sign;
}

void GraphInter::enter(std::string &word)
{
	std::cin.sync();
	std::getline(std::cin, word);
	std::cin.clear();
}

void GraphInter::enter(int &digit)
{
	std::cin.sync();
	std::cin >> digit;
	std::cin.clear();
}

void GraphInter::enter(char* str)
{
	std::cin.sync();
	std::cin >> str;
	std::cin.clear();
}
