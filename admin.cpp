#define _CRT_SECURE_NO_WARNINGS
#include "admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

Admin::Admin(int id, string fname, string lname, int day, int month, int year) :Viewer(id, fname, lname, day, month, year) {}

void Admin::addMovie() {
	time_t currTime = time(nullptr);
	//string timeString = ctime(&currTime);
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
	fout.open(path, ios::out | ios::app);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }
	else
	{
		cout << "Movies.txt open, nice" << endl;
		fout << name << endl;
		fout << category << endl;
		fout << year << endl;
		fout << length << endl;
		fout << currTime << endl;//timeString without endl
		fout << "\n";
	}
	fout.close();
	cout << "Movies.txt closed, nice" << endl;
}

void Admin::addSeries() {
	time_t currTime = time(nullptr);
	//string timeString = ctime(&currTime);
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
	fout.open(path, ios::app | ios::out);//try catch instead
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }
	else
	{
		cout << "Series.txt open" << endl;
		fout << name << endl;
		fout << category << endl;
		fout << year << endl;
		fout << seasons << endl;
		fout << episodes << endl;
		fout << currTime << endl;
		fout << "\n";
	}
	fout.close();
}

void Admin::findMovieByName() {
	int answer = 0;
	string name;
	vector<Movie> movies = openFile (movies, "movies.txt");
	vector<Movie> watchListMovie = openFile(watchListMovie, "moviesWatchList.txt");

	if (isEmpty(movies)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	cout << "Write name of movie you want delete" << endl;
	cin.get();
	getline(cin, name);

	int size = movies.size();
	int sizeWatch = watchListMovie.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector of data base
		if (i->getName() == name) {
			movies.erase(i);
			break;
		}
	}

	for (vector<Movie>::iterator j = watchListMovie.begin(); j != watchListMovie.end(); ++j) {//delete from vector watch list of user
		if (j->getName() == name) {
			watchListMovie.erase(j);
			break;
		} 
	}

	if (size == movies.size()) {
		cout << "Movie with this name is not exist in data base" << endl;
		return;
	}

	if (sizeWatch == watchListMovie.size()) {
		cout << "Movie with this name is not exist in watch list" << endl;
		return;
	}

	movies = closeFile(movies, "movies.txt");
	watchListMovie = closeFile(watchListMovie, "moviesWatchList.txt");
}

void Admin::findMovieByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name;
	vector<Movie> movies = openFile(movies, "movies.txt");
	vector<Movie> watchListMovie = openFile(watchListMovie, "moviesWatchList.txt");

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


	for (vector<Movie>::iterator j = watchListMovie.begin(); j != watchListMovie.end(); ++j) {//delete from vector watch list of user
		if (j->getName() == name) {
			watchListMovie.erase(j);
			break;
		}
	}


	movies = closeFile(movies, "movies.txt");
	watchListMovie = closeFile(watchListMovie, "moviesWatchList.txt");
	cout << "Movie deleted succesfully" << endl;
}

void Admin::findSeriesByName(){
	int answer = 0;
	string name;
	vector<Series> series = openFile(series, "series.txt");
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");

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

	series = closeFile(series, "series.txt");
	watchListSeries = closeFile(watchListSeries, "seriesWatchList.txt");
}

void Admin::findSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category, name;
	vector<Series> series = openFile(series, "series.txt");
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");
	

	if (isEmpty(series)) {
		cout << "No series in data base, fail" << endl;
		return;
	}

	cout << "Write category of series you want delete" << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].category == category) {
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

	series = closeFile(series, "series.txt");
	watchListSeries = closeFile(watchListSeries, "seriesWatchList.txt");
	cout << "Series deleted succesfully" << endl;
}

vector<Movie> Admin::openFile(vector<Movie> movies, string way) {
	string name, category, year, length, buffer, time;
	int iyear, ilength, itime;
	string path = way;
	Movie currentMovie;

	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "file not found" << endl; }
	else {
		while (!fin.eof()) {
			getline(fin, name);
			if (name == "") {
				break;
			}
			currentMovie.setName(name);
			getline(fin, category);
			currentMovie.setCategory(category);
			getline(fin, year);
			iyear = stoi(year);
			currentMovie.setYear(iyear);
			getline(fin, length);
			ilength = stoi(length);
			currentMovie.setMovieLength(ilength);
			getline(fin, time);
			itime = stoi(time);
			currentMovie.setTime(itime);
			movies.emplace_back(currentMovie);
			getline(fin, buffer);
		}
	}
	fin.close();
	return movies;
}

vector<Movie> Admin::closeFile(vector<Movie> movies, string way) {
	string name, category, year, length, buffer;
	string path = way;
	Movie currentMovie;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		for (int i = 0; i < movies.size(); i++) {
			currentMovie = movies[i];
			fout << currentMovie.getName() << endl;
			fout << currentMovie.getCategory() << endl;
			fout << currentMovie.getYear() << endl;
			fout << currentMovie.getMovieLength() << endl;
			fout << currentMovie.getTime() << endl;
			fout << "\n";
		}
	}
	fout.close();
	return movies;
}

vector<Series> Admin::openFile(vector<Series> series, string way) {
	string name, category, year, seasons, episodes, buffer, time;
	int iyear, iepisodes, iseasons, itime;
	string path = way;
	Series currentSeries;

	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "file not found" << endl; }
	else {
		while (!fin.eof()) {
			getline(fin, name);
			if (name == "") {
				break;
			}
			currentSeries.setName(name);
			getline(fin, category);
			currentSeries.setCategory(category);
			getline(fin, year);
			iyear = stoi(year);
			currentSeries.setYear(iyear);
			getline(fin, seasons);
			iseasons = stoi(seasons);
			currentSeries.setSeasons(iseasons);
			getline(fin, episodes);
			iepisodes = stoi(episodes);
			currentSeries.setEpisodes(iepisodes);
			getline(fin, time);
			itime = stoi(time);
			currentSeries.setTime(itime);
			series.emplace_back(currentSeries);
			getline(fin, buffer);
		}
	}
	fin.close();
	return series;
}

vector<Series> Admin::closeFile(vector<Series> series, string way) {
	string name, category, year, seasons, episodes, buffer;
	string path = way;
	Series currentSeries;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		for (int i = 0; i < series.size(); i++) {
			currentSeries = series[i];
			fout << currentSeries.getName() << endl;
			fout << currentSeries.getCategory() << endl;
			fout << currentSeries.getYear() << endl;
			fout << currentSeries.getSeasons() << endl;
			fout << currentSeries.getEpisodes() << endl;
			fout << currentSeries.getTime() << endl;
			fout << "\n";
		}
	}
	fout.close();
	return series;
}