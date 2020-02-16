#include "voter.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream inputFile;
	ofstream outputFile;
	
	//inputFile.open("input.dat");
	//outputFile.open("output.dat");
	
	Voter v = new Voter();
	
	cout << getVoterID();
	
}
