#include "server.h"

int server::customerNum = 0;

// Default constructor
server::server()
{
	isBusy = false;
	beginWorkingTime = 0;
	finishWorkingTime = 0;
}

// Set the status for the server indicating if the server is busy or not
void server::setIsBusy(bool inIsBusy)
{
	isBusy = inIsBusy;
}

// Set the time when server begin to work
void server::setBeginWorkingTime(int intime)
{
	beginWorkingTime = intime;
}

// Set the time when server finish working
void server::setFinishWorkingTime(int intime)
{
	finishWorkingTime = intime;
}

// To access the condition of the server
bool server::serverIsBusy()
{
	return isBusy;
}

// get beginWorkingTime
int server::getBeginWorkingTime()
{
	return beginWorkingTime;
}

// get finishWorkingTime
int server::getFinishWorkingTime()
{
	return finishWorkingTime;
}

// finish serving a customer and customerNum + 1
void server::addNumServed()
{
	customerNum = customerNum + 1;
}

// get access to the static value
int server::getNumServed()
{
	return customerNum;
}


