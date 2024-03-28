#include "moviesDB.h"
#include "validationFile.h"
#include "movie.h"
#include "show.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

static vector<Movie> moviesdb;
static vector<Movie> moviesWLdb;

void MoviesDB::setupMoviesDB(string way) {
	string name, category, year, length, buffer, time, isWL;
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
			getline(fin, isWL);
			currentMovie.setIsWL(isWL);
			if (way == "movies.txt")	moviesdb.emplace_back(currentMovie);
			else moviesWLdb.emplace_back(currentMovie);
			getline(fin, buffer);
		}
	}
	fin.close();
	if (way == "movies.txt") {
		if (isEmptyVec(moviesdb));
	}
	else {
		if (isEmptyVec(moviesWLdb));
	}
}

void MoviesDB::compareMoviesDB() {
	string name;
	if (moviesdb.size() == 0) return;
	for (vector<Movie>::iterator i = moviesdb.begin(); i != moviesdb.end(); ++i) {
		if (i->getIsWL() == "Y") {
			name = i->getName();
			if (!existInWL(name)) {
				i->setDeleteWLDB();
			}
		}
	}
}

int MoviesDB::existInWL(string name) {
	if (moviesWLdb.size() == 0) return 0;
	for (vector<Movie>::iterator j = moviesWLdb.begin(); j != moviesWLdb.end(); ++j) {
		if (j->getName() == name) {
			return 1;
		}
	}
	return 0;
}

vector<Movie>& MoviesDB::getMoviesDB()
{
	 return moviesdb; 
}

vector<Movie>& MoviesDB::getMoviesWatchListDB()
{
	return moviesWLdb;
}

void MoviesDB::updateFileMoviesDB(string way) {
	string path = way;
	Movie currentMovie;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		if (way == "movies.txt") {
			for (int i = 0; i < moviesdb.size(); i++) {
				currentMovie = moviesdb[i];
				fout << currentMovie.getName() << endl;
				fout << currentMovie.getCategory() << endl;
				fout << currentMovie.getYear() << endl;
				fout << currentMovie.getMovieLength() << endl;
				fout << currentMovie.getTime() << endl;
				fout << currentMovie.getIsWL() << endl;
				fout << "\n";
			}
		}
		else {
			for (int i = 0; i < moviesWLdb.size(); i++) {
				currentMovie = moviesWLdb[i];
				fout << currentMovie.getName() << endl;
				fout << currentMovie.getCategory() << endl;
				fout << currentMovie.getYear() << endl;
				fout << currentMovie.getMovieLength() << endl;
				fout << currentMovie.getTime() << endl;
				fout << currentMovie.getIsWL() << endl;
				fout << "\n";
			}
		}
	}
	fout.close();
}


void MoviesDB::addMovieToDB(Movie& movie) {
	int place = 0;
	for (vector<Movie>::iterator i = moviesdb.begin(); i != moviesdb.end(); ++i) {//delete from vector of data base
		if (i->getYear() <= movie.getYear()) {
			break;
		}
		place++;
	}
	moviesdb.insert(moviesdb.begin() + place, movie);
}

void MoviesDB::deleteFromMoviesWatchList(vector<Movie>& watchListMovies, string name) {
	for (vector<Movie>::iterator j = watchListMovies.begin(); j != watchListMovies.end(); ++j) {//delete from vector
		if (j->getName() == name) {
			watchListMovies.erase(j);
			break;
		}
	}
}