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

  unsigned short getTime()
  {
    return militaryTime;
  }

  string getPhone()
  {
    return phoneNum;
  }
};

#endif
