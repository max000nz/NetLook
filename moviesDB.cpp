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

/// <summary>
/// function will get all the movies from the file to movies vector
/// </summary>
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
		if (isEmptyVecM(moviesdb));
	}
}

/// <summary>
/// for the setup-check if all the marked movies are in watchlist and no movies that not exist in data base 
/// </summary>
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
	for (vector<Movie>::iterator j = moviesWLdb.begin(); j != moviesWLdb.end(); ++j) {
			name = j->getName();
			if (!isMarked(name)) {
				deleteFromMoviesWatchList(name);
				break;
			}
	}
}

/// <summary>
/// check if the movie is in watchlist
/// </summary>
int MoviesDB::existInWL(string name) {
	if (moviesWLdb.size() == 0) return 0;
	for (vector<Movie>::iterator j = moviesWLdb.begin(); j != moviesWLdb.end(); ++j) {
		if (j->getName() == name) {
			return 1;
		}
	}
	return 0;
}

/// <summary>
/// check if the movie is marked
/// </summary>
int MoviesDB::isMarked(string name) {
	if (moviesdb.size() == 0) return 0;
	for (vector<Movie>::iterator j = moviesdb.begin(); j != moviesdb.end(); ++j) {
		if (j->getName() == name) {
			j->setAddWL();
			return 1;
		}
	}
	return 0;
}

/// <summary>
/// return the vector movies
/// </summary>
vector<Movie>& MoviesDB::getMoviesDB()
{
	 return moviesdb; 
}

/// <summary>
/// return the movies watchlist vector
/// </summary>
vector<Movie>& MoviesDB::getMoviesWatchListDB()
{
	return moviesWLdb;
}

/// <summary>
/// update the file of the movies
/// </summary>
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

/// <summary>
/// adding the movie that admin create to the vector
/// </summary>
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

/// <summary>
/// delete the movie that the admin want
/// </summary>
void MoviesDB::deleteFromMoviesWatchList(string name) {
	string lowCurrName;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	for (vector<Movie>::iterator j = moviesWLdb.begin(); j != moviesWLdb.end(); ++j) {//delete from vector
		lowCurrName = j->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == name) {
			moviesWLdb.erase(j);
			break;
		}
	}
}