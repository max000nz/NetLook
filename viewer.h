#pragma once
#include "series.h"
#include "movie.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

class Viewer {

protected:
	int id;
	string fname;
	string lname;
	int bday, bmonth, byear;

public:
	Viewer() = default;
	Viewer(int id, string fname, string lname, int day, int month, int year);
	int   getId() const { return id; };
	string getFname() const { return fname; };
	string getLname() const { return lname; };
	int   getDay() const { return bday; };
	int   getMonth() const { return bmonth; };
	int   getYear() const { return byear; };
	void setId(int year) { this->id = id; };
	void setBDay(int bday) { this->bday = bday; };
	void setBMonth(int bmonth) { this->bmonth = bmonth; };
	void setBYear(int byear) { this->byear = byear; };
	string chooseCategory();
	virtual void getPersonalInfo() throw (invalid_argument);
	int validateViewerInfo(string fname, string lname, int id, int day, int month, int year);
};