#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

int branches=0;
int branchT=0;
int branchTC=0;
int branchN=0;
int branchNC=0;
int branchP;
int hashtable[64];

void countlines (){
	std::string line;
	std::ifstream input("branch_trace.dat");
	while (std::getline(input, line)){
		branches++;
	}
	input.close();
}	

bool checkhash(int branch){
	if (hashtable[branch%64] < 2){ return false; }
	else return true;
}

void trace(){
	bool lastPath = true;
	std::string branch;
	std::string takeuntake;

	std::ifstream input("branch_trace.dat");
	bool hashed;
	bool correctpath;
	int instruction;
	int switchcase;

	while (std::getline(input,branch,' ')){
		std::getline(input,takeuntake,'\n');
		instruction = atoi(branch.c_str());
		hashed = checkhash(instruction);
		if (takeuntake == "T"){correctpath=true;}
		else correctpath=false;

		if (hashed){ branchT++;}
		if (!hashed){ branchN++;}

		if (hashed && correctpath){switchcase=0;}
		else if (hashed && !correctpath){switchcase=1;}
		else if ( !hashed && !correctpath){switchcase=2;}
		else if ( !hashed && correctpath){switchcase=3;}

		switch(switchcase){
    			case 0:
       				branchTC++;
				hashtable[instruction%64]++;
       				break;
    			case 1:
      				hashtable[instruction%64]--;
       				break;
    			case 2:
      				branchNC++;
				hashtable[instruction%64]--;
       				break;
    			case 3:
      				hashtable[instruction%64]++;
       				break;
		}
		branches++;
	}
	input.close();

}

void getpercent(){
	//std::cout << branchTC << " " << branchNC << " " << branches << std::endl;
	double branchC = branchTC+branchNC;
	double totalbranches = branches;
	//std::cout << branchC+totalbranches << std::endl;
	branchP = (branchC/totalbranches)*100;
}

int main(){
	for (int i=0; i<64; i++){
		hashtable[i]=2;
	}

	//countlines();
	trace();
	getpercent();

	std::cout << "Number of Branches: " << branches << std::endl;
	std::cout << "Numberof branches taken: " << branchT << std::endl;
	std::cout << "	Number taken branches correctly predicted: " << branchTC << std::endl;
	std::cout << "Number of branches not taken: " << branchN << std::endl;
	std::cout << "	Number not taken branches correctly predicted: " << branchNC << std::endl << std::endl;
	std::cout << "Overall rate of correct predictions: " << branchP << "%" << std::endl;
	
	return 0;
}
