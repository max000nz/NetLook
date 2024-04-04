#pragma once
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

extern int validateInt(int ans, int min, int max);
extern string answerStringViewer(string message, int onlyLetters, int min, int max) throw(invalid_argument, out_of_range);
extern int answerIntViewer(string message, int min, int max) throw(invalid_argument, out_of_range);
extern int isEmptyVec(vector<Movie>& check) throw(out_of_range);
extern int isEmptyVec(vector<Series>& check) throw(out_of_range);
extern int validateAdmin(Admin currAdmin);
extern int validateUser(User currUser);
