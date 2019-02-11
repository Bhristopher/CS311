//=========================================================
//HW#: HW1P2 queue
//Your name: Chris Edusada
//Complier:  g++ compiler
//File type: queue implementation file  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"

// PURPOSE: Constructor to create an object initalizing front, rear and count.
queue::queue()
{
  front = 0;
  rear = -1;
  count = 0;
}

//PURPOSE: Destructore to destroy an object.
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if (count == 0)
  {
		return true;
	}
  else
  {
    return false;
  }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if (count == MAX_SIZE)
  {
		return true;
	}
  else
  {
    return false;
  }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// PARAMETER: provide the element (newElem) to be added
// ALGORITHM: If the queue is full (isFull()), throw Overflow.
// Otherwise change the position of rear, initialize rear as the new element (newElem) to be added
// and increment the counter.
void queue::add(el_t newElem)
{
	if (isFull())
  {
		throw Overflow();
	}
	rear = (rear + 1) % MAX_SIZE;
	el[rear] = newElem;
	count++;
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
// ALGORITHM: If the queue is empty (isEmpty()), throw Underflow.
// Otherwise, initalize the front element (removedElem) to be removed, change the position of front,
// and decrement the counter.
void queue::remove(el_t& removedElem)
{
	if (isEmpty())
  {
		throw Underflow();
	}

	removedElem = el[front];
	front = (front + 1) % MAX_SIZE;
	count--;
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// PARAMETER: provide a holder (theElem) for the element (pass by ref)
// ALGORITHM: If the queue is empty, throw Underflow. Otherwise, initialize
// the parameter (theElem) to the front of the queue.
void queue::frontElem(el_t& theElem)
{
	if (isEmpty())
  {
		throw Underflow();
	}
  else
  {
    theElem = el[front];
  }
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
int queue::getSize()
{
	return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
// ALGORITHM: If the queue is empty, display error message. Otherwise,
// display the elements from front to rear.
void queue::displayAll()
{
  if (isEmpty())
  {
    cout << "[ empty ]" << endl;
  }

  else
  {
    int j = front;
    cout << "[";

    for (int i = 1; i <= (count); i++)
    {
      cout << el[(j + i - 1) % MAX_SIZE];
    }
    cout << "]" << endl;
  }
}

// PURPOSE: if empty, throws an exception Underflow
// if queue has just 1 element, does nothing
// if queue has more than 1 element, moves the front one to the rear by
// calling remove followed by add using a local variable as a parameter (temp).
// ALGORITHM: If the queue is empty, throw Underlow. Otherwise, place front elem
// to the rear.
void queue::goToBack()
{
	if (isEmpty())
  {
		throw Underflow();
	}

  else if(count == 1)
  {
    return;
  }

	// if count larger than 1, do remove add operation.
	if (count > 1)
  {
		el_t temp; // tmp is the local variable within this function
		remove(temp);
		add(temp);
	}
}
