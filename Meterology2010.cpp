
//Name: Jima Dube
   //ID No:
   //Email: jimd3730@gmail.com
//Assignment Number 1
/* Program to record highest and lowest temperature of the day for one year and
respond to user queries for the temperature analysis */
// submitted date: June 29, 2021
#include <iostream>
#include<string>

using namespace std;
int mon_size,day_size;
string print[2]={"High temperature","Low temperature"};
void record(float temprate[12][31][3]); // records High & Low temperatures for each day of all months
void choice(float temprate[12][31][3]);//function that asked the user to choose the file recorded
void highAndLow(float temprate[12][31][3]);//display high and low of the daily temperature
void high_low_average_month(float temprate[12][31][3]);//To calculate the highest temperature of the month and the lowest temperature and it's average
void calc_average(float temprate[12][31][3]);//To calculate the average of each days and store in the array
void high_temp(float temprate[12][31][3]);//To calculate the highest temperature of the month and the day
void low_temp(float temprate[12][31][3]);//To calculate the lowest temperature of the month and the day
void month_average_temp(float temprate[12][31][3]);//To display the average temperature of the months


int main()
{   int menu;
    float temprate[12][31][3]; // 12 months 31 days 3 - High, Low & Average respectively
    record(temprate);
    choice(temprate);

    return 0;
}
void record(float temprate[12][31][3])/*it recored the that data from the user and calculate and check the
 highest and the lowest temperature of each days.*/
{   cout<<"\t\t---------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t Ethiopian meteorology in 2010 that recored the temperature of the month and day "<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------"<<endl;
    cout<<"To recored a data please input the below instruction "<<endl;
    cout<<"Recored the data that with degree Celsius:\n The high and low temp not exceed and under to 200 and -50 degree Celsius respectively  "<<endl<<endl;
     label:
     cout<<"Enter the size of month you would like to recored :";
     cin>>mon_size;
     cout<<"Enter the size of day you would like to recored :";
     cin>>day_size;
     if(mon_size>13||day_size>31)
     {
         system("cls");
         cout<<"Error input,please try again "<<endl;
         goto label;
     }
    for(int i = 0; i < mon_size; i++){
            cout<<"month: "<<i+1<<" "<<endl;
        for(int j = 0; j < day_size; j++){
            cout<<"day: "<<j+1<<" "<<endl;
              print:
            for(int k = 0; k < 2; k++){
                    check:
                    cout << "please input Month " << (i+1) << " Day  " << (j+1) <<" "<< print[k]<<" ";
                    cin >> temprate[i][j][k];
                    if(temprate[i][j][k]>200||temprate[i][j][k]<-50)
                    {
                        cout<<"Invalid low/high temperature,please try again "<<endl<<endl;
                        goto check;
                    }

                }
                if(temprate[i][j][0]<temprate[i][j][1])
                    {
                        cout<<"Invalid input,please try again "<<endl;
                        goto print;
                    }
                cout << endl;
            }
        }
        system("cls");
}
void choice(float temprate[12][31][3]){
    int menu; // Choice of user to access the data below
    do
    {
    cout<<  "  ____________________________________________________________________________________________________"<<endl;
    cout<<  " |                    WELCOME TO ETHIOPIAN METEOROLOGY,TO ACCES DATA RECORDED CHOOSE THE BELLOW OPTION|"<<endl;
    cout << " |                    1. Any day's high and low temperatures                                          |" <<endl;
    cout << " |                    2. Any month high, low and average temperatures for a given month               |" <<endl;
    cout << " |                    3. Month and day with the highest temperature                                   |" <<endl;
    cout << " |                    4. Month and day with the lowest temperature                                    |" <<endl;
    cout << " |                    5. All months average temperature to be printed in table format                 |" <<endl;
    cout << " |                    0. To exit:                                                                     |"<<endl;
    cout << " |____________________________________________________________________________________________________|"<<endl<<endl;
    cout<<"choose the above option :";
    cin >> menu;
    cout<<endl;
    switch(menu){
        case 1:
            highAndLow(temprate);
            break;
        case 2:
            high_low_average_month(temprate);
            break;
        case 3:
            high_temp(temprate);
            break;
        case 4:
            low_temp(temprate);
            break;
        case 5:
            month_average_temp(temprate);
            break;
        case 0:
             break;
        default:

            cout<<"Invalid input"<<endl;
    }
}
  while(menu!=0);

}

void highAndLow(float temprate[12][31][3]){ /*void function that store and display the temperature high and low temperature*/

    int month, day;
    up:
    cout << "Enter a Month " << endl;
    cin >> month ;
    cout<<"Enter a day ";
    cin>>day;
    if(month>mon_size||day>day_size)
    {
        cout<<"Error input,try again "<<endl;
     goto up;
    }
    cout << "Month " << month << " Day " << day << " High Temprature: " << temprate[month-1][day-1][0] << endl;
    cout << "Month " << month << " Day " << day << " Low Temprature: " << temprate[month-1][day-1][1] << endl;
    cout << endl;
}


void high_low_average_month(float temprate[12][31][3]) // Any month high, low and average temperatures for a given month
   {
    int month;
     try_again:
    calc_average(temprate);
    cout << "Enter a Month for to display high ,low and average at that point :" ;
    cin >> month;

    if(month>mon_size)
        {
        cout<<"Error input,try again :"<<endl;
        goto try_again;
    }



     float highest=temprate[0][0][2];
     float lowest=temprate[0][0][2];
     int mon_num=0;
     double sum_average=0;
     double month_average=0;

    double month_arr[mon_size][day_size];
    for(int i=0;i<mon_size;i++)
    {

      if(i==month-1)
      {
          highest=lowest;
        lowest=highest;
        sum_average=0;

        for(int j=0;j<day_size;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==2)
                {
                if(temprate[i][j][k]>highest)
                {
                    highest=temprate[i][j][k];
                }
                else if(temprate[i][j][k]<lowest)
                {
                    lowest=temprate[i][j][k];
                }
                sum_average+=temprate[i][j][k];
               mon_num=i;


                }




            }


        }
        month_average=sum_average/mon_size;
    cout << "Month " << mon_num +1<<  "  highest temperature  is: " << highest << endl;
    cout<< "Month " << mon_num+1<< " lowest temperature is " << lowest<<endl;
    cout<<"Month " << mon_num+1<<" Average temperature is "<<month_average<<endl<<endl;
        }

    }

}
/* calculate the average temperature day in each month that takes the size from the input
  by adding the low and high temperature data that takes from the user*/
void calc_average(float temprate[12][31][3]){
    for(int i = 0; i < mon_size; i++){
        for(int j = 0; j < day_size; j++){
                    temprate[i][j][2] = 0.0;
            for(int k = 0; k < 2; k++){
                   temprate[i][j][2] += temprate[i][j][k];
                }
                    temprate[i][j][2] = (float)temprate[i][j][2] /(float) 2.0;
            }
        }
}
void high_temp(float temprate[12][31][3]){ // Month and day with the highest temperature
    float highestTemp = temprate[0][0][0];
    int month = 0, day = 0; // Save the index of the highest temperature
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
                if(temprate[i][j][0]>highestTemp){
                    highestTemp = temprate[i][j][0];
                    month = i;
                    day = j;
                }
            }
        }
    cout << "Month " << (month+1) << " Day " << (day+1) << " has the highest temperature that is : " << highestTemp << endl << endl;
}
void low_temp(float temprate[12][31][3]){ // Month and day with the lowest temperature
    float lowestTemp = temprate[0][0][1];
    int month = 0, day = 0; // Save the index of the lowest temperature
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
                if(temprate[i][j][1]<lowestTemp){
                    lowestTemp = temprate[i][j][1];
                    month = i;
                    day = j;
                }
            }
        }
    cout << "Month " << (month+1) << " Day " << (day+1) << " has the lowest temperature that is: " << lowestTemp << endl << endl;
}
void month_average_temp(float temprate[12][31][3]){ // All months average temperature to be printed in table format
    calc_average(temprate);
    float sumtemp;
    float avetemp;
    sumtemp=0;

    cout << "\t\tAverage Temperature of All Months" << endl;
    cout<<"__________________________________________"<<endl;
    cout <<"|"<<"Month" <<" |"<< "\t" <<"   |" << "Average Temperature"<<"  |" << endl;
    for(int i = 0; i < mon_size; i++){
            sumtemp=0;
        for(int j = 0; j < day_size; j++){
            for(int k=0;k<3;k++) {
                if(k==2)
                 sumtemp += temprate[i][j][2];
             }
        }
        avetemp=sumtemp/mon_size;

    cout << "|  "<<(i+1) <<"   | "<< "\t"<<"   |    " << avetemp <<"        | "<< endl;
    cout<< "------------------------------------------3"<< endl;
    }
    cout<<"__________________________________________"<<endl;



    cout << endl;

}
