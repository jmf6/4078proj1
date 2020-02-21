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
	int UwfID;
	string altID;
	string temp;
	vector<Voter> voters;

	srand(time(0));
	
	inStream.open("input.dat");
	outStream.open("output.dat");

	while(!inStream.eof()){
		inStream >> name;
		inStream >> UwfID;
		inStream >> altID;
	
		Voter v = Voter(name, UwfID, altID);
		voters.push_back(v);
		outStream << v.toString() << endl;
		cout << v.toString() << endl;
	}

	cout << "Welcome to Voting Registration" << endl;
	do{
		bool invalid = false;

	        cout << "Name> ";
        	getline(cin, name);

	        if(name == ""){
		        cout << "Program terminated" << endl;
		        return 0;
	        }
	        cout << "6 digit UWF ID> ";
	        cin >> UwfID;
	
        	//getline(cin, temp);
        	//do something with this to check if positive integer
        	cout << "Alternate ID> ";
        	cin.ignore();
        	getline(cin, altID);
        	for(int i = 0; i < voters.size(); i++){
        		if(UwfID == voters.at(i).getUwfID()){
        		       cout << "Invalid input" << endl;
                               invalid = true;
                        }
                }

        	if(name.length() >= 500){
        		cout << "Invalid input" << endl;
        		invalid = true;
        	}
        	else if(altID.length() >= 500){
        		cout << "Invalid input" << endl;
        		invalid = true;
        	}
        	else if(altID == ""){
        		cout << "Invalid input" << endl;
        		invalid = true;
        	}
        	else if(UwfID < 100000 || UwfID > 999999){
        		cout << "Invalid input" << endl;
        		invalid = true;
        	}
        	//need to check for non-numeric input
        	//need to check for overflow for int value
        	//need to check for negative input
        	
        	if(!invalid){
        		Voter v = Voter(name, UwfID, altID);
        		voters.push_back(v);
        		outStream << v.toString() << endl;
        		cout << v.toString() << endl;
        	}
	}while(name != "");
	return 0;
}
