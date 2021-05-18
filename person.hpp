#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
  string name, phoneNum;
  unsigned short militaryTime;

public:
  Person();

  void setName(string n)
  {
    name = n;
  }

  void setTime(unsigned short time)
  {
    while (time > 0)
    {
      int hour = time % 1000;
      hour /= 10;
      int minute = time % 100;

      if(hour > 23)
      {
        time = 0;
        break;
      }

      if(minute > 59)
      {
        time = 0;
        break;
      }
    }

    militaryTime = time;

  }

  void setPhone(string phone)
  {
    phoneNum = phone;
  }

  string getName()
  {
    return name;
  }

  string getTime()
  {
    return militaryTime;
  }

  string getPhone()
  {
    return phoneNum;
  }
};

string Person::name;
unsigned short Person::militaryTime;
string Person::phoneNum;

#endif
