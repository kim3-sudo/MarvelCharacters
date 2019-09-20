# MakeFile to build the MarvelCharacters search program
# Kenyon College SCMP 318
# C++ compiler
CC= g++

# For optimization
# CFLAGS= -O2
# For debugging
CFLAGS= -std=c+11

RM= /bin/rm -f

all: marvelcharacters

CharacterNameMap.o: CharacterNameMap.cpp CharacterNameEntry.h includes.h
	$(CC) $(CFLAGS) CharacterNameMap.cpp -c
	
CharacterProfile.o: CharacterProfile.cpp CharacterProfile.h includes.h
	$(CC) $(CFLAGS) CharacterProfile.cpp
	
CharacterYearMap.o: CharacterYearMap.cpp CharacterYearMap.h includes.h CharacterProfile.h
	$(CC) $(CFLAGS) CharacterYearMap.cpp
	
UserOutput.o: UserOutput.cpp UserOutput.h CharacterProfile.h includes.h
	$(CC) $(CFLAGS) UserOutput.cpp
	
MarvelCharLookup.o: MarvelCharLookup.cpp UserOutput.h CharacterNameMap.h CharacterProfile.h includes.h
	$(CC) $(CFLAGS) MarvelCharLookup.cpp
	
clean:
	rm -f *.o marvelcharacters