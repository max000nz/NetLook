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

User::User(int id, char* name, char* surname, int day, int month, int year, vector<Show> watchList)
	:Viewer(id, name, surname, day, month, year)
{
	this->watchList = watchList;
}

void User::addMovieToWatchList(Movie currentMovie) {
	watchList.emplace_back(currentMovie);
	//string path = "moviesWatch.txt";
	//ofstream fout;
	//fout.open(path, ios::app);//try catch instead
	//if (!fout.is_open()) { cout << "File cannot open!" << endl; }
	//else
	//{
	//	cout << "File open, nice" << endl;
	//	fout.write((char*)&currentMovie, sizeof(Movie));
	//}
	//fout.close();
}

void User::addSeriesToWatchList(Series currentSeries) {
	watchList.emplace_back(currentSeries);
	//string path = "seriesWatch.txt";
	//ofstream fout;
	//fout.open(path, ios::app);//try catch instead
	//if (!fout.is_open()) { cout << "File cannot open!" << endl; }
	//else
	//{
	//	cout << "File open, nice" << endl;
	//	fout.write((char*)&currentSeries, sizeof(Series));
	//}
	//fout.close();
}

void User::findByName(char* name) {
	int answer = 0;
	string movies = "movies.txt";
	string series = "series.txt";
	ifstream fin;
	fin.open(movies, ios::in);
	if (!fin.is_open()) {
		cout << "file not found" << endl;
	}
	else {
		Movie currentMovie;
		while (fin.read((char*)&currentMovie, sizeof(Movie)))//change to vector use
		{
			if (strcmp(currentMovie.getName(), name)) {//chars need to use func
				cout << currentMovie; // .Print(); //need use
				cout << "You want to add this movie?" << endl;
				cout << "1: yes \n 2: no" << endl;
				cin >> answer;
				if (answer == 1)
				{
					addMovieToWatchList(currentMovie);
				}
				else {
					continue;
				}
			}
			else {
				cout << "Movies with this name not found!" << endl;
			}
		}
	}
	fin.close();

	answer = 0;

	fin.open(series, ios::in);
	if (!fin.is_open()) {
		cout << "file not found" << endl;
	}
	else {
		Series currentSeries;
		while (fin.read((char*)&currentSeries, sizeof(Series)))
		{
			if (strcmp(currentSeries.getName(), name)) {
				cout << currentSeries; // .Print(); //need use
				cout << "You want to add this movie?" << endl;
				cout << "1: yes \n 2: no" << endl;
				cin >> answer;
				if (answer == 1)
				{
					addSeriesToWatchList(currentSeries);
				}
				else {
					continue;
				}
			}
			else {
				cout << "Series with this name not found!" << endl;
			}
		}
	}
	fin.close();
}

void User::watchMovieFromList() {
	//open vector watchlist -> find first movie -> out info ->replay 
	int answer = 0;
	string path = "moviesWatch.txt";
	ifstream fin;
	fin.open(path, ios::in);//try catch instead
	if (!fin.is_open()) { cout << "File cannot open!" << endl; }
	else
	{
		cout << "File open, nice" << endl;
		Movie currentMovie;
		while (fin.read((char*)&currentMovie, sizeof(Movie))) {
			cout << "You now watching: " << currentMovie;
			cout << "Want to see next your series?" << endl;
			cout << "1: yes \n 2: no" << endl;
			cin >> answer;
			if (answer == 1) {
				continue;
			}
			else {
				break;
			}
		}
		fin.close();
	}
}

void User::watchSeriesFromList() {
	//open vector watchlist -> find first series -> out info ->replay
	int answer = 0;
	string path = "seriesWatch.txt";
	ifstream fin;
	fin.open(path, ios::in);//try catch instead
	if (!fin.is_open()) { cout << "File cannot open!" << endl; }
	else
	{
		cout << "File open, nice" << endl;
		Series currentSeries;
		while (fin.read((char*)&currentSeries, sizeof(Series))) {
			cout << "You now watching: " << currentSeries;
			cout << "Want to see next your series?" << endl;
			cout << "1: yes \n 2: no" << endl;
			cin >> answer;
			if (answer == 1) {
				continue;
			}
			else {
				break;
			}
		}

	}
	fin.close();
}

void User::deleteMovieFromList()
{
	for (int i = 0; i < watchList.size(); i++)
	{
		if(){}
			//df
	}
}

void User::deleteSeriesFromList()
{

}