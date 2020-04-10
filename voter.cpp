#include "voter.hpp"
#include <string>
Voter::Voter(){
	setVoterName("");
	setUwfID(0);
	setAltID("");
	setVoterID();
	setVotingStation();

	countID++;
}

Voter::Voter(std::string name, int ID, std::string altID){
	setVoterName(name);
	setUwfID(ID);
	setAltID(altID);
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

unsigned int Voter::getUwfID(){
	return this->uwfID;	
}

void Voter::setUwfID(unsigned int ID){
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

	for(int i = 0; i < 2; i++){
    	r = rand() % 26;
		c = 'A' + r;
		
		ID += c;
	}
	
	ID += std::to_string(countID);
	
	this->voterID = ID;
}

int Voter::getVotingStation(){
	return this->votingStation;
}

void Voter::setVotingStation(){//randomizes voter station

	int r = rand() % 9 + 1;

	this->votingStation = r;
	
}

std::string Voter::toString(){	
	std::string r =  getVoterName() + " " + std::to_string(getUwfID()) + " " + getAltID() + " " + getVoterID() + " " + std::to_string(getVotingStation());

	return r;
}
