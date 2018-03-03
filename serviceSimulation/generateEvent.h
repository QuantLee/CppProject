#ifndef _GENERATEEVENT_H_
#define _GENERATEEVENT_H_
// This function is used to generate event and put the event into the eventlist.
// the input is the type of the event, and eventList passing by reference.
void generateEvent(int eventType, int currentTime,
	SortedListClass<event> &eventList);
void generateEvent(int eventType, int currentTime,
	SortedListClass<event> &eventList)
{
	if (eventType == Served)
	{
		int inTime = getNormal(MEAN, STD);
		event newEvent = event(currentTime + inTime, Served);
		eventList.insertValue(newEvent);
	}
	if (eventType == Arrived)
	{
		int inTime = getUniform(MIN, MAX);
		event newEvent = event(currentTime + inTime, Arrived);
		eventList.insertValue(newEvent);
	}
}
#endif