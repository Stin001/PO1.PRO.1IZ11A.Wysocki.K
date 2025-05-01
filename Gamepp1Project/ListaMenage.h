#pragma once

#include "spawnObj.h"
#include "wahadlo.h"

struct Node {
    spawnObj* data;
    Node* next;

    Node(spawnObj* d) : data(d), next(nullptr) {}
};


class ListaMenage {


private:
    Node* head;

public:
    ListaMenage();
    ~ListaMenage();

    void add(float x, float y);           

    void updatePhysics();                    

    void drawAll(sf::RenderWindow& window);           

    void removeDead();                                 

    void checkCollision(wahadlo& pendulum);            

    void clear();                                      

    void printList() const;  

    Node* getHead() const;                             
};