#include "ListNode.h"

ListNode::ListNode()
{
	this->data = 0;
	this->next = nullptr;
}

ListNode::ListNode(int data)
{
	this->data = data;
	this->next = nullptr;
}

ListNode::~ListNode()
{
}

int ListNode::getData() const
{
	return this->data;
}

ListNode* ListNode::getNextNode() const
{
	return this->next;
}