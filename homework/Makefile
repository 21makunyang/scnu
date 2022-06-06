graph:graph.cpp Shape.h Triangle.o Circle.o Rectangle.o
	g++ graph.cpp Shape.h Triangle.o Circle.o Rectangle.o -o graph
Triangle.o:Shape.h Triangle.h Triangle.cpp

Rectangle.o:Shape.h Rectangle.h Rectangle.cpp

clean:
	rm -f graph Shape.o Triangle.o Circle.o Rectangle.o