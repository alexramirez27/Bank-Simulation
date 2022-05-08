/* 
 * BinaryHeap.cpp
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

#include "BinaryHeap.h"  // Header file

// Description: Default Constructor
BinaryHeap::BinaryHeap() {
  elements = new Event[capacity]; 
  elementCount = 0;
   
} // end of default constructor

// Description: Copy Constructor
BinaryHeap::BinaryHeap( const BinaryHeap& aBinaryHeap ) {
  exponent = aBinaryHeap.exponent; // private though ?
  capacity = aBinaryHeap.capacity;
  elementCount = aBinaryHeap.elementCount;
  // Copy elements
  for ( unsigned int i = 0; i < elementCount; i++ )
    elements[i] = aBinaryHeap.elements[i];
}

// Description: Destructor
// Postcondition: All elements are removed
BinaryHeap::~BinaryHeap() {
  delete [] elements;
  elementCount = 0;
}

	
// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
unsigned int BinaryHeap::getElementCount() const {
   return elementCount;
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a Minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
bool BinaryHeap::insert( Event& newElement ) { 
  bool ableToInsert = false;

  // Empty Binary Heap
  if ( elementCount == 0 ) {
    elements[0] = newElement; 
    elementCount++;
    ableToInsert = true;
    return ableToInsert;
  }
  
  // Binary Heap is full
  if ( elementCount == capacity ) {
    capacity = capacity + pow(2, exponent);
    exponent++;
    Event* newElements = new Event[capacity];
    
    // Copy elements into newElements
    for ( unsigned int i = 0; i < elementCount; i++ ) 
      newElements[i] = elements[i];

    elements = newElements;
  }

  elements[elementCount] = newElement;
  elementCount++; // Increment elementCount
  reHeapUp( elementCount - 1 );
  ableToInsert = true;
  return ableToInsert;
} // end insert


// Utility method - Recursively put the array back into a Minimum Binary Heap.
void BinaryHeap::reHeapUp( unsigned int indexOfBottom ) {
  float indexOfMinElementCalc = indexOfBottom; 
  int indexOfMinElement = indexOfMinElementCalc;

  // Find index of parent
  float indexOfParentCalc = floor( (indexOfMinElementCalc-1)/2 ); 
  int indexOfParent = indexOfParentCalc;

  // Base case: elements[indexOfBottom] is the root
  if ( indexOfParent < 0 ) return;
  
  // If we need to swap, select the smallest element
  if ( ! (elements[indexOfParent] <= elements[indexOfBottom]) )
    indexOfMinElement = indexOfParent;
  
  // Swap parent with smallest element
  if ( indexOfMinElement != indexOfBottom  ) {
    Event temp = elements[indexOfBottom];
    elements[indexOfBottom] = elements[indexOfMinElement];
    elements[indexOfMinElement] = temp;
    reHeapUp( indexOfMinElement );
  }
    
	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Minimum Binary Heap after the removal.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
void BinaryHeap::remove() {
  // Move each element forward by one
  for ( int i = 1; i < elementCount; i++ ) 
    elements[i-1] = elements[i];

  elementCount--;

  for ( unsigned int i = 0; i < elementCount; i++ ) 
    reHeapUp(i);
  
	return;
}  // end remove


// Utility method - Recursively put the array back into a Minimum Binary Heap.
void BinaryHeap::reHeapDown( unsigned int indexOfRoot ) {
	unsigned int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

  // Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;

	// If we need to swap, select the smallest child
  // if (elements[indexOfRoot] > elements[indexOfLeftChild])
	if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
    indexOfMinChild = indexOfLeftChild;

  // Check if there is a right child, is it the smallest?
  if ( indexOfRightChild < elementCount ) {
	  // if (elements[indexOfMinChild] > elements[indexOfRightChild])
	  if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
		  indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if ( indexOfMinChild != indexOfRoot ) {
		
	   Event temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown( indexOfMinChild );
    }

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
Event BinaryHeap::retrieve() const {
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve

// For Testing Purposes
// Description: Prints the content of "rhs".
ostream& operator<<( ostream & os, const BinaryHeap& rhs ) {
	for ( unsigned int index = 0; index < rhs.elementCount; index++ )
		os << rhs.elements[index]; // Print data

	return os;
} // end of operator <<

void BinaryHeap::printHeap() {
  for ( unsigned int i = 0; i < elementCount; i++ ) 
    std::cout << elements[i];
  
  std::cout << std::endl;
}

//  End of implementation file.