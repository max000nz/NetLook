#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Winscard")
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include "validationFile.h"
#include "user.h"
#include "movie.h"
#include "moviesDB.h"
#include "seriesDB.h"
#include "series.h"
#include "admin.h"

using namespace std;

int validateInt(int ans, int min, int max) {
    if (ans >= min && ans <= max) return 1;
    return 0;
}

string answerStringViewer(string message, int onlyLetters, int min, int max) throw(invalid_argument, out_of_range) {
	string answer;
	while (true) {
		cout << message << "\nAnswer: ";
		try {
			cin >> ws;
			getline(cin, answer);

			if (answer == "") {
				throw invalid_argument("String empty, please try again\n");
			}
			if (answer.size() < min || answer.size() > max) {
				throw out_of_range("String length error");
			}
			if (onlyLetters) {
				for (char c : answer) {//if onlyLetters = 1(no numbers)
					if (!isalpha(c)) {
						if (c ==  ' ') {
							continue;
						}
						throw invalid_argument("String contains non-letter characters, please try again\n");
					}
				}
			}
			break;
		}
		catch (const invalid_argument& e) {
			cerr << e.what() << endl;
		}
		catch (const out_of_range& e) {
			cerr << e.what() << ", must be between "<< min << " and " << max << endl << endl;
		}
	}
	cout << "\n-----------------------------------------------------\n\n";
	return answer;
}

int answerIntViewer(string message, int min, int max) throw(invalid_argument, out_of_range) {
	string answerS;
	int answer;
	while (true) {
		cout << message << "\nAnswer: ";
		try {
			cin >> answerS;
			answer = stoi(answerS);
			if (!validateInt(answer, min, max)) {
				throw out_of_range("");
			}
			break;
		}
		catch (const invalid_argument& e) {
			cout << "\n-----------------------------------------------------\n\n";
			cerr << "Input must be an integer, please try again" << endl;
			cout << "\n-----------------------------------------------------\n\n";
		}
		catch (const out_of_range& e) {
			cout << "\n-----------------------------------------------------\n\n";
			cerr << "Number must be between " << min << " and " << max << endl;
			cout << "\n-----------------------------------------------------\n\n";
		}
		catch (...) {
			cout << "\n-----------------------------------------------------\n\n";
			cerr << "Try again\n" << endl;
			cout << "\n-----------------------------------------------------\n\n";
		}

	}
	cout << "\n-----------------------------------------------------\n\n";
	return answer;
}

int isEmptyVecM(vector<Movie>& check) throw(out_of_range) {
	try {
		if (!check.size()) throw out_of_range("Movie vector is empty");
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
		cout << "\n-----------------------------------------------------\n\n";
		return 1;
	}
	return 0;
}

int isEmptyVecS(vector<Series>& check) throw(out_of_range) {
	try {
		if (!check.size()) throw out_of_range("Series vector is empty");
	}
	catch (const out_of_range& e) {
		cerr << e.what() << endl;
		cout << "\n-----------------------------------------------------\n\n";
		return 1;
	}
	return 0;
}

int validateUser(User currUser) {
	string fname, lname, message, rFName, rLName;
	int id, answer = 0;
	currUser.getPersonalInfo();
	while (true) {
		message = "Enter name for validate\n";
		fname = answerStringViewer(message, 1, 2, 15);
		message = "Enter surname for validate\n";
		lname = answerStringViewer(message, 1, 2, 15);
		message = "Enter password for validate\n";
		id = answerIntViewer(message, 100000000, 999999999);
		rFName = currUser.getFname();
		rLName = currUser.getLname();

		transform(fname.begin(), fname.end(), fname.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(rFName.begin(), rFName.end(), rFName.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(rLName.begin(), rLName.end(), rLName.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(lname.begin(), lname.end(), lname.begin(), [](unsigned char c) { return std::tolower(c); });

		if (fname == rFName && id == currUser.getId() && lname == rLName)break;
		else {
			message = "Wrong data, please select:\n"
				"1.Try again\n"
				"2.Return to menu\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}

int validateAdmin(Admin currAdmin) {
	string fname, lname, message, rFName, rLName;
	int id, answer = 0;
	currAdmin.getPersonalInfo();
	while (true) {
		message = "Enter name for validate\n";
		fname = answerStringViewer(message, 1, 2, 15);
		message = "Enter surname for validate\n";
		lname = answerStringViewer(message, 1, 2, 15);
		message = "Enter password for validate\n";
		id = answerIntViewer(message, 100000000, 999999999);
		rFName = currAdmin.getFname();
		rLName = currAdmin.getLname();

		transform(fname.begin(), fname.end(), fname.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(rFName.begin(), rFName.end(), rFName.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(rLName.begin(), rLName.end(), rLName.begin(), [](unsigned char c) { return std::tolower(c); });
		transform(lname.begin(), lname.end(), lname.begin(), [](unsigned char c) { return std::tolower(c); });


		if (fname == rFName && id == currAdmin.getId() && lname == rLName)break;
		else {
			message = "Wrong data, please select:\n"
				"1.Try again\n"
				"2.Return to menu\n";
			answer = answerIntViewer(message, 1, 2);
			if (answer == 1) continue;
			else break;
		}
	}
	if (answer == 2) return 0;
	return 1;
}