#include "show.h"
#include <iostream>
#include <fstream>
using namespace std;

Show::Show(char* name, int year, char* category) {
	setName(name);
	this->year = year;
	setCategory(category);
}

void Show::setName(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Show::setCategory(const char* category)
{
	this->category = new char[strlen(category) + 1];
	strcpy_s(this->category, strlen(category) + 1, category);
}