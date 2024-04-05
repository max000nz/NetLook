#pragma once
#pragma comment(lib, "Winscard")
#include "user.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int validateInt(int ans, int min, int max);
string answerStringViewer(string message, int onlyLetters, int min, int max) throw(invalid_argument, out_of_range);
int answerIntViewer(string message, int min, int max) throw(invalid_argument, out_of_range);
int isEmptyVecM(vector<Movie>& check) throw(out_of_range);
int isEmptyVecS(vector<Series>& check) throw(out_of_range);
int validateAdmin(Admin currAdmin);
int validateUser(User currUser);