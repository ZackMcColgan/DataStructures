/**
 * This creates a student roster using a tree structure
 * Zack McColgan
 * Project 5
 */

#include <stdio.h>
#include <stdlib.h>
#include "StudentRoster.h"
#include "Node.h"
#include "Tree.h"

struct StudentRoster
{
    TreeP tree; // A tree used by the student roster
};



/*
 * Returns a pointer to a new empty StudentRoster
 * If memory cannot be allocated, returns a NULL pointer
 */
StudentRosterP newStudentRoster()
{
   StudentRosterP roster = malloc(sizeof(struct StudentRoster));
   if(roster == NULL)
   {
       fprintf(stderr,"Memory allocation failed when creating roster!");
       return NULL;
   }
   roster->tree = newTree();
   
   return roster;
}

/*
 * Locates and displays the desired entry from the student roster
 * If entry is not found, display an appropriate message
 * Parameters: roster, id
 * Returns true if successful, else false
 */
int findStudentRoster(StudentRosterP roster, int id)
{
    find(roster->tree, id);
}

/*
 * Creates a node with the provided data
 * Inserts the node into the correct position in the tree
 * DO NOT insert a duplicate student ID
 * NOTE: Copy the name into the node
 * Display error message if duplicate is found
 * Parameters: roster, first name, id
 */
void insertStudentRoster(StudentRosterP roster, char *name, int id)
{ 
    insertTree(roster->tree,name,id);
    
}
/*
 * Removes the node containing the matching names
 * Parameters: StudentRoster, id
 */
void removeStudentRoster(StudentRosterP roster, int id)
{
    removeTree(roster->tree,id);
}

/*
 * Displays all the entries in the Phone book in order
 * Display one person per line, ID followed by first name
 */
void displayStudentRoster(StudentRosterP roster)
{
    treeToString(roster->tree);
}

/*
 * Frees the memory used by each node in the book
 * Frees the memory used by this roster
 * Parameter: roster
 * Returns NULL
 */
StudentRosterP freeStudentRoster(StudentRosterP roster)
{
    freeTree(roster->tree);
    free(roster);
}
