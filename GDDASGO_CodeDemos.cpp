// GDDASGO_CodeDemos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void program_run(vector<string> input) {
	/*logic of your code to be placed here.
	  Parse vector<string> input to a compatible data type.
	  */
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] + "\n";
	}
}

int main()
{
	//this is an example of how your instructor will test your code by giving at least 3 test cases
	vector<string> strInput;
	strInput.push_back("Blue");
	strInput.push_back("Red");
	strInput.push_back("Orange");
	strInput.push_back("Yellow");

	program_run(strInput);
	cout << "\n";

	strInput.clear();
	strInput.push_back("I");
	strInput.push_back("Love");
	strInput.push_back("GDDASGO!");
	
	program_run(strInput);
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
