#include "movie.h"
#include "moviesDB.h"
#include "show.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
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
    char row = 205, col = 179, cornerL = 192, cornerR = 217, midd = 197, cornerLU = 218;
    char cornerRU = 188, middU = 193, cornerRR = 191, cornerLL = 218, middleSingle = 194; //ascii codes
    cout << "\n   ";
    
    for (int f = 0; f < 50; f++) {
        if (f == 0) { cout << cornerLL; }
        else if (f == 49) { cout << cornerRR; }
        else { cout << row; }
    }
    for (int i = 0; i < 1; i++) {
        cout << "\n";
        int size = 53 - m.getName().length() - 13 - m.getCategory().length() - to_string(m.getMovieLength()).length();
        for (int j = 0; j < 1; j++) {
            os << "   "<< col << " " << m.getName() << " " << m.getYear() << " " << m.getCategory() << " " << m.getMovieLength();
            for (int l = 0; l < size; l++) {
                cout << " ";
            }
            cout << col;
        }
        cout << "\n   ";
        for (int rd = 0; rd < 50; rd++) {
            switch (rd) {
            case 0: cout << cornerL; continue;
            case 49: cout << cornerR; continue;
            default:cout << row;
            }
        }
    }
    return os;
}