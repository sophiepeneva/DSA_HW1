# DSA_HW1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hours(int hoursStart, int minutesStart, int hoursEnd, int minutesEnd)
{
    int hours = hoursEnd - hoursStart;
    if(minutesStart>minutesEnd)hours--;
    if(hours<0)hours+=24;
    return hours;
}
int minutes(int minutesStart, int minutesEnd)
{
    int minutes = minutesEnd - minutesStart;
    if(minutes<0)minutes+=60;
    return minutes;
}

void print(int hours, int minutes)
{
    cout<<hours<<":";
    if(minutes<10)cout<<"0";
    cout<<minutes<<endl;
}

int compareMax(int hoursFirst, int minutesFirst, int hoursSecond, int minutesSecond, int hoursThird, int minutesThird)
{
    int totalFirst = hoursFirst*60 + minutesFirst;
    int totalSecond = hoursSecond*60 + minutesSecond;
    int totalThird = hoursThird*60 + minutesThird;
    int max = (totalFirst > totalSecond ? totalFirst : totalSecond);
    max = (totalThird > max ? totalThird : max);
    if(max==totalFirst)return 1;
    if(max==totalSecond)return 2;
    return 3;
}

int compareMin(int hoursFirst, int minutesFirst, int hoursSecond, int minutesSecond, int hoursThird, int minutesThird)
{
    int totalFirst = hoursFirst*60 + minutesFirst;
    int totalSecond = hoursSecond*60 + minutesSecond;
    int totalThird = hoursThird*60 + minutesThird;
    int min = (totalFirst < totalSecond ? totalFirst : totalSecond);
    min = (totalThird < min ? totalThird : min);
    if(min==totalFirst)return 1;
    if(min==totalSecond)return 2;
    return 3;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int startHourFirst, startMinuteFirst;
    int startHourSecond, startMinuteSecond;
    int startHourThird, startMinuteThird;
    int endHourFirst, endMinuteFirst;
    int endHourSecond, endMinuteSecond;
    int endHourThird, endMinuteThird;
    cin>>startHourFirst>>startMinuteFirst>>endHourFirst>>endMinuteFirst;
    cin>>startHourSecond>>startMinuteSecond>>endHourSecond>>endMinuteSecond;
    cin>>startHourThird>>startMinuteThird>>endHourThird>>endMinuteThird;
    int max = compareMax(hours(startHourFirst, startMinuteFirst, endHourFirst, endMinuteFirst),
                         minutes(startMinuteFirst, endMinuteFirst),
                        hours(startHourSecond, startMinuteSecond, endHourSecond, endMinuteSecond),
                        minutes(startMinuteSecond, endMinuteSecond),
                        hours(startHourThird, startMinuteThird, endHourThird, endMinuteThird),
                        minutes(startMinuteThird, endMinuteThird));
    int min = compareMin(hours(startHourFirst, startMinuteFirst, endHourFirst, endMinuteFirst),
                         minutes(startMinuteFirst, endMinuteFirst),
                        hours(startHourSecond, startMinuteSecond, endHourSecond, endMinuteSecond),
                        minutes(startMinuteSecond, endMinuteSecond),
                        hours(startHourThird, startMinuteThird, endHourThird, endMinuteThird),
                        minutes(startMinuteThird, endMinuteThird));
    if(min==1)print(hours(startHourFirst, startMinuteFirst, endHourFirst, endMinuteFirst),
                    minutes(startMinuteFirst, endMinuteFirst));
    if(min==2)print(hours(startHourSecond, startMinuteSecond, endHourSecond, endMinuteSecond),
                    minutes(startMinuteSecond, endMinuteSecond));
    if(min==3)print(hours(startHourThird, startMinuteThird, endHourThird, endMinuteThird),
                    minutes(startMinuteThird, endMinuteThird));
    if(max==1)print(hours(startHourFirst, startMinuteFirst, endHourFirst, endMinuteFirst),
                    minutes(startMinuteFirst, endMinuteFirst));
    if(max==2)print(hours(startHourSecond, startMinuteSecond, endHourSecond, endMinuteSecond),
                    minutes(startMinuteSecond, endMinuteSecond));
    if(max==3)print(hours(startHourThird, startMinuteThird, endHourThird, endMinuteThird),
                    minutes(startMinuteThird, endMinuteThird));
    return 0;
}
