#ifndef GRAPHINTER
#define GRAPHINTER

class GraphInter
{
private:

	static GraphInter* inter;

	GraphInter() {}
  
  int update(int key, int elem, int max_elems);
  
  int menu(std::vector<std::string> elems);
  
  std::string tab_word(std::string word);
	std::string pags(Session* session);
  
public:

	static GraphInter* get();
	static void close();
	static void load();
  
  std::string center_word(std::string word, int length, std::string arround);
  
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
