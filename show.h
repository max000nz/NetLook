#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include <ctime>//need to check how to use(for sort by adding date, update)

class Show {

public:
	string name;
	int year;
	string category;
	int time;

public:
	Show() = default;
	Show(string name, int year, string category);
	string getName() const { return name; };
	int   getYear() const { return year; };
	string getCategory() const { return category; };
	int getTime() const { return time; };
	void setName(const string name);
	void setYear(int year) { this->year = year; };
	void setCategory(const string category);
	void setTime(int time) { this->time = time; };
	bool operator > (const Show& str) const {
		if (getYear() != str.getYear())	return (getYear() > str.getYear());
		return (getTime() > str.getTime());
	}
};