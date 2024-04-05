#include "seriesDB.h"
#include "validationFile.h"
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

/// <summary>
/// function will get all the series from the file to series vector
/// </summary>
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
	if (way == "series.txt") {
		if (isEmptyVecS(seriesdb));
	}
}

/// <summary>
/// 
/// </summary>
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

void SeriesDB::deleteFromSeriesWatchList(string name) {
	string lowCurrName;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	for (vector<Series>::iterator j = seriesWLdb.begin(); j != seriesWLdb.end(); ++j) {//delete from vector
		lowCurrName = j->getName();
		transform(lowCurrName.begin(), lowCurrName.end(), lowCurrName.begin(), ::tolower);
		if (lowCurrName == name) {
			seriesWLdb.erase(j);
			break;
		}
	}
}

void SeriesDB::compareSeriesDB() {
	string name;
	if (seriesdb.size() == 0) return;
	for (vector<Series>::iterator i = seriesdb.begin(); i != seriesdb.end(); ++i) {
		if (i->getIsWL() == "Y") {
			name = i->getName();
			if (!existInWL(name)) {
				i->setDeleteWLDB();
			}
		}
	}
	for (vector<Series>::iterator j = seriesWLdb.begin(); j != seriesWLdb.end(); ++j) {
		name = j->getName();
		if (!isMarked(name)) {
			deleteFromSeriesWatchList(name);
			break;
		}
	}
}

int SeriesDB::existInWL(string name) {
	if (seriesWLdb.size() == 0) return 0;
	for (vector<Series>::iterator j = seriesWLdb.begin(); j != seriesWLdb.end(); ++j) {
		if (j->getName() == name) {
			return 1;
		}
	}
	return 0;
}

int SeriesDB::isMarked(string name) {
	if (seriesdb.size() == 0) return 0;
	for (vector<Series>::iterator j = seriesdb.begin(); j != seriesdb.end(); ++j) {
		if (j->getName() == name) {
			j->setAddWL();
			return 1;
		}
	}
	return 0;
}