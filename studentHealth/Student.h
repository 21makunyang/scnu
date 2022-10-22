#pragma once
#include <string>
using namespace std;

enum Gender {
	male,
	female
};

typedef struct Stuednt {
	unsigned int id;
	string name;
	string birthday;
	Gender gender;
	string health;
}Student,*LPStudent;



