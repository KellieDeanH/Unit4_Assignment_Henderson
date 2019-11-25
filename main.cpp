//Kellie Henderson,Dr_T,11/24/19 
//A vector to average grades using a negative number (-0.1) to exit the loop
#include <iostream>
#include <vector>
#include<algorithm>
#include "color.h"
#include<fstream>
#include "Input_Validation_Extended.h"
#include <iomanip>

using namespace std;



void func(double n, vector<double> &gradesVector)
 {
   gradesVector.push_back(n);
   } 

double avg(vector<double> &vec)
{
  double sum = 0.0;
  for(auto &i : vec)
  {
    sum+= i;
  }
  return(sum/vec.size());
}

void print(vector<double> &printVector)
{
  sort(printVector.begin(), printVector.end());
  reverse(printVector.begin(), printVector.end());

   for (int i=0; i<printVector.size(); i++) 
   cout <<"\x1b[" + std::to_string(93) + ";1m" << printVector[i] << " "<<  "\x1b[0m" <<endl ; 

}

void text(vector<double> &printTranscript)
{
   ofstream file;
    file.open("Transcript.txt", ios::trunc);
 
   for (int i=0; i < printTranscript.size(); i++) 
   file << "Grade: "<< printTranscript[i] << endl ; 
    file.close();
    }

int main() 
{
  double g = 0.0;
  char option = '\0';
  vector<double> vect; 
  cout << fixed << setprecision(4) <<endl;
    
do{
  cout << "Enter the grades values that you want to be averaged \n(enter a negative value to stop): " << endl;
  
  while(g > -0.1)
  {
    
    cout << "Enter your Grade: ";
    g = validateDouble(g);
    if( g > -1.0) 
    {
      func(g,vect); 
    }
    
  }


print(vect);
cout << "Average: " <<"\x1b[" + std::to_string(93) + ";1m"<< avg(vect) << "\x1b[0m" << endl;

text(vect);
g = 0.0;
cout << "c to continue or e to exit: ";
option = validateChar(option);
    
  cout << "\033[2J\033[1;1H";
}while(option != 'E' && option != 'e');
  cout << "Bye"; 
 
  return 0;
}

