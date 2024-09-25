#include "Queue.h"
//template <class T>
//Queue<T>::Queue(){
//  back=nullptr;
//}

template <class T>
//TODO
// add an element t to the end queue 
// this should be an O(1) operation
void Queue<T>::add(T  t){
  //TODO
    LinkedList<T>::add(t);
    
}

//TODO
//remove an element from the front of the queue
// this should be an O(1) operation
template <class T>
void Queue<T>::remove(){
  
  //TODO
  // if queue is empty
  // throw new std::string("NULL POINTER EXCEPTION QUEUE IS EMPTY \n");
  if(this->front == nullptr)
  {
      throw std::string("NULL POINTER EXCEPTION QUEUE IS EMPTY \n");
  }
    else
    {
        this->front = this->front -> next;
    }
}

template<class T>
bool Queue<T>::isempty(){
    return this->empty();
    
}

