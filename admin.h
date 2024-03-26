#pragma once
#include "user.h"
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
	vector<Movie> openFile(vector<Movie> movies, string way);
	vector<Movie> closeFile(vector<Movie> movies, string way);
	vector<Series> openFile(vector<Series> series, string way);
	vector<Series> closeFile(vector<Series> series, string way);
};