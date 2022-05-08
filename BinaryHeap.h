/* 
 * BinaryHeap.h
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
 
#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h"
#include <cmath>
#include "Event.h"

class BinaryHeap {
  private:
    unsigned int INITIAL_CAPACITY = 7;
    unsigned int exponent = 3;
   
  public:
    Event* elements;
    unsigned int capacity = INITIAL_CAPACITY;
    unsigned int elementCount;

    // Utility method - Recursively put the array back into a Minimum Binary Heap.
	  void reHeapUp(unsigned int indexOfBottom);

	  // Utility method - Recursively put the array back into a Minimum Binary Heap.
	  void reHeapDown(unsigned int indexOfRoot);  

	  // Default Constructor
	  BinaryHeap(); 
	
    // Copy Constructor
    BinaryHeap( const BinaryHeap& aBinaryHeap );

    // Destructor
    ~BinaryHeap();
	
    // 1) Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	  // Time Efficiency: O(1)
    unsigned int getElementCount() const;

	  // 2) Description: Inserts newElement into the Binary Heap.
	  //              It returns "true" if successful, otherwise "false".        
	  // Postcondition: Remains a __________ Binary Heap after the insertion.
	  // Time Efficiency: O(log2 n)
	  bool insert(Event& newElement);
	   
	  // 3) Description: Removes (but does not return) the element located at the root.
	  // Precondition: This Binary Heap is not empty.
	  // Postcondition: Remains a __________ Binary Heap after the removal.	
	  // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	  // Time Efficiency: O(log2 n)
	  void remove();

	  // 4) Description: Retrieves (but does not remove) the element located at the root.
	  // Precondition: This Binary Heap is not empty.
	  // Postcondition: This Binary Heap is unchanged.
	  // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	  // Time Efficiency: O(1) 
	  Event retrieve() const;

    // Description: Prints the elements in the Heap Array
    void printHeap();

	  // For Testing Purposes
	  // Description: Prints the content of "this". 
	  friend ostream & operator<<(ostream & os, const BinaryHeap& rhs);
   
}; // end BinaryHeap
