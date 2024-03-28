#include "user.h"
#include "show.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"
#include "viewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int validateInt(int ans, int min, int max);
string answerStringViewer(string message, int onlyLetters, int min, int max);
int answerIntViewer(string message, int min, int max);
int isEmptyVec(vector<Movie>& check);
int isEmptyVec(vector<Series>& check);