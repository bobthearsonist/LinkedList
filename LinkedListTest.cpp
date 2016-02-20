#include "List.h"
#include <string>
#include <list>

using namespace MTL;

namespace MTL_Test{
class people
{
public:
	people(std::string name = ""){this->name = name;}
	std::string name;
};

const int TEST_LIST_SIZE = 3;

int main()
{
	//create objects for test
	people teachers[];
	teachers[0].name = "Bob";
	teachers[1].name = "Sally";
	teachers[2].name = "Susan";

	//create MTL list of objects
	List<people>* list = new List<people>();
	for (int i = 0; i<4;i++)
	{
		list->insert(teachers[i]);
	}

	//create STL list of objects
	std::list<people>* stlList = new std::list<people>();
	stlList->push_front(teachers[0]);
	stlList->pop_front();



	return EXIT_SUCCESS;
}
}//MTL_Test
