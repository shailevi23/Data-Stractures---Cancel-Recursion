#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

#include "AccessibleGroupList.h"
#include "List.h"
#include "ListNode.h"

const int FIRST = 2;
const int SECONED = 3;
const int THIRD = 4;

class ItemType
{
private:
	int ITPROTOTYPE_moked;
	ListNode* ITLOCAL_currentComputerNode;
	int ITLOCAL_ComputerDataNumber;
	int IT_LINE;
	ItemType* next;

public:
	ItemType(); // c'tor
	ItemType(ItemType node, ItemType* nextIT); // c'tor
	ItemType(int ITPROTOTYPE_networkArr_computerNumber, ListNode* ITLOCAL_currentComputerNode,
		int ITLOCAL_ComputerDataNumber,	int IT_LINE); // c'tor
	~ItemType();
	ItemType* getNextNode() const;
	int getLine() const;
	int getMoked() const;
	ListNode* getCurrentComputerNode() const;

	void setCurrentComputerNodeInListValue(const int num);
	void setLine(const int num);
	void setMoked(const int num);
	void setCurrentComputerNodeInList(ListNode* currentComputerNode);

};
#endif

