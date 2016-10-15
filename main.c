//
//  main.c
//  waitqueue_implement
//
//  Created by Henry Zhou on 10/15/16.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

/*
 * this file implements the basic functionalities of a queue
 * this code is for the preparation for lab 3 in ece344
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int *data;
    struct Node *next;
}Node;

struct wait_queue {
    Node *first;
    Node *last;
};


//create a wait queue
struct wait_queue *
wait_queue_create()
{
    struct wait_queue *wq;
    
    wq = malloc(sizeof(struct wait_queue));
    wq->first = NULL;
    wq->last = NULL;
    
    return wq;
}

//print the data in queue. for testing purposes
void printqueue(struct wait_queue *wq){
    Node *curr = wq->first;
    while (curr != NULL){
        printf("%d ", *curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void push_ele(struct wait_queue *wq, Node *new_ele){
    if (wq->first == NULL){ //no element in the list
        wq->first = new_ele;
        wq->last = new_ele;
        return;
    }
    else{
        wq->last->next = new_ele;
        wq->last = new_ele;
        return;
    }
}

//clear the element in queue to ensure no memory leak
void
wait_queue_destroy(struct wait_queue *wq)
{
    while (wq->first != NULL){
        Node *curr = wq->first;
        wq->first = curr->next;
        free(curr->data);
        free(curr);
    }
    free(wq);
}

int main() {
    
    struct wait_queue *myqueue = wait_queue_create();
    
    for (int i = 0; i < 15; i++){
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->data = (int *)malloc(sizeof(int));
        *(new_node->data) = i;
        new_node->next = NULL;
        push_ele(myqueue, new_node);
    }
    
    printqueue(myqueue);
    
    
    
    wait_queue_destroy(myqueue);
    
    return 0;
}
