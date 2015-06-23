/*===========================================================
 *
 *  -*- fundamental structures to create a binary tree    -*-
 *
 *===========================================================
 */

#include "meta-type.h"

/*
 * A node abstraction
 *
 */

struct node {
    meta_data stuff;   
    struct node *left; 
    struct node *right;
};


/*
 * A abstraction for tree
 *
 */
typedef struct node tree;
