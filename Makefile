OBJS:= main.o Hero.o Monster.o JSON.o
CFLAGS:= -Wall
CC:= g++

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
Hero.o: Hero.cpp
	$(CC) $(CFLAGS) -c Hero.cpp
	
Monster.o: Monster.cpp
	$(CC) $(CFLAGS) -c Monster.cpp
	
JSON.o: JSON.cpp
	$(CC) $(CFLAGS) -c JSON.cpp

clean:
	rm -rf *.o game ./DOCS

doc:
	doxygen doxconf
