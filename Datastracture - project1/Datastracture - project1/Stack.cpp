#include "Stack.h"

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	ItemType* temp;
	while (top != NULL)
	{
		temp = top;
		top = top->getNextNode();
		delete temp;
	}
}

bool Stack::IsEmpty()
{
	if (top == NULL)
		return true;
	return false;
}

void Stack::Push(ItemType& node)
{
	top = new ItemType(node, this->top);
}

ItemType Stack::Pop()
{
	if (IsEmpty())
		exit(1);
	ItemType* temp = top;
	ItemType item = *top;
	top = top->getNextNode();
	delete temp;
	return item;
}

ItemType Stack::Top()
{
	ItemType x;
	x = Pop();
	Push(x);
	return x;
}
