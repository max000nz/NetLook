#define _CRT_SECURE_NO_WARNINGS
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


void userMenu(User user);
void adminMenu(Admin admin);
int validateUser(User currUser);
int validateAdmin(Admin currAdmin);

int main() {
	MoviesDB::setupMoviesDB("movies.txt");
	MoviesDB::setupMoviesDB("moviesWatchList.txt");
	SeriesDB::setupSeriesDB("series.txt");
	SeriesDB::setupSeriesDB("seriesWatchList.txt");
	int answer = 0;
	string name, answerS, message;
	User currUser;
	Admin currAdmin;
	while (answer != 3) {
		message = "1.User\n2.Admin\n3.Exit\n";
		answer = answerIntViewer(message, 1, 3);
		switch (answer) {
		case 1:
			//if (validateUser(currUser)) {
				userMenu(currUser);
			//}
			break;
		case 2:
			//if (validateAdmin(currAdmin)) {
				adminMenu(currAdmin);
			//}
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

int validateUser(User currUser) {
	string fname, lname, message;
	int id, answer = 0;
	currUser.getPersonalInfo();
	while (true) {
		message = "Enter name for validate\n";
		fname = answerStringViewer(message, 1, 2, 15);
		message = "Enter surname for validate\n";
		lname = answerStringViewer(message, 1, 2, 15);
		message = "Enter password for validate\n";
		id = answerIntViewer(message, 100000000, 999999999);
		if (fname == currUser.getFname() && id == currUser.getId())break;
		else {
			message = "Wrong data, please select:\n"
					  "1.Try again\n"
					  "2.Return to menu\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}

int validateAdmin(Admin currAdmin) {
	string fname, lname, message;
	int id, answer = 0;
	currAdmin.getPersonalInfo();
	while (true) {
		message = "Enter name for validate\n";
		fname = answerStringViewer(message, 1, 2, 15);
		message = "Enter surname for validate\n";
		lname = answerStringViewer(message, 1, 2, 15);
		message = "Enter password for validate\n";
		id = answerIntViewer(message, 100000000, 999999999);
		if (fname == currAdmin.getFname() && id == currAdmin.getId())break;
		else {
			message = "Wrong data, please select:\n"
					  "1.Try again\n"
				      "2.Return to menu\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}


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