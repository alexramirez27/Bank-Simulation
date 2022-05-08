/* 
 *
 * Queue.h
 *
 * Description: A Queue ADT class.         
 * Class Invariant: Elements are kept in FIFO or LILO order.
 *
 * Date: F Mar. 25 2022
 */

#include <iostream>
#include <cstddef>
#include "Queue.h"

// Description: Default Constructor
// Poscondition: Queue is empty
Queue::Queue() {
  elements = new Event[capacity];
  elementCount = 0;
}

// Description: Copy Constructor
// Postcondition: New Queue is created and is a copy
Queue::Queue( const Queue& aQueue ) {
  elements = new Event[capacity];
  elementCount = aQueue.elementCount;
  capacity = aQueue.capacity;

  for ( unsigned int i = 0; i < elementCount; i++ ) {
    elements[i] = aQueue.elements[i];
  }
}

// Description: Destructor
// Postcondition: All elements are removed
Queue::~Queue() {
  elementCount = 0;
}

// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
  return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue( Event& newElement ) {
  // Scenario: array is full
  if ( elementCount == capacity ) {
    capacity = capacity*2;

    // New array twice the size
    Event* newElements = new Event[capacity];
    
    // Copy elements from the original array into the new array
    for ( unsigned int i = 0; i < elementCount; i++ ) 
      newElements[i] = elements[i];

    // Point the original array to the new array
    elements = newElements;
  }
  elements[elementCount] = newElement;
  elementCount++;
  return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
// (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
void Queue::dequeue() {
  if ( elementCount == 0 )
    throw EmptyDataCollectionException("This Queue is empty.");

  // Move each element forward by one
  for ( unsigned int i = 1; i <= elementCount; i++ ) 
    elements[i-1] = elements[i];

  elementCount--;
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
// (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
Event Queue::peek() const {
  if ( elementCount == 0 )
    throw EmptyDataCollectionException("This Queue is empty.");

  return elements[0];
}

// Description: Prints all the elements of the Queue in FIFO/LILO order.
//       If the Queue is empty, it prints "Empty Queue!" (without the quotes).     
// Postcondition: This Queue is unchanged.
void Queue::printQ() const {
	if ( elementCount == 0 )
    std::cout << "Empty Queue!" << std::endl;
  
  for ( unsigned int i = 0; i < elementCount; i++ ) {
    std::cout << elements[i] << " ";
  }
  std::cout << std::endl;
}



