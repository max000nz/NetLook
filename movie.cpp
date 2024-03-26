#include "movie.h"
#include "show.h"
using namespace std;

Movie::Movie(string name, int year, string category, int length):Show(name, year, category) {
	this->length = length;
}

ostream& operator<<(ostream& os, const Movie& m) {
	os << m.getName() << " " << m.getYear() << " " << m.getCategory() << " " << m.getMovieLength();
	return os;
}
