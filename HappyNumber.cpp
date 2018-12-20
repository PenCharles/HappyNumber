#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

	//Author: James Saylor
	//Description : This program will prompt user for 2 pos numbers. The first num
	//must be equal or less than the second num. The program will then
	//cycle through sequence to determine if the number is happy or
	//unhappy

//global constants
const int MIN = 1;	//smallest num a user can enter
const int MAX = 9999;	//largest num a user can enter

//function prototypes
void VerifyNum (int& lowNum, int& highNum); //verify input based on MIN and MAX
bool HappyNum (int num);		   //calc and display num in sequence
											

int main ()
{
	//local variables
	int lowNum;	//lowest user num in the sequence
	int highNum;	//highest user num in the sequence
	bool happy;	//indicates a happy or unhappy num
	
	cout << endl << "This program will test for happy numbers" << endl << endl;
	VerifyNum (lowNum, highNum);
	
	do			//do...while loop will cycle through all num
	{
		happy = HappyNum(lowNum);
		lowNum++;
		
	} while (lowNum <= highNum);

 	cout << endl << endl;
 	return 0;
}

void VerifyNum (int& lowNum, int& highNum)
{
	do
	{
		cout << "Please enter a number that is greater than " << MIN << ":";
		cin >> lowNum;
		cout << endl;
		
		if (lowNum < MIN || lowNum > MAX)
			cout << "The number you have entered is out of range. Try again." << endl << endl;
			
	} while (lowNum < MIN || lowNum > MAX);
	
	do
	{
		cout << "Please enter a second number that is less than " << MAX << ":";
		cin >> highNum;
		cout << endl;
		
		if (highNum < lowNum || highNum > MAX)
			cout << "The number you have entered is out of range. Try again." << endl << endl;
			
	}while (highNum < lowNum || highNum > MAX);
	
}

bool HappyNum (int num)
{	  
	int sum = 0;      //holds the num to be used next in the seq
	int numSplit; 	  //the last digit in the num var used to calc the next num in the seq
	int term = 1;  	  //counts the sums computed for each test seq
	bool happy;
	
	cout << "Test sequence for " << num << " is:" << endl;
	cout << setw(8) << num;					//must see the first num in the seq
	do
	{
		do						//this do...while loop splits the 
		{						//numbers up and then performs math
			numSplit = num % 10;			//calc to see if they are happy
			sum = sum + pow(numSplit, 2);
			num = num / 10;	
		} while (num >= 1);
	
		term++;
	
		cout << setw(8) << sum;
			
		if (sum == 1)	//if the sum calc equals 1 than it is happy
			{
				cout << endl << term << " sequence terms computed" << endl << endl;
				cout << "The above sequence of numbers is happy" << endl << endl;
				happy = true;
				system("pause");
				cout << endl << endl << endl;
			}
		else if(sum != 1 && term == 50) //if the sum != 1 and terms counted to 50
			{							//then is it unhappy		
				cout << endl << term << " sequence terms computed" << endl << endl;
				cout << "The above sequence of numbers is unhappy" << endl << endl;
				happy = false;
				system("pause");
				cout << endl << endl << endl;
			}
			
		num = sum;	//sum value is transfered to num so calc are correct in inner do...while
		sum = 0;	//sum is set to 0 so calc are correct in in inner do...while
	
	}while (num != 1 && term != 50);	//this func must keep running if the num	
										//var from the inner do...while loop != 1					
	return happy;						//and the terms counted are less than 50
}
