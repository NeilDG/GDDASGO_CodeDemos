#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

void problem_p1(string input) {
	int nMostLetterCount = 0, nCounter = 0, nIndex = 0;
	char cLetter;
	string sStorage, sHolder;
	vector<int> nLetterTally(26);

	for (int i = 0; i < 26; i++)
		nLetterTally[i] = 0;

	for (int i = 0; i < input.length(); i++) {
		if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
			input[i] = tolower(input[i]);
			nLetterTally[input[i] - 97] = nLetterTally[input[i] - 97] + 1;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (nLetterTally[i] > 0)
			nCounter++;
	}

	for (int i = 0; i < nCounter; i++) {
		nMostLetterCount = 0;
		for (int j = 0; j < 26; j++) {
			if (nMostLetterCount < nLetterTally[j]) {
				nIndex = j;
				nMostLetterCount = nLetterTally[j];
			}
		}
		cLetter = nIndex + 97;
		cout << (char)(toupper(cLetter)) << " " << nMostLetterCount << endl;
		nLetterTally[nIndex] = 0;
	}
	cout << endl;
}

void problem_p2(vector<string> input) {
	int nUserInput_TrainLenght = 0, nIndex = 0, nHolder = 0, nNumberOfSwaps = 0;
	vector<int> nTrainLenght;

	stringstream ssLenght(input[0]);
	ssLenght >> nUserInput_TrainLenght;

	stringstream ssArray(input[1]);
	for (int i = 0; i < nUserInput_TrainLenght; i++) {
		ssArray >> nHolder;
		nTrainLenght.push_back(nHolder);
	}

	if (nTrainLenght.size() >= 0 && nTrainLenght.size() <= nUserInput_TrainLenght) {
		nHolder = 0;
		for (int i = 0; i < nUserInput_TrainLenght; i++)
		{
			nIndex = nUserInput_TrainLenght - 1;
			nHolder = nIndex;
			for (int j = nHolder; j > -1; j--) {
				if (0 < nIndex && nTrainLenght[nIndex - 1] > nTrainLenght[nIndex]) {
					swap(nTrainLenght[nIndex], nTrainLenght[nIndex - 1]);
					nNumberOfSwaps++;
				}
				nIndex--;
			}
		}
		cout << "The most optimal train swaps: " << nNumberOfSwaps << endl;
	}

	else
		cout << "NOT WITHIN THE GIVEN LIMIT!" << endl;
}


void problem_p3(vector<string> input) {
	int nHighest = 0, nNumInput = 0, nTemp = 0, nTemp2 = 0, nTemp3 = 0, nIdx = 0;

	stack<int> nBuildingFloors;
	vector<int> nInput;
	vector<int> nSortedInput;

	stringstream ssNumInput(input[0]);
	ssNumInput >> nNumInput;

	if (nNumInput > 0 && nNumInput < 500000) {
		for (int i = 0; i < nNumInput; i++) {
			stringstream ssInput(input[i + 1]);
			ssInput >> nTemp;
			nInput.push_back(nTemp);
		}

		for (int j = 0; j < nNumInput; j++) {
			nHighest = 0;
			for (int i = 0; i < nNumInput; i++) {
				if (nInput[i] >= -999999 && nInput[i] <= 999999) {
					if (nInput[i] < 0 && nHighest <= 0) { // if both negative
						nTemp2 = -1 * nInput[i];
						nTemp3 = -1 * nHighest;
						if (nTemp2 > nTemp3) {
							nHighest = nInput[i];
							nIdx = i;
						}
						nTemp2 = 0;
						nTemp3 = 0;
						//cout << nHighest << endl;
					}

					else if (nInput[i] > 0 && nHighest > 0) { // if both positive
						if (nInput[i] > nHighest) {
							nHighest = nInput[i];
							nIdx = i;
						}
						//cout << nHighest << endl;
					}

					else if (nInput[i] > 0 && nHighest <= 0) { // if nInput is positive & nHighest is negative
						nTemp2 = -1 * nHighest;
						if (nInput[i] > nTemp2) {
							nHighest = nInput[i];
							nIdx = i;
						}
						nTemp2 = 0;
						//cout << nHighest << endl;
					}

					else if (nInput[i] < 0 && nHighest > 0) { // if nInput is negative & nHighest is positive
						nTemp2 = -1 * nInput[i];
						if (nTemp2 > nHighest) {
							nHighest = nInput[i];
							nIdx = i;
						}
						nTemp2 = 0;
						//cout << nHighest << endl;
					}
				}
			}
			nInput[nIdx] = 0;
			if (nBuildingFloors.empty())
				nBuildingFloors.push(nHighest);

			else if (!nBuildingFloors.empty()) {
				if (nBuildingFloors.top() > 0) {
					if (nHighest < 0)
						nBuildingFloors.push(nHighest);
				}
				else if (nBuildingFloors.top() < 0) {
					if (nHighest > 0)
						nBuildingFloors.push(nHighest);
				}
			}
		}
		cout << nBuildingFloors.size() << endl;
	}

	else
		cout << "NOT WITHIN THE GIVEN LIMIT!" << endl;
}


int main()
{
	vector<string> strInput;
	strInput.push_back("Count me 1 2 3 4 5! Wow! I love ALGOCOM!");

	cout << "=========================================\n";
	cout << "#1 - Test 1 \n\n";

	problem_p1(strInput[0]);

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("9");
	strInput.push_back("4 3 2 1 5 6 7 8 9");

	cout << "#2 - Test \n\n";
	problem_p2(strInput);
	cout << "\n";

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("7");
	strInput.push_back("3");
	strInput.push_back("-4");
	strInput.push_back("-9");
	strInput.push_back("6");
	strInput.push_back("-2");
	strInput.push_back("6");
	strInput.push_back("7");

	cout << "#3 - Test \n\n";
	problem_p3(strInput);
	cout << "\n";

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
