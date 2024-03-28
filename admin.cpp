#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
#include "validationFile.h"
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
	string name, message, category;
	int year, length, answer;
	ofstream fout;
	cout << "Which movie you want to add?" << endl;
	message = "Name?\n";
	name = answerStringViewer(message, 0, 2, 30);
	cout << "Category?" << endl;
	category = chooseCategory();
	message = "Year of release?\n";
	year = answerIntViewer(message, 1950, 2024);
	message = "Length?\n";
	length = answerIntViewer(message, 30, 300);
	currentMovie.setName(name);
	currentMovie.setCategory(category);
	currentMovie.setYear(year);
	currentMovie.setMovieLength(length);
	currentMovie.setTime(currTime);
	cout << currentMovie << endl;
	message = "\nAdd this movie?\n1.Yes\n2.No\n";
	answer = answerIntViewer(message, 1, 2);
	if (answer == 1) {
		MoviesDB::addMovieToDB(currentMovie);
	}else return;
}

void Admin::addSeries() {
	time_t currTime = time(nullptr);
	Series currentSeries;
	string path = "series.txt";
	string name, category, message;
	int year, seasons, episodes, answer;
	ofstream fout;

	cout << "Which series you want to add?" << endl;
	message = "Name?\n";
	name = answerStringViewer(message, 0, 2, 30);
	cout << "Category?" << endl;
	category = chooseCategory();
	message = "Year of release?\n";
	year = answerIntViewer(message, 1950, 2024);
	message = "How much seasons in series?\n";
	seasons = answerIntViewer(message, 1, 30);
	message = "How much episodes in every season?\n";
	episodes = answerIntViewer(message, 1, 30);
	currentSeries.setName(name);
	currentSeries.setCategory(category);
	currentSeries.setYear(year);
	currentSeries.setSeasons(seasons);
	currentSeries.setEpisodes(episodes);
	currentSeries.setTime(currTime);
	cout << currentSeries << endl;
	message = "\nAdd this series?\n1.Yes\n2.No\n";
	answer = answerIntViewer(message, 1, 2);
	if (answer == 1) {
		SeriesDB::addSeriesToDB(currentSeries);
	}
	else return;
}

void Admin::findMovieByName() {
	int answer = 0;
	string name, message;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(movies)) {
		cout << "No movies in data base\n" << endl;
		return;
	}

	message = "Write name of movie you want delete\n";
	name = answerStringViewer(message, 0, 2, 25);

	int size = movies.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector of data base
		if (i->getName() == name) {
			if (i->getIsWL() == "Y") {
				MoviesDB::deleteFromMoviesWatchList(watchListMovies, name);
			}
			movies.erase(i);
			break;
		}
	}
	if (size == movies.size()) {
		cout << "Movie with this name is not exist in data base" << endl;
		return;
	}

	cout << "Movie deleted succesfully" << endl;
}


void Admin::findMovieByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name, message;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(movies)) {
		cout << "No movies in data base\n" << endl;
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
	cout << counter << ": \n   ------Exit------\n" << endl;
	message = "Which movie you want delete\n";
	answer = answerIntViewer(message, 1, counter+1);
	if (answer == counter) {
		return;
	}

	counter=0;

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector
		if (i->getCategory() != category) continue;
		counter++;
		if (counter != answer) continue;
		name = i->getName();
		if (i->getIsWL() == "Y") {
			MoviesDB::deleteFromMoviesWatchList(watchListMovies, name);
		}
		movies.erase(i);
		break;
	}

	cout << "Movie deleted succesfully" << endl;
}

void Admin::findSeriesByName(){
	int answer = 0;
	string name, message;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(series)) {
		cout << "No series in data base" << endl;
		return;
	}

	message = "Write name of series you want delete\n";
	name = answerStringViewer(message, 0, 2, 25);

	int size = series.size();

	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {//delete from vector of data base
		if (i->getName() == name) {
			if (i->getIsWL() == "Y") {
				SeriesDB::deleteFromSeriesWatchList(watchListSeries, name);
			}
		series.erase(i);
		break;
		}
	}

	if (size == series.size()) {
		cout << "Series with this name is not exist in data base" << endl;
		return;
	}

	cout << "Series deleted succesfully" << endl;
}

void Admin::findSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name, message;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(series)) {
		cout << "No series in data base" << endl;
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

	cout << counter << ": \n   ------Exit------\n" << endl;
	message = "Which series you want delete\n";
	answer = answerIntViewer(message, 1, counter);
	if (answer == counter) {
		return;
	}

	counter = 0;

	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {//delete from vector
		if (i->getCategory() != category) continue;
		counter++;
		if (counter != answer) continue;
		name = i->getName();
		if (i->getIsWL() == "Y") {
			SeriesDB::deleteFromSeriesWatchList(watchListSeries, name);
		}
		series.erase(i);
		break;
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

