# MakeFile to build the MarvelCharacters search program
# Kenyon College SCMP 318
# C++ compiler
CC= g++

# For optimization
# CFLAGS= -O2
# For debugging
# CFLAGS= -std=c+11

# RM= /bin/rm -f

#all: marvelcharacters

MarvelCharLookup.o: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o MarvelCharLookup MarvelCharLookup.cpp
	
CharacterNameMap.o: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o CharacterNameMap CharacterNameMap.cpp
	
CharacterProfile.o: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o CharacterProfile CharacterProfile.cpp
	
CharacterYearMap.o: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o CharacterYearMap CharacterYearMap.cpp
	
UserOutput.o: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o UserOutput UserOutput.cpp

clean:
	rm -f *.o marvelcharacters
