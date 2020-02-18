#include "voter.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ifstream inStream;
	ofstream outStream;
	string name;
	int ID;
	string altID;
	vector<Voter> voters;


	inStream.open("input.dat");
	outStream.open("output.dat");
	
	while(!inStream.eof()){
		inStream >> name;
		inStream >> ID;
		inStream >> altID;

		Voter *v = new Voter(name, ID, altID);
		cout << v.getUwfID() << endl;
		voters.push_back(*v);
	}
}
