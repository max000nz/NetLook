#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "series.h"
#include "validationFile.h"
#include "strings.h"
#include "outputs.h"
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
	int counter = 1;
	string name;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies;

	if (isEmptyVecM(movies)) {
		cout << emptyMoviesDB << endl;
		return;
	}

	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getIsWL() == "Y") continue;
		cout << counter << ": " << movies[i] << endl;
		counter++;
		answer = answerIntViewer(userAddMovie, 1, 3);
		switch (answer){
			case 1:
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				MoviesDB::updateFileMoviesDB("movies.txt");
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				addedSuccessfully("Movie");
				continue;
			case 2:
				continue;
			case 3:
				return;
		}
		break;
	}
	noMore("movie");
}

void User::chooseFromMoviesByCategory() {
	int answer = 0;
	int counter = 1;
	string category;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies;

	if (isEmptyVecM(movies)) {
		cout << emptyMoviesDB << endl;
		return;
	}

	cout << categoryChoice << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].getIsWL() == "Y") continue;
		if (movies[i].getCategory() == category) {
			cout << counter << ": " << movies[i] << endl;
			counter++;
			answer = answerIntViewer(userAddMovie, 1, 3);
			switch (answer) {
			case 1:
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				MoviesDB::updateFileMoviesDB("movies.txt");
				addedSuccessfully("Movie");
				continue;
			case 2:
				continue;
			case 3:
				return;
			}
		}
	
	}
	if (answer != 3) {
		noMore("movies");
	}
}

void User::chooseFromSeries() {
	int answer = 0;
	int counter = 1;
	string name;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	Series currentSeries;

	if (isEmptyVecS(series)) {
		cout << emptySeriesDB << endl;
		return;
	}

	for (int i = 0; i < series.size(); i++) {
		if (series[i].getIsWL() == "Y") continue;
		cout << counter << ": " << series[i] << endl;
		counter++;
		answer = answerIntViewer(userAddSeries, 1, 3);
		switch (answer) {
		case 1:
			series[i].setAddWL();
			watchListSeries.emplace_back(series[i]);
			SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
			SeriesDB::updateFileSeriesDB("series.txt");
			addedSuccessfully("Series");
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
	Series currentSeries;

	if (isEmptyVecS(series)) {
		cout << emptySeriesDB << endl;
		return;
	}

	cout << categoryChoice << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].getIsWL() == "Y") continue;
		if (series[i].getCategory() == category) {
			cout << counter << ": " << series[i] << endl;
			counter++;
			answer = answerIntViewer(userAddSeries, 1, 3);
			switch (answer) {
			case 1:
				series[i].setAddWL();
				watchListSeries.emplace_back(series[i]);
				SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				SeriesDB::updateFileSeriesDB("series.txt");
				addedSuccessfully("Series");
				continue;
			case 2:
				continue;
			case 3:
				return;
			}
		}
	}
	if (answer != 3) {
		noMore("series");
	}
}

void User::findMovieByName() {
	string name, currName;
	int answer;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	name = answerStringViewer(whatShowName, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });
	if (isEmptyVecM(movies)) {
		cout << emptyMoviesDB << endl;
		return;
	}
	int size = movies.size();

	for (int i = 0; i < movies.size(); i++) {
		currName = movies[i].getName();
		transform(currName.begin(), currName.end(), currName.begin(), [](unsigned char c) { return std::tolower(c); });
		if (currName == name) {
			if (movies[i].getIsWL() == "Y") {
				alreadyInWL("Movie");
				return;
			}
			cout << movies[i] << endl;
			answer = answerIntViewer(AddMovieWE, 1, 2);
			if (answer == 1) {
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				size++;
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				MoviesDB::updateFileMoviesDB("movies.txt");
				addedSuccessfully("Movie");
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == movies.size()) {
		cout << nameNotExist << endl;
		return;
	}
}

void User::findSeriesByName() {
	string name, currName;
	int answer;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	name = answerStringViewer(whatShowName, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });

	if (isEmptyVecS(series)) {
		cout << emptySeriesDB << endl;
		return;
	}
	int size = series.size();

	for (int i = 0; i < series.size(); i++) {
		currName = series[i].getName();
		transform(currName.begin(), currName.end(), currName.begin(), [](unsigned char c) { return std::tolower(c); });
		if (currName == name) {
			if (series[i].getIsWL() == "Y") {
				alreadyInWL("Series");
				return;
			}
			cout << series[i] << endl;
			answer = answerIntViewer(AddSeriesWE, 1, 2);
			if (answer == 1) {
				series[i].setAddWL();
				watchListSeries.emplace_back(series[i]);
				size++;
				SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				SeriesDB::updateFileSeriesDB("series.txt");
				addedSuccessfully("Series");
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == series.size()) {
		cout << nameNotExist << endl;
		return;
	}
}

void User::watchMovieFromList() {
	int answer;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVecM(watchListMovies)) {
		cout << emptyMoviesWL << endl;
		return;
	}

	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << userWatching << endl;
		cout << "   " << watchListMovies[i] << endl;
		answer = answerIntViewer(userWatchNext, 1, 2);

		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	noMore("movies");
}

void User::watchSeriesFromList() {
	int answer;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVecS(watchListSeries)) {
		cout << emptySeriesWL << endl;
		return;
	}

	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << userWatching << endl;
		cout << "   " << watchListSeries[i] << endl;
		answer = answerIntViewer(userWatchNext, 1, 2);
		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	noMore("series");
}

void User::deleteMovieFromList() {
	int answer;
	string name;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVecM(watchListMovies)) {
		cout << emptyMoviesWL << endl;
		return;
	}

	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << i + 1 << ": " << watchListMovies[i] << endl;
	}
	
	cout << watchListMovies.size()+1 << ": \n   ------Exit------" << endl;
	answer = answerIntViewer(DeleteFromWLorDB, 1, watchListMovies.size()+1);
	if (answer == watchListMovies.size() + 1) {
		return;
	}

	for (vector<Movie>::iterator i = watchListMovies.begin(); i != watchListMovies.end(); ++i) {
		advance(i,answer-1);
		name = i->getName();
		i->setDeleteWL(name);
		watchListMovies.erase(i);
		break;
	}
	MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
	MoviesDB::updateFileMoviesDB("movies.txt");
	deletedSuccessfully("Movie");
}

void User::deleteSeriesFromList(){
	int answer;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVecS(watchListSeries)) {
		cout << emptySeriesWL << endl;
		return;
	}

	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << i + 1 << ": " << watchListSeries[i] << endl;
	}
	
	cout << watchListSeries.size() + 1 << ": \n   ------Exit------" << endl;
	answer = answerIntViewer(DeleteFromWLorDB, 1, watchListSeries.size()+1);
	if (answer == watchListSeries.size() + 1) {
		return;
	}

	for (vector<Series>::iterator i = watchListSeries.begin(); i != watchListSeries.end(); ++i) {
		advance(i, answer - 1);
		watchListSeries.erase(i);
		break;
	}
	SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
	SeriesDB::updateFileSeriesDB("series.txt");
	deletedSuccessfully("Series");
}

void User::getPersonalInfo() throw (invalid_argument){
	string lname, fname, byear, bmonth, bday, id;
	string path = "user.txt";
	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "file not found" << endl; }
	else {
		try {
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

			fin.close();
			if (!validateViewerInfo(fname, lname, stoi(id), stoi(bday), stoi(bmonth), stoi(byear))) {
				cout << "Invalid info of the user";
			}
		}
		catch (const invalid_argument& e) {
			cerr << "Invalid info of the user" << endl;
			return;
		}
	}
}




