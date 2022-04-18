library:library.o Book.o BDatabase.o RDatabase.o Reader.o
	g++ -c library.o Book.o BDatabase.o RDatabase.o Reader.o
library.o:library.cpp Book.h BDatabase.h RDatabase.h Reader.h
	g++ -c library.cpp Book.h BDatabase.h RDatabase.h Reader.h
Book.o:Book.cpp Book.h
	g++ -c Book.cpp Book.h
BDatabase.o:BDatabase.cpp BDatabase.h
	g++ -c BDatabase.cpp BDatabase.h
RDatabase.o:RDatabase.cpp RDatabase.h
	g++ -c RDatabase.cpp RDatabase.h
Reader.o:Reader.cpp Reader.h
	g++ -c Reader.cpp Reader.h
clean:
	rm -f library library.o Book.o BDatabase.o RDatabase.o Reader.o