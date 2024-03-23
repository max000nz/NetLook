#include "series.h"
#include "show.h"
using namespace std;

Series::Series(char* name, int year, char* category, int seasons, int episodes) :Show(name, year, category) {
	this->episodes = episodes;
	this->seasons = seasons;
}

Series::Series() {}

ostream& operator<<(ostream& os, const Series& s) {
	os << s.getName() << " " << s.getYear() << " " << s.getCategory() << " " << s.getSeries() << " " << s.getSeasons();
	return os;
}