#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

class Employee {
  private:
    std::string eName;
    int id;
    float current_sal, new_sal;
    std::string status;

  public:
    void add_employee(int, std::string, float);
    void increment(float);
    void decrement(float);
    void updateStatus();
    void display();
    int getID();
    std::string getStatus();
    float getNewSalary();
};

int Employee::getID(){
  return this->id;
}

void Employee::add_employee(int id, std::string eName, float current_sal){
  this->id = id;
  this->eName = eName;
  this->current_sal = current_sal;
}

void Employee::increment(float inc){
  this->new_sal = inc + current_sal;
  updateStatus();
}

void Employee::decrement(float dec){
  this->new_sal = current_sal - dec;
  updateStatus();
}

void Employee::updateStatus(){
  if(new_sal < 50000.0 || new_sal == current_sal){
    status = "NO-CHANGE";
  } else if (new_sal >= 50000.0) {
    status = "PROMOTED";
  } else {
    status = "DEMOTED";
  }
}

void Employee::display() {
  std::cout<<std::setw(25)<<id<<std::setw(25)<<eName<<std::setw(25)<<current_sal<<std::setw(25)<<new_sal<<std::setw(25)<<status<<std::endl;
}

std::string Employee::getStatus() {
  return status;
}

float Employee::getNewSalary() {
  return new_sal;
}

int main() {
  int EMPLOYEE_COUNT;
  std::cout << "Enter the number of employees: ";
  std::cin >> EMPLOYEE_COUNT;

  Employee eArray[EMPLOYEE_COUNT];


  std::string eName;
  int id;
  float current_sal, new_sal;
  for(int i=0; i<EMPLOYEE_COUNT; i++){
    std::cout << "Enter details for employee no. " << i << std::endl;

    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter name: ";
    std::getline(std::cin, eName);

    std::cout << "Enter current salary: ";
    std::cin >> current_sal;

    eArray[i].add_employee(id, eName, current_sal);
  }

  int choice;
  float amount;
  std::cout << "1: Increment\n2: Decrement\n";

  for(int i = 0; i < EMPLOYEE_COUNT; i++){
    std::cout << "\nEnter your choice for employee "<< eArray[i].getID() <<": ";
    std::cin >> choice;

    std::cout << "\nEnter the amount: ";
    std::cin >> amount;
    
    switch (choice) {
      case 1 : eArray[i].increment(amount); break;
      case 2 : eArray[i].decrement(amount); break;
      default: std::cout << "Enter a valid choice!"; i--;
    }
  }

  std::cout<<std::setw(25)<<"ID"<<std::setw(25)<<"Name"<<std::setw(25)<<"Current"<<std::setw(25)<<"New"<<std::setw(25)<<"Status"<<std::endl;
  for(int i=0; i < EMPLOYEE_COUNT; i++){
    eArray[i].display();
  }

  return 0;
}
