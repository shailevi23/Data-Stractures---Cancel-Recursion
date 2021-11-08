#ifndef __LIST_H
#define __LIST_H

#include "ListNode.h"
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class List
{
public:
	List();
	~List();
	ListNode* createNode(int dataToAdd);
	bool AddToList(int data);
	ListNode* getHeadOfList() const;
	

private:
	ListNode* head;
};

#endif

