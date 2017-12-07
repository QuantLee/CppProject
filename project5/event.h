#ifndef _EVENT_H_
#define _EVENT_H_

// This class is used to reprent the events which will be inserted into a
// SortedListClass in a sorted way based on the time that the event is scheduled
// to occur, there are three kinds of events, one is the the customer arrival,
// one server begins to serve, and server finishes serving.
class event
{
	private:
		// The event is scheduled to happend in the sccheduled time
		int timeScheduled;
		// eventType can be 0, 1, 1 represent the arrival event, 0 represent
		// server finish serving and is ready to serve another costomer.
		int eventType;
	public:
		// The default constructor
		event();
		// Other type of  constructor of event class, need to specify the time,type.
		event(int inTime, int inType);
		// Operation overload, in order to be inserted into a SortedListClass in
		// a sorted way based on the time that the event is scheduled to occur.
		bool operator>(const event &rhs);
		// Get the time scheduled for the event
		int getTimeScheduled();
		// Get value of event type
		char getType();
};

#endif