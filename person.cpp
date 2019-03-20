#include "person.h"

//include scope resolution to let compiler know that you
//are defining a function for the class Person
//lets compiler know that variables referenced in the
//function can be found within that class
Person::Person() {}

void Person::setFirstName(string fName) {
  firstName = fName;
}

string Person::getFirstName() {
  return firstName;
}

void Person::setLastName(string lName) {
  lastName = lName;
}

string Person::getLastName() {
  return lastName;
}

void Person::setEmployeeID(int id) {
  employeeID = id;
}

int Person::getEmployeeID() {
  return employeeID;
}

void Person::setCompanyName(string coName) {
  companyName = coName;
}

string Person::getCompanyName() {
  return companyName;
}

void Person::setHoursWorked(float hours) {
  hoursWorked = hours;
}

float Person::getHoursWorked() {
  return hoursWorked;
}

void Person::setPayRate(float rate) {
  payRate = rate;
}

float Person::getPayRate() {
  return payRate;
}

float Person::totalPay() {
  float total = hoursWorked * payRate;
  return total;
}

string Person::fullName() {
  string fullName = firstName + " " + lastName;
  return fullName;
}
