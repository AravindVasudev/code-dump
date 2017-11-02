#include <iostream>
#include <string>
#include "aadhar.h"

int main() {
  std::string aadhar_number;

  std::cout << "Enter Aadhar Card: ";
  std::getline(std::cin, aadhar_number);

  std::cout << Aadhar::is_aadhar_valid(aadhar_number);
}