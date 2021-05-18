#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../reservation.hpp"
#include "../person.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Person, constructor) {
  Person person;
  ASSERT_EQ(person.getName(), "") << "### ERROR calling Person constructor, the return value of getName should be an empty string ###";
  ASSERT_EQ(person.getTime(), 0) << "### ERROR calling Person constructor, the return value of getTime should be \'0\' ###";
  ASSERT_EQ(person.getPhone(), "") << "### ERROR calling Person constructor, the return value of getPhone should be an empty string ###";

}

TEST(Reservation, addPersonNoMax) {
  Reservation reservation;
  for(int i = 0; i < 200; i++){
    reservation.addPerson("Tuffy",100,"555-1212");
  }
  ASSERT_EQ(reservation.getName(199), "Tuffy") << "### ERROR calling addPerson, with the name Tuffy 200 times the name at element 199 should be \'Tuffy\' ###";
}

TEST(Reservation, addPersonCheckSort) {
  Reservation reservation;
  reservation.addPerson("Tuffy500",500,"555-1212");
  reservation.addPerson("Tuffy900",900,"555-1212");
  reservation.addPerson("Tuffy700",700,"555-1212");
  ASSERT_EQ(reservation.getName(1), "Tuffy700") << "### ERROR calling addPerson with (name Tuffy500 at time 500), (name Tuffy900 at time 900), (name Tuffy700 at time 700) added and sorted the time at element 1 should be \'Tuffy700\' ###";
}

TEST(Reservation, getPersonBeyondCount) {
  Reservation reservation;
  ASSERT_EQ(reservation.getName(20), "") << "### ERROR calling getName, with the element number much larger than the array size should be an empty string ###";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
