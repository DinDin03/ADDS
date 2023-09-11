#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (array && len > 0) {
        for (int i = 0; i < len; i++) {
            insertPosition(i + 1, array[i]);
        }
    }
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 0) {
        pos = 1;
    }

    Node* newNode = new Node(newNum);

    if (pos == 1 || !head) {
        newNode->setLink(head);
        head = newNode;
    } else {
        Node* current = head;
        int count = 1;

        while (current->getLink() != nullptr && count < pos - 1) {
            current = current->getLink();
            count++;
        }

        newNode->setLink(current->getLink());
        current->setLink(newNode);
    }
}

bool LinkedList::deletePosition(int pos) {
    if (pos <= 0) {
        return false;
    }

    if (pos == 1 && head != nullptr) {
        Node* temp = head;
        head = head->getLink();
        delete temp;
        return true;
    } else {
        Node* current = head;
        int count = 1;

        while (current != nullptr && count < pos - 1) {
            current = current->getLink();
            count++;
        }

        if (current == nullptr || current->getLink() == nullptr) {
            return false;
        }

        Node* temp = current->getLink();
        current->setLink(temp->getLink());
        delete temp;
        return true;
    }
}

int LinkedList::get(int pos) {
    if (pos <= 0) {
        return std::numeric_limits<int>::max();
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr && count < pos) {
        current = current->getLink();
        count++;
    }

    if (current == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return current->getData();
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        if (current->getData() == target) {
            return index;
        }
        current = current->getLink();
        index++;
    }

    return -1;
}

void LinkedList::printList() {
    Node* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->getData();
        current = current->getLink();
        if (current != nullptr) {
            std::cout << " ";
        }
    }
    std::cout << "]" << std::endl;
}
