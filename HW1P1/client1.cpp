//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Chris Edusada
//Complier:  GCC
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: This program displays the use of postfix expressions input by the user.
//Algorithm: A stack is being utilized in order to use postfix mathematical expressions and display the results in a vertical order.
//A while loop will be used to push operands onto the stack inputted by the user until an operator is pushed.
//Once an operator is inputted, the top two elements of the stack will be popped and will be pushed on top of the stack.
//The expression is complete when there are no elements left in the stack. An error message  for an incomplete expression
//will be displayed if there are elements left in the stack.

int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression

  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;

  cout << "Type a postfix expression: " ;
  cin >> expression;

  while (expression[i] != '\0')
  {
    try
    {
      item = expression[i];  //Current char.
      //If item is an operand, push onto the stack.
      if (item >= '0' && item <= '9') //For single digit numbers only.
      {
        postfixstack.push(item - 48); //Convert string into integer in ASCII code.
        postfixstack.displayAll();
      }
      //Else if, item is an operator, pop the top two elements (box1 and box2)
      else if ((item == '+') || (item == '-') || (item == '*'))
      {
        postfixstack.pop(box1);
        postfixstack.pop(box2);

        if (item == '-')
        {
          result = box2 - box1;
        }
          else if (item == '+')
        {
          result = box2 + box1;
        }
          else if (item == '*')
        {
          result = box2 * box1;
        }

        //Push the result (result) onto stack and displays all of the elements vertically.
        postfixstack.push(result);
        postfixstack.displayAll();
      }

      //Exception is thrown when an item is not an operator or operand.
      else
      {
        throw "invalid item(s)";
      }

      i++; //increment to go to next item in expression

    } // this closes try

    //Exception handling cases.
    catch (stack::Overflow)
    {
      cerr << "Error Overflow: Too many items!" << endl;  //Display error there are too many items in the stack.
      exit(1);
    }

    catch (stack::Underflow)
    {
      cerr << "Error Underflow: Not enough operands!" << endl;  //Display error when there are not enough operands.
      exit(1);
    }
    catch (char const* errormsg) //Display error when an invalid item is inputted.
    {
      cerr << "Error: Expression contains invalid item!" << endl;
      exit(1);
    }
  }// end of while
  //Result (result) is popped off the stack and displayed.
  postfixstack.pop(result);
  cout << "Result: " << result << endl;

  //Display error message if the stack is not empty and the expression is incomplete.
  //Then display the current stack.
  if (!postfixstack.isEmpty())
  {
    cerr << "Error: Incomplete expression!" << endl << endl;
    cerr << "Current Stack" << endl;
    cerr << "--------------" << endl;
    postfixstack.displayAll();
  }
}// end of the program
