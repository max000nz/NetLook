#pragma once
#include "show.h"

class Series :public Show {

	int seasons;
	int episodes;

public:
	Series();
	Series(char* name, int year, char* category, int seasons, int episodes);
	int getSeasons() const { return seasons; };
	int getSeries() const { return episodes; };
	void setSeasons(int seasons) { this->seasons = seasons; };
	void setSeries(int series) { this->episodes = series; };
	friend ostream& operator<<(ostream& os, const Series& s);
};