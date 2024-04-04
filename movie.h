#pragma once
#include "show.h"
using namespace std;

class Movie :public Show {
protected:
	int length;//minutes

public:
	Movie() = default;
	Movie(string name, int year, string category, int length);
	void setMovieLength(int length) { this->length = length; };
	int getMovieLength() const { return length; };
	friend ostream& operator<<(ostream& os, const Movie& m);
	void setDeleteWL(string name);
};