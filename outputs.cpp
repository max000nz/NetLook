#define _CRT_SECURE_NO_WARNINGS
#include "outputs.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"
#include "viewer.h"
using namespace std;

/// <summary>
/// prints if show added
/// </summary>
void addedSuccessfully(string show) {
	cout << show << " added successfully\n";
	cout << "\n-----------------------------------------------------\n\n";
}

/// <summary>
/// prints if show deleted
/// </summary>
void deletedSuccessfully(string show) {
	cout << show << " deleted successfully\n";
	cout << "\n-----------------------------------------------------\n\n";
}

/// <summary>
/// prints if no more shows avaliable
/// </summary>
void noMore(string show) {
	cout << "No more " << show << " avaliable\n";
	cout << "\n-----------------------------------------------------\n\n";
}

/// <summary>
/// prints if show already added
/// </summary>
void alreadyInWL(string show) {
	cout << show << " already in your watch list\n";
	cout << "\n-----------------------------------------------------\n\n";
}