#pragma once
#include "viewer.h"
#include <vector>
#include "show.h"
#include "movie.h"
#include "series.h"

class User :public Viewer {

public:
	User() = default;
	User(int id, string fname, string lname, int day, int month, int year);
	void findMovieByName();
	void findSeriesByName();
	void watchMovieFromList();
	void watchSeriesFromList();
	void deleteMovieFromList();
	void deleteSeriesFromList();
	void chooseFromMovies();
	void chooseFromMoviesByCategory();
	void chooseFromSeriesByCategory();
	void chooseFromSeries();
	virtual void getPersonalInfo() throw (invalid_argument);
};