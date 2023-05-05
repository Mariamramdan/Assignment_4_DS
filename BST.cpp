#include<bits/stdc++.h>
#include "BST.h"
BST::BST() {
    Root = NULL;
}

BSTNode* BST::AddStudent(BSTNode * pNode , Student stu) {
    if (pNode == NULL){
        BSTNode * newNode = new BSTNode();
        newNode->data = stu;
        pNode = newNode;
    } else if (stu.getId() < pNode->data.getId()){
        pNode->Left = AddStudent(pNode->Left , stu);
    } else if (stu.getId() > pNode->data.getId()){
        pNode->Right = AddStudent(pNode->Right , stu);
    }

    return pNode;
}

void BST::Add(Student stu) {
    Root = AddStudent(Root , stu);
}

void BST::printAll(BSTNode *pNode) {
    queue<BSTNode*> Q ;
    if(pNode != NULL){
        Q.push(pNode);
        while (Q.empty() == false){
            BSTNode* newNode = Q.front();
            cout<<newNode->data.getName()<<" "<<newNode->data.getId()<<" "<<newNode->data.getGpa()<<endl;
            Q.pop();
            if (newNode->Left != NULL)
                Q.push(newNode->Left);
            if (newNode->Right != NULL)
                Q.push(newNode->Right);
        }
    }
}

BSTNode * BST::Remove(BSTNode * pNode ,int id) {
    if(pNode == NULL)
        return pNode;
    else if (pNode->data.getId() > id)
        pNode->Left = Remove(pNode->Left , id);
    else if (pNode->data.getId() < id)
        pNode->Right = Remove(pNode->Right , id);
    else{
        if (pNode->Left == NULL && pNode->Right == NULL){
            delete pNode;
            pNode = NULL;
        }
        else if (pNode->Left != NULL && pNode->Right == NULL){
            BSTNode* tmp = pNode;
            pNode = pNode->Left;
            delete tmp;
        }
        else if (pNode->Left == NULL && pNode->Right != NULL){
            BSTNode* tmp = pNode;
            pNode = pNode->Right;
            delete tmp;
        }
        else{
           BSTNode * tmp = getMax(pNode->Left);
           pNode->data.setId(tmp->data.getId());
           pNode->Left = Remove(pNode->Left , tmp->data.getId());
        }
    }
    return pNode;
}

BSTNode *BST::getMax(BSTNode *pNode) {
    if (pNode == NULL)
        return pNode;
    else if (pNode->Right == NULL)
        return pNode;
    else
        return getMax(pNode->Right);
}

int BST::max() {
    BSTNode* get = getMax(Root);
    return get->data.getId();
}

bool BST::Search(int id) {
    BSTNode * SR = searchNode(Root , id);
    if (SR == NULL) {
        cout << "Student is not found.\n";
        return false;
    }
    else {
        cout << "Student is Found.\n";
        cout << "[" << SR->data.getId() << " , " << SR->data.getName() << " , " << SR->data.getGpa() << "]"<<endl;
        return true;
    }
}

BSTNode *BST::searchNode(BSTNode *pNode, int id) {
    if (pNode == NULL)
        return pNode;
    else if (pNode->data.getId() == id)
        return pNode;
    else if (pNode->data.getId() > id)
        return searchNode(pNode->Left , id);
    else if (pNode->data.getId() < id)
        return searchNode(pNode->Right , id);
}


