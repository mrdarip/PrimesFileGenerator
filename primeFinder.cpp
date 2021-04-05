/*
	#     #                                     
	##   ## #####  #####    ##   #####  # #####  
	# # # # #    # #    #  #  #  #    # # #    # 
	#  #  # #    # #    # #    # #    # # #    # 
	#     # #####  #    # ###### #####  # #####  
	#     # #   #  #    # #    # #   #  # #      
	#     # #    # #####  #    # #    # # #     
   ==============================================
   
	TITLE:Prime finder

	DESCRIPTION:Finds as much prime numbers as you want

   ==============================================

*/
#include <iostream>
#include <fstream>

using namespace std;



void loadingBar(float val,float min,float max ,int barLength)
{	
	cout << "Loading...  [";
	for (int i = 1; i < ((val-min)/(max-min))*barLength + 1; i++)
	{
		cout<<"#";
	}
	for (int i = 1; i < barLength - ((val-min)/(max-min))*barLength + 1; i++)
	{
		cout<<".";
	}
	cout << "]  "<< ((val-min)/(max-min))* 100 << "%"<< endl;
}





unsigned int primesWanted;
unsigned int possiblePrime=3; //We are going to start searching on the 3
unsigned int primesFound = 1; //We start asigning 2 because later we declare that we have one prime found, the 2

int main(int argc, char* argv[])
{
	ofstream file;
	file.open("primes.txt");
	
	cout <<"Number of primes wanted?:"<< endl << "=========================" << endl;
	cin  >> primesWanted;
	cout << endl << "========================="<< endl; 	//the ======== is just for decoration
	
	int* primes = new int[primesWanted];					// this is an array that contains all primes found
	primes[0]= 2;											// We asign the 2 as the first prime found
	
	
	file<<primes[0]<<"\n";
	
	
	
	while(primesFound < primesWanted)						// this will be executed until all primes wanted are found
	{														//if you delete this, it doesnt work i dont know why
		for (unsigned int i = 1; i <= primesFound; i++)
		{
			if(possiblePrime % primes[i-1])					//if the number that we are searching remainder is 0 when dividing by a prime, thats mean that could be a prime
			{
				if(i == primesFound)						//if i is equal as the number of primes found, that means that that possiblePrime is a prime
				{
					primes[primesFound] = possiblePrime;	//we add it to the prime list
					primesFound++;	
					file <<possiblePrime << "\n";
					if(!(primesFound%100))
					{	
						loadingBar(primesFound,0,primesWanted,25);//we add one because we have added on prime to the list
					}
				}
			}
			else
			{
				break;										//if the number that we are searching remainder is 0 when dividing by a prime, thats mean that is not a prime
			}
		}
		possiblePrime++;									//we continue to the next number to search
	}
	
	/*for (unsigned int i = 0; i < primesFound; i++)
	{
		file <<primes[i] << "\n";
	}*/
	
	file.close();
	system("pause");
	return 0;
}
