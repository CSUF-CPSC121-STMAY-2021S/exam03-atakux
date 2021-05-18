#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "person.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct User
{
  string name, phoneNum;
  unsigned short militaryTime;
};

class Reservation
{
private:
  int elementNum;
  User * elements;

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

  unsigned short getTime(int x)
  {
    return elements[x].militaryTime;
  }

  string getPhone(int x)
  {
    return elements[x].phoneNum;
  }


  ~Reservation();

};


#endif
