#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
class customer
{
	private:
		// number of customer generated
		static int customerNum;
		// Time of arrival at the restaurant
		int arrivalTime;
		// Service start time
		int startTime;
		// customer leaving time
		int leavingTime;
	public:
		// Constructor, initialize all times to be zero
		customer();
		// Optional constructor with arrival time input
		customer(int inTime);
		// set the arrival time for the customer
		void setArrivalTime(int inTime);
		// set the start time when customer begin to be served
		void setStartTime(int inTime);
		// set the finish time when the customer leave the restaurant
		void setLeavingTime(int inTime);
		// get arrival time
		int getArrivalTime();
		// get start time
		int getStartTime();
		// get leaving time
		int getLeavingTime();
		// get the number of the customer
		int getCustomerNum();
};

#endif