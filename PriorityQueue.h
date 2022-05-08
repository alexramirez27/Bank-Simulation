/* 
 * PriorityQueue.h
 * 
 * Author: Alex Ramirez
 *
 * Last Modification: March 2022
 *
 */  

/******* Start of Priority Queue Public Interface *******/
#pragma once

#include "BinaryHeap.h"
#include "Event.h"

//template<class ElementType>

class PriorityQueue {
  
  private:
    BinaryHeap heap;

  public:

    // Description: Default Constructor
    PriorityQueue();
    
    // Description: Copy Constructor
    // Postcondition: New Priority Queue is created and is a copy
    PriorityQueue( const PriorityQueue& aPriorityQueue );

    // Description: Destructor
    // Postcondition: All elements are removed
    ~PriorityQueue();

    // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in this Priority Queue and 
    //              returns "true" if successful, otherwise "false".
    bool enqueue( Event& newElement );

    // Description: Removes (but does not return) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    void dequeue();
   
    // Description: Returns (but does not remove) the element with the next 
    //              "highest" priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    Event peek() const;

    // Description: Prints all the elements in the Queue
    void printPriorityQueue() const;

};
/*******  End of Priority Queue Public Interface *******/
