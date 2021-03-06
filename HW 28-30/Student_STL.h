#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include "string to file.h"

using namespace std;

class Student_STL
{
	string surname;
	string name;
	int age;
	string vuz;
	vector<int> marks;
	list<string> subjects;

public:
	Student_STL();
	Student_STL(string surname, string name, int age, string vuz, vector<int> marks, list<string> subjects);

	int GetAge()const { return age; }
	string GetSurname()const { return surname; }

	double average()const {
		double tmp = 0;
		for (auto val : marks)
			tmp += val;
		tmp /= marks.size();
		return tmp;
	}
	void TakeSubject(const string& s);

	friend ostream& operator << (ostream& out, const Student_STL & st);
	friend istream& operator >> (istream& in, Student_STL& st);
	
	friend bool operator<(const Student_STL& a, const Student_STL& b);

	friend ofstream& operator << (ofstream& out, const Student_STL& st);
	friend ifstream& operator >> (ifstream& in, Student_STL& st);
};



