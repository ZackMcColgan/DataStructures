/*
 * Node.h
 * Zack McColgan
 */

#ifndef _node_h
#define _node_h

#define TRUE 1
#define FALSE 0

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
NodeP newNode(char *, int);

/*
 * Calls the compareTo on the info portion of two nodes
 * Parameters: the two node pointers
 * Return:
 *    negative if node1 < node2
 *    zero if node1 == node2
 *    positive if node1 > node2
 */
int compareToNode(NodeP, NodeP);

/*
 * Swaps info portion of node1 and node2
 * Parameters: two nodes
 */
void swapNode(NodeP, NodeP);



/*
 * Frees the memory used by this node
 * Parameter: Pointer to the node
 * Return:
 *    NULL
 */
NodeP freeNode(NodeP);

#endif
