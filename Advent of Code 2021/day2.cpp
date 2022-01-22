#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
	string direction[1000];		//Reading input from file (someone else's code, idk)
	short loop = 0;
	string line;
	ifstream myfile("day2Input.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			direction[loop] = line;
			cout << direction[loop] << endl;
			loop++;
		}
		myfile.close();
		system("echo file closed");
	}
	else cout << "can't open this file" << endl;

	//Declaring variables
	int variableLength;		//length of the selected variable within the array
	char distance;			//distance value of the selected variable within the array
	int position = 0;		//current position of the submarine
	int depth = 0;			//current depth of the submarine
	int answer;				//the final answer for problem position multiplied by depth


	for (int arrayCounter = 0; arrayCounter <= 999; arrayCounter++) {		//for loop running once per array value
		variableLength = direction[arrayCounter].size();					//counting the number of characters in array value
		if (variableLength == 4) {											//creating up if loop
			distance = direction[arrayCounter].at(3);						//getting the distance value from string
			depth = depth - distance;										//subtracting value to depth
			cout << "<up> " << distance << endl;						//debug output
		}
		if (variableLength == 6) {							//creating down if loop
			distance = direction[arrayCounter].at(5);		//getting distance value from string
			depth = depth + distance;						//adding value from depth
			cout << "<down> " << distance << endl;			//debug output
		}
		if (variableLength == 9) {								//creating forward if loop
			distance = direction[arrayCounter].at(8);			//getting distance value from string
			position = position + distance;						//adding value to distance
			cout << "<forward> " << distance << endl;			//debug output
		}
		if (variableLength != 4 && variableLength != 6 && variableLength != 9) {		//if loop checking for any values with wrong length
			cout << "Variable Length is: " << variableLength << endl;					//outputting variable length that caused error
			cout << "Error" << endl;													//outputting "error"
			break;																		//stopping code
		}
	}
	answer = position * depth;										//setting answer variable to answer to probelm
	cout << "position is: " << position << endl;					//debug position output
	cout << "depth is: " << depth << endl;							//debug depth output
	cout << "puzzle answer is: " << answer << endl;					//puzzle output

	return 0;
}
