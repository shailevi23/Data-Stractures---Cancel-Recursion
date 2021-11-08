#ifndef __ACC_H
#define __ACC_H

#include "AccessibleGroupNode.h"
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

class AccessibleGroupList
{
public:
	AccessibleGroupList(int size = 1);
	~AccessibleGroupList();
	void MakeEmpty();
	bool IsEmpty();
	void InsertNode(int computerNum);
	void Print();

private:
	int size;
	int headFree;
	int headList;
	int tailLocation;
	AccessibleGroupNode* accessibleList;

};

#endif