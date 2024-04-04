#include "show.h"
#include "validationFile.h"
#include <iostream>
#include <fstream>

using namespace std;

Show::Show(string name, int year, string category) {
		this->name = name;
		this->year = year;
		this->category = category;
		this->isWL = "N";
}

Show::Show() {
	this->isWL = "N";
}

void Show::setName(const string name) {
	this->name = name;
}

void Show::setCategory(const string category) {
	this->category = category;
}

void Show::setAddWL() {
	this->isWL = "Y";
}

void Show::setDeleteWLDB() {
	this->isWL = "N";
}