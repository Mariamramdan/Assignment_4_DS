#include "Student.h"

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

float Student::getGpa() {
    return GPA;
}

void Student::setName(string _name) {
    this->name = _name;
}

void Student::setId(int _id) {
    this->id = _id;
}

void Student::setGPA(float _GPA) {
    this->GPA =_GPA;
}

Student::Student() {
    this->name = " ";
    this->id = 0;
    this-> GPA = 0.0;
}

Student::Student(string _name, int _id, float _GPA) {
    this->name = _name;
    this->id = _id;
    this-> GPA = _GPA;
}
