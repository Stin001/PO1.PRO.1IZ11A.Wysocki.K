#include "ListaMenage.h"
#include <iostream>

ListaMenage::ListaMenage() : head(nullptr) {}

ListaMenage::~ListaMenage() {
    clear();
}

void ListaMenage::add(float x, float y) {
    spawnObj* obj = new spawnObj(x, y);
    obj->spawnObject(x, y);
    Node* newNode = new Node(obj);
    newNode->next = head;
    head = newNode;
}

void ListaMenage::updatePhysics() {    
    Node* current = head;
    while (current) {
        Node* checker = head;
        bool collisionDetected = false; 

        
        while (checker) {  
            if (checker->data != current->data && checker->data->aliveObject) {
                sf::FloatRect nextPos = current->data->getBounds();
                nextPos.top += opadanie_speed; 

                if (nextPos.intersects(checker->data->getBounds())) {
                    sf::Vector2f pos = current->data->object.getPosition();
                    float y = checker->data->object.getPosition().y - current->data->object.getSize().y;
                    current->data->object.setPosition(pos.x, y); 
                    collisionDetected = true; 
                    break; 
                }
            }
            checker = checker->next;
        }

        
        if (!collisionDetected) {      // spadanie obiektu bez kolicji 
            sf::Vector2f pos = current->data->object.getPosition();
            float bottom = pos.y + current->data->object.getSize().y;

            if (bottom < border_down_map) {
                current->data->object.move(0, opadanie_speed);  
            }
            else {
                current->data->object.setPosition(pos.x, border_down_map - current->data->object.getSize().y);
            }
        }

        current = current->next;
    }
}

void ListaMenage::drawAll(sf::RenderWindow& window) {  // draw elements of porgram 
    Node* current = head;
    while (current) {
        current->data->draw_and_refresh(window);
        current = current->next;
    }
}

void ListaMenage::removeDead() {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (!current->data->aliveObject) {
            Node* toDelete = current;
            if (prev)
                prev->next = current->next;
            else
                head = current->next;

            current = current->next;

            delete toDelete->data;
            delete toDelete;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void ListaMenage::checkCollision(wahadlo& pendulum) {  
    Node* current = head;
    while (current) {
        if (current->data->aliveObject &&
            current->data->getBounds().intersects(pendulum.getBounds())) {
            current->data->killObject();
            pendulum.dzwiek_replay();
            std::cout << " nastapilo uderzenie \n  " ;
        }
        current = current->next;
    }
}

void ListaMenage::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = nullptr;
}

void ListaMenage::printList() const    // print list 
{

    Node* current = head;
    int index = 0;
    while (current) {
        std::cout << "Object " << index++ << " - ";
        if (current->data->aliveObject) {
            std::cout << "Alive, ";
        }
        
        sf::Vector2f pos = current->data->object.getPosition();
        std::cout << "Position: (" << pos.x << ", " << pos.y << ")\n";
        current = current->next;
    }


}

Node* ListaMenage::getHead() const {
    return head;
}