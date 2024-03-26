#pragma once
#include "viewer.h"
#include <vector>
#include "show.h"
#include "movie.h"
#include "series.h"

class User :public Viewer {

private:
	vector<Movie> watchListMovies;
	vector<Series> watchListSeries;

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
	void notToAddTwice(vector<Movie> movies);
	void notToAddTwice(vector<Series> series);
	vector<Movie> openFile(vector<Movie> movies, string way);
	vector<Series> openFile(vector<Series> series, string way);
	vector<Movie> closeWatchListMovies(vector<Movie> movies);
	vector<Series> closeWatchListSeries(vector<Series> series);
};