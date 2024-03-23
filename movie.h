#pragma once
#include "show.h"

class Movie :public Show {

	int length;//minutes

public:
	Movie();
	Movie(char* name, int year, char* category, int length);
	void setMovieLength(int length) { this->length = length; };
	int getMovieLength() const { return length; };
	friend ostream& operator<<(ostream& os, const Movie& m);
};