#include "AccessibleGroupList.h"

AccessibleGroupList::AccessibleGroupList(int size)
{
	this->accessibleList = new AccessibleGroupNode[(size+1)];
	this->size = size;
	this->headFree = 1;
	this->headList = -1; // none
	this->tailLocation = -1;
	MakeEmpty();
}

AccessibleGroupList::~AccessibleGroupList()
{
	delete[] this->accessibleList;
}

void AccessibleGroupList::MakeEmpty()
{
	int i;
	for (i = 0; i < this->size; i++)
	{
		this->accessibleList[i].data = -1;  // init all the data to -1
		this->accessibleList[i].next = i + 1; //the next free is sequential
	}
	this->accessibleList[i].data = -1;
	this->accessibleList[i].next = -1; //the last computer in list, his next is -1
}

bool AccessibleGroupList::IsEmpty()
{
	if (headList == -1)
		return true;
	else
		return false;
}

void AccessibleGroupList::InsertNode(int computerNum)
{
	int locNew = this->headFree;

	if (IsEmpty())
	{
		this->headList = this->headFree;
		this->tailLocation = this->headFree;
		this->headFree = this->accessibleList[this->headFree].next;
		this->accessibleList[locNew].data = computerNum;
		this->accessibleList[locNew].next = -1;
	}
	else
	{
		this->headFree = this->accessibleList[this->headFree].next;
		this->accessibleList[locNew].data = computerNum;
		this->accessibleList[locNew].next = this->accessibleList[tailLocation].next;
		this->accessibleList[tailLocation].next = locNew;
		this->tailLocation = locNew;
	}
}

void AccessibleGroupList::Print()
{
	int i = 1;
	int end = this->accessibleList[i].data;
	cout << "{";
	while (end != -1)
	{
		end = this->accessibleList[i].next;
		cout << " " << this->accessibleList[i++].data;
	}
	cout << " }";

}