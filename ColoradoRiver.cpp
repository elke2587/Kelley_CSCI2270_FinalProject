#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Diversions.h"
#include <sstream>

using namespace std;

void displayMenu()
{
    cout<<"======Main Menu====="<<endl;
    cout<<"1. Initialize the program (You must do this before picking any other menu items)"<<endl;
    cout<<"2. Does this date have flow data?"<<endl;
    cout<<"3. Frequency analysis"<<endl;
    cout<<"4. Print median and mean of each water year"<<endl;
    cout<<"5. Print the mean and median for a user specified period of time "<<endl;
    cout<<"6. Quit"<<endl;
}



int main(int argc,char *argv[])
{


    ifstream infile;
    infile.open(argv[1]);
    string line;

    ifstream infile1;
    infile1.open(argv[2]);
    string line1;

    int flowdata[33511];
    Day* dayArray = new Day[33511];
    Diversions moffat = Diversions(dayArray);
    int i=0;
    int j=0;

    while(getline(infile1,line1))
    {
        istringstream strstr(line1);
        string holder;
        flowdata[i]=atoi(holder.c_str());
        i++;
    }
     while(getline(infile,line))
    {

        istringstream strstr(line);
        Day newObject;
        string holder;

        getline(strstr, holder,'/');
        newObject.month = atoi(holder.c_str());

        getline(strstr, holder, '/');
        newObject.day = atoi(holder.c_str());

        getline(strstr, holder, '/');
        newObject.year = atoi(holder.c_str());

        newObject.flowrate = flowdata[j];

        dayArray[j] = newObject;
        j++;
    }
    string choice = "";

    while(choice != "6")
    {
        displayMenu();
        cin>>choice;
        //This choice is used to set all of the struct values.
        if(choice == "1")
        {
            moffat.flowRateForDate1();
            moffat.leapyear();
            moffat.checkDataMissingDates();
            moffat.assignDiversion();
        }
        if(choice == "2")
        {
            cout<<"Enter month: "<<endl;
            string month;

            getline(cin,month);
            int month1 = atoi(month.c_str());

            cout<<"Enter day: "<<endl;
            string day;

            getline(cin,day);
            int day1 = atoi(day.c_str());

            cout<<"Enter year (1904 -> 04): "<<endl;
            string year;

            getline(cin,year);
            int year1 = atoi(year.c_str());

            moffat.flowRateForDate(month1, day1, year1);

        }
        if(choice == "3")
        {
            cout<<"Enter start month: "<<endl;
            string month;

            getline(cin,month);
            int month1S = atoi(month.c_str());

            cout<<"Enter start day: "<<endl;
            string day;

            getline(cin,day);
            int day1S = atoi(day.c_str());

            cout<<"Enter start year (1904 -> 04): "<<endl;
            string year;

            getline(cin,year);
            int year1S = atoi(year.c_str());

            cout<<"Enter end month: "<<endl;
            string month2;

            getline(cin,month2);
            int month1E = atoi(month.c_str());

            cout<<"Enter end day: "<<endl;
            string day2;

            getline(cin,day2);
            int day1E = atoi(day.c_str());

            cout<<"Enter end year (1904 -> 04): "<<endl;
            string year2;

            getline(cin,year2);
            int year1E = atoi(year.c_str());

            moffat.frequencyAnalysis( month1S, day1S, year1S, month1E, day1E, year1E);

        }
        if(choice == "4")
        {

            moffat.wateryear();
        }
        if(choice == "5")
        {
            cout<<"Enter start month: "<<endl;
            string month;

            getline(cin,month);
            int month1S = atoi(month.c_str());

            cout<<"Enter start day: "<<endl;
            string day;

            getline(cin,day);
            int day1S = atoi(day.c_str());

            cout<<"Enter start year (1904 -> 04): "<<endl;
            string year;

            getline(cin,year);
            int year1S = atoi(year.c_str());

            cout<<"Enter end month: "<<endl;
            string month2;

            getline(cin,month2);
            int month1E = atoi(month.c_str());

            cout<<"Enter end day: "<<endl;
            string day2;

            getline(cin,day2);
            int day1E = atoi(day.c_str());

            cout<<"Enter end year (1904 -> 04): "<<endl;
            string year2;

            getline(cin,year2);
            int year1E = atoi(year.c_str());

            moffat.meanmedian(month1S, day1S, year1S, month1E, day1E, year1E);
        }

    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
