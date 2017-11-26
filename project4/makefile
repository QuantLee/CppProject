project4a.exe: project4a.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o
	g++ project4a.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o -o project4a.exe

project4a.o: project4a.cpp
	g++ -c project4a.cpp -o project4a.o
LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o
SortedListClass.o: SortedListClass.cpp SortedListClass.h
	g++ -c SortedListClass.cpp -o SortedListClass.o
FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h
	g++ -c FIFOQueueClass.cpp -o FIFOQueueClass.o
LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h
	g++ -c LIFOStackClass.cpp -o LIFOStackClass.o

clean:
	rm -rf project4a.exe project4a.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o