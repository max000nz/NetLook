#include "series.h"
#include "show.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Series::Series(string name, int year, string category, int seasons, int episodes) :Show(name, year, category) {
	this->episodes = episodes;
	this->seasons = seasons;
}

ostream& operator<<(ostream& os, const Series& s) {
	os << s.getName() << " " << s.getYear() << " " << s.getCategory() << " " << s.getSeasons() << " " << s.getEpisodes();
	return os;
}