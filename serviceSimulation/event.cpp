#include "event.h"

// The default constructor
event::event()
{
	timeScheduled = 0;
	eventType = 0;
}
// The only constructor of event class, need to specify the time and type.
event::event(int inTime, int inType)
{
	eventType = inType;
	timeScheduled = inTime;
}

// Operation overload, in order to be inserted into a SortedListClass in
// a sorted way based on the time that the event is scheduled to occur.
bool event::operator>(const event &rhs)
{
	if (timeScheduled > rhs.timeScheduled)
	{
		return true;
	}
	return false;
}

// Get the time scheduled for the event
int event::getTimeScheduled()
{
	return timeScheduled;
}

// Get value of event type
char event::getType()
{
	return eventType;
}
