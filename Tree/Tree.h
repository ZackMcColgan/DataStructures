/* 
 * File:   Tree.h
 * Author: Zack McColgan
 *
 */

#ifndef TREE_H
#define	TREE_H


/**
 * A pointer to the Tree structure
 */
typedef struct Tree *TreeP;    

/*
 * Allocates memory and creates a new tree
 * Sets the root to NULL
 * Returns: a pointer to a new tree
 */
TreeP newTree();

/**
 * Inserts a node into the tree
 * @param temp a pointer to a node in the tree
 * @param node the node to be entered into the tree 
 */
void notEmpty (NodeP, NodeP);

/**
 * Traverses through the tree and prints the students in order 
 * by id
 * @param root The root of the tree
 */
void traverseToString (NodeP);


/**
 * Prints the tree
 * @param tree The tree that needs to be printed
 */
void treeToString(TreeP);  

/**
 * Searches for an id in a tree, if id is found
 * it prints the name and id of the student
 * @param tree The tree that will be searched
 * @param id   The id that will be searched for
 * @return     True = 1, False = 0
 */
int find(TreeP, int);

/**
 * The recursive search function used by the find function
 * @param root  the starting of the tree
 * @param id    the id to search for
 * @return   True = 1, False = 0
 */
int search(NodeP, int);

/**
 * Frees a selected tree
 * @param tree the tree to free
 */
void freeTree(TreeP);

/**
 * Performs a post order traversal to delete the tree
 * @param root The beginning of the tree
 */
void traverseFree(NodeP);

/**
 * Removes a specified student from the tree
 * @param root The start of the tree
 * @param id   The id of the student to delete
 */
void removeTree(NodeP, int);
    


#endif


