OBJS:= main.o Hero.o Monster.o JSON.o
CFLAGS:= -std=c++17 -Wall
CC:= g++-10

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
Hero.o: Hero.cpp Hero.h
	$(CC) $(CFLAGS) -c Hero.cpp
	
Monster.o: Monster.cpp Monster.h
	$(CC) $(CFLAGS) -c Monster.cpp
	
JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

clean:
	rm -rf *.o game ./DOCS

doc:
	doxygen doxconf
