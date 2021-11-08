#ifndef __ACCNODE_H
#define __ACCNODE_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)


class AccessibleGroupNode
{
public:
	AccessibleGroupNode();
	~AccessibleGroupNode();

private:
	int data;
	int next;

	friend class AccessibleGroupList;

};

#endif
