#ifndef _STATISTICSCOLLECTION_H_
#define _STATISTICSCOLLECTION_H_
// Statistic accumulation function, do calculation on customer infomation we collected
// during the whole simulation period.
void statisticsCollection(FIFOQueueClass<customer> &customerInfo,
	int &totalServingTime, int &totalWaitingTime, int &noWaitingCustomer,
	int &longestWaitingTime, int &longestServingTime);

void statisticsCollection(FIFOQueueClass<customer> &customerInfo,
	int &totalServingTime, int &totalWaitingTime, int &noWaitingCustomer,
	int &longestWaitingTime, int &longestServingTime)
{
	customer info;
	int waitingTime;
	int servingTime;
	while(customerInfo.dequeue(info))
	{
		waitingTime = info.getStartTime() - info.getArrivalTime();
		if (waitingTime > longestWaitingTime)
		{
			longestWaitingTime = waitingTime;
		}
		if (waitingTime == 0)
		{
			noWaitingCustomer = noWaitingCustomer + 1;
		}
		servingTime = info.getLeavingTime() - info.getStartTime();
		if (servingTime > longestServingTime)
		{
			longestServingTime = servingTime;
		}
		totalServingTime = totalServingTime + servingTime;
		totalWaitingTime = totalWaitingTime + waitingTime;
	}
}
#endif