#include "stack.h"
stack::stack()
	:head(nullptr)
{

}

stack::~stack()
{
	makeEmpty();
	delete head;
}

void stack::Push(ItemType &data)
{
	ItemType temp(data);
	itemTypeNode* newHead = new itemTypeNode{ temp, head };
	head = newHead;
}



ItemType stack::Pop()
{
	if (isEmpty() == true)
	{
		return -1;
	}
	else
	{
		itemTypeNode *temp = head;
		head = head->next;
		ItemType res(temp->_data);
		delete temp;
		return res;
	}
}

bool stack::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

void stack::makeEmpty()
{
	itemTypeNode* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}