#include "customer.h"

int customer::customerNum = 0;

customer::customer()
{
	arrivalTime = 0;
	startTime = 0;
	leavingTime = 0;
}

// Optional constructor
customer::customer(int inTime)
{
	customerNum = customerNum + 1;
	arrivalTime = inTime;
	startTime = 0;
	leavingTime = 0;
}


void customer::setArrivalTime(int inTime)
{
	arrivalTime = inTime;
}

void customer::setStartTime(int inTime)
{
	startTime = inTime;
}

void customer::setLeavingTime(int inTime)
{
	leavingTime = inTime;
}

// get arrival time
int customer::getArrivalTime()
{
	return arrivalTime;
}

// get start time
int customer::getStartTime()
{
	return startTime;
}

// get leaving time
int customer::getLeavingTime()
{
	return leavingTime;
}

// get the number of the customer
int customer::getCustomerNum()
{
	return customerNum;
}



