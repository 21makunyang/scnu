mystr:mystr.o MyString.o
	g++ mystr.o MyString.o -o mystr
mystr.o:mystr.cpp MyString.h
	g++ -c mystr.cpp MyString.h
MyString.o:MyString.cpp MyString.h
	g++ -c MyString.cpp MyString.h
clean:
	rm -f mystr mystr.o mystring.o