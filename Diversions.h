#ifndef DIVERSIONS_H
#define DIVERSIONS_H
#include <string>
#include <iostream>
using namespace std;

struct Day
{
    int month;
    int day;
    int year;
    int flowrate;
    bool dataForDay;
    bool leapyear;
    int diver;


};

class Diversions
{
    public:
        Diversions(Day *);
        virtual ~Diversions();
        void flowRateForDate(int m, int d, int y);
        bool flowRateForDate1();
        void leapyear();
        void checkDataMissingDates();
        int factorial(int n);
        void wateryear();
        void meanmedian(int monthS, int dayS, int yearS, int monthE,int dayE,int yearE);
        bool leapyear1(int year);
        void assignDiversion();
        void frequencyAnalysis(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE);
        int median(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE);
        int * selectionSort(int arr[], int n);
        int mean(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE);
    protected:
    private:
        Day * dayArray;
};

#endif // DIVERSIONS_H
