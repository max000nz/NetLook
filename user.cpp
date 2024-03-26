#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "show.h"
#include "movie.h"
#include "series.h"
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
	vector<Movie> movies = openFile(movies, "movies.txt");
	vector<Movie> watchListMovies = openFile(watchListMovies, "moviesWatchList.txt");
	Movie currentMovies; //buffer object

	sort(movies.begin(), movies.end(), greater<Movie>()); //sort vector by year and time

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

	watchListMovies = closeWatchListMovies(watchListMovies);
}

void User::chooseFromMoviesByCategory() {
	int answer = 0;
	int counter = 1;
	string category;
	vector<Movie> movies = openFile(movies, "movies.txt");
	vector<Movie> watchListMovies = openFile(watchListMovies, "moviesWatchList.txt");
	Movie currentMovies; //buffer object

	sort(movies.begin(), movies.end(), greater<Movie>()); //sort vector by year and time

	if (!isEmpty(watchListMovies)) {
		notToAddTwice(movies);
	}

	cout << "In which category you want search movies?" << endl;
	category = chooseCategory();

	for (int i = 0; i < movies.size(); ++i) {
		if (movies[i].category == category) {
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
	watchListMovies = closeWatchListMovies(watchListMovies);
}

void User::chooseFromSeries() {
	int answer = 0;
	string name;
	vector<Series> series = openFile(series, "series.txt");
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");
	Series currentSeries; //buffer object

	sort(series.begin(), series.end(), greater<Series>()); //sort vector by year and time

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

	watchListSeries = closeWatchListSeries(watchListSeries);
}

void User::chooseFromSeriesByCategory() {
	int answer = 0;
	int counter = 1;
	string category;
	vector<Series> series = openFile(series, "series.txt");
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");
	Series currentSeries; //buffer object

	sort(series.begin(), series.end(), greater<Series>()); //sort vector by year and time

	//delete from vector movies that already in watch list(if watch list not empty)
	if (!isEmpty(watchListSeries)) {
		notToAddTwice(series);
	}

	cout << "In which category you want search series?" << endl;
	category = chooseCategory();

	for (int i = 0; i < series.size(); ++i) {
		if (series[i].category == category) {
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
	watchListSeries = closeWatchListSeries(watchListSeries);
}

void User::findMovieByName() {
	string name;
	int answer;
	vector<Movie> movies = openFile(movies, "movies.txt");
	vector<Movie> watchListMovies = openFile(watchListMovies, "moviesWatchList.txt");

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

	watchListMovies = closeWatchListMovies(watchListMovies);
}

void User::findSeriesByName() {
	string name;
	int answer;
	vector<Series> series = openFile(series, "series.txt");
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");

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

	watchListSeries = closeWatchListSeries(watchListSeries);
}

void User::watchMovieFromList() {
	int answer;
	vector<Movie> watchListMovies = openFile(watchListMovies, "moviesWatchList.txt");
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
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");
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
	vector<Movie> watchListMovies = openFile(watchListMovies, "moviesWatchList.txt");

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
	watchListMovies = closeWatchListMovies(watchListMovies);
}

void User::deleteSeriesFromList(){
	int answer;
	vector<Series> watchListSeries = openFile(watchListSeries, "seriesWatchList.txt");

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
	watchListSeries = closeWatchListSeries(watchListSeries);

}

vector<Movie> User::openFile(vector<Movie> movies, string way) {
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

vector<Series> User::openFile(vector<Series> series, string way) {
	string name, category, year, seasons, episodes, buffer, time;
	int iyear, iseasons, iepisodes, itime;
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

vector<Movie> User::closeWatchListMovies(vector<Movie> movies) {
	string name, category, year, length, buffer;
	string path = "moviesWatchList.txt";
	Movie currentMovie;

	ofstream fout;
	fout.open(path, ios::trunc | ios::out);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		//cout << "moviesWatchList.txt open" << endl;
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

vector<Series> User::closeWatchListSeries(vector<Series> series) {
	string name, category, year, seasons, episodes, buffer;
	string path = "seriesWatchList.txt";
	Series currentSeries;

	ofstream fout;
	fout.open(path, ios::trunc | ios::out);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		//cout << "moviesWatchList.txt open" << endl;
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

void User::notToAddTwice(vector<Movie> movies) {
	for (vector<Movie>::iterator j = watchListMovies.begin(); j != watchListMovies.end(); ++j) {
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