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
		MoviesDB::updateFileMoviesDB("movies.txt");
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
		cout << "No movies in data base\n" << endl;
		return;
	}

	message = "Write name of movie you want delete\n";
	name = answerStringViewer(message, 0, 2, 25);
	lowName = name;
	transform(lowName.begin(), lowName.end(), lowName.begin(), ::tolower);
	int size = movies.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector of data base
		lowCurrName = i->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == lowName) {
			cout << movies[counter];
			message = "\n\n This is the movie?\n 1: yes\n 2: no";
			if (answerIntViewer(message, 1, 2) == 1){
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
		counter = 0;
	}
	if (size != movies.size()) {
		cout << "Movie deleted succesfully\n\n" << endl;
		return;
	}
	else {
		cout << "Movie with this name is not exist in data base\n\n" << endl;
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
			MoviesDB::deleteFromMoviesWatchList(name);
			MoviesDB::updateFileMoviesDB("moviesWatchlist.txt");
		}
		movies.erase(i);
		MoviesDB::updateFileMoviesDB("movies.txt");
		break;
	}

	cout << "Movie deleted succesfully" << endl;
}

void Admin::findSeriesByName(){
	int answer = 0, counter = 0;
	string name, message, lowCurrName;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(series)) {
		cout << "No series in data base" << endl;
		return;
	}

	message = "Write name of series you want delete\n";
	name = answerStringViewer(message, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	int size = series.size();
	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {
		lowCurrName = i->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == name) {
			cout << series[counter];
			message = "\n\n This is the series?\n 1: yes\n 2: no";
			if (answerIntViewer(message, 1, 2) == 1) {
				if (i->getIsWL() == "Y") {
					SeriesDB::deleteFromSeriesWatchList(watchListSeries, name);
					SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				}
				series.erase(i);
				SeriesDB::updateFileSeriesDB("series.txt");
				break;
			}
			else return;
		}
	}

	if (size != series.size()) {
		cout << "Series deleted succesfully" << endl;
		return;
	}
	else {
		cout << "Series with this name is not exist in data base" << endl;
	}
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
			SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
		}
		series.erase(i);
		SeriesDB::updateFileSeriesDB("series.txt");
		break;
	}
	cout << "Series deleted succesfully" << endl;
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

