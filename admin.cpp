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
	string path = "movies.txt";
	vector<Movie> movies = openMovies(movies);

	if (isEmpty(movies)) {
		cout << "No movies in data base, fail" << endl;
		return;
	}

	cout << "Write name of movie you want delete" << endl;
	cin.get();
	getline(cin, name);

	int size = movies.size();

	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {//delete from vector
		if (i->getName() == name) {
			movies.erase(i);
			break;
		}
	}

	if (size == movies.size()) {
		cout << "Movie with this name is not exist" << endl;
		return;
	}

	movies = closeMovies(movies);
	cout << "Movies.txt closed" << endl;
}

void Admin::findMovieByCategory() {
	int answer = 0;
	int counter = 1;
	vector<Movie> movies = openMovies(movies);
	string category;

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
				movies.erase(i);
				break;
			}
		}
	}

	movies = closeMovies(movies);
	cout << "Movie deleted succesfully" << endl;
}

void Admin::findSeriesByName(){
	int answer = 0;
	string name;
	string path = "series.txt";
	vector<Series> series = openSeries(series);

	if (isEmpty(series)) {
		cout << "No series in data base, fail" << endl;
		return;
	}

	cout << "Write name of series you want delete" << endl;
	cin.get();
	getline(cin, name);

	int size = series.size();

	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {//delete from vector
		if (i->getName() == name) {
			series.erase(i);
			break;
		}
	}

	if (size == series.size()) {
		cout << "Series with this name is not exist" << endl;
		return;
	}

	series = closeSeries(series);
	cout << "Series.txt closed" << endl;
}

void Admin::findSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	vector<Series> series = openSeries(series);
	string category;

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
				series.erase(i);
				break;
			}
		}
	}

	series = closeSeries(series);
	cout << "Series deleted succesfully" << endl;
}

vector<Movie> Admin::openMovies(vector<Movie> movies) {
	string name, category, year, length, buffer, time;
	int iyear, ilength, itime;
	string path = "movies.txt";
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

vector<Movie> Admin::closeMovies(vector<Movie> movies) {
	string name, category, year, length, buffer;
	string path = "movies.txt";
	Movie currentMovie;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		cout << "Movies.txt open" << endl;
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

vector<Series> Admin::openSeries(vector<Series> series){
	string name, category, year, seasons, episodes, buffer, time;
	int iyear, iepisodes, iseasons, itime;
	string path = "series.txt";
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

vector<Series> Admin::closeSeries(vector<Series> series) {
	string name, category, year, seasons, episodes, buffer;
	string path = "series.txt";
	Series currentSeries;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		cout << "Movies.txt open" << endl;
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