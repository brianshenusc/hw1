/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void push_back(Node*& head, Node*& append);


using namespace std;
// #include <iostream>
void split(Node*& in, Node*& odds, Node*& evens)
{
  // ends the function if in is NULL
  if(in == nullptr) {
    return;
  }

  // if the current value is even, creates a new node and adds it to the even LinkedList
  if(in->value % 2 == 0) {
    Node* newEven = new Node(in->value, nullptr);
    if(evens == nullptr) {
      evens = newEven;
    }
    else {
      push_back(evens, newEven);
    }
  }
  // if the current value is odd, creates a new node and adds it to the even LinkedList
  else if(in->value % 2 != 0) {
    Node* newOdd = new Node(in->value, nullptr);
    if(odds == nullptr) {
      odds = newOdd;
    }
    else {
      push_back(odds, newOdd);
    }
  }
  // deletes the current in node and sets it to the next node
  Node* temp = in;
  in = in->next;
  delete temp;
  // recursive call back to the function
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */

// helper function that appends the current Node to the end
void push_back(Node*& head, Node*& append)
{
  Node* temp = head;
  // recursively calls the function until the end is reached
  if(temp->next != nullptr) {
    temp = temp->next;
    push_back(temp, append);
  }
  // when the end is reached, the new value is appened to the LinkedList and the function ends
  else {
    temp->next = append;
    return;
  }
}