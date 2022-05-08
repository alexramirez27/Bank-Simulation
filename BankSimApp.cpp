#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"

// Process an arrival event
void processArrival( Event arrivalEvent, PriorityQueue& eventPriorityQueue, Queue& bankLine, unsigned int& currentTime, bool& tellerAvailable ) {
  // Remove this event from the event queue
  eventPriorityQueue.dequeue();

  // Event customer = customer referenced in arrivalEvent ????
  Event customer = arrivalEvent;
  if ( bankLine.isEmpty() && tellerAvailable ) {
    unsigned int departureTime = currentTime + customer.getLength();
    Event newDepartureEvent = Event( Event::DEPARTURE, departureTime ); // Event object with Departure type parameterized and created
    eventPriorityQueue.enqueue( newDepartureEvent ); // Added object to Priority Queue
    tellerAvailable = false;
  }
  else
    bankLine.enqueue( customer ); // Line is currently occupied so enqueue the customer
}

// Process a departure event
void processDeparture( Event departureEvent, PriorityQueue& eventPriorityQueue, Queue& bankLine, unsigned int& currentTime, bool& tellerAvailable , unsigned int& cumulativeWaitingTime ) {
  // Remove this event from the event queue
  eventPriorityQueue.dequeue();

  if ( !bankLine.isEmpty() ) {
    // Customer at front of line begins transaction
    Event customer = bankLine.peek();
    cumulativeWaitingTime = cumulativeWaitingTime + currentTime - customer.getTime();
    bankLine.dequeue();
    unsigned int departureTime = currentTime + customer.getLength();
    Event newDepartureEvent = Event( Event::DEPARTURE, departureTime ); // Create new Event object
    eventPriorityQueue.enqueue( newDepartureEvent ); // Add object to the Priority Queue
  }
  else
    tellerAvailable = true;
}

// Simulate
int main( int argc, char *argv[] ) {
  
  // Initializing variables
	Queue bankLine;
	PriorityQueue eventPriorityQueue;
	unsigned int currentTime = 0;
	unsigned int customerCount = 0;
  unsigned int cumulativeWaitingTime = 0;
	float averageWaitingTime = 0.0;
	bool tellerAvailable = true;

  // Create and add arrival events to event queue
  string filename = "simulationShuffled1.in";
  ifstream file( filename );
  if ( !file.is_open() ) {
    std::cout << "Error while opening the file." << std::endl;
  }
  else {
    while ( !file.eof() ) {
      string line;
      getline( file, line );
      string delimiter = " ";
      string firstNum = line.substr(0, line.find(delimiter));
      string secondNum = line.substr(2, line.find(delimiter));

      unsigned int time = stoi( firstNum );
      unsigned int length = stoi( secondNum );

      Event newArrival = Event( Event::ARRIVAL, time, length );
      eventPriorityQueue.enqueue( newArrival );
      customerCount++;
    }
    //eventPriorityQueue.printPriorityQueue();
  }

  std::cout << "Simulation Begins" << std::endl;
  // Event loop
  while ( !eventPriorityQueue.isEmpty() ) {
    Event newEvent = eventPriorityQueue.peek();

    // Get current time
    currentTime = newEvent.getTime();

    if ( newEvent.getType() == Event::ARRIVAL ) {
      processArrival( newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable );
      if ( newEvent.getTime() < 10 )
        std::cout << "Processing an arrival event at time:      " << newEvent.getTime() << std::endl;
      else
        std::cout << "Processing an arrival event at time:     " << newEvent.getTime() << std::endl;
    }
    else {
      processDeparture( newEvent, eventPriorityQueue, bankLine, currentTime, tellerAvailable, cumulativeWaitingTime );
      if ( newEvent.getTime() < 10 )
        std::cout << "Processing a departure event at time:     " << newEvent.getTime() << std::endl;
      else
        std::cout << "Processing a departure event at time:    " << newEvent.getTime() << std::endl;
    }
    
  }
  file.close();

  std::cout << "Simulation Ends" << std::endl << "\n";
  std::cout << "Final Statistics:" << std::endl << "\n";
  std::cout << "   Total number of people processed: " << customerCount << std::endl;
  std::cout << "   Average time people spent waiting: " << float(float(cumulativeWaitingTime)/float(customerCount)) << std::endl;

  return 0;
}