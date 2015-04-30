#include "Diversions.h"

Diversions::Diversions(Day * array1)
{
    dayArray = array1;
}

Diversions::~Diversions()
{
    if(dayArray == NULL)
    {
        delete[] dayArray;
    }
}
//This function checks the data and assigns false to days where no flow rate has been measured.
//If the flow rate has been measured it assigns a value of true.
//it also enables a user to check if a particular date has flow data
void Diversions::flowRateForDate(int m, int d, int y)
{
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].flowrate < 0)
        {
            dayArray[i].dataForDay = false;
            if(dayArray[i].month == m && dayArray[i].day == d && dayArray[i].year == y)
            {
                cout<<"There is no flow rate in the data for this day."<<endl;
            }
        }
        else
        {
            dayArray[i].dataForDay = true;
             if(dayArray[i].month == m && dayArray[i].day == d && dayArray[i].year == y)
             {
                 cout<<"The flow rate for this day is " << dayArray[i].flowrate<<endl;
             }
        }
    }
}

void Diversions::flowRateForDate()
{
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].flowrate < 0)
        {
            dayArray[i].dataForDay = false;
        }
        else
        {
            dayArray[i].dataForDay = true;
        }
    }
}
//check if the year is a leap year
//1 If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
//2 If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
//3 If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
//4 The year is a leap year (it has 366 days).
//5 The year is not a leap year (it has 365 days).

void Diversions::leapyear()
{

    for(int i=0; i<=33511; i++)
    {
       int year = dayArray[i].year +1900;
       if (year%4 == 0)
       {
            if(year%100 == 0)
            {
                if(year%400 ==0)
                {
                    dayArray[i].leapyear = true;
                }
                else
                {
                    dayArray[i].leapyear = false;
                }
            }
            else
            {
                dayArray[i].leapyear = true;
            }
       }
       else
       {
           dayArray[i].leapyear = false;
       }
    }
}
bool Diversions::leapyear(int year)
{
   bool leapyear;
   if (year%4 == 0)
   {
        if(year%100 == 0)
        {
            if(year%400 ==0)
            {
                leapyear = true;
            }
            else
            {
               leapyear = false;
            }
        }
        else
        {
            leapyear = true;
        }
   }
   else
   {
       leapyear = false;
   }
   return leapyear;
}
//This is a function that finds the factorial of a number and is used in checkDataMissingDates
int Diversions::factorial(int n)
{
    int factorial = 0;
	if (n == 0 || n == 1)	//if n is 0 or 1, return 1 without looping. This also allows for the loop to run without checking this condition every time
		return 1;

    for(int i=1; i<=n; i++)	//
    {
        factorial = factorial * i;
    }
    return factorial;
}
//This is a function that checks to see if every date had been entered into the list of dates
void Diversions::checkDataMissingDates()
{
    int year = 04;
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].year == year)
        {
            int jan = 31;
 			int countJ = 1;
            int feb = 28;
            int countF =1;
            if(dayArray[i].leapyear == true)
            {
                feb = 29;
            }
            int mar = 31;
            int countMar =1;
            int april = 30;
            int countApr =1;
            int may = 31;
            int countMay = 1;
            int june = 30;
            int countJune =1;
            int july = 31;
            int countJuly =1;
            int aug = 30;
            int countAug =1;
            int sep = 31;
            int countSep =1;
            int oct = 30;
            int countOct =1;
            int nov = 31;
            int countNov =1;
            int dec = 30;
            int countDec =1;

            for(int i=0; i<=33511; i++)
            {
                if(dayArray[i].year == year)
                {
                    if(dayArray[i].month == 1)
                    {
                        countJ = countJ * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 2)
                    {
                        countF = countF * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 3)
                    {
                        countMar = countMar * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 4)
                    {
                        countApr = countApr * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 5)
                    {
                        countMay = countMay * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 6)
                    {
                        countJune = countJune * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 7)
                    {
                        countJuly = countJuly * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 8)
                    {
                        countAug = countAug * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 9)
                    {
                        countSep = countSep * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 10)
                    {
                        countOct = countOct * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 11)
                    {
                        countNov = countNov * dayArray[i].day;
                    }
                    else if(dayArray[i].month == 12)
                    {
                        countDec = countDec * dayArray[i].day;
                    }
                    if(countJ != factorial(jan))
                    {
                       cout<<"There is a day missing in January of 19"<<year<<endl;
                       cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countF != factorial(feb))
                    {
                        cout<<"There is a day missing in February of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countMar != factorial(mar))
                    {
                        cout<<"There is a day missing in March of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countApr != factorial(april))
                    {
                        cout<<"There is a day missing in April of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countMay != factorial(may))
                    {
                       cout<<"There is a day missing in May of 19"<<year<<endl;
                       cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countJune != factorial(june))
                    {
                        cout<<"There is a day missing in June of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countJuly != factorial(july))
                    {
                        cout<<"There is a day missing in July of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countAug != factorial(aug))
                    {
                        cout<<"There is a day missing in August of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countSep != factorial(sep))
                    {
                        cout<<"There is a day missing in September of 19"<<year<<endl;
                       cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countOct != factorial(oct))
                    {
                        cout<<"There is a day missing in October of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countNov != factorial(nov))
                    {
                        cout<<"There is a day missing in November of 19"<<year<<endl;
                        cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                    if(countDec != factorial(dec))
                    {
                       cout<<"There is a day missing in December of 19"<<year<<endl;
                       cout<<"Please go to the data file and add the missing date and a flow rate of -1."<<endl;
                    }
                }
                 year++;
        }
    }
}
}
//This function takes the average and the mean of each water year
//water year goes from October first to September 30 of the next year
void Diversions::wateryear()
{
    int monthS;
    int dayS;
    int yearS;
    int monthE;
    int dayE;
    int yearE;

    int year = 04;

    while(year<=94)
    {
        int nextYear = year + 1;

        for(int i=0; i<=33511; i++)
        {

            if(dayArray[i].year == year && dayArray[i].month == 10 && dayArray[i].day ==1)
            {
                monthS = dayArray[i].month;
                dayS = dayArray[i].day;
                yearS = dayArray[i].year;
            }

            if(dayArray[i].year == nextYear && dayArray[i].month == 9 && dayArray[i].day ==30)
            {
                monthE = dayArray[i].month;
                dayE = dayArray[i].day;
                yearE = dayArray[i].year;
            }

             int medain1 = median(monthS, dayS, yearS,  monthE, dayE, yearE);
            int mean1 = mean(monthS, dayS, yearS,  monthE, dayE, yearE);

            cout<<"For water year "<<year<< " "<<nextYear<<" the mean is "<<mean1<<" the median is "<<medain1<<"."<<endl;

        }//end for loop
        year++;
    }//end while
}
//This function finds the mean and median for a user specified period of time
void Diversions::meanmedian(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE)
{

        int medain1 = median(monthS, dayS, yearS, monthE, dayE, yearE);
        int mean1 = mean(monthS, dayS, yearS,  monthE, dayE, yearE);

        cout<<"Between these dates the mean is "<<mean1<<" the median is "<<medain1<<"."<<endl;

    }//end for loop

//assign years to each period of time when a diversion is in use
//PreDiversions (4)
//Moffat1936 (36)
//cbt 1950 (50)
//Windy gap 1985 (85)
void Diversions::assignDiversion()
{
    for(int i=0; i<=33511; i++)
    {
        //PreDiversions (4)
        if(dayArray[i].year < 36)
        {
            dayArray[i].diver = 4;
        }
        //Moffat1936 (36)
        else if(dayArray[i].year >= 36 && dayArray[i].year < 50)
        {
            dayArray[i].diver = 36;
        }
        //cbt 1950 (50)
        else if(dayArray[i].year >= 50 && dayArray[i].year < 85)
        {
            dayArray[i].diver = 50;
        }
        //Windy gap 1985 (85)
        else
        {
            dayArray[i].diver = 85;
        }

    }
}
/*void Diversions::analizeDiversion();
{
     for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].dataForDay == true)
        {
            if(dayArray[i].diver == 4)

        }
    }
}*/
//This function finds the min and max flow rates for a user defined time and divides this span of flow rates into 10 equal segments.
//Then the number of days with flow rates within each segment is determined.
//This analysis is useful for determining if a mean or a median should be used for analysis
//If many of the flow rates are contained within the same segment median is better
//If the flow rates are evenly distributed the mean is a better analysis tool
void Diversions::frequencyAnalysis(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE)
{
    int indexS;
    int indexE;
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].month == monthS && dayArray[i].day == dayS && dayArray[i].year == yearS)
        {
            indexS = i;
        }
        if(dayArray[i].month == monthE && dayArray[i].day == dayE && dayArray[i].year == yearE)
        {
            indexE = i;
        }

    }
    int Max = dayArray[indexS].flowrate;
    int Min = dayArray[indexS].flowrate;
    int step;
    int iteration = 1;
    for(int i=indexS; i<=indexE; i++)
    {
        if(dayArray[i].dataForDay == true)
        {
            if(dayArray[i].flowrate > Max)
            {
                Max = dayArray[i].flowrate;
            }
            if(dayArray[i].flowrate < Min)
            {
                Min = dayArray[i].flowrate;
            }
        }
    }
    step = (Max - Min)/10;
    while(iteration <=10)
    {
        int countFrequency = 0;
        for(int i=indexS; i<=indexE; i++)
        {
            if(dayArray[i].flowrate >= Min && dayArray[i].flowrate < Min + step)
            {
                countFrequency++;
            }
        }
        cout<<"In the range of flow rates "<<Min<<" to "<<Min + step<<" the number of days was "<<countFrequency<<endl;
        Min = Min+step;
        iteration++;
    }
}
//finds the median between two specified days
int Diversions::median(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE)
{
    int indexS;
    int indexE;
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].month == monthS && dayArray[i].day == dayS && dayArray[i].year == yearS)
        {
            indexS = i;
        }
        if(dayArray[i].month == monthE && dayArray[i].day == dayE && dayArray[i].year == yearE)
        {
            indexE = i;
        }

    }
    int j = 0;
    int *medianArray = new int[indexE - indexS];
    for(int i=indexS; i<=indexE; i++)
    {
        medianArray[j] = dayArray[i].flowrate;
        j++;
    }
    medianArray = selectionSort(medianArray,j);

    if(j % 2 != 0)//function is even
    {
        int temp = ((j+1)/2)-1;
        return medianArray[temp];
    }
    else//function is odd
    {
       return (medianArray[(j/2)-1] + medianArray[j/2])/2;//????????think about this
    }
}
//sort the int array that the function is given and return the sorted array
int *Diversions::selectionSort(int *arr, int n)
{
      int i, j, minIndex, tmp;
      for (i = 0; i < n - 1; i++)
        {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i)
            {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
      return arr;
}
int Diversions::mean(int monthS, int dayS, int yearS, int monthE, int dayE, int yearE)
{
    int indexS;
    int indexE;
    int sum = 0;
    int countItems = 0;
    for(int i=0; i<=33511; i++)
    {
        if(dayArray[i].month == monthS && dayArray[i].day == dayS && dayArray[i].year == yearS)
        {
            indexS = i;
        }
        if(dayArray[i].month == monthE && dayArray[i].day == dayE && dayArray[i].year == yearE)
        {
            indexE = i;
        }

    }
    for(int i=indexS; i<=indexE; i++)
    {
        sum = sum + dayArray[i].flowrate;
        countItems++;
    }
    int averageFlow = sum/countItems;
    return averageFlow;
}

