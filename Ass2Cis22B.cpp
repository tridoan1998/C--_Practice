//============================================================================
// Name        : Ass2Cis22B.cpp
// Author      : Tri Doan
// Version     : n+1
// Copyright   : All rights
// Description : Assisgnment for CIS 22B class
//CTRL + SHIFT + L
//Shows you a list of your currently defined shortcut keys.
//============================================================================


#include <iostream>
#include <string>
#include <iomanip>	// std::setprecision
#include <stdlib.h>	//stand, rand
#include <time.h>	//time
#include <fstream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <fstream>

using namespace std;

void Question13_Chapter5();
void Question17_Chapter5();
void Question18_Chapter5();
void Question20_Chapter5();
void Question22_Chapter5();
void Question23_Chapter5();
void Question24_Chapter5();
void test(int &a, int &b);
double Question1_Chapter6(double wholesale_cost, double markup_percentage);
double Question3_Chapter6(double Northeast, double Southeast, double Northwest, double Southwest);
double getSales();
//is passed the name of a region. It asks the user for the
//number of automobile accidents reported in that region during the last year, validates
//the input, then returns it. It should be called once for each city region.
int getNumAccidents();
//is passed the five accident totals. It determines which is the
//smallest and prints the name of the region, along with its accident figure.
//void findLowest(int north, int south, int east, int west, int central);
//this function take in the time as second and return the distance in meter.
int fallingDistance(int seconds);

//should ask the user for a test score, store it in a reference parameter
//variable, and validate it. This function should be called by main once for each
//of the five scores to be entered
void getScore(int &test_score);

//should calculate and display the average of the four highest
//scores. This function should be called just once by main and should be passed the
//five scores.
void calcAverage(int &test_score1, int &test_score2, int &test_score3, int &test_score4, int &test_score5);

//should find and return the lowest of the five scores passed to it.
//It should be called by calcAverage, which uses the function to determine which of
//the five scores to drop.
int findLowest(int &test_score1, int &test_score2, int &test_score3, int &test_score4, int &test_score5);

int main()
{
	int test_score1 = 0;
	int test_score2 = 0;
	int test_score3 = 0;
	int test_score4 = 0;
	int test_score5 = 0;

	getScore(test_score1);
	getScore(test_score2);
	getScore(test_score3);
	getScore(test_score4);
	getScore(test_score5);

	calcAverage(test_score1, test_score2, test_score3, test_score4, test_score5);


	return 0;
}

void Question13_Chapter5()
{
	int number;
	int higher;
	cin >> number;	//number = 2
	higher = number;	// higher = number = 2
	do{

		cin >> number;	// number = 3
		if(higher < number) //2 < 3
		{
			higher = number; // higher = 3
		}
		else
			continue;		//keep hgiher the same
	}while(number != -99);

	cout << higher;
}

void Question17_Chapter5()
{
	int store[5];
	int count;
	int result[5];
	for (int i = 0; i < 5; i++)
	{
		count = 0;
		cout << "Enter today's sales for store " << i+1 << ":";
		cin >> store[i];
		while(store[i] > 0)
		{
			store[i] -= 100;
			count += 1;
		}
		result[i] = count;
	}

	cout << endl;
	cout <<"SALES BAR CHART\n(Each * = $100)" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Store " << i+1 << ": ";
		for (int j = 0; j < result[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void Question18_Chapter5()
{
	ifstream file;
	int year, population;
	int count = 0;
	int calculation[5];
	file.open("People.txt");
	if(file.is_open())
	{
		cout << "PRAIRIEVILLE POPULATION GROWTH\n(each * represents 1,000 people)" << endl;
		while(!file.eof())
		{
			file >> year >> population;
			calculation[count] = population/1000;
			cout << year << " ";
			for (int i = 0; i< calculation[count]; i++)
			{
				cout << "*";
			}
			cout << endl;
			count += 1;
		}
	}
	else
	{
		cout << "Error!!!";
		exit(true);
	}
	file.close();

}

void Question20_Chapter5()
{
	//declare a random variable
	int random_number = rand()%100 +10;

	//input variable from user to guess the random number
	int user_guess;
	cout << "Please enter your guess for the number: ";
	cin >> user_guess;

	//amount times the user can guess the number
	int count = 0;
	while(user_guess != random_number)
	{
		if(user_guess > random_number)
		{
			cout <<"Go lower";
			cin >> user_guess;
		}
		else
		{
			cout << "Go higher";
			cin >> user_guess;
		}
		count += 1;
		//this if statement won't run until count reach 10
	}
	cout << "Correct";
	cout << count << " is the amonut of times you took you guess.";
}

void Question22_Chapter5()
{
	int number;
	do
	{
		cout <<"Enter a number no greater than 15: ";
		cin >> number;
	}while(number > 15 || number <= 0);

	for (int i = 0; i < number; i++)
	{
		for(int j = 0; j < number; j++)
		{
			cout << "X";
		}
		cout << endl;
	}
}

void Question23_Chapter5()
{
	string element = "++++++++++";
	string space = "                ";
	int count = 0;	//keep length of string element
	//find length element
	while(element[count] != NULL)
	{
		count +=1;
	}
	cout << count << endl;
	cout << "Pattern A "<< space << "Pattern B" << endl;



	//outer loop run 10 times, three for loop inside to create the + signs and space
	for (int i = 1; i <= count; i++)
	{
		//create + for pattern A
		for (int a = 0; a < i; a++)
			cout << "+";

		//create space
		for (int b = 26; b > i; b--)
		{
			cout << " ";
		}

		//ceare + for pattern B
		for (int c = count+1; c > i; c--)
		{
			cout << "+";
		}
		cout << endl;
	}
}

void Question24_Chapter5()
{
	ifstream inputfile;
	int read_in_number;			//keep the numbers in this variable
	int total_number = 0;					//count the amount of numbers in the file
	int sum = 0;
	inputfile.open("People.txt");

	// open file
	if(inputfile.is_open())
	{
		while(!inputfile.eof())
		{
			inputfile >> read_in_number;
			sum += read_in_number;
			total_number++;
		}
	}
	//edge case
	else
	{
		cout << "Error!";
		exit(true);
	}
	inputfile.close();

	cout << total_number << endl;
	cout << sum;
}

void test(int &a, int &b)
{
	a = 2;
	b = 5;
	cout << a << " " << b;
}


double Question1_Chapter6(double wholesale_cost, double markup_percentage)
{

/*	these codes go to main

	double wholesale_cost, markup_percentage;
	cout << "enter an item’s wholesale cost: ";
	cin >> wholesale_cost;
	cout << "enter markup percentage: ";
	cin >> markup_percentage;

	cout << fixed << setprecision(2) << Question1_Chapter6(wholesale_cost, markup_percentage);

*/

	double result;
 	result = wholesale_cost*markup_percentage/100 + wholesale_cost;
	return result;
}


double Question3_Chapter6(double Northeast, double Southeast, double Northwest, double Southwest)
{

	/*
	double Northeast = getSales();
	double Southeast = getSales();
	double Northwest = getSales();
	double Southwest = getSales();
	cout << "The highest value is " << Question3_Chapter6(Northeast, Southeast, Northwest, Southwest);

	*/


	double highest = 0;
	//using if else statement to compare and set the highest value to variable highest
	if(Northeast > highest)
	{
		highest = Northeast;
	}
	else
	{

	}
	if(Southeast > highest)
	{
		highest = Southeast;
	}
	else
	{

	}
	if(Northwest > highest)
	{
		highest = Northwest;
	}
	else
	{

	}
	if(Southwest > highest)
	{
		highest = Southwest;
	}
	else
	{

	}

	return highest;
}

double getSales()
{
	double total_sale = 0;
	cout << "Enter the sale: ";
	cin >> total_sale;
	while(total_sale < 0.00)
	{
		cout <<"Please enter an amount greater than 0.00: ";
		cin >> total_sale;
	}
	return total_sale;
}


int getNumAccidents()
{

	/*
	//get data for north, south, east, west, and central
	int north = getNumAccidents();
	int south = getNumAccidents();;
	int east = getNumAccidents();
	int west = getNumAccidents();
	int central = getNumAccidents();

	findLowest(north, south, east, west, central);

	*/

	int num = 0;
	do
	{
		cout << "Enter the number of automobile accidents: ";
		cin >> num;
	}while(num < 0);

	return num;
}

//this function passed the five data integer variables
//print out the lowest value of the five datas passed
/*

void findLowest(int north, int south, int east, int west, int central)
{
	int lowest = north;

	if(lowest > south)
	{
		lowest = south;
	}
	if(lowest > east)
	{
		lowest = east;
	}
	if(lowest > west)
	{
		 lowest = west;
	}
	if(lowest > central)
	{
		lowest = central;
	}

	cout << "The lowest out of the five is: " << lowest;
}
	*/

int fallingDistance(int seconds)
{

	/*
	// calling it in a loop that passes the values 1 through 10 as arguments and
	//displays the return value
	for (int i = 1; i <= 10; i++)
		cout << fallingDistance(i);
	*/
	int distance;
	double g = 9.8;
	distance = 1/2*g*seconds*seconds;
	return distance;
}

//should ask the user for a test score, store it in a reference parameter
//variable, and validate it. This function should be called by main once for each
//of the five scores to be entered
void getScore(int &test_score)
{
	do{
		cout << "Enter a test score: ";
		cin >> test_score;
	}while(test_score < 0 || test_score > 100);

}

//should find and return the lowest of the five scores passed to it.
//It should be called by calcAverage, which uses the function to determine which of
//the five scores to drop.
int findLowest(int &test_score1, int &test_score2, int &test_score3, int &test_score4, int &test_score5)
{
	//declare a variable
	int lowest = 0;
	test_score1 = lowest;
	if(test_score1 > test_score2)
	{
		test_score2 = lowest;
	}
	if(test_score2 > test_score3)
	{
		test_score3 = lowest;
	}
	if(test_score3 > test_score4)
	{
		test_score4 = lowest;
	}
	if(test_score4 > test_score5)
	{
		test_score5 = lowest;
	}
	return lowest;
}

//should calculate and display the average of the four highest
//scores. This function should be called just once by main and should be passed the
//five scores.
void calcAverage(int &test_score1, int &test_score2, int &test_score3, int &test_score4, int &test_score5)
{
	int lowest = 0;
	int average = 0;
	lowest = findLowest(test_score1, test_score2, test_score3, test_score4, test_score5);
	if(lowest == test_score1)
	{
		average = test_score2 + test_score3 + test_score4 + test_score5;
	}
	if(lowest == test_score2)
	{
		average = test_score1 + test_score3 + test_score4 + test_score5;
	}
	if(lowest == test_score3)
	{
		average = test_score1 + test_score2 + test_score4 + test_score5;
	}
	if(lowest == test_score4)
	{
		average = test_score1 + test_score2 + test_score3 + test_score5;
	}
	if(lowest == test_score5)
	{
		average = test_score1 + test_score2 + test_score3 + test_score4;
	}

	average /= 4;
	cout << "Average: " << average << endl;
}
/*
#include <iostream>
#include <string>
#include <fstream>

   srand(time(0));  // Initialize random number generator.
   for (int i = 0; i <= 30; i++)
   {
   	   int r = (rand() % 10) + 1;
   	   cout << r << endl;
   }



using namespace std;

void bubblesort(string array1[], string array2[], char alphabet1[], char alphabet2[], int counter1, int counter2);

void searchkeywords(string array1[], string array2[], char alphabet1[], char alphabet2[], int counter1, int counter2);

int binarysearch(int arraytest[], int low, int high, int element);

int linearsearch(int array[], int SIZE, int element);

int main() {
	//set counter to check how mant elements in the file
	int counter1 = 0;
	int counter2 = 0;

	//open file 1 and check for how many elements
	ifstream inputfile;
	inputfile.open("unsorted_dictionary.txt");
	if(inputfile.is_open())
	{
		while(!inputfile.eof())
		{
			string data;
			inputfile >> data;
			counter1++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//open file 2 and check for how many elements
	ifstream inputfile2;
	inputfile2.open("keywords.txt");
	if(inputfile2.is_open())
	{
		while(!inputfile2.eof())
		{
			string data;
			inputfile2 >> data;
			counter2++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//create string array with numbers of elements counted
	string array1[counter1];
	string array2[counter2];

	//open file 1 and input all elements into the array
	ifstream inputfile3;
	inputfile3.open("unsorted_dictionary.txt");
	if(inputfile3.is_open())
	{
		int counter = 0;		//set counter for array
		while(!inputfile3.eof())
		{
			string data = "";
			inputfile3 >> data;
			array1[counter] = data;
			counter++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//Print out elements in array1 to check if correct
	//for (int i = 0; i < counter1; i++)
	//{
	//	cout << array1[i] <<endl;
	//}

	//open file 2 and input all elements into the array
	ifstream inputfile4;
	inputfile4.open("keywords.txt");
	if(inputfile4.is_open())
	{
		int counter = 0;		//set counter for array
		while(!inputfile4.eof())
		{
			string data = "";
			inputfile4 >> data;
			array2[counter] = data;
			counter++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//Print out elements in array2 to check if correct
	//for (int i = 0; i < counter2; i++)
	//{
	//	cout << array2[i] << endl;
	//}

	//create two empty array type char
	char alphabet1[counter1];
	char alphabet2[counter2];

	//bubblesort(array1, array2, alphabet1, alphabet2, counter1, counter2);

	//searchkeywords(array1, array2, alphabet1, alphabet2, counter1, counter2);


	int S = 3;
	int a[3] = {1, 2, 3};
	cout << "Index: " << linearsearch(a, S, 100);
	return 0;
}



/*
 * buddle sort
 * Arguments: string array1, string array2, counter1, and counter2
 * create 2 chars arrays, sort it using bubble sort and sort it with the string array as well.


void bubblesort(string array1[], string array2[], char alphabet1[], char alphabet2[], int counter1, int counter2)
{

	//insert every first word in array1 into char array
	for (int i = 0; i < counter1; i++)
	{
		alphabet1[i] = array1[i][0];
	}

	//print out to check if alphabet2 contains correct elements
	//for (int i = 0; i < counter1; i++)
	//{
		//cout << i+1 << ": "<< alphabet1[i] << endl;
	//}

	//insert every first word in array2 into char array
	for (int i = 0; i < counter2; i++)
	{
		alphabet2[i] = array2[i][0];
	}

	//print out to check if alphabet2 contains correct elements
	//for (int i = 0; i < counter2; i++)
	//{
	//	cout << i+1 << ": " << alphabet2[i] << endl;
	//}

	//start the bubble sort to sort char array and at the same time with the string array1
	for (int i = 0; i < counter1-1; i++)
	{
	    //for (j = 0; j < n-i-1; j++)
		for (int j = 0; j < counter1-i-1; j++)
		{
			char temp;
			string stemp;
			if(alphabet1[j] >= alphabet1[j+1])
			{
				temp = alphabet1[j];
				stemp = array1[j];

				alphabet1[j] = alphabet1[j+1];
				array1[j] = array1[j+1];

				alphabet1[j+1] = temp;
				array1[j+1] = stemp;
			}
			else
			{
				continue;
			}
		}
	}

	//start the bubble sort to sort char array and at the same time with the string array2
	//for (i = 0; i < n-1; i++)
	for (int i = 0; i < counter2-1; i++)
	{
	    //for (j = 0; j < n-i-1; j++)
		for (int j = 0; j < counter2-i-1; j++)
		{
			char temp;
			string stemp;
			if(alphabet2[j] >= alphabet2[j+1])
			{
				temp = alphabet2[j];
				stemp = array2[j];

				alphabet2[j] = alphabet2[j+1];
				array2[j] = array2[j+1];

				alphabet2[j+1] = temp;
				array2[j+1] = stemp;
			}
			else
			{
				continue;
			}
		}
	}

	//print out to the console to check if array1 already store the words sorted or not
	//for (int i = 0; i < counter1;i++)
	//{
		//cout << i+1 << ": " << array1[i] << endl;
	//}

	//print out to the console to check if array2 already store the words sorted or not
	//for (int i = 0; i < counter2;i++)
	//{
		//cout << i+1 << ": " << array2[i] << endl;
	//}

	return;
}

//search to see what elements in array2 are in array1 and which one are not
void searchkeywords(string array1[], string array2[], char alphabet1[], char alphabet2[], int counter1, int counter2)
{


}



int binarysearch(int arraytest[], int low, int high, int element)
{
	if(low > high)
	{
		return -1;
	}
	int mid = low + (high-low)/2;
	if(element == arraytest[mid])
	{
		return mid;
	}
	else if(element < arraytest[mid])
	{
		return binarysearch(arraytest, low, mid-1, element);
	}
	else
	{
		return binarysearch(arraytest, mid+1, high, element);
	}
	return 1000;
}

int linearsearch(int array[], int SIZE, int element)
{
	for(int i = 0; i < SIZE; i++)
	{
		if(element == array[i])
		{
			return i+1;
		}
		else
		{
			continue;
		}
	}
	return -1;
}

*/
