proj3.exe: project3.o ColorClass.o ColorImageClass.o RowColumnClass.o
	g++ project3.o ColorClass.o ColorImageClass.o RowColumnClass.o -o proj3.exe

project3.o: project3.cpp
	g++ -c project3.cpp -o project3.o
ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o
ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o
RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

clean:
	rm -rf proj3.exe project3.o ColorClass.o ColorImageClass.o RowColumnClass.o