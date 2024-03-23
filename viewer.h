#pragma once

class Viewer {

protected:
	int id;
	char* fname;
	char* lname;
	int bday, bmonth, byear;

public:
	Viewer(int id, char* fname, char* lname, int day, int month, int year);

	int   getId() const { return id; };
	char* getFname() const { return fname; };
	char* getLname() const { return lname; };
	int   getDay() const { return bday; };
	int   getMonth() const { return bmonth; };
	int   getYear() const { return byear; };
	void setId(int year) { this->id = id; };
	void setFname(const char* fname);
	void setLname(const char* lname);
	void setBDay(int bday) { this->bday = bday; };
	void setBMonth(int bmonth) { this->bmonth = bmonth; };
	void setBYear(int byear) { this->byear = byear; };
};