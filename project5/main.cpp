#include <iostream>
using namespace std;

#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "random.h"
#include "constant.h"
#include "event.h"
#include "server.h"
#include "customer.h"
// Globle function include files
#include "generateEvent.h"
#include "statisticsCollection.h"
#include "handleEvent.h"

// Programmer: Dongxu Li
// Date: Nov 28, 2017
// Purpose: Template 2 data structure classes: Sorted double linked list class,
// Queue class, the simulation to implement will be a server simulation at a
// fast food restaurant. And gather valuable statistics from the experiment.
// The statiscs in the result output include:
// 1. Total number of customers simulated.
// 2. Percentage of time the server was busy helping customers.
// 3. What percentage of customers had to wait in line.
// 4. The longest of line was throughout the simulation.

// This funtion is used to check is the input is valid.
void intInput(int &input);


int main()
{
	// The main default input parameter values for simulation.
	cout << "Defaut constant values list: " << endl;
	cout << "Random Seed Value: ";
	intInput(SEED);
	cout << "Uniformed distribution used to describe customer arrival." << endl;
	cout << "min value: ";
	intInput(MIN);
	cout << "max value: ";
	intInput(MAX);
	if (MIN > MAX)
	{
		cout << "invalid MIN and MAX value, MIN value should be smaller than Max"
		<< "value, please start over!" << endl;
		return 1;
	}
	cout << "Normal distribution describes server's serving spead." << endl;
	cout << "mean value: ";
	intInput(MEAN);
	cout << "standard deviation: ";
	intInput(STD);
	cout << "restaurant closing time: ";
	intInput(TIME);
	cout << endl;
	// Set random seed to get ready for simulations
	setSeed(SEED);
	// Used to collect served customer information
	FIFOQueueClass<customer> customerInfo;
	// Event list, use to store the arrival events
	SortedListClass<event> eventList;
	// Waiting queue, use to store customer object, customer waiting line.
	FIFOQueueClass<customer> waitingQueue;
	int numInLine = 0;
	int longestLine = 0;
	// Time to start the simulation
	int currentTime = 0;
	// Begining event:
	generateEvent(Arrived, currentTime, eventList);
	event currentEvent;
	server Server;
	// Stop the simulation when the eventlist is empty.
	while(eventList.removeFront(currentEvent))
	{
		currentTime = currentEvent.getTimeScheduled();
		handleEvent(eventList, currentEvent, Server, waitingQueue, numInLine,
			customerInfo, longestLine);
	}


///////////////////////////statistic collection/////////////////////////////////
	int totalServingTime = 0;
	int totalWaitingTime = 0;
	int noWaitingCustomer = 0;
	int longestWaitingTime = 0;
	int longestServingTime = 0;
	int totalCustomer = Server.getNumServed();

	statisticsCollection(customerInfo, totalServingTime, totalWaitingTime,
		noWaitingCustomer, longestWaitingTime, longestServingTime);
	cout << "#---------------------Statiscs Summary---------------------#"<< endl;
	cout << "Constant values list: " << endl;
	cout << "Uniformed distribution used to describe customer arrival." << endl;
	cout << "min value: " << MIN << "   max value: " << MAX << endl;
	cout << "Normal distribution describes server's serving spead." << endl;
	cout << "mean value: " << MEAN << "   standard deviation: " << STD << endl;
	cout << endl;
	cout << "Simulation Result: " << endl;

	cout << "Total simulation time: " << currentTime << endl;
	cout << "1. Total number of customers simulated: " << totalCustomer << endl;
	// 100 appear below is used to convert float number to percentage
	cout << "2. Percentage of time the server was busy helping customers: "
	<< float(totalServingTime)/currentTime * 100 << "%" << endl;
	cout << "3. What percentage of customers had to wait in line: "<<
	(totalCustomer - noWaitingCustomer)/float(totalCustomer) * 100 << "%" << endl;
	cout << "4. The longest of line was throughout the simulation: "
	<< longestLine + 1 << endl;
	cout << "5: The average waiting time is: "
	<< totalWaitingTime / float(totalCustomer) << endl;
	cout << "6: The average serving time is: "
	<< totalServingTime / float(totalCustomer) << endl;
	cout << "7: The longest waiting time is: "
	<< longestWaitingTime << endl;
	cout << "8: The longest serving time is: "
	<< longestServingTime << endl;
	cout << "9: When the restaurant closed, there are still people waiting inline"
	<< endl << "So Server need to spend extra: " << currentTime - TIME
	<< " minutes in the restaurant cus the overcrowded situation." << endl;
	return 0;
}


void intInput(int &input)
{
  int charIgnoreNum = IGNORE;
  bool validInputFound = false;
  while (!validInputFound)
  {
    cin >> input;
    if (cin.fail() || input < 0)
    {
      cin.clear();
      cin.ignore(charIgnoreNum, '\n');
      cout << endl;
      cout << "Fail state! The input is not an positive interger" << endl;
      cout << "Try again - Enter an interger: ";
    }
    else
    {
      validInputFound = true;
    }
  }
}