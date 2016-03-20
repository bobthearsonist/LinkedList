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

	const int TEST_LIST_SIZE = 6;
}//MTL_Test

using namespace MTL_Test;
void main(void)
{
	//create objects for test
	people teachers[TEST_LIST_SIZE];
	teachers[0].name = "Bob";
	teachers[1].name = "Sally";
	teachers[2].name = "Jim";
	teachers[3].name = "Rachel";
	teachers[4].name = "Anthony";
	teachers[5].name = "Antuane";
	people person;
	//iterators
	List<people>::iterator mtlListIterator;
	int index;

	/**************************************************************************************************************
	This section was coded up as a control to compare my implementations against. It could be removed when done,
	but I left it here to show what I was doing.
	***************************************************************************************************************/

	std::list<people>::iterator stlListIterator;
	//create STL list of objects
	std::list<people>* stlList = new std::list<people>();

	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		stlList->insert(stlList->begin(), teachers[i]);
	}
	//YOU CANT GET THE HEAD THIS WAY!
	//person head_person = stlList->head->item;
	people head_person = stlList->front();

	//note that we declare an iterator from the container class.
	//we do not innitialize the list form the iterator class like this
	//for (stlListIterator.begin(); stlListIterator.end(); mtlListIterator++)
	//we use the container class to initialize it, menaing it is not defined in the iterator but in the container
	index = TEST_LIST_SIZE - 1;
	for (stlListIterator = stlList->begin(); stlListIterator != stlList->end(); ++stlListIterator, --index)
	{
		//this was expanded out to aid in debugging
		people currentPerson = (*stlListIterator);
		people originalPerson = teachers[index];
		assert(currentPerson.name.compare(originalPerson.name) == 0);
	}

	//insert into the middle of the list
	stlListIterator = stlList->begin();
	while (stlListIterator->name != "Jim")
	{
		people currentPerson = *stlListIterator;
		++stlListIterator;
	}
	person = people("Leeroy");
	stlList->insert(stlListIterator, person);
	index = 0;
	for (stlListIterator = stlList->begin(); stlListIterator->name != "Leeroy" && stlListIterator != stlList->end(); ++stlListIterator, ++index)
	{
		people currentPerson = *stlListIterator;
	}
	stlList->clear();

	//now lets look at push_front and push_back and see which is the same as insert(head,item)
	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		stlList->push_front(teachers[i]);
	}
	index = TEST_LIST_SIZE - 1;
	for (stlListIterator = stlList->begin(); stlListIterator != stlList->end(); ++stlListIterator, --index)
	{
		//this was expanded out to aid in debugging
		people currentPerson = (*stlListIterator);
		people originalPerson = teachers[index];
	}
	stlList->clear();
	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		stlList->push_back(teachers[i]);
	}
	index = 0;
	for (stlListIterator = stlList->begin(); stlListIterator != stlList->end(); ++stlListIterator, ++index)
	{
		//this was expanded out to aid in debugging
		people currentPerson = (*stlListIterator);
		people originalPerson = teachers[index];
	}
	stlList->clear();
	//this has shown that push_fornt inserts at head and push_back inserts at the tail

	//now lets look at the stl remove and pop
	stlList->push_front(teachers[0]);
	stlList->pop_front();
	stlList->push_front(teachers[0]);
	//TODO you need an == defined for people before you can use remove.
	//stlList->remove(teachers[0]);

	/**************************************************************************************************************
	This section tests the MTL List class. Its behavior is meant to mdel that of the STL as closely as possible
	***************************************************************************************************************/

	//constructor tests
	//TODO implement a copy contructor for an array
	//List<people> staticlist(teachers[0],teachers[0] + (TEST_LIST_SIZE-1))

	//create MTL list of objects
	List<people>* list = new List<people>();
	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		list->insert(list->begin(),teachers[i]);
	}
	//test size and for correct size after insert
	assert(list->size() == TEST_LIST_SIZE);
	//The stl does not allow this, which is why you were having problems. head is always an empty item
	//test that the head was set properly
	//assert(list->head->item.name.compare(teachers[TEST_LIST_SIZE-1].name) == 0);
	//test instead that we have the right person at the front
	assert(list->front().name.compare(teachers[TEST_LIST_SIZE-1].name) == 0);

	//test that the values were set appropriately
	//tests the iterator operator++(), operator*, and the operator++() of the inherited classes
	//tests the list begin and end
	//tests the iterator assignment operator
	index = TEST_LIST_SIZE-1;
	for (mtlListIterator = list->begin(); mtlListIterator != list->end(); ++mtlListIterator, --index)
	{
		//this was expanded out to aid in debugging
		people currentPerson = (*mtlListIterator);
		people originalPerson = teachers[index];
		assert(currentPerson.name.compare(originalPerson.name) == 0);
	}

	//test insertion at the middle of the list, the expected insertion point is BEFORE the target
	//note that this is the opposite of what we dsicussed in class, but is the expected behavior of the stl
	mtlListIterator = list->begin();
	while ((*mtlListIterator).name != "Jim")
	{
		++mtlListIterator;
	}
	person = people("Leeroy");
	list->insert(mtlListIterator, person);
	//make sure we dont get the tartget item before insert item, which would indicate we inserted after the target. 
	//remember the list index and the array index are flipped because we inserted at the head so we count backwards
	index = 0;
	for (mtlListIterator = list->begin(); (*mtlListIterator).name != "Leeroy" && mtlListIterator!=list->end(); ++mtlListIterator,++index)
	{
		people currentPerson = *mtlListIterator;
	}
	assert(index == 3);
	//make sure the item after the inserted item is the target item, proving we didnt insert after the target
	++mtlListIterator;
	assert((*mtlListIterator).name == "Jim");

	//test clear and empty
	list->clear();
	assert(list->empty());

	//test push_front
	for (int i = 0; i<TEST_LIST_SIZE; i++)
	{
		list->push_front(teachers[i]);
	}
	index = TEST_LIST_SIZE - 1;
	for (mtlListIterator= list->begin(); mtlListIterator!= list->end(); ++mtlListIterator, --index)
	{
		//this was expanded out to aid in debugging
		people currentPerson = (*mtlListIterator);
		people originalPerson = teachers[index];
		assert(currentPerson.name.compare(originalPerson.name) == 0);
	}

	//test pop_front and front and empty
	index = TEST_LIST_SIZE - 1;
	while(!list->empty())
	{
		people currentPerson = list->front();
		people originalPerson = teachers[index--];
		assert(currentPerson.name.compare(originalPerson.name) == 0);
		list->pop_front();
	}

	//TODO test our underflow exception
	try
	{
		//list->pop_front();
	}
	catch(std::exception exception)
	{
		
	}
	

}


