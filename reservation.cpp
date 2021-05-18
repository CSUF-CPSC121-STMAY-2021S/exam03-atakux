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

void Reservation::addPerson(string UserName, unsigned short mTime, string phoneNo)
{
  int MAX = getCount();

  User * temp = nullptr;
  temp = new User[MAX + 1];

  for(int i = 0; i < MAX; i++)
  {
    temp[i].name = elements[i].name;
    temp[i].militaryTime = elements[i].militaryTime;
    temp[i].phoneNum = elements[i].phoneNum;
  }

  temp[elementNum].name = UserName;
  temp[elementNum].militaryTime = mTime;
  temp[elementNum].phoneNum = phoneNo;

  if(elementNum > 0)
    delete [] elements;

  elements = nullptr;
  elements = temp;

  elementNum++;

}
