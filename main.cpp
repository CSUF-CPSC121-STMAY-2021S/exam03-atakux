//Name: Angela DeLeo
//Date: 05.09.2021
//Exercise: Exam03 Solution

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "person.hpp"
#include "reservation.hpp"

using namespace std;

int main()
{
  int MAX = 25;
  int count = 0;
  Reservation reserve[MAX];
  unsigned short timeyTime;
  string pName, phone;

  do{
    cout << "*** TUFFY TITAN RESERVATION PROGRAM ***" << endl;

    cin.ignore();
    cout << endl << "Enter new name or 'exit': ";
    getline(cin, pName);
    reserve[count].setName(pName);

    cout << endl << "Enter military time: ";
    cin >> timeyTime;
    reserve[count].setTime(timeyTime);

    cout << endl << "Enter phone: ";
    getline(cin, phone);
    reserve[count].setPhone(phone);

    reserve[count].addPerson(pName, timeyTime, phone);

    count++;

    cout << endl;
    cout << "Time                Name                Phone               " << endl;
    cout << "============================================================" << endl;
    for(int i = 0; i <= count; i++)
    {
      unsigned short mcTime = reserve[i].getTime(i);

      cout << left << setw(20) << reserve[i].displayTime(mcTime)
           << left << setw(20) << reserve[i].getName(i)
           << left << setw(20) << reserve[i].getPhone(i)
           << setw(20) << setfill(' ') << endl;
    }
    
  }while(name != "exit" || count != MAX);

  return 0;
}
