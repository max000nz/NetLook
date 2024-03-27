#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Show {

protected:
	string name;
	int year;
	string category;
	int time;
	string isWL;
public:
	Show();
	Show(string name, int year, string category);
	string getName() const { return name; };
	int   getYear() const { return year; };
	string getCategory() const { return category; };
	int getTime() const { return time; };
	void setName(const string name);
	void setYear(int year) { this->year = year; };
	void setCategory(const string category);
	void setTime(int time) { this->time = time; };
	void setIsWL(string isWL) { this->isWL = isWL; };
	string getIsWL() const { return isWL; };
	void setAddWL();
	void setDeleteWLDB();
};