#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include <vector>
#include <list>

using namespace std;


ofstream& operator << (ofstream& out, const string& str);
ifstream& operator >> (ifstream& in, string& str);


ofstream& operator << (ofstream& out, const vector<int>& arr);
ifstream& operator >> (ifstream& in, vector<int>& arr);


ofstream& operator << (ofstream& out, const list<string>& lst);
ifstream& operator >> (ifstream& in, list<string>& lst);