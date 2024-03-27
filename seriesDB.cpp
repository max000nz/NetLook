#include "seriesDB.h"
#include "series.h"
#include "show.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

static vector<Series> seriesdb;
static vector<Series> seriesWLdb;

vector<Series>& SeriesDB::getSeriesDB()
{
	return seriesdb;
}

vector<Series>& SeriesDB::getSeriesWatchListDB()
{
	return seriesWLdb;
}

void SeriesDB::setupSeriesDB(string way) {
	string name, category, year, seasons, episodes, buffer, time, isWL;
	int iyear, iepisodes, iseasons, itime;
	string path = way;
	Series currentSeries;

	ifstream fin;
	fin.open(path, ios::in);
	if (!fin.is_open()) { cout << "file not found" << endl; }
	else {
		while (!fin.eof()) {
			getline(fin, name);
			if (name == "") {
				break;
			}
			currentSeries.setName(name);
			getline(fin, category);
			currentSeries.setCategory(category);
			getline(fin, year);
			iyear = stoi(year);
			currentSeries.setYear(iyear);
			getline(fin, seasons);
			iseasons = stoi(seasons);
			currentSeries.setSeasons(iseasons);
			getline(fin, episodes);
			iepisodes = stoi(episodes);
			currentSeries.setEpisodes(iepisodes);
			getline(fin, time);
			itime = stoi(time);
			currentSeries.setTime(itime);
			getline(fin, isWL);
			currentSeries.setIsWL(isWL);
			if (way == "series.txt") seriesdb.emplace_back(currentSeries);
			else seriesWLdb.emplace_back(currentSeries);
			getline(fin, buffer);
		}
	}
	fin.close();
}


void SeriesDB::updateFileSeriesDB(string way) {
	string name, category, year, seasons, episodes, buffer;
	string path = way;
	Series currentSeries;

	ofstream fout;
	fout.open(path, ios::trunc);
	if (!fout.is_open()) { cout << "File cannot open!" << endl; }//open file and put new vector
	else
	{
		if (way == "series.txt") {
			for (int i = 0; i < seriesdb.size(); i++) {
				currentSeries = seriesdb[i];
				fout << currentSeries.getName() << endl;
				fout << currentSeries.getCategory() << endl;
				fout << currentSeries.getYear() << endl;
				fout << currentSeries.getSeasons() << endl;
				fout << currentSeries.getEpisodes() << endl;
				fout << currentSeries.getTime() << endl;
				fout << currentSeries.getIsWL() << endl;
				fout << "\n";
			}
		}
		else {
			for (int i = 0; i < seriesWLdb.size(); i++) {
				currentSeries = seriesWLdb[i];
				fout << currentSeries.getName() << endl;
				fout << currentSeries.getCategory() << endl;
				fout << currentSeries.getYear() << endl;
				fout << currentSeries.getSeasons() << endl;
				fout << currentSeries.getEpisodes() << endl;
				fout << currentSeries.getTime() << endl;
				fout << currentSeries.getIsWL() << endl;
				fout << "\n";
			}
		}
	}
	fout.close();
}


void SeriesDB::addSeriesToDB(Series& series) {
	int place = 0;
	for (vector<Series>::iterator i = seriesdb.begin(); i != seriesdb.end(); ++i) {//delete from vector of data base
		if (i->getYear() <= series.getYear()) {
			break;
		}
		place++;
	}
	seriesdb.insert(seriesdb.begin() + place, series);
}