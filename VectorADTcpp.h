
#include <iostream>
#include "VectorADT.h"

//GIVEN
template <class T> // Assuming the existence of "class T" for the creation of functions. Since we want parameters as objects from any class T

 VectorADT<T>::VectorADT()
{
    dataArray= new  T*[SIZE];
    count=0;
  }

 
 //TODO
 //double the size of the dataArray
 //create a temporary dataArray of double the size
 //copy over the current data Array and then delete it
 //use REM documentation

template <class T>
  void VectorADT<T>::resizeADT()
{
      // TODO
    SIZE = 2*SIZE;
    T **temp = new T* [SIZE];
    
    for(int i = 0; i < count; i++)
    {
        
        temp[i] = this-> dataArray[i];
    }
    

    delete []dataArray;
    
    dataArray = temp;
    
    
}



  //TODO
  //appends an element to the end of the VectorADT
  //increments size by 1
  //if run out of size, resize the vector
  // REM documentation
template <class T>
  void VectorADT<T>::push_back(T *v){
    //TODO
     // dataArray[this->size()+1] = v;
     // count++;
    // You need to increase size then add.
    
    if(count >= SIZE)
    {
        resizeADT();
    }
    dataArray[count] = v;//my edit
      count++;
      
    
  }
   //TODO
  //returns a copy of the  element from the end of the VectorADT
  //does not delete
  //no resize of the vector
  // REM documentation
  template <class T>
   T * VectorADT<T>::pop(){
     //TODO
       return dataArray[size()-1];
    }
   
    //TODO
  //removes  an element from the end of the VectorADT
  //decrements size by 1
  //no resize of the vector
  // REM documentation
  template <class T>
   T * VectorADT<T>::pop_back() {
  //TODO
      
      count -= 1;
       return dataArray[size()-1] = nullptr;
   }


  template <class T>
  void VectorADT<T>::printVectorADT(){
    for (int i=0;i<count;i++)
         std::cout<<dataArray[i]<<"\n";
  }
    
  template <class T>
   int VectorADT<T>::size() const
   { return count;}


  
//FILL IN THE BLANK FOR COMPARISON
  template <class T>
int VectorADT<T>::sort(LessThan<T> less){
  int steps=0;
  T * minValue= new T();
   int minIndex=0;
   for (int i=0;i<count;i++){
      minValue=dataArray[i];
      minIndex=i;
  for (int j=i+1;j<count;j++){
     
    //if ...compare the objects using the LessThan functor
      if(less(*dataArray[j], *minValue))
    {
     
      minValue=dataArray[j];
      minIndex=j;
    }
     steps++;
  }
    dataArray[minIndex]=dataArray[i];
    dataArray[i]=minValue;
   
  }
  return steps;
  }


 //GIVEN
template <class T>
   bool VectorADT<T>:: empty(){
     return (count<=0);
   }

   //GIVEN
template <class T>
   T* VectorADT<T>:: get(int i) const{
     if (i>=0 && i<count)
       return dataArray[i];
    else
      {
      throw new std::string("No such element exception");
      exit(-1);
    }
   }

   //GIVEN
  template <class T>
  void VectorADT<T>::set(int i, T * t){
    if (i>=0 && i<count)
       dataArray[i]=t;
    else
      {
      throw new std::string("No such element exception");
      exit(-1);
    }
  }


 //TODO
 //USE template
 //inserts the object at the given INDEX position NOT chart position
 //DOes NOT adjust chart position
 //THROWS exception if index out of bounds
 //right adjusts the elements to the right of the inserted object
 //returns number of adjusted steps
  template <class T>
  int VectorADT<T>::insert(T * v, int pos){
    int adjustSteps=0;
     // TODO
      if(pos >= 0 && pos < size())
      {
          T **temp = new T* [size() + 1]; // to contain the elements at the right of the v
          
          for(int i = 0; i < pos; i++) // to copy the elements before the INDEX position
          {
              
              temp[i] = dataArray[i];
          }
          
          temp[pos] = v; // insert v in position pos
          
          for(int i = pos; i < size(); i++)
          {
              temp[i+1] = dataArray[i];
              
              adjustSteps++;
          }
          
          delete [] dataArray;
          dataArray = temp;
      }
      else
      {
          throw new std::string ("Out of bounds!");
          std::exit(-1);
      }
      
      
      
    return adjustSteps;
  }


  //TODO
 //USE template
 //removes the object at the given INDEX position NOT chart position
 //DOes NOT adjust chart position
 //THROWS exception if index out of bounds
 //left adjusts the elements to the right of the inserted object
 //returns number of adjusted steps
  template <class T>
  int VectorADT<T>::remove(int pos){
    int adjustSteps=0;
    //TODO
      if(pos >= 0 && pos < size())
      {
          T **temp = new T* [size() + 1]; // to contain the elements at the right of the v
          
          for(int i = 0; i < pos; i++) // to copy the elements before the INDEX position
          {
              
              temp[i] = dataArray[i];
          }
          
           // remove element in position pos
          
          for(int i = pos; i < size() - 1; i++)
          {
              temp[i] = dataArray[i+1];
              
              adjustSteps++;
          }
          
          delete [] dataArray;
          dataArray = temp;
          count--;
      }
      else
      {
          throw new std::string ("Out of bounds!");
          std::exit(-1);
      }
    
      
  return adjustSteps;
  }

  //TODO Linear search
  //use the overloaded == operator of the Song objects
  //returns -1 if not found else returns the found index

// It takes 'count' times to complete the operation
  template <class T>
  int  VectorADT<T>::searchByTitle(int& steps, T *v){
    // TODO
      int index = 0;
      int position = -1;
      bool found = false;
      
      while (index < this->size() && !found)
      {
          if(dataArray[index]->getTitle() == v->getTitle())
          {
              found = true;
              position = index;
          }
          index++;
          steps++;
      }
    
      if(!found){
          steps++;
          return -1;
      }
    
    return steps;
    
  }
