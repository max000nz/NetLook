#include "series.h"
#include "seriesDB.h"
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

void Series::setDeleteWL(string name) {
	vector<Series>& series = SeriesDB::getSeriesDB();
	for (vector<Series>::iterator i = series.begin(); i != series.end(); ++i) {
		if (i->getName() == name) {
			i->setDeleteWLDB();
		}
	}
}

ostream& operator<<(ostream& os, const Series& s) {
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

        int size = 53 - s.getName().length() - 14 - s.getCategory().length() - to_string(s.getSeasons()).length() - to_string(s.getEpisodes()).length();
        for (int j = 0; j < 1; j++) {
            os << "   " << col << " " << s.getName() << " " << s.getYear() << " " << s.getCategory() << " " << s.getSeasons() << " " << s.getEpisodes();
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