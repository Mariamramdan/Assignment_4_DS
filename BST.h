#ifndef UNTITLED58_BST_H
#define UNTITLED58_BST_H
#include "Student.h"

class BSTNode{
public:
    Student data;
    BSTNode* Left;
    BSTNode* Right;


    BSTNode(){
        Left = Right = NULL;
    }

    BSTNode(Student stu){
        this->data = stu;
        Left = Right = NULL;
    }
};

class BST {
private:
    BSTNode* AddStudent(BSTNode * pNode ,Student stu);
    BSTNode * getMax(BSTNode* pNode);
    BSTNode * searchNode(BSTNode* pNode , int id);
    int max();
public:
    BSTNode* Root ;
    BST();
    void Add(Student stu);
    void printAll(BSTNode* pNode);
    BSTNode * Remove(BSTNode * pNode ,int id);
    bool Search (int id);

};


#endif //UNTITLED58_BST_H
