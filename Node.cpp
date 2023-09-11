#include "Node.h"

Node::Node(int value) : data(value), link(nullptr) {}

int Node::getData() const {
    return data;
}

Node* Node::getLink() const {
    return link;
}

void Node::setLink(Node* nextNode) {
    link = nextNode;
}
