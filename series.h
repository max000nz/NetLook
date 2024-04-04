#pragma once
#include "show.h"
using namespace std;

class Series:public Show {

protected:
	int seasons;
	int episodes;

public:
	Series() = default;
	Series(string name, int year, string category, int seasons, int episodes);
	int getSeasons() const { return seasons; };
	int getEpisodes() const { return episodes; };
	void setSeasons(int seasons) { this->seasons = seasons; };
	void setEpisodes(int episodes) { this->episodes = episodes; };
	friend ostream& operator<<(ostream& os, const Series& s);
	void setDeleteWL(string name);
};