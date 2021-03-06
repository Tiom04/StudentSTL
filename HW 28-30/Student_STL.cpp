#include <iostream>
#include "Student_STL.h"
#include "string to file.h"

using namespace std;

Student_STL::Student_STL()
{
	surname = "no name";
	name = "name";
	age = 0;
	vuz = "no vuz";
}

Student_STL::Student_STL(string surname, string name, int age, string vuz, vector<int> marks,
	               list<string> subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}
ostream& operator << (ostream& out, const Student_STL& st)
{
	out << "\nФамилия:          " << st.surname
		<< "\nИмя:              " << st.name
		<< "\nВозраст:          " << st.age
		<< "\nВУЗ:              " << st.vuz
		<< "\nКол-во оценок:    " << st.marks.size()
		<< "\nОценки:           "; 
	for (auto v : st.marks)
		cout << v << "  ";
	cout << "\nКол-во предметов: " << st.subjects.size()
		<< "\nПредметы:         ";
	for (auto val : st.subjects)
		cout << val << "  ";
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Student_STL& st)
{
	cout << "\nВведи данные студента: \n";
	cout << "Фамилия:         ";
	in >> st.surname;
	cout << "Имя:             ";
	in >> st.name;
	cout << "Возраст:         ";
	in >> st.age;
	in.get();
	cout << "ВУЗ:             ";
	in >> st.vuz;
	cout << "Кол-во оценок:   ";
	int s;
	in >> s;
	st.marks.resize(s);
	cout << "Оценки:          ";
	for (auto& v : st.marks)
		in >> v;
	cout << "Кол-во предметов:";
	in >> s;
	in.get();
	cout << "Предметы:        \n";
	string sub;
	for (int p = 1; p <= s; p++	)
	{
		getline(in, sub);
		st.subjects.push_back(sub);
	}
	return in;
}

void Student_STL::TakeSubject(const string& s)
{
	subjects.push_back(s);
}

bool operator<(const Student_STL& a, const Student_STL& b)
{
	return a.surname < b.surname;
}

ofstream& operator << (ofstream& out, const Student_STL& st)
{
	out << st.surname << st.name;
	out.write((char*)&st.age, sizeof(st.age));
	out << st.vuz << st.marks << st.subjects;
	return out;
}
ifstream& operator >> (ifstream& in, Student_STL& st)
{
	in >> st.surname >> st.name;
	in.read((char*)&st.age, sizeof(st.age)); 
	in >> st.vuz >> st.marks >> st.subjects;
	return in;
}



