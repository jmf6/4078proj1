#ifndef VOTER_HPP
#define VOTER_HPP

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

class Voter{
	private:
		std::string voterName;
		unsigned int uwfID;
		std::string altID;
		std::string voterID;
		int votingStation;
		static int countID;
		
		
	public:
		Voter();
		Voter(std::string name, int ID, std::string altID);
		std::string getVoterName();
		void setVoterName(std::string name);
		unsigned int getUwfID();
		void setUwfID(unsigned int ID);
		std::string getAltID();
		void setAltID(std::string altID);
		std::string getVoterID();
		void setVoterID(); //randomizes voter ID
		int getVotingStation();
		void setVotingStation();//randomizes voter station
		std::string toString();
};

#endif
