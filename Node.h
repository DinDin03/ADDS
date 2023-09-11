#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    Node(int value);
    int getData() const;
    Node* getLink() const;
    void setLink(Node* nextNode);
};

#endif // NODE_H
