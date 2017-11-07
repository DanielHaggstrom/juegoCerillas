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
