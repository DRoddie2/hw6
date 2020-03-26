//
// Created by The Rock Spot on 3/25/2020.
//

#ifndef HW6_REFCOUNT_H
#define HW6_REFCOUNT_H

#endif //HW6_REFCOUNT_H

typedef struct{
    int data;
    int refCount;
    Node next;
}Node;

Node* createNode(int data, int N);