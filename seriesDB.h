#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "series.h"
using namespace std;

class SeriesDB
{
public:
	static vector<Series>& getSeriesDB();
	static vector<Series>& getSeriesWatchListDB();
	static void setupSeriesDB(string way);
	static void updateFileSeriesDB(string way);
	static void addSeriesToDB(Series& series);
	static void deleteFromSeriesWatchList(string name);
	static void compareSeriesDB();
	static int isMarked(string name);
	static int existInWL(string name);
};