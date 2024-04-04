#include "viewer.h"
#include "movie.h"
#include "series.h"
#include "validationFile.h"
#include "strings.h"
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>


Viewer::Viewer(int id, string fname, string lname, int day, int month, int year) {
	this->id = id;
	this->fname = fname;
	this->lname = lname;
	this->bday = day;
	this->bmonth = month;
	this->byear = year;
}

string Viewer::chooseCategory() {
	int answer;
	string category;
	answer = answerIntViewer(categoryShow, 1, 4);
	switch (answer) {
	case 1:
		category = "Sci-fi";
		break;
	case 2:
		category = "Horror";
		break;
	case 3:
		category = "Comedy";
		break;
	case 4:
		category = "Thriller";
		break;
	}
	return category;
}

void Viewer::getPersonalInfo()  throw (invalid_argument)
{}

int Viewer::validateViewerInfo(string fname, string lname, int id, int day, int month, int year) {
	try {
		if (fname == "") {
			throw out_of_range("Missing name");
		}
		if (lname == "") {
			throw out_of_range("Missing last name");
		}
		if (id < 100000000 || id>999999999) {
			throw out_of_range("Wrong ID");
		}
		if (day < 1 || day>31) {
			throw out_of_range("Wrong day");
		}
		if (month < 1 || month > 12) {
			throw out_of_range("Wrong month");
		}
		if (year < 1900 || year > 2024) {
			throw out_of_range("Wrong year");
		}
	}catch(const out_of_range& e) {
			cerr << e.what() << endl;
			return 0;
	}
	return 1;
}
