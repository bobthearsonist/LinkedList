#include "List.h"
#include <string>
#include <list>
#include <cassert>

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
	people teachers[TEST_LIST_SIZE];
	teachers[0].name = "Bob";
	teachers[1].name = "Sally";
	teachers[2].name = "Susan";

	//create MTL list of objects
	List<people>* list = new List<people>();
	for (int i = 0; i<TEST_LIST_SIZE;i++)
	{
		list->insert(teachers[i]);
	}
	//test for correct size
	assert(list->size() == TEST_LIST_SIZE);
	//
	assert( list->head->item.name.compare(teachers[0].name) == 0 );

	//create STL list of objects
	std::list<people>* stlList = new std::list<people>();
	stlList->push_front(teachers[0]);
	stlList->pop_front();

	for (int i = 0; i<4;i++)
	{
		list->insert(teachers[i]);
	}

	return EXIT_SUCCESS;
}
}//MTL_Test
