/**
 * Implements the node that is used by the tree
 * Zack McColgan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node *NodeP;



/*
 * Defines one node in the Binary Search Tree
 */
struct Node 
{
    struct Node *L;   // Points to the left
    char name[30];    // The first name of the student
    int  id;          // The students id
    struct Node *R;   // Points to the right
};




/*
 * Interface to a Node
 */

/*
 * Returns a pointer to a new Node
 * Creates a new Node containing the data supplied by the pointer
 * If memory cannot be allocated, returns a NULL pointer
 */
NodeP newNode(char *name, int id)
{
    NodeP node = malloc(sizeof(struct Node));
    if(node == NULL)
    {
        fprintf(stderr,"Node memory allocation failed!!!\n");
        exit(1);
    }
    
    strcpy(node->name,name);   // Puts the name into the node
    node->id = id;    // Puts the id into the node
    node->L = NULL;      // Sets the left pointer to null
    node->R = NULL;     // Sets the right pointer to null
    
    
    
    
    
    return node;
    
}




/*
 * Calls the compareTo on the info portion of two nodes
 * Parameters: the two node pointers
 * Return:
 *    negative if node1 < node2
 *    zero if node1 == node2
 *    positive if node1 > node2
 */
int compareToNode(NodeP node1, NodeP node2)
{
    
}

/*
 * Frees the memory used by this node
 * Parameter: Pointer to the node
 * Return: NULL
 */
NodeP freeNode(NodeP node)
{
    free(node->L);
    free(node->R);
    free(node->name);
    free(node->id);
    free(node);
    return NULL;
}
