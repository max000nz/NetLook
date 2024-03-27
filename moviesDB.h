#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"

class MoviesDB
{
public:
	static vector<Movie>& getMoviesDB();
	static vector<Movie>& getMoviesWatchListDB();
	static void setupMoviesDB(string way);
	static void updateFileMoviesDB(string way);
	static void addMovieToDB(Movie& movie);
};
