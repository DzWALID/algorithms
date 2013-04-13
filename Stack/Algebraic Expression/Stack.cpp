#include <iostream>
#include "Stack.h"
using namespace std;

// Constructor
Stack::Stack()
{
	topPtr=NULL;
}

// Control whether stack is empty or not
bool Stack::isEmpty() const
{
	if(topPtr==NULL)
		return true;
	else
		return false;
}

// Insert new item to stack
bool Stack::push(stackItemType newItem)
{
	stackNode *newPtr = new stackNode;
	newPtr->item=newItem;
	newPtr->next = topPtr;
	topPtr=newPtr;
	return true;
}

// Remove top item from stack
bool Stack::pop()
{
	if(!topPtr)
		return false;
	else
	{
		stackNode *tmp = topPtr;
		topPtr=topPtr->next;
		tmp->next = NULL;
		delete tmp;
		return true;
	}
}

// Return top item
double Stack::getTop() const
{
	if(topPtr==NULL)
		return '\0';
	else
	{
		return topPtr->item;
	}
}
