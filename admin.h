#pragma once
#include "user.h"
#include "viewer.h"

class Admin :public Viewer {

public:
	Admin(int id, char* fname, char* lname, int day, int month, int year);
private:
	int addMovie();
	int addSeries();
	int deleteMovie();
	int deleteSeries();
	//void backToMenu();
	void writeToFile(const char* fileName)const;
};