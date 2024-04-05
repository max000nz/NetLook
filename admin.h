#pragma once
#include <iostream>
#include "viewer.h"

using namespace std;

class Admin :public Viewer {
public:
	Admin() = default;
	Admin(int id, string fname, string lname, int day, int month, int year);
	void addMovie();
	void addSeries();
	void findMovieByName();
	void findMovieByCategory();
	void findSeriesByName();
	void findSeriesByCategory();
	virtual void getPersonalInfo() throw (invalid_argument);
};