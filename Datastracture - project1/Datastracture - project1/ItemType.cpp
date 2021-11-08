#include "ItemType.h"

ItemType::ItemType()
{
	this->ITPROTOTYPE_moked = -1;
	this->ITLOCAL_currentComputerNode = nullptr;
	this->ITLOCAL_ComputerDataNumber = -1;
	this->IT_LINE = -1;
	this->next = nullptr;
}

ItemType::ItemType(ItemType node, ItemType* nextIT) // c'tor
{	this->ITPROTOTYPE_moked = node.ITPROTOTYPE_moked;
	this->ITLOCAL_currentComputerNode = node.ITLOCAL_currentComputerNode;
	this->ITLOCAL_ComputerDataNumber = node.ITLOCAL_ComputerDataNumber;
	this->IT_LINE = node.IT_LINE;
	this->next = nextIT;
}

ItemType::ItemType(int ITPROTOTYPE_computerNumber, ListNode* ITLOCAL_currentComputerNode,
	int ITLOCAL_ComputerDataNumber,int IT_LINE) // c'tor
{
	this->ITPROTOTYPE_moked = ITPROTOTYPE_computerNumber;
	this->ITLOCAL_currentComputerNode = ITLOCAL_currentComputerNode;
	this->ITLOCAL_ComputerDataNumber = ITLOCAL_ComputerDataNumber;
	this->IT_LINE = IT_LINE;
	this->next = nullptr;
}

ItemType* ItemType::getNextNode() const
{
	return this->next;
}

int ItemType::getLine() const
{
	return this->IT_LINE;
}

int ItemType::getMoked() const
{
	return this->ITPROTOTYPE_moked;
}

ListNode* ItemType::getCurrentComputerNode() const
{
	return this->ITLOCAL_currentComputerNode;
}

void ItemType::setCurrentComputerNodeInListValue(const int num)
{
	this->ITLOCAL_ComputerDataNumber = num;
}

void ItemType::setLine(const int num)
{
	this->IT_LINE = num;
}

void ItemType::setMoked(const int num)
{
	this->ITPROTOTYPE_moked = num;
}

void ItemType::setCurrentComputerNodeInList(ListNode* currentComputerNode)
{
	this->ITLOCAL_currentComputerNode = currentComputerNode;
}



ItemType::~ItemType()
{

}
