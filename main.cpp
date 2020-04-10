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
	unsigned int UwfID;
	string altID;
	string temp;
	vector<Voter> voters;

	srand(time(0));
	
	inStream.open("input.dat");
	outStream.open("output.dat");

	while(!inStream.eof()){
		inStream >> name;
		inStream >> temp;
		inStream >> altID;
		
		bool test = false;

		try{
                        UwfID = stoul(temp);
                }
                catch(invalid_argument& a){
                        UwfID = 0;
                        test = true;
                }
                catch(out_of_range& o){
                        UwfID = 0;
                        test = true;
                }

                for(unsigned int i = 0; i < voters.size(); i++){
                        if(UwfID == voters.at(i).getUwfID()){
                               test = true;
                        }
                }

                if(name.length() >= 500){
                        test = true;
                }
                else if(altID.length() >= 500){
                        test = true;
                }
                else if(altID == ""){
                        test = true;
                }
                else if(UwfID < 100000 || UwfID > 999999){
                        test = true;
                }

                if(!test){
                        Voter v = Voter(name, UwfID, altID);
			for(unsigned int i = 0; i < voters.size(); i++){
                                if(v.getVoterID() == voters.at(i).getVoterID()){
                                        v.setVoterID();
                                }
                        }
                        voters.push_back(v);
                        outStream << v.toString() << endl;
                }
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
	
        	getline(cin, temp);

        	cout << "Alternate ID> ";
        	//cin.ignore();
        	getline(cin, altID);

		try{
                        UwfID = stoul(temp);
                }
                catch(invalid_argument& a){
			UwfID = 0;
                        invalid = true;
                }
                catch(out_of_range& o){
                       	UwfID = 0;
		       	invalid = true;
                }

        	for(unsigned int i = 0; i < voters.size(); i++){
        		if(UwfID == voters.at(i).getUwfID()){
                               invalid = true;
                        }
                }

        	if(name.length() >= 500){
        		invalid = true;
        	}
        	else if(altID.length() >= 500){
        		invalid = true;
        	}
        	else if(altID == ""){
        		invalid = true;
        	}
        	else if(UwfID < 100000 || UwfID > 999999){
        		invalid = true;
        	}

        	if(!invalid){
        		Voter v = Voter(name, UwfID, altID);
			for(unsigned int i = 0; i < voters.size(); i++){
				if(v.getVoterID() == voters.at(i).getVoterID()){
					v.setVoterID();
				}
			}
        			voters.push_back(v);
        			outStream << v.toString() << endl;
				 cout << v.getVoterName() << " is assigned VoterID " << v.getVoterID() << " at Voting Station " << v.getVotingStation() << endl;
		}

		else{
			cout << "Invalid input" << endl;
		}
	}while(name != "");
	return 0;
}
