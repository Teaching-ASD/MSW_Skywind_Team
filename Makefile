OBJS:= main.o Hero.o Monster.o JSON.o
CFLAGS:= -Wall
CC:= g++

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

hero.o: Hero.cpp
	$(CC) $(CFLAGS) -c Hero.cpp

monster.o: Monster.cpp
	$(CC) $(CFLAGS) -c Monster.cpp

json.o: JSON.cpp
	$(CC) $(CFLAGS) -c JSON.cpp

clean:
	rm -rf *.o game ./DOCS

doc:
	doxygen doxconf
