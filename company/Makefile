company:company.o Employee.o Manager.o SalesMan.o SalesManager.o Technician.o 
	g++ company.o Manager.o SalesMan.o SalesManager.o Technician.o Employee.o -o company
company.o:company.cpp Manager.h SalesMan.h SalesManager.h Technician.h Employee.h
	g++ -c company.cpp Manager.h SalesManager.h Technician.h Employee.h
Employee.o:Employee.cpp Employee.h
	g++ -c Employee.cpp Employee.h
Manager.o:Manager.cpp Manager.h
	g++ -c Manager.cpp Manager.h
SalesMan.o:SalesMan.cpp SalesMan.h
	g++ -c SalesMan.cpp SalesMan.h
SalesManager.o:SalesManager.cpp SalesManager.h
	g++ -c SalesManager.cpp SalesManager.h
Technician.o:Technician.cpp Technician.h
	g++ -c Technician.cpp Technician.h
clean:
	rm -f company company.o Manager.o SalesManager.o Technician.o Employee.o