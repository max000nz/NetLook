#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "series.h"
#include "validationFile.h"
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
	string name, message;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies; //buffer object

	if (isEmptyVec(movies)) {
		cout << "No movies in data base\n" << endl;
		return;
	}

	for (int i = 0; i < movies.size(); i++) {
		if (movies[i].getIsWL() == "Y") continue;
		cout << counter << ": " << movies[i] << endl; //printing the vector in list-like form
		counter++;
		message = "\nYou wanna add this movie?\n"
				  "1.Yes\n2.No\n3.Exit\n";
		answer = answerIntViewer(message, 1, 3);
		switch (answer){
			case 1:
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				MoviesDB::updateFileMoviesDB("movies.txt");
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				continue;
			case 2:
				continue;
			case 3:
				return;
		}
		break;
	}
	cout << "No more movies in data base\n" << endl;
}

void User::chooseFromMoviesByCategory() {
	int answer = 0;
	int counter = 1;
	string category, message;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();
	Movie currentMovies; //buffer object

	if (isEmptyVec(movies)) {
		cout << "No movies in data base\n" << endl;
		return;
	}

	cout << "In which category you want search movies?" << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].getIsWL() == "Y") continue;
		if (movies[i].getCategory() == category) {
			cout << counter << ": " << movies[i] << endl;
			counter++;
			message = "\nYou want to add this movie to your watch list?\n"
					  "1.Yes\n2.No\n3.Exit\n";
			answer = answerIntViewer(message, 1, 3);
			switch (answer) {
			case 1:
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				MoviesDB::updateFileMoviesDB("movies.txt");
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
	int counter = 1;
	string name, message;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	Series currentSeries; //buffer object

	if (isEmptyVec(series)) {
		cout << "No series in data base\n" << endl;
		return;
	}

	for (int i = 0; i < series.size(); i++) {
		if (series[i].getIsWL() == "Y") continue;
		cout << counter << ": " << series[i] << endl; //printing the vector in list-like form
		counter++;
		message = "\nYou want to add this series to your watch list?\n"
				  "1.Yes\n2.No\n3.Exit\n";
		answer = answerIntViewer(message, 1, 3);
		switch (answer) {
		case 1:
			series[i].setAddWL();
			watchListSeries.emplace_back(series[i]);
			SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
			SeriesDB::updateFileSeriesDB("series.txt");
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
	string category, message;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();
	Series currentSeries; //buffer object

	if (isEmptyVec(series)) {
		cout << "No series in data base\n" << endl;
		return;
	}

	cout << "In which category you want search series?" << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].getIsWL() == "Y") continue;
		if (series[i].getCategory() == category) {
			cout << counter << ": " << series[i] << endl;
			counter++;
			message = "\nYou want to add this series to your watch list?\n"
				      "1.Yes\n2.No\n3.Exit\n";
			answer = answerIntViewer(message, 1, 3);
			switch (answer) {
			case 1:
				series[i].setAddWL();
				watchListSeries.emplace_back(series[i]);
				SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				SeriesDB::updateFileSeriesDB("series.txt");
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
	string name, message, currName;
	int answer;
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	message = "Please write which movie you want to find\n";
	name = answerStringViewer(message, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });
	if (isEmptyVec(movies)) {
		cout << "No movies in data base\n" << endl;
		return;
	}
	int size = movies.size();

	for (int i = 0; i < movies.size(); i++) {//delete from vector
		currName = movies[i].getName();
		transform(currName.begin(), currName.end(), currName.begin(), [](unsigned char c) { return std::tolower(c); });
		if (currName == name) {
			if (movies[i].getIsWL() == "Y") {
				cout << "That movie already in your watch list\n" << endl;
				return;
			}
			cout << "You want to add this movie?" << endl;
			cout << movies[i] << endl;
			message = "1.Yes\n2.No\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) {
				movies[i].setAddWL();
				watchListMovies.emplace_back(movies[i]);
				size++;
				MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
				MoviesDB::updateFileMoviesDB("movies.txt");
				cout << "Movie added successfully";
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == movies.size()) {
		cout << "Movie with this name is not exist, sorry\n" << endl;
		return;
	}
}

void User::findSeriesByName() {
	string name, message, currName;
	int answer;
	vector<Series>& series = SeriesDB::getSeriesDB();
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	message = "Please write which series you want to find\n";
	name = answerStringViewer(message, 0, 2, 25);
	transform(name.begin(), name.end(), name.begin(), [](unsigned char c) { return std::tolower(c); });

	if (isEmptyVec(series)) {
		cout << "No series in data base\n" << endl;
		return;
	}
	int size = series.size();

	for (int i = 0; i < series.size(); i++) {//delete from vector
		currName = series[i].getName();
		transform(currName.begin(), currName.end(), currName.begin(), [](unsigned char c) { return std::tolower(c); });
		if (series[i].getName() == name) {
			if (series[i].getIsWL() == "Y") {
				cout << "That series already in your watch list\n" << endl;
				return;
			}
			cout << "You want to add this series?" << endl;
			cout << series[i] << endl;
			message = "1.Yes\n2.No\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) {
				series[i].setAddWL();
				watchListSeries.emplace_back(series[i]);
				size++;
				SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
				SeriesDB::updateFileSeriesDB("series.txt");
				break;
			}
			else {
				size++;
				break;
			}
		}
	}

	if (size == series.size()) {
		cout << "Series with this name is not exist, sorry\n" << endl;
		return;
	}
}

void User::watchMovieFromList() {
	int answer;
	string message;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(watchListMovies)) {
		cout << "No movies in watch list\n" << endl;
		return;
	}

	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << "You now watching" << endl;
		cout << "   " << watchListMovies[i] << endl;
		message = "\n1.Watch next\n2.Exit\n";
		answer = answerIntViewer(message, 1, 2);

		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	cout << "No more movies in your watch list\n" << endl;
}

void User::watchSeriesFromList() {
	int answer;
	string message;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(watchListSeries)) {
		cout << "No series in watch list\n" << endl;
		return;
	}

	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << "You now watching" << endl;
		cout << "   " << watchListSeries[i] << endl;
		message = "\n1.Watch next\n2.Exit\n";
		answer = answerIntViewer(message, 1, 2);
		if (answer == 1) {
			continue;
		}
		else {
			return;
		}
	}
	cout << "No more series in your watch list\n" << endl;
}

void User::deleteMovieFromList() {
	int answer;
	string name, message;
	vector<Movie>& watchListMovies = MoviesDB::getMoviesWatchListDB();

	if (isEmptyVec(watchListMovies)) {
		cout << "No movies in watch list\n" << endl;
		return;
	}

	for (int i = 0; i < watchListMovies.size(); i++) {
		cout << i + 1 << ": " << watchListMovies[i] << endl;
	}
	
	cout << watchListMovies.size()+1 << ": \n   ------Exit------" << endl;
	message = "\nWhich movie you want delete?\n";
	answer = answerIntViewer(message, 1, watchListMovies.size()+1);
	if (answer == watchListMovies.size() + 1) {
		return;
	}

	for (vector<Movie>::iterator i = watchListMovies.begin(); i != watchListMovies.end(); ++i) {//delete from vector
		advance(i,answer-1);
		name = i->getName();
		i->setDeleteWL(name);
		watchListMovies.erase(i);
		break;
	}
	MoviesDB::updateFileMoviesDB("moviesWatchList.txt");
	MoviesDB::updateFileMoviesDB("movies.txt");
	cout << "Chosen movie deleted sucsesfully\n" << endl;
}

void User::deleteSeriesFromList(){
	int answer;
	string message;
	vector<Series>& watchListSeries = SeriesDB::getSeriesWatchListDB();

	if (isEmptyVec(watchListSeries)) {
		cout << "No series in watch list\n" << endl;
		return;
	}

	for (int i = 0; i < watchListSeries.size(); i++) {
		cout << i + 1 << ": " << watchListSeries[i] << endl;
	}
	
	cout << watchListSeries.size() + 1 << ": \n   ------Exit------" << endl;
	message = "\nWhich series you want delete?\n";
	answer = answerIntViewer(message, 1, watchListSeries.size()+1);
	if (answer == watchListSeries.size() + 1) {
		return;
	}

	for (vector<Series>::iterator i = watchListSeries.begin(); i != watchListSeries.end(); ++i) {//delete from vector
		advance(i, answer - 1);
		watchListSeries.erase(i);
		break;
	}
	SeriesDB::updateFileSeriesDB("seriesWatchList.txt");
	SeriesDB::updateFileSeriesDB("series.txt");
	cout << "Chosen series deleted sucsesfully\n" << endl;
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




