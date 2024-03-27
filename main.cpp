#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"
#include "viewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	string name;
	User currUser;
	Admin currAdmin;
	while (answer != 3) {
		cout << "1.User\n2.Admin\n3.Exit" << endl;
		cin >> answer;
		if (answer < 1 || answer > 3) {
			cout << "Wrong answer, try again" << endl;
			continue;
		}
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
	string fname, lname;
	int id, answer = 0;
	currUser.getPersonalInfo();
	while (true) {
		cout << "Enter name for validate" << endl;
		cin >> fname >> lname;
		cout << "Enter password for validate" << endl;
		cin >> id;
		if (fname == currUser.getFname() && id == currUser.getId())break;
		else {
			cout << "Wrong data, please select:\n1.Try again\n2.Return to menu" << endl;
			cin >> answer;
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}

int validateAdmin(Admin currAdmin) {
	string fname, lname;
	int id, answer = 0;
	currAdmin.getPersonalInfo();
	while (true) {
		cout << "Enter name for validate" << endl;
		cin >> fname >> lname;
		cout << "Enter password for validate" << endl;
		cin >> id;
		if (fname == currAdmin.getFname() && id == currAdmin.getId())break;
		else {
			cout << "Wrong data, please select:\n1.Try again\n2.Return to menu" << endl;
			cin >> answer;
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}


void userMenu(User user) {
	int answer;
	int logOut = 0;
	while (!logOut) {
		cout << "1.Add new movie to watch list\n2.Add new series to watch list\n3.Search for movie/series\n4.Watch movie from watch list" << endl;
		cout << "5.Watch series from watch list\n6.Delete movie from watch list\n7.Delete series from watch list\n8.Exit to main menu" << endl;
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "You want to search by newest movies or by category" << endl;
			cout << "1.Newest movies\n2.By category" << endl;
			cin >> answer;
			if (answer == 1) {
				user.chooseFromMovies();
			}
			else {
				user.chooseFromMoviesByCategory();
			}
			break;
		case 2:
			cout << "You want to search by newest series or by category" << endl;
			cout << "1.Newest series\n2.By category" << endl;
			cin >> answer;
			if (answer == 1) {
				user.chooseFromSeries();
			}
			else {
				user.chooseFromSeriesByCategory();
			}
			break;
		case 3:
			cout << "You want to search movie or series" << endl;
			cout << "1.Movie\n2.Series" << endl;
			cin >> answer;
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
	string name;
	int logOut = 0;
	while (!logOut) {
		cout << "1.Add new movie\n2.Add new series" << endl;
		cout << "3.Delete movie\n4.Delete series\n5.Exit to main menu" << endl;
		cin >> answer;
		switch (answer) {
		case 1:
			admin.addMovie();
			break;
		case 2:
			admin.addSeries();
			break;
		case 3:
			cout << "1.Find by name\n2.Find by category" << endl;
			cin >> answer;
			if (answer == 1) {
				admin.findMovieByName();
			}
			else {
				admin.findMovieByCategory();
			}
			break;
		case 4:
			cout << "1.Find by name\n2.Find by category" << endl;
			cin >> answer;
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