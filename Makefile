CFLAGS=-Wall 

smith_counter: smith.o
	g++ -o smith_counter $(CFLAGS) smith.o

smith.o: smith.cpp smithCounter.h smithCounter.cpp
	g++ -c $(CFLAGS) smith.cpp

clean:
	rm -f smith_counter *.o
