CFLAGS=-Wall -g

smith_counter: smith.o stats.o smithCounter.o
	g++ -o smith_counter $(CFLAGS) smith.o stats.o smithCounter.o

smithCounter.o: smithCounter.cpp smithCounter.h
	g++ $(CFLAGS) -c smithCounter.cpp -o smithCounter.o

stats.o: stats.cpp stats.h
	g++ $(CFLAGS) -c stats.cpp -o stats.o

smith.o: smith.cpp stats.h smithCounter.h
	g++ $(CFLAGS) -c smith.cpp -o smith.o

clean:
	rm -f smith_counter *.o
