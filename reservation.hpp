#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "person.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Reservation : public Person
{
private:
  int elementNum;
  Person * elements;

public:
  Reservation();

  void addPerson(string, unsigned short, string);

  int getCount()
  {
    return elementNum;
  }

  string getName(int x)
  {
    return elements[x].name;
  }

  int getTime(int x)
  {
    return elements[x].militaryTime;
  }

  string getPhone(int x)
  {
    return elements[x].phoneNum;
  }

  string displayTime(unsigned short);

  ~Reservation();

};


#endif
