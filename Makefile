# MakeFile to build the MarvelCharacters search program
# Kenyon College SCMP 318
# C++ compiler
CC= g++

# For optimization
# CFLAGS= -O2
# For debugging
# CFLAGS= -std=c+11

# RM= /bin/rm -f
	
charChar: charChar.cpp charChar.h
	g++ -o charChar charChar.cpp

charNameMap: includes.h charNameMap.cpp charNameMap.h
	g++ -o charNameMap charNameMap.cpp
	
charYearMap: includes.h charYearMap.cpp charYearMap.h
	g++ -o charYearMap charYearMap.cpp
	
userOut: userOut.cpp userOut.h
	g++ -o userOut userOut.cpp
	
main: includes.h main.cpp userOut.h charChar.h charNameMap.h charYearMap.h
	g++ -o main main.cpp
	
clean:
	rm -f *.o main
