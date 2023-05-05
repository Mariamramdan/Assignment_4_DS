#ifndef UNTITLED58_STUDENT_H
#define UNTITLED58_STUDENT_H
#include<bits/stdc++.h>
using namespace std;

class Student {
    string name ;
    int id;
    float GPA;
public:
    Student();
    Student(string _name , int _id , float _GPA);
    int getId();
    string getName();
    float getGpa();
    void setName(string _name);
    void setId(int _id);
    void setGPA(float _GPA);

};


#endif //UNTITLED58_STUDENT_H
