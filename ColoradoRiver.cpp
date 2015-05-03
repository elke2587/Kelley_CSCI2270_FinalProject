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
    int choice = 0;

    while(choice != 6)
    {
        displayMenu();
        cin>>choice;
        //This choice is used to set all of the struct values.
        if(choice == 1)
        {
            moffat.flowRateForDate();
            moffat.leapyear();
            moffat.checkDataMissingDates();
            moffat.assignDiversion();
        }
        if(choice == 2)
        {
            string month, day, year;
            
            cin.clear();
			cin.ignore(10000,'\n');
            
            cout<<"Enter month: "<<endl;
            getline(cin,month);

            cout<<"Enter day: "<<endl;
            getline(cin,day);

            cout<<"Enter year (1904 -> 04): "<<endl;
            getline(cin,year);

            moffat.flowRateForDate(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()));
			//Passing the return value of atoi directly to the flowRateForData function lowers the number of variables required, and therefore the amount of memory; 

        }
        if(choice == 3)
        {
            string month, day, year, month2, day2, year2;
            
            cin.clear();
			cin.ignore(10000,'\n');
			            
            cout<<"Enter start month: "<<endl;
            getline(cin,month);

            cout<<"Enter start day: "<<endl;
            getline(cin,day);

            cout<<"Enter start year (1904 -> 04): "<<endl;
            getline(cin,year);

            cout<<"Enter end month: "<<endl;
            getline(cin,month2);

            cout<<"Enter end day: "<<endl;
            getline(cin,day2);

            cout<<"Enter end year (1904 -> 04): "<<endl;
            getline(cin,year2);

            moffat.frequencyAnalysis(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()), atoi(month2.c_str()), atoi(day2.c_str()), atoi(year2.c_str()));

        }
        if(choice == 4)
        {

            moffat.wateryear();
        }
        if(choice == 5)
        {
			string month, day, year, month2, day2, year2;
            
            cin.clear();
			cin.ignore(10000,'\n');
			
            cout<<"Enter start month: "<<endl;
            getline(cin,month);

            cout<<"Enter start day: "<<endl;
            getline(cin,day);

            cout<<"Enter start year (1904 -> 04): "<<endl;
            getline(cin,year);

            cout<<"Enter end month: "<<endl;
            getline(cin,month2);

            cout<<"Enter end day: "<<endl;
            getline(cin,day2);

            cout<<"Enter end year (1904 -> 04): "<<endl;
            getline(cin,year2);

            moffat.meanmedian(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()), atoi(month2.c_str()), atoi(day2.c_str()), atoi(year2.c_str()));
        }
		if (choice == 6)
		{
			cout << "Goodbye!" << endl;
			break;
		}
		if (choice > 6)
			cout << "Please choose an option on the menu." << endl;
    }
    
    return 0;
}
