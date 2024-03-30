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
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


void userMenu(User user) {
	int answer;
	string message;
	int logOut = 0;
	while (!logOut) {
		message = "1.Add new movie to watch list\n"
			"2.Add new series to watch list\n"
			"3.Search for movie/series\n"
			"4.Watch movie from watch list\n"
			"5.Watch series from watch list\n"
			"6.Delete movie from watch list\n"
			"7.Delete series from watch list\n"
			"8.Exit to main menu\n";
		answer = answerIntViewer(message, 1, 8);
		switch (answer) {
		case 1:
			message = "You want to search by newest movies or by category\n"
				"1.Newest movies\n2.By category\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) {
				user.chooseFromMovies();
			}
			else {
				user.chooseFromMoviesByCategory();
			}
			break;
		case 2:
			message = "You want to search by newest series or by category\n"
				"1.Newest series\n2.By category\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) {
				user.chooseFromSeries();
			}
			else {
				user.chooseFromSeriesByCategory();
			}
			break;
		case 3:
			message = "You want to search movie or series\n"
				"1.Movie\n2.Series\n";
			answer = answerIntViewer(message, 1, 2);
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

void adminMenu(Admin admin) {
	int answer;
	string name, message;
	int logOut = 0;
	while (!logOut) {
		message = "1.Add new movie\n"
			"2.Add new series\n"
			"3.Delete movie\n"
			"4.Delete series\n"
			"5.Exit to main menu\n";
		answer = answerIntViewer(message, 1, 5);
		switch (answer) {
		case 1:
			admin.addMovie();
			break;
		case 2:
			admin.addSeries();
			break;
		case 3:
			message = "1.Find by name\n"
				"2.Find by category\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) {
				admin.findMovieByName();
			}
			else {
				admin.findMovieByCategory();
			}
			break;
		case 4:
			message = "1.Find by name\n"
				"2.Find by category\n";
			answer = answerIntViewer(message, 1, 2);
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
