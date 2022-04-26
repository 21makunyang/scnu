company:company.o Employee.o MainAger.o SalesMan.o SalesManager.o Technician.o 
	g++ company.o MainAger.o SalesManager.o Technician.o Employee.o -o company
company.o:company.cpp MainAger.h SalesMan.h SalesManager.h Technician.h Employee.h
	g++ -c company.cpp MainAger.h SalesManager.h Technician.h Employee.h
Employee.o:Employee.cpp Employee.h
	g++ -c Employee.cpp Employee.h
MainAger.o:MainAger.cpp MainAger.h
	g++ -c MainAger.cpp MainAger.h
SalesMan.o:SalesMan.cpp SalesMan.h
	g++ -c SalesMan.cpp SalesMan.h
SalesManager.o:SalesManager.cpp SalesManager.h
	g++ -c SalesManager.cpp SalesManager.h
Technician.o:Technician.cpp Technician.h
	g++ -c Technician.cpp Technician.h
clean:
	rm -f company company.o MainAger.o SalesManager.o Technician.o Employee.o