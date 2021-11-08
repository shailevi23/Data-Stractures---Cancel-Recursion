#ifndef __LNODE_H
#define __LNODE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)


class ListNode
{
public:
	ListNode();
	~ListNode();
	ListNode(int data);
	int getData() const;
	ListNode* getNextNode() const;

	friend class List;

private:
	int data;
	ListNode* next;
};

#endif
