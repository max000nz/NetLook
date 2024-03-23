#include "movie.h"
using namespace std;

Movie::Movie(char* name, int year, char* category, int length) :Show(name, year, category) {
	this->length = length;
}

Movie::Movie() {}


ostream& operator<<(ostream& os, const Movie& m) {
	os << m.getName() << " " << m.getYear() << " " << m.getCategory() << " " << m.getMovieLength();
	return os;
}
