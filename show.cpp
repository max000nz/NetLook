#include "show.h"
#include <iostream>
#include <fstream>
using namespace std;

Show::Show(string name, int year, string category) {
	this->name = name;
	this->year = year;
	this->category = category;
}


void Show::setName(const string name) {
	this->name = name;
}

void Show::setCategory(const string category) {
	this->category = category;
}