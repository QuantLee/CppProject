#ifndef _HANDLEEVENT_H_
#define _HANDLEEVENT_H_
// This function is used to handle event and make changes to eventlist and the
// waiting Queue. When handling a event, generate a new event.
void handleEvent(SortedListClass<event> &eventList, event &currentEvent,
	server &Server, FIFOQueueClass<customer> &waitingQueue, int &numInLine,
	FIFOQueueClass<customer> &customerInfo, int &longestLine);

void handleEvent(SortedListClass<event> &eventList, event &currentEvent,
	server &Server, FIFOQueueClass<customer> &waitingQueue, int &numInLine,
	FIFOQueueClass<customer> &customerInfo, int &longestLine)
{
	int type = currentEvent.getType();
	int currentTime = currentEvent.getTimeScheduled();
	cout << "At Time: " << currentTime << "  ";
	if (type == Arrived)
	{
		// create the customer and assign the arrive time attribute
		customer newCustomer(currentTime);
		cout << "customer " << newCustomer.getCustomerNum() << " arrived. ";
		if (Server.serverIsBusy())
		{
			cout << "server is busy, so customer is waiting in the queue." << endl;
			waitingQueue.enqueue(newCustomer);
			numInLine = numInLine + 1;
		}
		else
		{
			cout << "server is not busy, so customer get served directly." << endl;
			generateEvent(Served, currentTime, eventList);
			Server.setBeginWorkingTime(currentTime);
			Server.setIsBusy(true);
			newCustomer.setStartTime(currentTime);
			waitingQueue.enqueue(newCustomer);
			numInLine = numInLine + 1;
		}
		if (currentTime < TIME)
		{
			generateEvent(Arrived, currentTime, eventList);
		}
		cout << "There are " << numInLine << " in the waiting line." << endl;
		cout << " (customer being served included)"<< endl;
	}
	if (type == Served)
	{
		Server.addNumServed();
		cout << "server finish serving customer " << Server.getNumServed() << "  ";
		customer servedCustomer;
		waitingQueue.dequeue(servedCustomer);
		numInLine = numInLine - 1;
		servedCustomer.setLeavingTime(currentTime);
		servedCustomer.setStartTime(Server.getBeginWorkingTime());
		// Connect information of the customer being served and use it to generate
		// statistic
		customerInfo.enqueue(servedCustomer);
		Server.setFinishWorkingTime(currentTime);
		Server.setIsBusy(false);
		// If there is nobody in queue in this very moment. Do nothing and wait for
		// the arrival of next customer.
		if (numInLine == 0)
		{
			cout << "wait for the next customer to arrive" << endl;
		}
		else
		{
			cout << "and begin to server another customer" << endl;
			generateEvent(Served, currentTime, eventList);
			Server.setBeginWorkingTime(currentTime);
			Server.setIsBusy(true);
		}
		cout << "There are " << numInLine << " in the waiting line" << endl;
		if (numInLine > longestLine)
		{
			longestLine = numInLine;
		}
	}
	cout << endl;
}
#endif