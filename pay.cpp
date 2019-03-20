#include "person.cpp"
#include <fstream> //std::filestream
#include <iostream> // std::cout, std::fixed
#include <vector> //std::vector
#include <string> //std::string
#include <algorithm> //std::count
#include <iomanip> //std::setprecision

//vectors are dynamically allocated (which means that)
//(the size may be determined and changed at runtime)
using namespace std;

void readData(vector<Person> &employees) {
  string firstName, lastName, companyName;
  int employeeID;
  float hoursWorked, payRate;
  Person p;

  ifstream inputFile;
  inputFile.open("input.txt");

  if (inputFile.is_open())
  {
    while (inputFile >> firstName >> lastName >> employeeID >> companyName >> hoursWorked >> payRate)
    {
      p.setFirstName(firstName);
      p.setLastName(lastName);
      p.setEmployeeID(employeeID);
      p.setCompanyName(companyName);
      p.setHoursWorked(hoursWorked);
      p.setPayRate(payRate);
      employees.push_back(p);
    }
    inputFile.close();
  }
  else
  {
    cout << "Unable to open file.";
  }
}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{
  string cName;
  for (int i = 0; i < employees.size(); i++)
  {
    cName = employees[i].getCompanyName();
    if (count(companyNames.begin(), companyNames.end(), cName) == 0)
    {
      companyNames.push_back(cName);
    }
  }
}

void printHighestPaid(vector<Person> &employees)
{
  string fullName, companyName;
  int employeeID, found;
  float max;

  for (int i = 0; i < employees.size(); i++)
  {
    if (employees[i].totalPay() > max)
    {
      max = employees[i].totalPay();
      found = i;
    }
  }

  fullName = employees[found].fullName();
  employeeID = employees[found].getEmployeeID();
  companyName = employees[found].getCompanyName();

  cout << "Highest Paid: " << fullName << endl;
  cout << "Employee ID: " << employeeID << endl;
  cout << "Employer: " << companyName << endl;
  cout << "Total Pay: $" << fixed << setprecision(2) << employees[found].totalPay() << endl;
}

void separateAndSave(vector <Person> &employees, vector<string> &companyNames)
{
  for(int i = 0; i < companyNames.size(); i++){
     string company = companyNames[i] + ".txt";
     float totalPay = 0.00;
     ofstream file;
     file.open(company);
     file << "_______________________________________________________" << endl;
     for(int j = 0; j < employees.size(); j++)
     {
         if(employees[j].getCompanyName() == companyNames[i])
         {
             file << fixed << setprecision(2) << setw(10) << left << employees[j].getFirstName() << setw(9) << left << employees[j].getLastName()
              << setw(4) << right << employees[j].getEmployeeID() << " " <<
               employees[j].getCompanyName() << " $" << employees[j].totalPay() << endl;
             totalPay += employees[j].totalPay();
         }
     }
     file << fixed << setprecision(2) << "Total $" << totalPay;
     file.close();
 }
}

int main() {
  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getCompanies(employees, companyNames);
  printHighestPaid(employees);
  separateAndSave(employees, companyNames);
  return 0;
}
