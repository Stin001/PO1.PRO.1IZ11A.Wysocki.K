#include "SpawnList.h"

SpawnList::SpawnList() : head(nullptr) {}

SpawnList::~SpawnList() {
    clear();
}

void SpawnList::add(float x, float y) {
    spawnObj* obj = new spawnObj(x, y);
    obj->spawnObject(x, y);
    Node* newNode = new Node(obj);
    newNode->next = head;
    head = newNode;
}

void SpawnList::updatePhysics() {
    Node* current = head;
    while (current) {
        current->data->opadanieFromList(head, current->data);
        current = current->next;
    }
}

void SpawnList::drawAll(sf::RenderWindow& window) {
    Node* current = head;
    while (current) {
        current->data->draw_and_refresh(window);
        current = current->next;
    }
}

void SpawnList::removeDead() {
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

void SpawnList::checkCollision(wahadlo& pendulum) {
    Node* current = head;
    while (current) {
        if (current->data->aliveObject &&
            current->data->getBounds().intersects(pendulum.getBounds())) {
            current->data->killObject();
            pendulum.dzwiek_replay();
        }
        current = current->next;
    }
}

void SpawnList::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current->data;
        delete current;
        current = next;
    }
    head = nullptr;
}

Node* SpawnList::getHead() const {
    return head;
}