#include "movie.h"
#include "moviesDB.h"
#include "show.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

Movie::Movie(string name, int year, string category, int length):Show(name, year, category) {
	this->length = length;
}


void Movie::setDeleteWL(string name){
	vector<Movie>& movies = MoviesDB::getMoviesDB();
	for (vector<Movie>::iterator i = movies.begin(); i != movies.end(); ++i) {
		if (i->getName() == name) {
			i->setDeleteWLDB();
		}
	}
}

ostream& operator<<(ostream& os, const Movie& m) {
	os << m.getName() << " " << m.getYear() << " " << m.getCategory() << " " << m.getMovieLength();
	return os;
}