// P3_Villanueva.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Christian Garret U. Villanueva X-22 11839775 GD-DASGO

#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// PROBLEM 1
void problem_p1(vector<string> input) {
	int i, j, nFlag, nTestcases = 0, nStringLenght = 0;
	string strHolder;
	char cHolder;
	stack<char> stkParen;

	stringstream ssTestcases(input[0]);
	ssTestcases >> nTestcases;

	// Conditions
	if (nTestcases <= input.size() - 1) {
		for (i = 1; i <= nTestcases; i++) {

			nFlag = 1;

			while (!stkParen.empty()) {
				stkParen.pop();
			}

			nStringLenght = input[i].size();

			if (nStringLenght <= 128) {
				strHolder = input[i];

				for (j = 0; j < nStringLenght; j++)
				{
					if (strHolder[j] == '(' || strHolder[j] == '[')
						stkParen.push(strHolder[j]);

					if (stkParen.empty()) {
						cout << "No" << endl;
						nFlag = 0;
					}

					else
					{
						if (strHolder[j] == ')') {
							if (stkParen.top() == '(')
								stkParen.pop();
							else
								cout << "No";
						}

						if (strHolder[j] == ']') {
							if (stkParen.top() == '[')
								stkParen.pop();
							else
								cout << "No";
						}
					}
				}
				if (nFlag == 1 && stkParen.empty())
					cout << "Yes" << endl;
				else if (nFlag == 1)
					cout << "No" << endl;
			}
			else
				cout << "EXCEEDED MAXIUMUM STRING INPUT! \n\n";
		}
	}
	else
		cout << "THE NUMBER OF TESTCASES ARE NOT WITHIN THE RANGE OF THIS CODE! \n\n";
}

// PROBLEM 2
void problem_p2(vector<string> input) {
	int i, nN = 0, nT = 0, nM = 0;
	queue<int> queFerry;

	stringstream ssInput(input[0]);
	ssInput >> nN >> nT >> nM;

	vector<int> nCarWaitTimeStorage(nM);
	vector<string> sCommandStorage(nM);

	if (input.size() - 1 <= nM && nM <= 10000) {
		for (i = 1; i < input.size(); i++)
		{
			//qFerry
			stringstream ssCommand(input[i]);
			ssCommand >> nCarWaitTimeStorage[i - 1] >> sCommandStorage[i - 1];
		}




	}
	else
		cout << "NOT WITHIN THE LIMIT!" << endl;
}

// PROBLEM 3
void problem_p3(string input) {
	int nLenght = 1, nInput = 0, nTemp = 0, nFlag = 0;
	stack<int> stkInput;
	stringstream ssInput(input);

	if (input.length() > 0) {
		for (int i = 0; input[i] != '\0'; i++) // Gets lenght without spaces 
		{
			if (input[i] == ' ')
				nLenght++;
		}

		vector<int> nArray(nLenght);
		vector<int> nArrayInc(nLenght);
		vector<int> nArrayDec(nLenght);

		if (nLenght <= 1000)
		{
			for (int i = 0; i < nLenght; i++) // converts string into int then, it will be put to nArray & stkInput
			{
				ssInput >> nInput;
				nArray[i] = nInput;
				stkInput.push(nInput);
			}

			nTemp = nArray[0];
			for (int i = 0; i < nLenght; i++) // Decrementing by 1
			{
				nArrayDec[i] = nTemp;
				nTemp--;
			}

			nTemp = nArray[0];
			for (int i = 0; i < nLenght; i++) // Incrementing by 1
			{
				nArrayInc[i] = nTemp;
				nTemp++;
			}

			for (int i = 0; i < nLenght; i++)
			{
				if (nArray[i] == nArrayDec[i] || nArray[i] == nArrayInc[i]) // Checks if Input is the same as nArrayDec or nArrayInc
				{
					nFlag = 0;
					stkInput.pop();
				}

				else
				{
					nFlag = 1;
					break;
				}
			}

			if (nFlag == 0 && stkInput.empty())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	else
		cout << "THERE IS NO INPUT!";
}



int main() {
	//this is an example of how your instructor will test your code by giving at least 3 test cases
	vector<string> strInput;
	strInput.push_back("3");
	strInput.push_back("([])");
	strInput.push_back("(([()])))");
	strInput.push_back("([()[]()])()");
	cout << "=========================================\n";
	cout << "#1 - Test 1 \n\n";

	problem_p1(strInput);

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("2 10 10");
	strInput.push_back("0 left");
	strInput.push_back("10 right");
	strInput.push_back("20 left");
	strInput.push_back("30 left");
	strInput.push_back("40 right");
	strInput.push_back("50 left");
	strInput.push_back("60 left");
	strInput.push_back("70 left");
	strInput.push_back("80 right");
	strInput.push_back("90 right");

	cout << "#2 - Test 1 \n\n";
	problem_p2(strInput);
	cout << "\n";

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("1 2 3 4 5 6 7 8 9 20");
	strInput.push_back("5 4 1 2 3");
	strInput.push_back("10 9 8 7 6 5 4 3 2 1");
	cout << "#3 - Test 1 \n\n";
	problem_p3(strInput[0]);
	cout << "\n";

	cout << "#3 - Test 2 \n\n";
	problem_p3(strInput[1]);
	cout << "\n";

	cout << "#3 - Test 3 \n\n";
	problem_p3(strInput[2]);
	cout << "\n";
}

