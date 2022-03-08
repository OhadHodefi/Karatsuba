#pragma once
#include "itemtype.h"
#include <cstring>

class stack
{
private:
	struct itemTypeNode
	{
		ItemType _data;
		itemTypeNode* next;
	};
	itemTypeNode* head = nullptr;

public:

	stack();
	~stack();
	void Push(ItemType &ata);
	ItemType Pop();
	bool isEmpty();
	void makeEmpty();

};


