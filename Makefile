CC = g++
CFLAGS  = -std=c++11 -g -Wall

byteotia: byteotia.o 
	$(CC) $(CFLAGS) byteotia.o -o byteotia

byteotia.o: byteotia.cpp
	$(CC) $(CFLAGS) -c byteotia.cpp

clean:
	rm -f *.o
	rm -f byteotia
