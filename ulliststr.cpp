#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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
	// if there is nothing in the list, creates a new Item for the first value
  if(head_ == NULL) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
    tail_ = newItem;
    tail_->last++;
		size_++;
  }
	// creates a new Item once the original tail_ Item is full
  else if(tail_->last == 10) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    tail_->last++;
    size_++;
  }
	// adds to the end of an Item that is not yet full
  else {
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
	// does nothing if the list is empty
  if(head_ == NULL) {
    return;
  }
	// creates a new Item once the original tail_ Item is full
  else if(tail_->last == 1 && tail_->prev != NULL) {
		Item* temp = tail_;
		tail_ = tail_->prev;
		tail_->next = NULL;
		delete temp;
    size_--;
  }
	// deletes the last element of an Item that is not full
  else {
		size_--;
    tail_->last--;
  }
	// deletes head_ and tail_ if the size_ is 0
	if(size_ == 0) {
		head_ = NULL;
		delete head_; 
		delete tail_;
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
	// if there is nothing in the list, creates a new Item for the first value
  if(head_ == NULL) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    head_ = newItem;
		tail_ = newItem;
    head_->last++;
		size_++;
  }
	// creates a new Item if the first element in head_ has data in it
  else if(head_->first == 0) {
    Item* newItem = new Item();
    newItem->val[9] = val;
    newItem->next = head_;
		head_->prev = newItem;
    head_ = newItem;
    head_->last = 10;
    head_->first = 9;
    size_++;
  }
	// adds to the front of an Item that is not full
  else {
    head_->val[head_->first - 1] = val;
    head_->first -= 1;
		size_++;
  }
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front() {
	// does nothing if the list is empty
  if(head_ == NULL) {
    return;
  }
	// deletes the Item if it only has one string in val at the 9th index
  else if(head_->first == 9 && head_->next != NULL) {
		Item* temp = head_;
		head_ = head_->next;
		head_->prev = NULL;
		delete temp;
    size_--;
  }
	// deletes the first value of the list
  else {
		size_--;
    head_->first++;
  }
	// deletes head_ and tail_ if size_ is 0
	if(size_ == 0) {
		head_ = NULL;
		delete head_; 
		delete tail_;
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
	// returns NULL if given an invalid loc
  if(loc >= size_) {
    return NULL;
  }
  else {
		// loops through the list until the correct index is found and returns the value
		Item* curr = head_;
    while(curr != NULL) {
			unsigned int numIndex = curr->last - curr->first;
      if(loc < numIndex) {
        return &(curr->val[curr->first + loc]);
      }
      loc -= numIndex;
      curr = curr->next;
    }
  }
  return NULL;
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
