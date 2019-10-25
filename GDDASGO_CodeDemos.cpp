// GDDASGO_CodeDemos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//#include <bits/stdc++.h>

using namespace std;
void combiRecur(int index, int k, vector<int> num, vector<int> combi) {
	if (k == 0) {
		for (int i = 0; i < combi.size(); i++) {
			cout << combi[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = index; i <= num.size() - k; i++) {
			combi.push_back(num[i]);
			combiRecur(i + 1, k - 1, num, combi);
			combi.pop_back();
		}
	}
}

void initCombi(int n, int k) {
	vector<int> num;
	vector<int> combi;

	for (int i = 0; i < n; i++) {
		num.push_back(i + 1);
	}

	combiRecur(0, k, num, combi);
}

void problem_p1(string input) {
	stringstream ss;
	int n = 0, k, check; // n = max num // k = num of elements	 
	string temp;

	ss << input;

	while (!ss.eof()) {
		ss >> temp;
		if (stringstream(temp) >> check && n == 0) {
			stringstream(temp) >> n;
		}
		else if (stringstream(temp) >> check)
			stringstream(temp) >> k;
	}

	initCombi(n, k);
}

vector<int> getLine(string input) {
	vector<int> temp;
	string num;
	stringstream check(input);

	while (getline(check, num, ' ')) {
		temp.push_back(atoi(num.c_str()));
	}

	return temp;
}

void initBox(vector <int> num, vector<int> converted) {
	int box[3];
	bool fit;

	for (int i = 0; i < num[0]; i++) {
		fit = true;
		for (int j = 0; j < 3; j++) {
			box[j] = converted[((3 * i) + j)];
			if (box[j] > 20) {
				fit = false;
			}
			cout << box[j] << " ";
		}
		if (fit) {
			cout << "CAN FIT\n";
		}
		else {
			cout << "CANNOT FIT\n";
		}
	}
}

void problem_p2(vector<string> input) {
	vector<int> converted;
	vector<int> num;
	vector<int> temp;

	num = getLine(input[0]);

	input.erase(input.begin());

	for (int i = 0; i < num[0]; i++) {
		temp = getLine(input[i]);
		for (int j = 0; j < 3; j++) {
			converted.push_back(temp[j]);
		}
	}

	initBox(num, converted);
}

void checkHarvest(vector <int> converted1, vector<int> converted2) {
	int sum = 0, req = 0;

	cout << "Number of villages: " << converted1[0] << "\n";
	cout << "cost: " << converted1[1] << "\n";

	req = converted1[0] * converted1[1];

	for (int i = 0; i < converted2.size(); i++) {
		sum += converted2[i];
		cout << converted2[i] << " ";
	}
	cout << "\n";

	if (req > sum) {
		cout << "NOT ENOUGH FOOD";
	}
	else if (req == sum) {
		cout << "JUST ENOUGH FOR EVERYONE";
	}
	else {
		cout << "PARTY!";
	}
}

void problem_p3(vector<string> input) {
	vector<int> converted1;
	vector<int> converted2;
	int temp, n, m, check, count = 0;

	converted1 = getLine(input[0]);
	converted2 = getLine(input[1]);

	checkHarvest(converted1, converted2);
}

int main()
{
	//this is an example of how your instructor will test your code by giving at least 3 test cases
	vector<string> strInput;
	strInput.push_back("5 3");
	strInput.push_back("6 3");
	strInput.push_back("4 3");
	cout << "=========================================\n";
	cout << "#1 - Test 1 \n\n";
	problem_p1(strInput[0]);
	cout << "\n";

	cout << "#1 - Test 2 \n\n";
	problem_p1(strInput[1]);
	cout << "\n";

	cout << "#1 - Test 3 \n\n";
	problem_p1(strInput[2]);
	cout << "\n";

	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("4");
	strInput.push_back("20 20 21");
	strInput.push_back("1 21 1");
	strInput.push_back("21 1 1");
	strInput.push_back("50 50 50");
	cout << "#2 - Test 1 \n\n";
	problem_p2(strInput);
	cout << "\n";

	strInput.clear();
	strInput.push_back("4");
	strInput.push_back("5 5 5");
	strInput.push_back("10 10 15");
	strInput.push_back("5 4 3");
	strInput.push_back("1 2 20");
	cout << "#2 - Test 2 \n\n";
	problem_p2(strInput);
	cout << "\n";

	strInput.clear();
	strInput.push_back("4");
	strInput.push_back("4 4 4");
	strInput.push_back("4 21 8");
	strInput.push_back("3 12 19");
	strInput.push_back("13 24 9");
	cout << "#2 - Test 3 \n\n";
	problem_p2(strInput);
	cout << "\n";
	
	cout << "=========================================\n";

	strInput.clear();
	strInput.push_back("5 500");
	strInput.push_back("100 0 300 100 100");
	cout << "#3 - Test 1 \n\n";
	problem_p3(strInput);
	cout << "\n";

	strInput.clear();
	strInput.push_back("5 500");
	strInput.push_back("1500 0 500 0 500");
	cout << "#3 - Test 2 \n\n";
	problem_p3(strInput);
	cout << "\n";

	strInput.clear();
	strInput.push_back("5 200");
	strInput.push_back("1000 100 100 100 100");
	cout << "#3 - Test 3 \n\n";
	problem_p3(strInput);
	cout << "\n";
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
