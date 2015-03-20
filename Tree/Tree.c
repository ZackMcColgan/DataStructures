#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

/**
 * A tree structure that uses nodes
 */
struct Tree
{
    NodeP root;  // The root of the tree
};

typedef struct Tree *TreeP;

/*
 * Allocates memory and creates a new tree
 * Sets the root to NULL
 * Returns: a pointer to a new tree
 */
TreeP newTree()
{
    TreeP tree = malloc(sizeof(struct Tree));
    if(tree == NULL)
    {
        fprintf(stderr,"Memory allocation failed when creating tree!!");
        exit(1);
    }
    
    tree->root = NULL;
    return tree;
}

/**
 * Inserts a node into the tree
 * @param temp a pointer to a node in the tree
 * @param node the node to be entered into the tree 
 */
void notEmpty (NodeP temp, NodeP node)
{
    /**
     * If a duplicate
     */
    if(node->id == temp->id)
    {
        printf("Duplicate student found!! \n");
        return;
    }
    /**
     * If to the left
     */
    if(node->id < temp->id)
    {
      if(temp->L == NULL)  
      {
          temp->L = node;
      }
      else 
      {
         temp =  temp->L;
         notEmpty(temp,node);
      }
    }
    
    /**
     * If to the right
     */
     if(node->id > temp->id)
    {
      if(temp->R == NULL)  
      {
          temp->R = node;
      }
      else 
      {
         temp =  temp->R;
         notEmpty(temp,node);
      }
    }
    
}

/*
 * Inserts a node with data into the tree
 */
void insertTree(TreeP tree,char *name,int id)
{
    NodeP node = newNode(name,id);
    
    /**
     * If the tree is empty
     */
    if(tree->root == NULL)
    {
        tree->root = node;
        return;
    }
    
    /**
     * If there is something in the tree
     */
    if(tree->root != NULL)
    {
      NodeP temp = tree->root; // Starts at the root
      notEmpty(temp,node);
    
    }
    
}



/**
 * Searches for an id in a tree, if id is found
 * it prints the name and id of the student
 * @param tree The tree that will be searched
 * @param id   The id that will be searched for
 * @return     True = 1, False = 0
 */
int find(TreeP tree, int id)
{
    int true = 1;
    int false = 0;
    int boolean; 
    
    
    if(tree->root == NULL)
    {
        printf("The id was not found");
        return false;
    }
    NodeP root = tree->root;
    
   
    boolean = search(root,id);
    
     if(boolean == false)
    {
        printf("The id was not found \n");
        return false;
    }
     else return true;
}

/**
 * The recursive search function used by the find function
 * @param root  the starting of the tree
 * @param id    the id to search for
 * @return   True = 1, False = 0
 */
int search(NodeP root, int id)
{
    int true = 1;
    int false = 0;
    
    if(root->id == id)
    {
        printf("Found: %s   %i \n",root->name,root->id);
        return 1;
    }
    
   if (root->L != NULL)
    {
        search(root->L,id);
    }
    
     
    if (root->R != NULL)
    {
        search(root->R,id);
    } 
}

/**
 * Traverses through the tree and prints the students in order 
 * by id
 * @param root the root of the tree
 */
void traverseToString (NodeP root)
{
    if (root->L != NULL)
    {
        traverseToString (root->L);
    }
     printf("%i     %s \n",root->id,root->name);
     
    if (root->R != NULL)
    {
        traverseToString (root->R);
    }
}

/**
 * Prints the tree
 * @param tree the tree that needs to be printed
 */
void treeToString(TreeP tree)
{
   NodeP temp = tree->root;
   
   traverseToString(temp);
  
}

/**
 * Performs a post order traversal to delete the tree
 * @param root The beginning of the tree
 */
void traverseFree(NodeP root)
{
    int result;
    
     if (root == NULL) return;
 
    /* Deletes the children */
    traverseFree(root->L);
    traverseFree(root->R);
   
    free(root);  // Frees the node
    

}

/**
 * Frees a selected tree
 * @param tree the tree to free
 */
void freeTree(TreeP tree)
{
   
   NodeP temp = tree->root;
   
   traverseFree(temp);
    
}

/**
 * Removes a specified student from the tree
 * @param root The start of the tree
 * @param id   The id of the student to delete
 */
void removeTree(NodeP root, int id)
{
    /**
     * If the tree has no children
     */
    if(root->L == NULL && root->R == NULL && root->id == id)
    {
        root = NULL;
    }
}


/**
 * A modified find in order to find the node to delete
 * Searches for an id in a tree, if id is found
 * it prints the name and id of the student
 * @param tree The tree that will be searched
 * @param id   The id that will be searched for
 * @return     True = 1, False = 0
 */
int findToDelete(TreeP tree, int id)
{
    int true = 1;
    int false = 0;
    int boolean; 
    
    
    if(tree->root == NULL)
    {
        printf("The id was not found");
        return false;
    }
    NodeP root = tree->root;
    
   
    boolean = search(root,id);
    
     if(boolean == false)
    {
        printf("The id was not found \n");
        return false;
    }
     else return true;
}

/**
 * The recursive search function used by the find function
 * @param root  the starting of the tree
 * @param id    the id to search for
 * @return   True = 1, False = 0
 */
int searchToDelete(NodeP root, int id)
{
    int true = 1;
    int false = 0;
    
    if(root->id == id)
    {
        printf("Found: %s   %i \n",root->name,root->id);
        return 1;
    }
    
   if (root->L != NULL)
    {
        searchToDelete(root->L,id);
    }
    
     
    if (root->R != NULL)
    {
        searchToDelete(root->R,id);
    } 
}
