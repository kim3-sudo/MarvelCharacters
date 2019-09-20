# MakeFile to build the MarvelCharacters search program
# Kenyon College SCMP 318
# C++ compiler
OBJS	= main.o charChar.o charNameMap.o charYearMap.o userOut.o
SOURCE	= main.cpp charChar.cpp charNameMap.cpp charYearMap.cpp userOut.cpp
HEADER	= charChar.h charNameMap.h charYearMap.h includes.h userOut.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 
CFLAGS	= -std=c++14

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

charChar.o: charChar.cpp
	$(CC) $(FLAGS) charChar.cpp -std=c++11

charNameMap.o: charNameMap.cpp
	$(CC) $(FLAGS) charNameMap.cpp -std=c++11

charYearMap.o: charYearMap.cpp
	$(CC) $(FLAGS) charYearMap.cpp -std=c++11

userOut.o: userOut.cpp
	$(CC) $(FLAGS) userOut.cpp -std=c++11


clean:
	rm -f *.o main
