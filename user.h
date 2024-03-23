#pragma once
#include "viewer.h"
#include <vector>
#include "show.h"
#include "movie.h"
#include "series.h"

class User :public Viewer {

private:
	vector<Show> watchList;

public:
	User(int id, char* fname, char* lname, int day, int month, int year, vector<Show> watchList);
	void addMovieToWatchList(Movie currentMovie);
	void addSeriesToWatchList(Series currentSeries);
	void findByName(char* name);
	void watchMovieFromList();
	void watchSeriesFromList();
	void deleteMovieFromList();
	void deleteSeriesFromList();
	//void backToMenu();
};