/* 
 *
 * Queue.h
 *
 * Description: A Queue ADT class.         
 * Class Invariant: Elements are kept in FIFO or LILO order.
 *
 * Date: F Mar. 25 2022
 */

#pragma once

#include "EmptyDataCollectionException.h"
#include "Event.h"

/******* Start of Queue Public Interface *******/

// Class Invariant: FIFO or LILO order

class Queue {
  private:
    unsigned int INITIAL_CAPACITY = 10;

  public:
    Event* elements;
    unsigned capacity = INITIAL_CAPACITY;
    unsigned int elementCount;

    // Description: Default Constructor
    // Poscondition: Queue is empty
    Queue();

    // Description: Copy Constructor
    // Postcondition: New Queue is created and is a copy
    Queue( const Queue& aQueue );
  
    // Description: Destructor
    // Postcondition: All elements are removed
    ~Queue();
    
    // Description: Returns "true" if this Queue is empty, otherwise "false".
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;
   
    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of its data structure) and 
    //              returns "true" if successful, otherwise "false".
    // Time Efficiency: O(1)
    bool enqueue( Event& newElement );
   
    // Description: Removes (but does not return) the element at the "front" of this Queue 
    // (not necessarily the "front" of its data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue(); 
   
    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of its data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    Event peek() const;

    // Description: Prints all the elements in the Queue
    void printQ() const;

    // Description: Returns the number of elements in the Queue
    //unsigned int getElementCount();

    // Description: Returns the capacity of the Queue
    //unsigned int getCapacity();
  
};
 
/******* End of Queue Public Interface *******/

//#include "Queue.cpp"