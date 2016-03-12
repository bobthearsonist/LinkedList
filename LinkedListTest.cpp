#include "List.h"
#include <string>
#include <list>
#include <vector>
#include <cassert>

using namespace MTL;

namespace MTL_Test {
	class people
	{
	public:
		people(std::string name = "") { this->name = name; }
		std::string name;
	};

	const int TEST_LIST_SIZE = 3;
}//MTL_Test

using namespace MTL_Test;
void main(void)
{
	//create objects for test
	people teachers[TEST_LIST_SIZE];
	teachers[0].name = "Bob";
	teachers[1].name = "Sally";
	teachers[2].name = "Susan";

	//constructor tests
	//TODO implement a copy contructor for an array
	//List<people> staticlist(teachers[0],teachers[0] + (TEST_LIST_SIZE-1))

	//create MTL list of objects
	List<people>* list = new List<people>();
	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		list->insert(teachers[i]);
	}
	//test for correct size
	assert(list->size() == TEST_LIST_SIZE);
	//test that

	List<people>::iterator mtlListIterator;
	for (List<people>::iterator mtlListIterator = list->begin(); mtlListIterator!= list->end(); ++mtlListIterator)
	{

	}

	/*
	This section was coded up as a control to compare my implementations against. It could be removed when done,
	but I left it here to show what I was doing.
	*/


	//create STL list of objects
	std::list<people>* stlList = new std::list<people>();
	stlList->push_front(teachers[0]);
	stlList->pop_front();

	for (int i = 0; i<4; i++)
	{
		list->insert(teachers[i]);
	}
	//note that we declare an iterator from the container class.

	//we do not innitialize the list form the iterator class like this
	//for (stlListIterator.begin(); stlListIterator.end(); mtlListIterator++)
	//we use the container class to initialize it, menaing it is not defined in the iterator but in the container
	for (std::list<people>::iterator stlListIterator = stlList->begin(); stlListIterator != stlList->end(); ++stlListIterator)
	{

	}
}


