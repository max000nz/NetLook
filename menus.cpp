#pragma comment(lib, "Winscard")
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
#include "strings.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

/// <summary>
/// user menu with all functions
/// </summary>
void userMenu(User user) {
	int answer;
	int logOut = 0;
	while (!logOut) {
		answer = answerIntViewer(main_user_M, 1, 8);
		switch (answer) {
		case 1:
			answer = answerIntViewer(addMovieToWL, 1, 2);
			if (answer == 1) {
				user.chooseFromMovies();
			}
			else {
				user.chooseFromMoviesByCategory();
			}
			break;
		case 2:
			answer = answerIntViewer(addSeriesToWL, 1, 2);
			if (answer == 1) {
				user.chooseFromSeries();
			}
			else {
				user.chooseFromSeriesByCategory();
			}
			break;
		case 3:
			answer = answerIntViewer(userFindByName, 1, 2);
			if (answer == 1) {
				user.findMovieByName();
			}
			else {
				user.findSeriesByName();
			}
			break;
		case 4:
			user.watchMovieFromList();
			break;
		case 5:
			user.watchSeriesFromList();
			break;
		case 6:
			user.deleteMovieFromList();
			break;
		case 7:
			user.deleteSeriesFromList();
			break;
		case 8:
			logOut = 1;
			break;
		}
	}
}

/// <summary>
/// admin menu with all functions
/// </summary>
void adminMenu(Admin admin) {
	int answer;
	string name, message;
	int logOut = 0;
	while (!logOut) {
		answer = answerIntViewer(main_admin_M, 1, 5);
		switch (answer) {
		case 1:
			admin.addMovie();
			break;
		case 2:
			admin.addSeries();
			break;
		case 3:
			answer = answerIntViewer(adminNameOrCategory, 1, 2);
			if (answer == 1) {
				admin.findMovieByName();
			}
			else {
				admin.findMovieByCategory();
			}
			break;
		case 4:
			answer = answerIntViewer(adminNameOrCategory, 1, 2);
			if (answer == 1) {

				admin.findSeriesByName();
			}
			else {
				admin.findSeriesByCategory();
			}
			break;
		case 5:
			logOut = 1;
			break;
		}
	}
}
