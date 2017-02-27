CFLAGS=-Wall -g

smith_counter: smith.o
	g++ -o smith_counter $(CFLAGS) smith.o

smith.o: smith.cc smithCounter.h smithCounter.cpp
	g++ -c $(CFLAGS) smith.cc

clean:
	rm -f smith_counter *.o
