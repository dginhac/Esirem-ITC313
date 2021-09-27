/**
  * @File:     date-main.cpp
  * @Author:   D. Ginhac (dginhac@u-bourgogne.fr)
  * @Date:     Fall 2021
  * @Course:   C-C++ Programming / Esirem 3A Informatique Electronique Robotique
  * @Summary:  Methods
  */

#include "date.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Date a_day(7,31);
  std::cout << "a day: " << a_day.day() << "/" << a_day.month() << std::endl;
  std::cout << "day #" << a_day.dayOfYear() << std::endl;
  a_day.next();
  std::cout << "a day++: " << a_day.day() << "/" << a_day.month() << std::endl;
  a_day.back();
  std::cout << "a day: " << a_day.day() << "/" << a_day.month() << std::endl;
  return 0;
}
