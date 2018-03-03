#ifndef _SERVER_H_
#define _SERVER_H_
class server
{
	private:
		// Number of customer be served
		static int customerNum;
		// A boolean variable used to keep track of the server status
		bool isBusy;
		int beginWorkingTime;
		int finishWorkingTime;
	public:
		// Default constructor
		server();
		// Set the status for the server indicating if the server is busy or not
		void setIsBusy(bool inIsBusy);
		// Set the time when server begin to work
		void setBeginWorkingTime(int intime);
		// Set the time when server finish working
		void setFinishWorkingTime(int intime);
		// To access the condition of the server
		bool serverIsBusy();
		// get beginWorkingTime
		int getBeginWorkingTime();
		// get finishWorkingTime
		int getFinishWorkingTime();
		// finish serving a customer and customerNum + 1
		void addNumServed();
		// get access to the static value
		int getNumServed();
};

#endif