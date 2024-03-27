#include "validationFile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <fstream>

using namespace std;

int validateInt(int ans, int min, int max) {
    if (ans >= min && ans <= max) return 1;
    return 0;
}

string answerStringViewer(string message, int onlyLetters, int min, int max) {
	string answer;
	while (true) {
		cout << message;
		try {
			//cin >> answer;
			cin.get();
			getline(cin, answer);
			if (answer == "") {
				throw invalid_argument("String empty, please try again");
			}
			if (answer.size() < min || answer.size() > max) {
				throw out_of_range("String length error");
			}
			if (onlyLetters) {
				for (char c : answer) {//if onlyLetters = 1(no numbers)
					if (!isalpha(c)) {
						throw invalid_argument("String contains non-letter characters, please try again");
					}
				}
			}
			break;
		}
		catch (const std::invalid_argument& e) {
			cerr << e.what() << endl;
		}
		catch (const out_of_range& e) {
			cerr << e.what()<< ", must be between "<< min << " and " << max << endl;
		}
	}
	return answer;
}


int answerIntViewer(string message, int min, int max) {
	string answerS;
	int answer;
	while (true) {
		cout << message;
		try {
			cin >> answerS;
			answer = stoi(answerS);
			if (!validateInt(answer, min, max)) {
				throw out_of_range("");
			}
			break;
		}
		catch (const invalid_argument& e) {
			cerr << "Input must be an integer, please try again" << endl;
		}
		catch (const out_of_range& e) {
			cerr << "Number must be between " << min << " and " << max << endl;
		}
		catch (...) {
			cerr << "Try again" << endl;
		}

	}
	return answer;
}