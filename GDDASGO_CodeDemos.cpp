// P5_Villanueva.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

void problem_p1(vector<string> input) {

	int nTemp = 0, nHolder = 0, nInputSize = 0;
	bool isfound = 0;
	vector<int> nInput;
	unordered_set <int> mHashtable;
	unordered_map <int, int> mStorage;
	stringstream ssInput(input[0]);

	ssInput >> nInputSize;
	// parse ssInput
	stringstream ssArray(input[1]);
	for (int i = 0; i < nInputSize; i++) {
		ssArray >> nHolder;
		nInput.push_back(nHolder);
	}

	// Algorithm for Zero Sum Triplet
	for (int i = 0; i < nInputSize; i++) {
		for (int j = 1 + i; j < nInputSize; j++) {
			nTemp = -(nInput[i] + nInput[j]);
			if (mHashtable.find(nTemp) != mHashtable.end()) { // found
				isfound = 1;
				mStorage[0] = nTemp;
				mStorage[1] = nInput[i];
				mStorage[2] = nInput[j];
			}
		}
		mHashtable.insert(nInput[i]);
	}

	if (isfound != 1) {
		cout << "NONE" << endl;
	}

	else {
		cout << mStorage[0] << " " << mStorage[1] << " " << mStorage[2] << endl;
	}
}

void problem_p2(vector<string> input) {
	int nInputSize = 0, nHolder = 0;
	vector<int> nInput;
	set <vector<int>> Stubborn_Pikachu;
	stringstream ssInput(input[0]);
	ssInput >> nInputSize;
	// parse ssInput
	stringstream ssArray(input[1]);
	for (int i = 0; i < nInputSize; i++) {
		ssArray >> nHolder;
		nInput.push_back(nHolder);
	}

	// Algorithm for The Electric Type Problem
	for (int i = 0; i < nInputSize; i++) {
		for (int j = i + 1; j < nInputSize; j++)
			Stubborn_Pikachu.insert({ nInput[i] , nInput[j] });
	}
	cout << Stubborn_Pikachu.size() << endl;
}

void problem_p3(vector<string> input) {

	int nInputSize = 0, nHolder = 0, nDays = 0;
	bool compared;
	unordered_map<int, int> mListOfDays;

	stringstream ssInput(input[0]);
	ssInput >> nInputSize;

	// parse ssInput
	stringstream ssArray(input[1]);
	for (int i = 0; i < nInputSize; i++) {
		ssArray >> nHolder;
		mListOfDays.insert({ i,nHolder });
	}

	// Algorithm for Daily Temperatures
	for (int i = 0; i < nInputSize; i++) {
		compared = false;
		nDays = 1;
		for (int j = i + 1; j < nInputSize; j++) {
			if (compared != true) {
				//cout << mListOfDays[i] << " " << mListOfDays[j] << endl;
				if (mListOfDays[i] > mListOfDays[j])
					nDays++;
				else
					compared = true;
			}
		}
		if (compared == false)
			cout << "0" << " ";
		else
			cout << nDays << " ";
	}
}


//for (auto i = Hashtable.begin(); i != Hashtable.end(); i++) { // check
//	cout << i->first << " : " << i->second << endl;
//}

int main() {
	//this is an example of how your instructor will test your code by giving at least 3 test cases
	vector<string> strInput;
	strInput.push_back("7");
	strInput.push_back("-13 0 4 3 2 1 13");
	cout << "=========================================\n";

	cout << "#1 - Test 1 \n\n";
	problem_p1(strInput);
	cout << "\n";

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("8");
	strInput.push_back("1 2 3 4 5 6 7 8");

	cout << "#2 - Test 1 \n\n";
	problem_p2(strInput);
	cout << "\n";

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("8");
	strInput.push_back("40 37 32 10 8 12 40 40");
	cout << "#3 - Test 1 \n\n";
	problem_p3(strInput);
	cout << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

