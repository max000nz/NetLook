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
	vector<Movie> openMovies(vector<Movie> movies);
	vector<Movie> closeMovies(vector<Movie> movies);
	vector<Series> openSeries(vector<Series> series);
	vector<Series> closeSeries(vector<Series> series);
};