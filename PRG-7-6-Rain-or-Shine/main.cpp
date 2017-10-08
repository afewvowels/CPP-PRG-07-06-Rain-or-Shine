//
//  main.cpp
//  PRG-7-6-Rain-or-Shine
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  An amateur meteorologist wants to keep track of weather conditions during the past
//  year's three-month summer season, and has designated each day as either rainy ('R'),
//  cloudy ('C'), or sunnny ('S'). Write a program that stores this information in a 3 x 30
//  array of characters, where the row indicates the month (0 = June, 1 = July, 2 = August)
//  and the column indicates the day of the month. Note data are not being collected for
//  the 31st of any month. The program should begin by reaeding the weather data in from
//  a file. Then it should create a report that displays, for each month and for the whole
//  three-month period, how many days were rainy, how many were cloudy, and how
//  many were sunny. It should also report which of the three months had the largest number
//  of rainy days. Data for the program can be found in the RainOrShine.txt file.


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int INT_MONTHS = 3;
const int INT_DAYS = 30;

const string STR_MONTHS[] = {"June", "July", "August"};

void populateArray(int intArray[][INT_DAYS]);
void calculateDaysTotal(const int intArray[][INT_DAYS], int &, int&, int&);
void calculateDaysJune(const int intArray[][INT_DAYS], int &, int&, int&);
void calculateDaysJuly(const int intArray[][INT_DAYS], int &, int&, int&);
void calculateDaysAugust(const int intArray[][INT_DAYS], int &, int&, int&);
void calculateMostRainyDays(int, int, int);
void displayResults(int, int, int, int, int, int, int, int, int, int, int, int);

int main()
{
    int intArray[INT_MONTHS][INT_DAYS];
    
    int intDaysSunny;
    int intDaysCloudy;
    int intDaysRainy;
    
    int intJuneSunny;
    int intJuneCloudy;
    int intJuneRainy;
    
    int intJulySunny;
    int intJulyCloudy;
    int intJulyRainy;
    
    int intAugustSunny;
    int intAugustCloudy;
    int intAugustRainy;
    
    intDaysSunny = 0;
    intDaysCloudy = 0;
    intDaysRainy = 0;
    
    intJuneSunny = 0;
    intJuneCloudy = 0;
    intJuneRainy = 0;
    
    intJulySunny = 0;
    intJulyCloudy = 0;
    intJulyRainy = 0;
    
    intAugustSunny = 0;
    intAugustCloudy = 0;
    intAugustRainy = 0;
    
    populateArray(intArray);
    
    calculateDaysTotal(intArray, intDaysSunny, intDaysCloudy, intDaysRainy);
    calculateDaysJune(intArray, intJuneSunny, intJuneCloudy, intJuneRainy);
    calculateDaysJuly(intArray, intJulySunny, intJulyCloudy, intJulyRainy);
    calculateDaysAugust(intArray, intAugustSunny, intAugustCloudy, intAugustRainy);
    calculateMostRainyDays(intJuneRainy, intJulyRainy, intAugustRainy);
    
    displayResults(intDaysSunny, intDaysCloudy, intDaysRainy, intJuneSunny, intJuneCloudy, intJuneRainy, intJulySunny, intJulyCloudy, intJulyRainy, intAugustSunny, intAugustCloudy, intAugustRainy);
    
    return 0;
}

void populateArray(int intArray[][INT_DAYS])
{
    char chrLetter;
    
    ifstream infile;
    
    infile.open("/Users/bluebackdev/Desktop/CodeBlocks/For Github/07-Arrays and Vectors/PRG-7-6-Rain-or-Shine/PRG-7-6-Rain-or-Shine/RainOrShine.txt");
    if(!infile)
    {
        cout << "File open Failure!";
    }
    
    for(int month = 0 ; month < INT_MONTHS ; month++)
    {
        for(int day = 0 ; day < INT_DAYS ; day++)
        {
            infile >> chrLetter;
            intArray[month][day] = chrLetter;
            //cout << chrLetter << endl;
            infile.clear();
        }
    }
    
    infile.close();
}

void calculateDaysTotal(const int intArray[][INT_DAYS], int &refSunny, int &refCloudy, int &refRainy)
{
    for(int month = 0 ; month < INT_MONTHS ; month++)
    {
        for(int day = 0 ; day < INT_DAYS ; day++)
        {
            if(intArray[month][day] == 'S')
            {
                refSunny++;
            }
            else if(intArray[month][day] == 'C')
            {
                refCloudy++;
            }
            else if(intArray[month][day] == 'R')
            {
                refRainy++;
            }
            else
            {
                cout << "ERROR UNEXPECTED ARRAY VALUE" << endl;
            }
        }
    }
}

void calculateDaysJune(const int intArray[][INT_DAYS], int &refSunny, int &refCloudy, int &refRainy)
{
    for(int day = 0 ; day < INT_DAYS ; day++)
    {
        if(intArray[0][day] == 'S')
        {
            refSunny++;
        }
        else if(intArray[0][day] == 'C')
        {
            refCloudy++;
        }
        else if(intArray[0][day] == 'R')
        {
            refRainy++;
        }
        else
        {
            cout << "ERROR UNEXPECTED ARRAY VALUE" << endl;
        }
    }
}

void calculateDaysJuly(const int intArray[][INT_DAYS], int &refSunny, int &refCloudy, int &refRainy)
{
    for(int day = 0 ; day < INT_DAYS ; day++)
    {
        if(intArray[1][day] == 'S')
        {
            refSunny++;
        }
        else if(intArray[1][day] == 'C')
        {
            refCloudy++;
        }
        else if(intArray[1][day] == 'R')
        {
            refRainy++;
        }
        else
        {
            cout << "ERROR UNEXPECTED ARRAY VALUE" << endl;
        }
    }
}

void calculateDaysAugust(const int intArray[][INT_DAYS], int &refSunny, int &refCloudy, int &refRainy)
{
    for(int day = 0 ; day < INT_DAYS ; day++)
    {
        if(intArray[2][day] == 'S')
        {
            refSunny++;
        }
        else if(intArray[2][day] == 'C')
        {
            refCloudy++;
        }
        else if(intArray[2][day] == 'R')
        {
            refRainy++;
        }
        else
        {
            cout << "ERROR UNEXPECTED ARRAY VALUE" << endl;
        }
    }
}

void calculateMostRainyDays(int intJuneRainy, int intJulyRainy, int intAugustRainy)
{
    if(intJuneRainy > intJulyRainy && intJuneRainy > intAugustRainy)
    {
        cout << "June had the most rainy days with " << intJuneRainy << " days of rain.\n\n";
    }
    else if(intJulyRainy > intJuneRainy && intJulyRainy > intAugustRainy)
    {
        cout << "July had the most rainy days with " << intJulyRainy << " days of rain.\n\n";
    }
    else if(intAugustRainy > intJuneRainy && intAugustRainy > intJulyRainy)
    {
        cout << "June had the most rainy days with " << intAugustRainy << " days of rain.\n\n";
    }
    else
    {
        cout << "There was a tie for most rainy days.\n\n";
    }
}

void displayResults(int intDaysSunny, int intDaysCloudy, int intDaysRainy, int intJuneSunny, int intJuneCloudy, int intJuneRainy, int intJulySunny, int intJulyCloudy, int intJulyRainy, int intAugustSunny, int intAugustCloudy, int intAugustRainy)
{
    cout << "Total Days Sunny: " << intDaysSunny << endl;
    cout << "Total Days Cloudy: " << intDaysCloudy << endl;
    cout << "Total Days Rainy: " << intDaysRainy << endl << endl;
    
    cout << "June Days Sunny: " << intJuneSunny << endl;
    cout << "June Days Cloudy: " << intJuneCloudy << endl;
    cout << "June Days Rainy: " << intJuneRainy << endl << endl;
    
    cout << "July Days Sunny: " << intJulySunny << endl;
    cout << "July Days Cloudy: " << intJulyCloudy << endl;
    cout << "July Days Rainy: " << intJulyRainy << endl << endl;
    
    cout << "August Days Sunny: " << intAugustSunny << endl;
    cout << "August Days Cloudy: " << intAugustCloudy << endl;
    cout << "August Days Rainy: " << intAugustRainy << endl << endl;
}

