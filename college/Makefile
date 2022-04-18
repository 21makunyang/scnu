college:college.o CollegePerson.o Student.o Teacher.o Worker.o InserviceTrainingTeacher.o
	g++ college.o CollegePerson.o Student.o Teacher.o Worker.o InserviceTrainingTeacher.o -o college
college.o:college.cpp CollegePerson.h Student.h Teacher.h Worker.h InserviceTrainingTeacher.h
	g++ -c college.cpp CollegePerson.h Student.h Teacher.h Worker.h InserviceTrainingTeacher.h
Student.o:Student.h Student.cpp
	g++ -c Student.h Student.cpp
Teacher.o:Teacher.cpp Teacher.cpp
	g++ -c Teacher.cpp Teacher.cpp
Worker.o:Worker.cpp Worker.h
	g++ -c Worker.cpp Worker.h
InserviceTrainingTeacher.o:InserviceTrainingTeacher.cpp InserviceTrainingTeacher.h
	g++ -c InserviceTrainingTeacher.cpp InserviceTrainingTeacher.h
clean:
	rm -f library college.o CollegePerson.o Student.o Teacher.o Worker.o InserviceTrainingTeacher.o