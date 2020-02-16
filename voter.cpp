#include "voter.hpp"

Voter::Voter(){
	setVoterName("");
	setUwfID(0);
	setAltID("");
	setVoterID();
	setVotingStation();

	countID++;
}

int Voter::countID = 100;

std::string Voter::getVoterName(){
	return this->voterName;	
}


void Voter::setVoterName(std::string name){
	this->voterName = name;	
}

int Voter::getUwfID(){
	return this->uwfID;	
}

void Voter::setUwfID(int ID){
	this->uwfID = ID;
}

std::string Voter::getAltID(){
	return this->altID;
}

void Voter::setAltID(std::string ID){
	this->altID = ID;
}

std::string Voter::getVoterID(){
	return this->voterID;
}

void Voter::setVoterID(){ //randomizes voter ID
	char c;
    int r;
	std::string ID = "";
	
	srand (time(NULL));

	for(int i = 0; i < 2; i++){
    	r = rand() % 26;
		c = 'A' + r;
		
		ID += c;
	}
	
	ID += countID;
	countID++;
	
	this->voterID = ID;
}

int Voter::getVotingStation(){
	return this->votingStation;
}

void Voter::setVotingStation(){//randomizes voter station

	
}
