#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Winscard")
#include "strings.h"
#include "menus.h"
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"
#include "viewer.h"
#include "validationFile.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


int main() {
	MoviesDB::setupMoviesDB("movies.txt");
	MoviesDB::setupMoviesDB("moviesWatchList.txt");
	MoviesDB::compareMoviesDB();
	SeriesDB::setupSeriesDB("series.txt");
	SeriesDB::setupSeriesDB("seriesWatchList.txt");
	SeriesDB::compareSeriesDB();
	int answer = 0;
	string name, answerS, message;
	User currUser;
	Admin currAdmin;
	while (answer != 3) {
		answer = answerIntViewer(main_M, 1, 3);
		switch (answer) {
		case 1:
			if (validateUser(currUser)) {
				userMenu(currUser);
			}
			break;
		case 2:
			if (validateAdmin(currAdmin)) {
				adminMenu(currAdmin);
			}
			break;
		case 3:
			MoviesDB::updateFileMoviesDB("movies.txt");
			MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
			SeriesDB::updateFileSeriesDB("series.txt");
			SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
			break;
		}
	}
}

