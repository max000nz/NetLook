#include "moviesDB.h"
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
			if (way == "movies.txt")	moviesdb.emplace_back(currentMovie);
			else moviesWLdb.emplace_back(currentMovie);
			getline(fin, buffer);
		}
	}
	fin.close();
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
	string name, category, year, length, buffer;
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