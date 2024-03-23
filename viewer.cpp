#include "viewer.h"
#include <string.h>

Viewer::Viewer(int id, char* fname, char* lname, int day, int month, int year) {
	this->id = id;
	setFname(fname);
	setLname(lname);
	this->bday = day;
	this->bmonth = month;
	this->byear = year;
}

void Viewer::setFname(const char* fname)
{
	this->fname = new char[strlen(fname) + 1];
	strcpy_s(this->fname, strlen(fname) + 1, fname);
}

void Viewer::setLname(const char* lname)
{
	this->lname = new char[strlen(lname) + 1];
	strcpy_s(this->lname, strlen(lname) + 1, lname);

}
