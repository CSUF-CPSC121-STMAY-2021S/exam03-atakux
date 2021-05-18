#include "reservation.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

Reservation::Reservation()
{
  elementNum = 0;
  elements = nullptr;
}

Reservation::~Reservation()
{
  delete [] elements;
}

Reservation::addPerson(string personName, unsigned short mTime, string phoneNo)
{
  int MAX = getCount();

  Person * temp = nullptr;
  temp = new Person[MAX + 1];

  for(int i = 0; i < MAX; i++)
  {
    temp[i].name = elements[i].name;
    temp[i].militaryTime = elements[i].militaryTime;
    temp[i].phoneNum = elements[i].phoneNum;
  }

  temp[elementNum].name = personName;
  temp[elementNum].militaryTime = mTime;
  temp[elementNum].phoneNum = phoneNo;

  if(elementNum > 0)
    delete [] elements;

  elements = nullptr;
  elements = temp;

  elementNum++;

  bool swap = true;
  for(int i = elementNum - 1; i > 0 && swap == true; i--)
  {
    swap = false;
    for(int j = 0; j < i; j++)
    {
      if(elements[j].militaryTime > elements[j + 1].militaryTime)
      {
        temp = elements[j];
        elements[j] = elements[j + 1];
        elements[j + 1] = temp;
        swap = true;
      }
    }
  }
}

string displayTime (unsigned short t)
{
    unsigned short hour = t / 100;
    unsigned short minutes = t % 100;

    string strMinutes;
    if(minutes >= 10)
        strMinutes = to_string(minutes);
    else
        strMinutes = "0"+to_string(minutes);

    string strHour;
    if(hour == 0)
        strHour = "12";
    else if(hour < 13)
        strHour = to_string(hour);
    else
        strHour = to_string(hour - 12);

    string strAMPM;
    if(hour < 12)
        strAMPM = "am";
    else
        strAMPM = "pm";

    return strHour+":"+strMinutes+strAMPM;

}
