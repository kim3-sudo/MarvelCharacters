#MakeFile to build and deploy the Sample US CENSUS Name Data using ajax
# For CSC3004 Software Development

# Put your user name below:
USER= kim3

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14

RM= /bin/rm -f

all: character_lookup PutCGI PutHTML

CharacterProfile.o: CharacterProfile.cpp CharacterProfile.h
	$(CC) $(CFLAGS) CharacterProfile.cpp -c

CharacterNameMap.o: CharacterNameMap.cpp CharacterNameMap.h
	$(CC) $(CFLAGS) CharacterNameMap.cpp -c

CharacterYearMap.o: CharacterYearMap.cpp CharacterYearMap.h
	$(CC) $(CFLAGS) CharacterYearMap.cpp -c

Marvel.o: Marvel.cpp CharacterNameMap.h CharacterYearMap.h CharacterProfile.h
	$(CC) $(CFLAGS) Marvel.cpp -c

character_lookup: Marvel.o CharacterNameMap.o CharacterYearMap.o CharacterProfile.o
	$(CC) Marvel.o -o character_lookup CharacterNameMap.o CharacterYearMap.o CharacterProfile.o -L/usr/local/lib -lcgicc

PutCGI: character_lookup
	chmod 757 character_lookup
	cp character_lookup /usr/lib/cgi-bin/$(USER)_character_lookup.cgi 

	echo "Current contents of your cgi-bin directory: "
	ls -l /usr/lib/cgi-bin/

PutHTML:
	cp namelookup.html /var/www/html/class/softdev/kim3/Names/
	cp namelookup.css /var/www/html/class/softdev/kim3/Names/
	cp namelookup.js /var/www/html/class/softdev/kim3/Names/

	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/class/softdev/$(USER)/Names/
clean:
	rm -f *.o  character_lookup
