/*
עמית אהרוני - 312346901 - קבוצה יום חמישי שישי עם איריס
שי לוי - 204124234 - קבוצה יום חמישי שישי עם איריס
*/

#include "Stack.h"

const int WHITE = 0;
const int BLACK = 1;

bool InputForArr(int& comp, int& connection, int size);
void InputForBegining(int& sizeOfComputer, int& sizeOfConnections);
int* InitializeComputerColorArr(int size);
void CreateNetworkStracture(int sizeOfConnection, int sizeOfComputers, List* networkArr);
bool ComputerInputToFindAccesibleList(int compSize, int& computerInput);
void FindAccessible(List* networkArr, int computerNumber, int* computerColor, AccessibleGroupList& accesslist);
void FindAccessibleNoRecursion(List* networkArr, int moked, int* computerColor, AccessibleGroupList& accesslist);


int main()
{
	bool flag;
	int computerInputForAccesibleFunction,  numOfComputers, numOfConnections;
	InputForBegining(numOfComputers,numOfConnections); // input for size of computers in network, and size of connections in the network
	int* computerColorArr = InitializeComputerColorArr(numOfComputers); // init the color for comps - all white FOR FUNCTION 1
	List* networkStractureArr =  new List[(numOfComputers+1)]; // index i=0 in the arr is empty, size is +1 to accsses all the number from 1 to n ( not 0 to n-1 )
	CreateNetworkStracture(numOfConnections, numOfComputers, networkStractureArr); // create the network stracture
	AccessibleGroupList accessList(numOfComputers); //create the static list without pointers with the size of computer input in network
	flag = ComputerInputToFindAccesibleList(numOfComputers, computerInputForAccesibleFunction); // input check for computer
	if (flag)
	{
		FindAccessible(networkStractureArr, computerInputForAccesibleFunction, computerColorArr, accessList); // function 1 with recursion
		accessList.Print(); // print the accessList

		//Function Two
		int* computerColorArrForFunctionTwo = InitializeComputerColorArr(numOfComputers); // init the color for comps - all white FOR FUNCTION 2
		AccessibleGroupList accessListFunctionTwo(numOfComputers); //create the static list without pointers with the size of computer input in network FOR FUNCTION 2
		FindAccessibleNoRecursion(networkStractureArr, computerInputForAccesibleFunction, computerColorArrForFunctionTwo, accessListFunctionTwo); // function 1 with recursion FOR FUNCTION 2
		accessListFunctionTwo.Print(); // print the accessList FOR FUNCTION 2

		delete[] computerColorArrForFunctionTwo;
	}
	else
		cout << "no such computer 10" << endl;

	delete[] computerColorArr;
	delete[] networkStractureArr;
}

bool InputForArr(int& comp, int& connection, int size)
{
	bool flag = true;
	cout << "\nPlease enter computer number: ";
	cin >> comp;

	while(comp > size)
	{
		cout << "\nPlease enter again the computer number: ";
		cin >> comp;
	}

	cout << "\nPlease enter computer connection: ";
	cin >> connection;

if (connection > size || connection == comp)
{
	flag = false;
}
return flag;
}

void InputForBegining(int& sizeOfComputer, int& sizeOfConnections)
{
	cout << "Please enter num of comps: ";
	cin >> sizeOfComputer;

	while (sizeOfComputer <= 0)
	{
		cout << "Please enter positive num of comps: ";
		cin >> sizeOfComputer;
	}

	cout << "\nPlease enter num of connections: ";
	cin >> sizeOfConnections;

	while (sizeOfComputer <= 0)
	{
		cout << "Please enter positive num of connections: ";
		cin >> sizeOfComputer;
	}
}

int* InitializeComputerColorArr(int size)
{
	int* arr = new int[size + 1];
	for (int i = 0; i < size + 1; i++)
		arr[i] = WHITE; // init all to 0, as white computer 

	return arr;
}

void CreateNetworkStracture(int sizeOfConnection, int sizeOfComputers, List* networkArr)
{
	bool flag = true;
	bool flag2;
	int i, currComputerInput = 0, currConnectionInput = 0;

	for (i = 0; i < sizeOfConnection; i++)
	{
		flag2 = InputForArr(currComputerInput, currConnectionInput, sizeOfComputers); // get input and check input
		if (flag2)
		{
			flag = networkArr[currComputerInput].AddToList(currConnectionInput); // add connection to the current computer, flag if there is already this computer
			if (flag == false)
			{
				cout << "computer connected already\n";
				i--;
			}
		}
		else
		{
			cout << "no such computer 6" << endl;
			exit(1);
		}
	}
}

bool ComputerInputToFindAccesibleList(int compSize, int& computerInput)
{
	bool flag = true;
	cout << "\nPlease enter computer Input to FindAccesibleGroup: ";
	cin >> computerInput;
	if (computerInput <= 0 || computerInput > compSize)
	{
		flag = false;
		
	}
	return flag;
}

void FindAccessible(List* networkArr, int computerNumber, int* computerColor, AccessibleGroupList& accesslist) // function 1 with recursion
{
	ListNode* currentComputerNode = networkArr[computerNumber].getHeadOfList();
	int ComputerDataNumber;
	computerColor[computerNumber] = BLACK; // change the current computer color to black
	accesslist.InsertNode(computerNumber); // insert to accessible list

	while (currentComputerNode != nullptr)
	{
		ComputerDataNumber = currentComputerNode->getData();
		if (computerColor[ComputerDataNumber] == WHITE) // if current computer is white
			FindAccessible(networkArr, ComputerDataNumber, computerColor, accesslist); // recursion with new computer in list
		else
			currentComputerNode = currentComputerNode->getNextNode(); //do not recursion, keep find the accesible computers
	}
}

void FindAccessibleNoRecursion(List* networkArr, int moked, int* computersColorArr, AccessibleGroupList& accesslistRes)
{
	Stack S;
	ListNode* currentComputerNodeInList = networkArr[moked].getHeadOfList();
	int currentComputerNodeInListValue = 0;
	ItemType currIT(moked, currentComputerNodeInList, currentComputerNodeInListValue, FIRST);
	ItemType nextIT;
	S.Push(currIT);

	while (!S.IsEmpty())
	{
		currIT = S.Pop();

		if (currIT.getLine() == FIRST) // before recursion
		{
			currentComputerNodeInList = networkArr[currIT.getMoked()].getHeadOfList();
			computersColorArr[currIT.getMoked()] = BLACK; // change the current computer color to black
			accesslistRes.InsertNode(currIT.getMoked()); // insert to accessible list

			if (currentComputerNodeInList != nullptr)
			{
				currentComputerNodeInListValue = currIT.getCurrentComputerNode()->getData();
				currIT.setCurrentComputerNodeInListValue(currentComputerNodeInListValue);

				if (computersColorArr[currentComputerNodeInListValue] == WHITE)
				{
					currIT.setLine(SECONED);
					S.Push(currIT);

					nextIT.setMoked(currentComputerNodeInListValue);
					nextIT.setCurrentComputerNodeInList(networkArr[currentComputerNodeInListValue].getHeadOfList());
					nextIT.setLine(FIRST);
					S.Push(nextIT);
				}
				else
				{
					currIT.setLine(SECONED);
					currIT.setCurrentComputerNodeInList(currIT.getCurrentComputerNode()->getNextNode());
					S.Push(currIT);
				}
			}

		}

		else if (currIT.getLine() == SECONED) // after recursion
		{

			if (currIT.getCurrentComputerNode() != nullptr)
			{
				currentComputerNodeInListValue = currIT.getCurrentComputerNode()->getData();
				currIT.setCurrentComputerNodeInListValue(currentComputerNodeInListValue);

				if (computersColorArr[currentComputerNodeInListValue] == WHITE)
				{
					currIT.setLine(SECONED);
					S.Push(currIT);

					nextIT.setMoked(currentComputerNodeInListValue);
					nextIT.setCurrentComputerNodeInList(networkArr[currentComputerNodeInListValue].getHeadOfList());
					nextIT.setLine(FIRST);
					S.Push(nextIT);
				}
				else
				{
					currIT.setLine(SECONED);
					currIT.setCurrentComputerNodeInList(currIT.getCurrentComputerNode()->getNextNode());
					S.Push(currIT);
				}
			}
		}
	}
}