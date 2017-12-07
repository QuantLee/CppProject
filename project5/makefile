main.exe: main.o random.o event.o customer.o server.o
	g++ main.o random.o event.o customer.o server.o -o main.exe

main.o: main.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h constant.h generateEvent.h handleEvent.h statisticsCollection.h
	g++ -c main.cpp -o main.o

random.o: random.cpp random.h
	g++ -c random.cpp -o random.o

event.o: event.cpp event.h
	g++ -c event.cpp -o event.o

customer.o: customer.cpp customer.h
	g++ -c customer.cpp -o customer.o

server.o: server.cpp server.h
	g++ -c server.cpp -o server.o

clean:
	rm -rf main.exe main.o random.o event.o customer.o server.o