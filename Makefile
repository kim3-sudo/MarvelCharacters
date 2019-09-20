# MakeFile to build the MarvelCharacters search program
# Kenyon College SCMP 318
# C++ compiler
CC= g++

# For optimization
# CFLAGS= -O2
# For debugging
# CFLAGS= -std=c+11

# RM= /bin/rm -f
	
CharacterNameMap: includes.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o -c CharacterNameMap CharacterNameMap.cpp
	
CharacterProfile: includes.h CharacterProfile.cpp CharacterProfile.h CharacterNameMap.cpp CharacterNameMap.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o -c CharacterProfile CharacterProfile.cpp
	
CharacterYearMap: includes.h CharacterYearMap.cpp CharacterYearMap.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h UserOutput.cpp UserOutput.h
	g++ -o -c CharacterYearMap CharacterYearMap.cpp
	
UserOutput: includes.h UserOutput.cpp UserOutput.h CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h
	g++ -o -c UserOutput UserOutput.cpp
	
MarvelCharLookup: includes.h MarvelCharLookup.cpp CharacterNameMap.cpp CharacterNameMap.h CharacterProfile.cpp CharacterProfile.h CharacterYearMap.cpp CharacterYearMap.h UserOutput.cpp UserOutput.h
	g++ -o -c MarvelCharLookup MarvelCharLookup.cpp

clean:
	rm -f *.o marvelcharacters
