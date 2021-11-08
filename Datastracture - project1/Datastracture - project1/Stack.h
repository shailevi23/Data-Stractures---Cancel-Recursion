#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

#include "ItemType.h"

class Stack
{
private:
	ItemType* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool IsEmpty();
	void Push(ItemType& node);
	ItemType Pop();
	ItemType Top();
};

#endif