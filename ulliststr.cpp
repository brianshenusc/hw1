#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val) {
  if(head_ == NULL) {
    // cout << "here 1" << endl;
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    tail_->last++;
		size_++;

  }
  else if(tail_->last == 10) {
    // cout << "here 2" << endl;
    Item* newItem = new Item();
    newItem->val[0] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    tail_->last++;
    size_++;
  }
  else {
    // cout << "here 3" << endl;
    tail_->val[tail_->last] = val;
    tail_->last++;
		size_++;
  }
}

/**
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back() {
  if(head_ == NULL) {
    return;
  }
  else if(tail_->last == 1) {
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->last = 10;
    tail_->first = 0;
    size_--;
  }
  else {
		size_--;
    tail_->last--;
  }
}
  
/**
* Adds a new value to the front of the list.
* If there is room before the 'first' value in
* the head node add it there, otherwise, 
* allocate a new head node.
*   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val) {
  if(head_ == NULL) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    tail_->last++;
		size_++;
  }
  else if(head_->first == 0) {
    Item* newItem = new Item();
    newItem->val[9] = val;
    newItem->next = head_;
    head_ = newItem;
    head_->last = 10;
    head_->first = 9;
    size_++;
  }
  else {
    head_->val[head_->first - 1] = val;
    head_->first = head_->first - 1;
		size_++;
  }
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front() {
  if(head_ == NULL) {
    return;
  }
  else if(head_->last == 10) {
    head_ = head_->next;
    delete head_->prev;
    size_--;
  }
  else {
		size_--;
    head_->first++;
  }
}
  
/**
* Returns a const reference to the back element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

/**
* Returns a const reference to the front element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const {
  // Item* temp = head_;
  // for(int i = 0; i < loc; i++) {
  //   temp = temp->next;
  // }
  std::string* temp = head_->val;
  for(unsigned int i = 0; i < loc; i++) {
    temp += 1;
  }
  return temp;
  // return tail_->val;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
