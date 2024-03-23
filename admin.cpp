#include "admin.h"
#include <iostream>
#include <fstream>
using namespace std;

Admin::Admin(int id, char* fname, char* lname, int day, int month, int year) :Viewer(id, fname, lname, day, month, year) {}