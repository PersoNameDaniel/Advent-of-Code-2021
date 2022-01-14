#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

//Declaring Variables
int numIncreased = 0;
int total = 0;

//Functions
void compute(int numNew, int numOld) {
	if (numNew > numOld) {
		cout << numNew << " (Increased)" << endl;
		++numIncreased;
	}
	if (numNew < numOld) {
		cout << numNew << " (Decreased)" << endl;
	}
	if (numNew == numOld) {
		cout << numNew << " (Unchanged)" << endl;
	}
}

int main() {

	//Receiving input
	string depthS[2000];
	short loop = 0;
	string line;
	ifstream myfile("day1Input.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			depthS[loop] = line;
			cout << depthS[loop] << endl;
			loop++;
		}
		myfile.close();
		system("echo i");
	}
	else cout << "can't open this file" << endl;


	//Computing data

	for (int i = 0; i <= 1999; i++) {
		if (i == 0) {
			int numNew = atoi(depthS[i].c_str());
			cout << numNew << " (First number)" << endl;
			continue;
		}
		else {
			int numNew = atoi(depthS[i].c_str());
			int numOld = atoi(depthS[i - 1].c_str());
			compute(numNew, numOld);
		}
	}
	


	//part two
	for (int i = 3; i <= 1999; i++) {
		int num1 = atoi(depthS[i - 3].c_str());
		int num2 = atoi(depthS[i - 2].c_str());
		int num3 = atoi(depthS[i - 1].c_str());
		int num4 = atoi(depthS[i].c_str());

		int section1 = (num1 + num2 + num3);
		int section2 = (num2 + num3 + num4);

		if (section1 > section2) {
			cout << section2 << "(Decreased)" << endl;
		}
		if (section2 > section1) {
			cout << section2 << "(Increased)" << endl;
			++total;
		}
		if (section1 == section2) {
			cout << section2 << "(Unchanged)" << endl;
		}
	}
	cout << numIncreased << " values increased" << endl;
	cout << total << " windows increased" << endl;

	return 0;
}