#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
#include "validationFile.h"
#include "outputs.h"
#include "moviesDB.h"
#include "strings.h"
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
	string name, category;
	int year, length, answer;
	ofstream fout;
	cout << adminQuestion << endl;
	name = answerStringViewer(adminAddShowName, 0, 2, 30);
	cout << adminAddShowCategory;
	category = chooseCategory();
	year = answerIntViewer(adminAddShowYear, 1950, 2024);
	length = answerIntViewer(adminAddMovieLength, 30, 300);
	currentMovie.setName(name);
	currentMovie.setCategory(category);
	currentMovie.setYear(year);
	currentMovie.setMovieLength(length);
	currentMovie.setTime(currTime);
	cout << currentMovie << endl;
	answer = answerIntViewer(AddMovieWE, 1, 2);
	if (answer == 1) {
		MoviesDB::addMovieToDB(currentMovie);
		MoviesDB::updateFileMoviesDB("movies.txt");
	}else return;
}

void Admin::addSeries() {
	time_t currTime = time(nullptr);
	Series currentSeries;
	string path = "series.txt";
	string name, category;
	int year, seasons, episodes, answer;
	ofstream fout;

	cout << adminQuestion << endl;
	name = answerStringViewer(adminAddShowName, 0, 2, 30);
	cout << adminAddShowCategory;
	category = chooseCategory();
	year = answerIntViewer(adminAddShowYear, 1950, 2024);
	seasons = answerIntViewer(adminAddSeriesSeasons, 1, 30);
	episodes = answerIntViewer(adminAddSeriesEpisodes, 1, 30);
	currentSeries.setName(name);
	currentSeries.setCategory(category);
	currentSeries.setYear(year);
	currentSeries.setSeasons(seasons);
	currentSeries.setEpisodes(episodes);
	currentSeries.setTime(currTime);
	cout << currentSeries << endl;
	answer = answerIntViewer(AddSeriesWE, 1, 2);
	if (answer == 1) {
		SeriesDB::addSeriesToDB(currentSeries);
		SeriesDB::updateFileSeriesDB("series.txt");
		
	}
	else return;
}

void Admin::findMovieByName() {
	int answer = 0, counter = 0;
	string name, message, lowName, lowCurrName;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(movies)) {
		noMore("movies");
		return;
	}

	name = answerStringViewer(DeleteFromWLorDB, 0, 2, 25);
	lowName = name;
	transform(lowName.begin(), lowName.end(), lowName.begin(), ::tolower);
	int size = movies.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {
		lowCurrName = i->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == lowName) {
			cout << movies[counter];
			if (answerIntViewer(deleteMovieWE, 1, 2) == 1){
				if (i->getIsWL() == "Y") {
					MoviesDB::deleteFromMoviesWatchList(lowName);
					MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				}
				movies.erase(i);
				MoviesDB::updateFileMoviesDB("movies.txt");
				break;
			}
			else return;

			
		}
		counter++;
	}
	if (size != movies.size()) {
		deletedSuccessfully("Movie");
		return;
	}
	else {
		cout << noMovieDB << endl;
		return;
	}
}

void Admin::findMovieByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name, message;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(movies)) {
		noMore("movies");
		return;
	}

	cout << categoryChoice << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].getCategory() == category) {
			cout << counter << ": " << movies[i] << endl;
			counter++;
		}
	}
	
	if (counter == 1) {
		cout << emptyCategoryMovie << endl;
		return;
	}
	cout << counter << ": \n   ------Exit------\n" << endl;
	answer = answerIntViewer(deleteMovieChoice, 1, counter+1);
	if (answer == counter) {
		return;
	}

	counter=0;

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {
		if (i->getCategory() != category) continue;
		counter++;
		if (counter != answer) continue;
		name = i->getName();
		if (i->getIsWL() == "Y") {
			MoviesDB::deleteFromMoviesWatchList(name);
			MoviesDB::updateFileMoviesDB("moviesWatchlist.txt");
		}
		movies.erase(i);
		MoviesDB::updateFileMoviesDB("movies.txt");
		break;
	}

	deletedSuccessfully("Movie");
}

void Admin::findSeriesByName(){
	int answer = 0, counter = 0;
	string name, message, lowCurrName;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(series)) {
		noMore("series");
		return;
	}

	name = answerStringViewer(DeleteFromWLorDB, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	int size = series.size();
	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {
		lowCurrName = i->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == name) {
			cout << series[counter];
			if (answerIntViewer(deleteSeriesWE, 1, 2) == 1) {
				if (i->getIsWL() == "Y") {
					SeriesDB::deleteFromSeriesWatchList(name);
					SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				}
				series.erase(i);
				SeriesDB::updateFileSeriesDB("series.txt");
				break;
			}
			else return;
		}
		counter++;
	}

	if (size != series.size()) {
		deletedSuccessfully("Series");
		return;
	}
	else {
		cout << noSeriesDB;
	}
}

void Admin::findSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name, message;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(series)) {
		cout << emptySeriesDB;
		return;
	}

	cout << categoryChoice << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].getCategory() == category) {
			cout << counter << ": " << series[i] << endl;
			counter++;
		}
	}

	if (counter == 1) {
		cout << emptyCategorySeries << endl;
		return;
	}

	cout << counter << ": \n   ------Exit------\n" << endl;
	answer = answerIntViewer(deleteSeriesChoice, 1, counter);
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
			SeriesDB::deleteFromSeriesWatchList(name);
			SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
		}
		series.erase(i);
		SeriesDB::updateFileSeriesDB("series.txt");
		break;
	}
	deletedSuccessfully("Series");
}

void Admin::getPersonalInfo()  throw (invalid_argument)
{
	string lname, fname, byear, bmonth, bday, id;
	string path = "admin.txt";
	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "File not found" << endl; }
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