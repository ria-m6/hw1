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
void ULListStr::push_back(const std::string& val){ //DONE!
    if(this->empty()){ //If the node is completely empty create a new Item
        head_ = new Item;
        tail_ = head_;
        head_ -> val[0] = val;
        head_->first = 0;
        head_->last = 1;
        size_++;
    }else if(tail_->last == ARRSIZE){ //if tail is full, create a new Node
        Item *temp = new Item;
        tail_->next = temp;
        temp->prev = tail_;
        tail_ = temp;
        
        tail_->val[0] = val;
        tail_->first = 0;
        tail_->last = 1;
        size_++;
    } else{ //if there is space at the end of tail, add to it
        tail_->val[tail_->last] = val;
        tail_->last++;
        size_++;
    }
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back(){ //DONE
  if(empty()){
    return;
  }
    tail_->last--; //decrementing last index
    
    //if there's only 1 element in list
    if(tail_->first == tail_ -> last){
        //if the list has more than 1 node
        Item *temp = tail_;
        if(tail_->prev != nullptr){
            tail_ = tail_->prev;
            tail_->next = nullptr;
            
        } else{ //only 1 node in list
            head_ = nullptr;
            tail_ = nullptr;
        }
        delete temp;
    }
    
    //if list is empty, reset
    if(empty()){ //if there are no values left
        head_ = NULL;
        tail_ = NULL;
        size_=0;
    } else{
        size_--; //decrease size
    }
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise,
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val){
    //case if there is no node
    if(empty()){ //If the node is completely empty create a new Item
        head_ = new Item;
        tail_ = head_;
        head_ -> val[0] = val;
        head_->first = 0;
        head_->last = 1;
        size_++;
    }else if(head_->first == 0){ //if head is full, create a new Node
        Item *temp = new Item;
        
        temp->val[ARRSIZE-1] = val;
        temp->first = ARRSIZE-1;
        temp->last = ARRSIZE;
        
        temp->next = head_;
        head_->prev = temp;
        head_ = temp;
        
        size_++;
    } else{ //if there is space at the beginning of head, add to it
        head_->first--;
        head_->val[head_->first] = val;
        size_++;
    }
    
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front(){

    if(empty()){
      return;
    }

    head_->first++; //decrementing first index
    
    //if there's only 1 element in list
    if(head_->first == head_ -> last){
        //if the list has more than 1 node
        Item *temp = head_;
        head_ = head_->next;

        if(head_!= nullptr){
            head_->prev = nullptr;
            
        } else{ //only 1 node in list
            tail_ = nullptr;
        }
        delete temp;
    }
    //if list is empty, reset
    
    size_--; //decrease size

    // if(empty()){
    //   head_ = NULL;
    //   tail_=NULL;
    // }
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::back() const{ //DONEEE
    return tail_->val[tail_->last-1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1) DONE
 */
std::string const & ULListStr::front() const{ //DONEEE
    //get the first value in the head
    return head_->val[head_->first];
}

/**
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n)
 */
std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(loc >= size_){
        return NULL;
    }
    //starting from head
    Item* temp = head_;
    size_t index = loc;
    //traverse list
    while(temp != nullptr){
        //see if index is within range of current node
        if(index < (temp->last)){
            //if so return value in array
            return &((temp->val)[index-(temp->first)]);
        }
        //If not, update index and move to next node
       index -= ((temp->last)-(temp->first));
       temp = temp->next;
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