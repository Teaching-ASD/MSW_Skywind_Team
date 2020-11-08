OBJS:= main.o Kalandor.o Warrior.o Json.o
CFLAGS:= -std=c++17 -Wall
CC:= g++

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
Warrior.o: Warrior.cpp Warrior.h
	$(CC) $(CFLAGS) -c Warrior.cpp
	
Kalandor.o: Kalandor.cpp Kalandor.h
	$(CC) $(CFLAGS) -c Kalandor.cpp
	
Json.o: Json.cpp Json.h
	$(CC) $(CFLAGS) -c Json.cpp

clean:
	rm -rf *.o game ./DOCS

doc:
	doxygen doxconf
