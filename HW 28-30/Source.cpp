#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include "Student_STL.h"
#include <vector>
#include "string to file.h"
#include <list>
using namespace std;

bool comp_age(const Student_STL& p1, const Student_STL& p2)
{
	return p1.GetAge() < p2.GetAge();
}
bool comp_average(const Student_STL& p1, const Student_STL& p2)
{
	return (p1.average() < p2.average());
}

int main()
{
	setlocale(LC_ALL, "rus");

	Student_STL stud1, stud2;
	cin >> stud1;
	cout << stud1;

	vector<int> vec1(2, 10);
	list<string> subj;
	subj.push_back("c++");
	subj.push_back("python");

	Student_STL stud_b("Semeonov", "Oleg", 20, "STEP", vec1, subj);

	vector<int> vec2(4, 9);
	list<string> subj1;
	subj1.push_back("c#");
	subj1.push_back("java");

	Student_STL stud_c("Antonov", "Anton", 19, "STEP", vec2, subj1);

	cout << "\nStudent stud_b : \n" << stud_b;

	ofstream file_write("StudTest", ios::binary);
	if (file_write)
	{
		file_write << stud_b;
		file_write.close();
	}
	else cout << "\nОшибка записи в файл";


	ifstream fr;
	fr.open("StudTest", ios::binary);
	if (fr)
	{
		fr >> stud2;
		cout << "\nСтудент из файла: " << stud2;
		fr.close();
	}
	else cout << "\nОшибка чтения файла";


	list<Student_STL> listStudent_STLs;
	listStudent_STLs.push_back(stud_b);
	listStudent_STLs.push_back(stud2);
	listStudent_STLs.push_back(stud1);
	listStudent_STLs.push_back(stud_c);

	cout << "\n=========sort by age=========";
	listStudent_STLs.sort(comp_age);
	for (auto val : listStudent_STLs)
		cout << val;
	cout << endl;
	cout << "\n=========sort by surname=========";
	listStudent_STLs.sort();
	for (auto val : listStudent_STLs)
		cout << val;
	cout << endl;
	cout << "\n=========sort by average=========";
	listStudent_STLs.sort(comp_average);
	for (auto val : listStudent_STLs)
		cout << val;
	cout << endl;









	_getch();
	return 0;
}