#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <ctime>//need to check how to use(for sort by adding date, update)

class Show {

protected:
	char* name;
	int year;
	char* category;

public:
	Show();
	Show(char* name, int year, char* category);
	char* getName() const { return name; };
	int   getYear() const { return year; };
	char* getCategory() const { return category; };
	void setName(const char* name);
	void setYear(int year) { this->year = year; };
	void setCategory(const char* category);
};