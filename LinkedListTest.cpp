#include "List.h"
#include <string>
#include <list>

using namespace MTL;

class people
{
public:
	people(std::string name = ""){this->name = name;}
	std::string name;
};

int main()
{
	people teachers[3];
	teachers[0].name = "Bob";
	teachers[1].name = "Sally";
	teachers[2].name = "Susan";
	List<people>* list = new List<people>();
	std::list<people>* stlList = new std::list<people>();
	stlList->push_front(teachers[0]);
	stlList->pop_front();

	for (int i = 0; i<4;i++)
	{
		list.insert(teachers[i]);
	}

	return EXIT_SUCCESS;
}
