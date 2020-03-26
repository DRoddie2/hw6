//
// Created by Danielle Rodriguez on 3/25/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "refcount.h"

int main(){
    /* Get number of nodes from input */
    int N;
    scanf("%i", &N);

    /* Create array of nodes to keep track of the nodes mentioned in the assignment statements to avoid duplicates */
    Node** nodes = (Node**)malloc(sizeof(Node*)*(N+1));
    for(int i = 0; i < (N+1); i++){
        nodes[i] = NULL;
    }

    /* Parse through assignment statements */
    for(;;){
        if(feof(stdin)) break;
        char c;
        int src, dest;
        scanf("%c %i->%i\n", &c, &src, &dest);
        /* check node index (will depend on if c == 'V' or 'L' */
        int srcIndexCap;
        if(c == 'V'){
            srcIndexCap = 9;
        }
        else{
            srcIndexCap = N;
        }
        if(src > srcIndexCap || src < 1 || dest > N || dest < 0)
        {
            fprintf(stderr, "Invalid node index specified");
            exit(1);
        }

        if(nodes[src] == NULL){
            nodes[src] = createNode(src, N);
        }
        if(nodes[dest] == NULL && dest != 0){
            nodes[dest] = createNode(dest, N);
        }

        nodes[src]->next = dest;
        nodes[dest]->refCount++;
    }

    for(int i = 0; i < 9; i++){
        if(nodes[i] == NULL) continue;
        printf("Node %i has %i incoming pointers \n", nodes[i]->data, nodes[i]->refCount);
    }


    return 0;
}

/* Initialize a new node */
Node* createNode(int data, int N){
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->refCount = 0;
    n->next = NULL:
}
