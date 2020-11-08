OBJS:= main.o hero.o monster.o json.o
CFLAGS:= -Wall
CC:= g++

game: $(OBJS)
	$(CC) $(CFLAGS) -o game $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

hero.o: hero.cpp
	$(CC) $(CFLAGS) -c hero.cpp

monster.o: monster.cpp
	$(CC) $(CFLAGS) -c monster.cpp

json.o: json.cpp
	$(CC) $(CFLAGS) -c json.cpp

clean:
	rm -rf *.o game ./DOCS

doc:
	doxygen doxconf
