#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "series.h"
#include "seriesDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


User::User(int id, string name, string surname, int day, int month, int year):Viewer(id, name, surname, day, month, year){
}


void User::chooseFromMovies() {
	int answer = 0;
	string name;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies; //buffer object

	if (!isEmpty(watchListMovies)) {
		notToAddTwice(movies);
	}

	for (int i = 0; i < movies.size(); i++) {
		cout << i + 1 << ": " << movies[i] << endl; //printing the vector in list-like form
		cout << "You wanna add this movie?" << endl;
		cout << "1.Yes\n2.No\n3.Exit" << endl;
		cin >> answer;
		switch (answer){
			case 1:
				watchListMovies.emplace_back(movies[i]);
				continue;
			case 2:
				continue;
			case 3:
				break;
		}
		break;
	}
}

void User::chooseFromMoviesByCategory() {
	int answer = 0;
	int counter = 1;
	string category;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies; //buffer object

	//sort(movies.begin(), movies.end(), greater<Movie>()); //sort vector by year and time

	if (!isEmpty(watchListMovies)) {
		notToAddTwice(movies);
	}

	cout << "In which category you want search movies?" << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].getCategory() == category) {
			cout << counter << ": " << movies[i] << endl;
			counter++;
			cout << "You want to add this movie to your watch list?" << endl;
			cout << "1.Yes\n2.No\n3.Exit" << endl;
			cin >> answer;
			switch (answer) {
			case 1:
				watchListMovies.emplace_back(movies[i]);
				continue;
			case 2:
				continue;
			case 3:
				break;
			}
			break;
		}
		//cout << "No more movies in this category" << endl;
	}
}

void User::chooseFromSeries() {
	int answer = 0;
	string name;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	Series currentSeries; //buffer object

	//sort(series.begin(), series.end(), greater<Series>()); //sort vector by year and time

	//delete from vector movies that already in watch list(if watch list not empty)
	if (!isEmpty(watchListSeries)) {
		notToAddTwice(series);
	}

	for (int i = 0; i < series.size(); i++) {
		cout << i + 1 << ": " << series[i] << endl; //printing the vector in list-like form
		cout << "You wanna add this series?" << endl;
		cout << "1.Yes\n2.No\n3.Exit" << endl;
		cin >> answer;
		switch (answer) {
		case 1:
			watchListSeries.emplace_back(series[i]);
			continue;
		case 2:
			continue;
		case 3:
			break;
		}
		break;
	}
}

void User::chooseFromSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	Series currentSeries; //buffer object

	//sort(series.begin(), series.end(), greater<Series>()); //sort vector by year and time

	//delete from vector movies that already in watch list(if watch list not empty)
	if (!isEmpty(watchListSeries)) {
		notToAddTwice(series);
	}

	cout << "In which category you want search series?" << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].getCategory() == category) {
			cout << counter << ": " << series[i] << endl;
			counter++;
			cout << "You want to add this series to your watch list?" << endl;
			cout << "1.Yes\n2.No\n3.Exit" << endl;
			cin >> answer;
			switch (answer) {
			case 1:
				watchListSeries.emplace_back(series[i]);
				continue;
			case 2:
				continue;
			case 3:
				break;
			}
			break;
		}
		//cout << "No more movies in this category" << endl;
	}
}

void User::findMovieByName() {
	string name;
	int answer;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	cout << "Please write which movie you want to find" << endl;
	cin.get();
	getline(cin, name);

	if (isEmpty(movies)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	if (!isEmpty(watchListMovies)) {
		notToAddTwice(movies);
	}

	int size = movies.size();

	for (int i = 0; i < movies.size(); i++) {//delete from vector
		if (movies[i].getName() == name) {
			cout << "You want to add this movie?" << endl;
			cout << movies[i] << endl;
			cout << "1.Yes\n2.No" << endl;
			cin >> answer;
			if (answer == 1) {
				watchListMovies.emplace_back(movies[i]);
				size++;
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == movies.size()) {
		cout << "Movie with this name is not exist, sorry" << endl;
		return;
	}
}

void User::findSeriesByName() {
	string name;
	int answer;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	cout << "Please write which series you want to find" << endl;
	cin.get();
	getline(cin, name);

	if (isEmpty(series)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	if (!isEmpty(watchListSeries)) {
		notToAddTwice(series);
	}

	int size = series.size();

	for (int i = 0; i < series.size(); i++) {//delete from vector
		if (series[i].getName() == name) {
			cout << "You want to add this series?" << endl;
			cout << series[i] << endl;
			cout << "1.Yes\n2.No" << endl;
			cin >> answer;
			if (answer == 1) {
				watchListSeries.emplace_back(series[i]);
				size++;
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == series.size()) {
		cout << "Series with this name is not exist, sorry" << endl;
		return;
	}
}

void User::watchMovieFromList() {
	int answer;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << "You now watching" << endl;
		cout << watchListMovies[i] << endl;
		cout << "1.Watch next\n2.Exit" << endl;
		cin >> answer;
		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	cout << "No more movies in your watch list" << endl;
}

void User::watchSeriesFromList() {
	int answer;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << "You now watching" << endl;
		cout << watchListSeries[i] << endl;
		cout << "1.Watch next\n2.Exit" << endl;
		cin >> answer;
		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	cout << "No more series in your watch list" << endl;
}

void User::deleteMovieFromList() {
	int answer;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmpty(watchListMovies)) {
		cout << "No movies in watch list, fail" << endl;
		return;
	}

	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << i + 1 << ": " << watchListMovies[i] << endl;
	}
	cout << "Which movie you want delete?" << endl;
	cin >> answer;

	for (vector<Movie>::iterator i = watchListMovies.begin(); i != watchListMovies.end(); ++i) {//delete from vector
		advance(i,answer-1);
		watchListMovies.erase(i);
		break;
	}
	cout << "Chosen movie deleted sucsesfully" << endl;
}

void User::deleteSeriesFromList(){
	int answer;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmpty(watchListSeries)) {
		cout << "No series in watch list, fail" << endl;
		return;
	}

	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << i + 1 << ": " << watchListSeries[i] << endl;
	}
	cout << "Which movie you want delete?" << endl;
	cin >> answer;

	for (vector<Series>::iterator i = watchListSeries.begin(); i != watchListSeries.end(); ++i) {//delete from vector
		advance(i, answer - 1);
		watchListSeries.erase(i);
		break;
	}
	cout << "Chosen series deleted sucsesfully" << endl;
}

void User::notToAddTwice(vector<Movie> movies) {
	for (vector<Movie>::iterator j = watchListMovies.begin(); j != watchListMovies.end(); ++j) {//REPAIR
		for (vector<Movie>::iterator k = movies.begin(); k != movies.end(); ++k) {
			if (j->getName() == k->getName()) {
				movies.erase(k);
				break;
			}
		}
	}//delete from vector movies that already in watch list(if watch list not empty)
}

void User::notToAddTwice(vector<Series> series) {
	for (vector<Series>::iterator j = watchListSeries.begin(); j != watchListSeries.end(); ++j) {
		for (vector<Series>::iterator k = series.begin(); k != series.end(); ++k) {
			if (j->getName() == k->getName()) {
				series.erase(k);
				break;
			}
		}
	}//delete from vector series that already in watch list(if watch list not empty)
}

void User::getPersonalInfo(){
	string lname, fname, byear, bmonth, bday, id;
	string path = "user.txt";
	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "file not found" << endl; }
	else {
		getline(fin, fname);
		this->fname = fname;
		getline(fin, lname);
		this->lname = lname;
		getline(fin, id);
		this->id = stoi(id);
		getline(fin, bday);
		this->bday = stoi(bday);
		getline(fin, bmonth);
		this->bmonth = stoi(bmonth);
		getline(fin, byear);
		this->byear = stoi(byear);
	}
	fin.close();
}
