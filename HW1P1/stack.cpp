//=========================================================
//HW#: HW1P1 stack
//Your name: Chris Edusada
//Complier:  GCC
//File type: stack implementation file stack.cpp
//=========================================================

using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
  top = -1; // indicate an empty stack, initialized to -1
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{
  // nothing
}

//PURPOSE: Checks top of the stack and returns true if empty.
//Stack is empty when top is -1.
bool stack::isEmpty()
{
  if ( top == -1) //If top is -1, return true.
  {
    return true;
  }
  else
  {
    return false;
  }
}

//PURPOSE: Checks top of the stack and returns true if full.
//Stack is full when top is MAX -1.
bool stack::isFull()
{
  if (top == MAX-1 ) return true; else return false;
}

// PURPOSE: If not full, enters an element at the top;
//          otherwise throws an exception - Overflow
// PARAMETER: Pass the element (elem) to be pushed
// ALGORITH: Calls isFull to check if stack has reached max elements (elem).
void stack::push(el_t elem)
{
  if (isFull()) //if isFull, throw Overflow.
  {
    throw Overflow();
  }
  else  //Else, increment top and push the element (elem).
  {
    top++;
    el[top] = elem;
  }
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref).
//ALGORITH: Calls isEmpty to check if stack has no elements (elem). Throw underflow if true.
void stack::pop(el_t& elem)
{
  if (isEmpty())
  {
    throw Underflow();
  }
  else
  {
    elem = el[top];
    top--;
  }
}

// PURPOSE: Calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: Provide a holder (elem) for the element (pass by ref)
//ALGORITH: Calls isEmpty to check if stack has no elements (elem). Throw Underflow if true.
void stack::topElem(el_t& elem)
{
  if (isEmpty())
  {
    throw Underflow();
  }
  else
  {
    elem = el[top];
  }
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//         Otherwise, displays the elements vertically.
// ALGORITH: Calls isEmpty to check if stack has no elements (elem).
// Invoke a for loop to display all elements of the stack.
void stack::displayAll()
{
  cout << "STACK:--------" << endl;
  if (isEmpty())
  {
   cout << "[ empty ]" << endl;
  }
  else
  {
    for (int i = top; i >= 0; i--)  //i is set to Top, display the position of the stack and decrement i.
    {
     cout << el[i] << endl;
    }
    cout << "--------------" << endl;
  }
}

//PURPOSE: pops all elements from the stack until
// it is empty
//ALGORITH: Invoke a while loop to clear the stack.
void stack::clearIt()
{
   int temp;  //Temp variable in order to pop elements from the stack.

   while(!isEmpty())  //Calls isEmpty. If elements exist, pop the stack.
   {
     pop(temp);
   }
}
