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

int validateInt(int ans, int min, int max);
int answerIntViewer(string message, int min, int max);
string answerStringViewer(string message, int onlyLetters, int min, int max);
/*
validation:
   -- validate int  +++++
        (get answer, min , max and return if valid)
   -- validate string +++++
        (get string and check if valid:
        number of chars
        )
   --  validate Movie
        
   --  validate Series

   --  validate Admin

   --  validate User



testing:
  -- setup movie db
  -- setup series db

*/
