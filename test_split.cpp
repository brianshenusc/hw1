/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
  Node* tail = new Node(5, NULL);
  Node* four = new Node(4, tail);
  Node* three = new Node(3, four);
  Node* two = new Node(2, three);
  Node* one = new Node(1, two);
  Node* head = new Node(0, one);

  // while(head != NULL) {
  //   cout << head->value << endl;
  //   head = head-> next;
  // }

  Node* odd = NULL;
  Node* even = NULL;
  split(head, odd, even);


  Node* oddHead = odd;
  while(oddHead != NULL) {
    cout << oddHead->value << endl;
    oddHead = oddHead-> next;
  }
  cout << endl;
  Node* evenHead = even;
  while(evenHead != NULL) {
    cout << evenHead->value << endl;
    evenHead = evenHead-> next;
  }
  


  while(odd != NULL) {
    Node* temp = odd;
    odd = odd->next;
    delete temp;
  }
  while(even != NULL) {
    Node* temp = even;
    even = even->next;
    delete temp;
  }



  // Node* temp3 = even;
  // while(even->next != NULL) {
  //   delete even->next;
  // }
  // delete temp3;

  



  
}
