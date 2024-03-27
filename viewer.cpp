#include "viewer.h"
#include "movie.h"
#include "series.h"
#include "validationFile.h"
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

bool Viewer::isEmpty(vector<Movie> movie) {
	int size = movie.size();
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Viewer::isEmpty(vector<Series> series) {
	int size = series.size();
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

string Viewer::chooseCategory() {
	int answer;
	string category, message;
	message = "1.Sci-fi\n2.Horror\n3.Comedy\n4.Thriller\n";
	answer = answerIntViewer(message, 1, 4);
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

void Viewer::getPersonalInfo()
{}
