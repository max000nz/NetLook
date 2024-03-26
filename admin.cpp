#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

Admin::Admin(int id, string fname, string lname, int day, int month, int year) :Viewer(id, fname, lname, day, month, year) {}

void Admin::addMovie() {
	Movie currentMovie;
	time_t currTime = time(nullptr);
	string path = "movies.txt";
	string name;
	string category;
	int year, length;
	ofstream fout;
	cout << "Which movie you want to add?" << endl;
	cout << "Name?" << endl;
	cin.get();
	getline(cin, name);
	cout << "Category?" << endl;
	category = chooseCategory();
	cout << "Year of release?" << endl;
	cin >> year;
	cout << "Length?" << endl;
	cin >> length;
	currentMovie.setName(name);
	currentMovie.setCategory(category);
	currentMovie.setYear(year);
	currentMovie.setMovieLength(length);
	currentMovie.setTime(currTime);
	MoviesDB::addMovieToDB(currentMovie);
}

void Admin::addSeries() {
	time_t currTime = time(nullptr);
	Series currentSeries;
	string path = "series.txt";
	string name;
	string category;
	int year, seasons, episodes;
	ofstream fout;

	cout << "Which series you want to add?" << endl;
	cout << "Name?" << endl;
	cin.get();
	getline(cin, name);
	cout << "Category?" << endl;
	category = chooseCategory();
	cout << "Year of release?" << endl;
	cin >> year;
	cout << "How much seasons in series?" << endl;
	cin >> seasons;
	cout << "How much episodes in every season?" << endl;
	cin >> episodes;
	currentSeries.setName(name);
	currentSeries.setCategory(category);
	currentSeries.setYear(year);
	currentSeries.setSeasons(seasons);
	currentSeries.setEpisodes(episodes);
	currentSeries.setTime(currTime);
	SeriesDB::addSeriesToDB(currentSeries);
}

void Admin::findMovieByName() {
	int answer = 0;
	string name;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmpty(movies)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	cout << "Write name of movie you want delete" << endl;
	cin.get();
	getline(cin, name);

	int size = movies.size();
	int sizeWatch = watchListMovies.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector of data base
		if (i->getName() == name) {
			movies.erase(i);
			break;
		}
	}

	for (vector<Movie>::iterator j = watchListMovies.begin(); j != watchListMovies.end(); ++j) {//delete from vector watch list of user
		if (j->getName() == name) {
			watchListMovies.erase(j);
			break;
		} 
	}

	if (size == movies.size()) {
		cout << "Movie with this name is not exist in data base" << endl;
		return;
	}

	if (sizeWatch == watchListMovies.size()) {
		cout << "Movie with this name is not exist in watch list" << endl;
		return;
	}
}

void Admin::findMovieByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmpty(movies)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	cout << "Write category of movie you want delete" << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].getCategory() == category) {
			cout << counter << ": " << movies[i] << endl;
			counter++;
		}
	}

	if (counter == 1) {
		cout << "No movies in this category, fail" << endl;
		return;
	}

	cout << "Which movie you want delete" << endl;
	cin >> answer;
	
	counter=0;

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector
		if (i->getCategory() == category) {
			counter++;
			if (counter == answer) {
				name = i->getName();
				movies.erase(i);
				break;
			}
		}
	}

	for (vector<Movie>::iterator j = watchListMovies.begin(); j != watchListMovies.end(); ++j) {//delete from vector watch list of user
		if (j->getName() == name) {
			watchListMovies.erase(j);
			break;
		}
	}


	cout << "Movie deleted succesfully" << endl;
}

void Admin::findSeriesByName(){
	int answer = 0;
	string name;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmpty(series)) {
		cout << "No series in data base, fail" << endl;
		return;
	}

	cout << "Write name of series you want delete" << endl;
	cin.get();
	getline(cin, name);

	int size = series.size();
	int sizeSeries = watchListSeries.size();

	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {//delete from vector
		if (i->getName() == name) {
			series.erase(i);
			break;
		}
	}

	for (vector<Series>::iterator j = watchListSeries.begin(); j != watchListSeries.end(); ++j) {//delete from vector
		if (j->getName() == name) {
			watchListSeries.erase(j);
			break;
		}
	}

	if (size == series.size()) {
		cout << "Series with this name is not exist in data base" << endl;
		return;
	}

	if (size == watchListSeries.size()) {
		cout << "Series with this name is not exist in watch list" << endl;
		return;
	}

}

void Admin::findSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	

	if (isEmpty(series)) {
		cout << "No series in data base, fail" << endl;
		return;
	}

	cout << "Write category of series you want delete" << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].getCategory() == category) {
			cout << counter << ": " << series[i] << endl;
			counter++;
		}
	}

	if (counter == 1) {
		cout << "No series in this category, fail" << endl;
		return;
	}

	cout << "Which series you want delete" << endl;
	cin >> answer;

	counter = 0;

	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {//delete from vector
		if (i->getCategory() == category) {
			counter++;
			if (counter == answer) {
				name = i->getName();
				series.erase(i);
				break;
			}
		}
	}

	for (vector<Series>::iterator j = watchListSeries.begin(); j != watchListSeries.end(); ++j) {//delete from vector
		if (j->getName() == name) {
			watchListSeries.erase(j);
			break;
		}
	}

	cout << "Series deleted succesfully" << endl;
}

void Admin::getPersonalInfo()
{
	string lname, fname, byear, bmonth, bday, id;
	string path = "admin.txt";
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