//============================================================================
// doubly_linked_list.cpp
//
// ---atkwong
//
// Program with Doubly linked list

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Doubly_linked_list
{
	public:
	// constructor initialize the prevPtr and nextPtr
	Doubly_linked_list()
	{
		number = 0;
		x = 0;
		y = 0;
		dist = 0;
		prevPtr = 0; // points to null at the beginning
		nextPtr = 0; // points to null at the beginning
	}

	// get a number
	int GetNum()
	{	return number;	}

	// set a number
	void SetNum( int num )
	{	number = num;	}

	// get the prev pointer
	Doubly_linked_list *GetPrev()
	{	return prevPtr;	}

	// set the prev pointer
	void SetPrev (Doubly_linked_list *ptr)
	{	prevPtr = ptr;	}

	// get the next pointer
	Doubly_linked_list *GetNext()
	{	return nextPtr;	}

	// set the next pointer
	void SetNext( Doubly_linked_list *ptr )
	{	nextPtr = ptr;	}

private:
	int	number;
	int x;
	int y;
	int dist;
	Doubly_linked_list *prevPtr;
	Doubly_linked_list *nextPtr;
};


// 1. create a doubly linked list
Doubly_linked_list *Create_Doubly_linked_list( int n )		// class *object (input int)
{
	Doubly_linked_list *tempPtr, *firstPtr, *lastPtr, *currentPtr;
	int		i = 0;

	do
	{
		tempPtr = new Doubly_linked_list;			// new object
		tempPtr ->SetNum(i);
		if ( i == 0 )
		{
			firstPtr	= tempPtr;					// first = temp
			lastPtr		= tempPtr;
			currentPtr	= tempPtr;
			i++;
		}
		else
		{
			lastPtr ->SetNext(tempPtr);				// head pointer of lastPtr points to next object
																			// e.g. ( last at 1, next points to 2 )
			lastPtr = tempPtr;						// last = temp			// ( last becomes 2 )
			lastPtr ->SetPrev(currentPtr);			// tail pointer of lastPtr points to previous object
																			// ( last at 2, prev points to 1 )
			currentPtr = tempPtr;					// current = temp		// ( current becomes 2 )
			i++;
		}
	} while ( i < n );

	return firstPtr;
}


// 2. print a doubly linked list
void Print_Doubly_linked_list( Doubly_linked_list *ptr )
{
	while ( ptr != 0 )
	{
		cout << "[" << ptr ->GetNum() << "]->"; // print pointer number
		ptr = ptr ->GetNext();					// next pointer
	}
	cout << "Null" << endl;						// ptr = 0
	cout << endl;
}

// 3. ***removed***

// 4. insert a node at the front
Doubly_linked_list *Insert_node_at_front ( Doubly_linked_list *ptr, Doubly_linked_list *firstPtr)
{
	Doubly_linked_list *tempPtr;

	tempPtr = firstPtr;								// temp  = first
	firstPtr = ptr;									// first = ptr
	ptr ->SetNext(tempPtr);							// ptr head points to temp
	tempPtr ->SetPrev(ptr);						// temp tail points back ptr

	return ptr;										// (next)
}

// 5. remove a node at the front
Doubly_linked_list *Remove_node_at_front ( Doubly_linked_list *firstPtr )
{
	Doubly_linked_list *tempPtr;

	tempPtr = firstPtr;								// temp  = first
	firstPtr = firstPtr ->GetNext();				// first = next of first
	firstPtr ->SetPrev(0);
	delete tempPtr;
	return firstPtr;
}


// 6. insert a node at the back
Doubly_linked_list *Insert_node_at_back ( Doubly_linked_list *ptr, Doubly_linked_list *firstPtr )
{
	Doubly_linked_list *prevPtr, *currPtr;

	currPtr = firstPtr;								// current  = first
	while ( currPtr != 0 )
	{
		prevPtr = currPtr;							// prev = current
		currPtr = currPtr->GetNext();				// current = next of current
	}
	prevPtr ->SetNext(ptr);
	ptr ->SetPrev(prevPtr);
	return firstPtr;
}

// 7. remove a node at the back
Doubly_linked_list *Remove_node_at_back ( Doubly_linked_list *firstPtr )
{
	Doubly_linked_list *prevPtr, *currPtr;

	currPtr = firstPtr;								// current  = first
	while ( currPtr ->GetNext() != 0 )
	{
		prevPtr = currPtr;							// prev = current
		currPtr = currPtr->GetNext();				// current = next of current
	}
	prevPtr ->SetNext(0);
	delete currPtr;
	return firstPtr;
}


// 8. insert a node before the node with the given value
Doubly_linked_list *Insert_node ( int n, Doubly_linked_list *ptr, Doubly_linked_list *firstPtr )
{
	Doubly_linked_list *prevPtr, *currPtr;

	currPtr = firstPtr;								// current  = first
	while ( currPtr ->GetNum() != n )
	{
		prevPtr = currPtr;							// prev = current
		currPtr = currPtr->GetNext();				// current = next of current
	}
	prevPtr ->SetNext(ptr);
	ptr ->SetNext(currPtr);
	ptr ->SetPrev(prevPtr);
	currPtr ->SetPrev(ptr);
	return firstPtr;
}

// 9. remove a node with the given value
Doubly_linked_list *Remove_node ( int n, Doubly_linked_list *firstPtr )
{
	Doubly_linked_list *prevPtr, *currPtr, *newPtr;

	currPtr = firstPtr;								// current  = first
	while ( currPtr ->GetNum() != n )
	{
		prevPtr = currPtr;							// prev = current
		currPtr = currPtr ->GetNext();				// current = next of current
	}
	newPtr = currPtr ->GetNext();
	prevPtr ->SetNext( newPtr );
	newPtr ->SetPrev(prevPtr);
	delete currPtr;
	return firstPtr;
}


int main()
{
	int num;
	Doubly_linked_list *headPtr;
//	Doubly_linked_list *newPtr;

	cout << "Number of nodes to be Created";
	cin >> num;

	headPtr = Create_Doubly_linked_list(num);
	Print_Doubly_linked_list(headPtr);
}
