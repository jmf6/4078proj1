#ifndef VOTER_HPP
#define VOTER_HPP

#include <string>
#include <vector>

class Voter{
	private:
		std::string voterName;
		int uwfID;
		std::string altID;
		std::string voterID;
		int votingStation;
		static int countID;
		
		
	public:
		Voter();
		Voter(std::string name, int ID, std::string altID);
		std::string getVoterName();
		void setVoterName(std::string name);
		int getUwfID();
		void setUwfID(int ID);
		std::string getAltID();
		void setAltID(std::string altID);
		std::string getVoterID();
		void setVoterID(); //randomizes voter ID
		int getVotingStation();
		void setVotingStation();//randomizes voter station
};

#endif
