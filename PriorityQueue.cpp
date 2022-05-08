/* 
 * PriorityQueue.cpp
 *
 * Description: Minimum Binary Heap data collection ADT class. 
 *
 * Class Invariant:  Always a Minimum Binary Heap
 * 
 * Author: Alex Ramirez
 *
 * Last Modification: March 2022
 *
 */  

#include "PriorityQueue.h"

// Description: Default Constructor
PriorityQueue::PriorityQueue() {
  heap = BinaryHeap();
}

// Description: Copy Constructor
// Postcondition: New Priority Queue is created and is a copy
PriorityQueue::PriorityQueue( const PriorityQueue& aPriorityQueue ) {
  heap = BinaryHeap();
  heap.elementCount = aPriorityQueue.heap.elementCount;
  heap.capacity = aPriorityQueue.heap.capacity;

  for ( unsigned int i = 0; i < aPriorityQueue.heap.elementCount; i++ ) {
    heap.elements[i] = aPriorityQueue.heap.elements[i];
  }
}

// Description: Destructor
// Postcondition: All elements are removed
PriorityQueue::~PriorityQueue() {
  heap.elementCount = 0;
}

// Description: Returns "true" if this Priority Queue is empty, otherwise "false".
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
bool PriorityQueue::isEmpty() const {
  return heap.elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Priority Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool PriorityQueue::enqueue( Event& newElement ) {
  bool ret = heap.insert( newElement );
  return ret;
}

// Description: Removes (but does not return) the element at the "front" of this Priority Queue 
// (not necessarily the "front" of its data structure).
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
void PriorityQueue::dequeue() {
  if ( heap.elementCount == 0 )
    throw EmptyDataCollectionException("This Priority Queue is empty.");

  heap.remove();
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
// (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
Event PriorityQueue::peek() const {
  if ( heap.elementCount == 0 )
    throw EmptyDataCollectionException("This Queue is empty.");

  return heap.elements[0];
}

// Description: Prints all the elements of the Queue in FIFO/LILO order.
//       If the Queue is empty, it prints "Empty Queue!" (without the quotes).     
// Postcondition: This Queue is unchanged.
void PriorityQueue::printPriorityQueue() const {
	if ( heap.elementCount == 0 )
    std::cout << "Empty Queue!" << std::endl;
  
  for ( unsigned int i = 0; i < heap.elementCount; i++ ) {
    std::cout << heap.elements[i];
  }
  std::cout << std::endl;
}