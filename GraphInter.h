#ifndef GRAPHINTER
#define GRAPHINTER

#include <vector>

class GraphInter
{
private:

	static GraphInter* inter;

	GraphInter() {}
	
	int update(int key, int elem, int max_elems);
  
	int menu(std::vector<std::string> elems);
	
	void tab_word(std::string word, int pos, int cont);
	std::string tab_word(std::string word);
  
public:

	static GraphInter* get();
	static void close();
	static void load();
	
	int modeMenu();
	int difficulty();
	int playermove(std::string player);
  
	std::string center_word(std::string word, int length, std::string arround);
	std::string validUser(Turno jugador);
	
	void mostrarCerillas(int cuantas);
  
	std::string linea();
	void clearConsole();
	void pause();
  
	void display(std::string error);
	void display(char sign);

	void enter(std::string &word);
	void enter(int &digit);
	void enter(char* str);
};
#endif