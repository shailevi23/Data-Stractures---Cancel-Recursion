#include "List.h"

List::List()
{
	this->head = nullptr;
}

List::~List()
{
	ListNode* curr = this->head;
	ListNode* temp;
	while (curr != nullptr)
	{
		temp = curr->next;
		delete curr;
		curr = temp;
	}
}


ListNode* List::createNode(int dataToAdd)
{
	ListNode* newNode = new ListNode(dataToAdd);
	return newNode;
}


bool List::AddToList(int data)
{
	bool compNotInListFlag = true;
	ListNode* curr = this->head;
	ListNode* prev = curr;

	if (this->head == nullptr)
	{
		ListNode* cell_to_add = createNode(data);
		this->head = cell_to_add;
	}
	else
	{
		while (curr != nullptr && compNotInListFlag) //check if computer already in list
		{
			prev = curr;
			if (data == curr->data)
				compNotInListFlag = false;

			curr = curr->next;
		}
		if (compNotInListFlag == true)
		{
			ListNode* cell_to_add = createNode(data);
			prev->next = cell_to_add;
		}
	}
	return compNotInListFlag;
}

ListNode* List::getHeadOfList() const
{
	return this->head;
}
