#include <iostream>
#include <string>

class Student {
  private: 
    std::string name, branch;
    int rollNo;
    char gender;

  public:
    void setData(std::string, int, std::string, char);
    void displayData();
};

void Student::setData(std::string name, int rollNo, std::string branch, char gender) {
  this->gender = gender;
  this->name = name;
  this->rollNo = rollNo;
  this->branch = branch;
}

void Student::displayData(){ std::cout << "Name: " << this->name << "\n" << "Roll No.: " << this->rollNo << "\n" << "Branch: " << this->branch << "\n" << "Gender: " << this->gender << std::endl; }

int main() {
  Student students[3];
  std::string name, branch;
  int rollNo;
  char gender;

  for(int i = 0; i < 3; i++) {
    std::cout << "Enter the details of student " << i+1 << ": " << "\n";

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Roll no.: ";
    std::cin >> rollNo;
    
    std::cout << "Enter Branch: ";
    std::getline(std::cin, branch);

    std::cout << "Enter Gender: ";
    std::cin >> gender;

    students[i].setData(name, rollNo, branch, gender);
  }

  for(int i = 0; i < 3; i++) {
    std::cout << "Details of student " << i+1 << ": " << std::endl;
    students[i].displayData();
  }

  return 0;
}
