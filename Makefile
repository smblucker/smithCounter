CFLAGS=-Wall -g

smith_counter: smith.o smithCounter.o
	g++ -o smith_counter $(CFLAGS) smith.o smithCounter.o

smithCounter.o: smithCounter.cpp smithCounter.h
	g++ $(CFLAGS) -c smithCounter.cpp -o smithCounter.o

smith.o: smith.cpp smithCounter.h
	g++ $(CFLAGS) -c smith.cpp -o smith.o

clean:
	rm -f smith_counter *.o
