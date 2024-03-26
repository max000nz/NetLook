#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "series.h"
#include "admin.h"
#include "viewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


User createUser();
Admin createAdmin();
void userMenu(User user);
void adminMenu(Admin admin);

int main() {
	int answer = 0;
	string name;
	vector<Show> watchList;
	//User user = createUser();
	//Admin admin = createAdmin();
	User user = { 337875397, "Max", "Prokopchuk", 14, 02, 2000};
	Admin admin = { 333333333, "Liad", "Mandil", 25, 05, 2001 };
	while (answer != 3) {
		cout << "1.User\n2.Admin\n3.Exit" << endl;
		cin >> answer;
		if (answer < 1 || answer > 3) {
			cout << "Wrong answer, try again" << endl;
			continue;
		}
		switch (answer) {
		case 1:
			userMenu(user);
			break;
		case 2:
			adminMenu(admin);
			break;
		case 3:
			break;
		}
	}
}

User createUser() {
	int id, day, month, year;
	string name, surname;
	cout << "Creating new user" << endl;
	cout << "Give me your id" << endl;
	cin >> id;
	cout << "Give me your full name" << endl;
	cin >> name;
	cin >> surname;
	cout << "What your bday(day/month/year)" << endl;
	cin >> day >> month >> year;
	User u1 = { id, name, surname, day, month, year};
	return u1;
}

Admin createAdmin() {
	int id, day, month, year;
	string name, surname;
	cout << "Creating new admin" << endl;
	cout << "Give me your id" << endl;
	cin >> id;
	cout << "Give me your full name" << endl;
	cin >> name;
	cin >> surname;
	cout << "What your bday(day/month/year)" << endl;
	cin >> day >> month >> year;
	Admin a1 = { id, name, surname, day, month, year };
	return a1;
}


void userMenu(User user) {
	int answer;
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
		break;
	}
}

void adminMenu(Admin admin) {
	int answer;
	string name;
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
		}else{
			admin.findMovieByCategory();
		}
		break;
	case 4:
		cout << "1.Find by name\n2.Find by category" << endl;
		cin >> answer;
		if (answer == 1) {

			admin.findSeriesByName();
		}else{
			admin.findSeriesByCategory();
		}
		break;
	case 5:
		break;
	}
}