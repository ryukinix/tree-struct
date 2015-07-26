/*
 * =====================================================================================
 *
 *                      Copyright 2015 Manoel Vilela
 *
 *
 *       Filename:  binary-tree.c
 *
 *    Description:  A conceptual implementation of a binary tree
 *
 *         Author:  Manoel Vilela
 *        Contact:  manoel_vilela@engineer.com
 *   Organization:  UFPA
 *
 * =====================================================================================
**/



// standard headers
#include <stdio.h>
#include <stdlib.h>

// my headers
#include "headers/clear-pause.h"
#include "headers/tree-type.h"
#include "headers/meta-functions.h"

// macro utils 
#define LEFT 0
#define RIGHT 1

/*===========================================================
 *
 *  -*-   A basic input functions to manipulate the tree  -*-
 *
 *===========================================================
 */

void leaf_node(tree *t) {
    t->left = (tree *) NULL;
    t->right = (tree *) NULL;
}

void input_tree(tree *t) {
    meta_data meta;
    new_meta(&meta);
    t->element = meta;
    leaf_node(t);

}


void start_tree(tree **t) {
    puts("== Root of the tree ==");
    *t = (tree *) malloc(sizeof(tree)); 
    input_tree(*t);
}

/*===========================================================
 *
 *  -*-    Some macros and the insert function   -*-
 *
 *===========================================================
 */

#define macro_alloc(orientation) \
    t->orientation = (tree *) malloc(sizeof(tree));\
    input_tree(t->orientation);\


#define macro_walk(orientation)\
    if (t->orientation == NULL) {\
        macro_alloc(orientation);\
    }\
    else {\
        insert(t->orientation);\
    }\


int walk_menu (tree *t) {
    int direction;
    system(CLEAR);
    printf("]== Walk on the Tree ==[\n\n");
    printf("[left] -> %p\n[right] -> %p\n\n", t->left, t->right);
    printf("Left[0] or right[1]: ");
    scanf("%d", &direction);
    clear_buffer();

    return direction;
}


void insert(tree *t){
    int direction = walk_menu(t);

    if (direction == LEFT) {
        macro_walk(left);
    }
    else if (direction == RIGHT) {
        macro_walk(right);
    }
    else {
        pause("Wrong direction! Try again.\n");
        insert(t);
    }
}
void insert_tree(tree *t) {
    if (t != NULL)
        insert(t);
    else
        puts("Tree not initialized yet! Call start method first!\n");
}


/*===========================================================
 *
 *  -*-   A set of output functions to print the tree   -*-
 *
 *===========================================================
 */


#define macro_print(orientation) \
    printf("\n");\
    output_tree(deepness);\
    print_tree(t->orientation, deepness + 2);\


void output_tree(int deepness){
    int i;
    for(i = 0; i <= deepness; i++)
        printf("   ");
    printf("|=>");
}

void print_tree(tree *t, int deepness) {
    if (t == NULL){
        puts("Tree empty!");
        return;
    }
    print_element(t->element);
    
    if (t->left != NULL) {
        macro_print(left)
    }
    if (t->right != NULL) {
        macro_print(right)
    }
}

/*===========================================================
 *
 *  -*-               The search function                -*-
 *
 *===========================================================
 */

#define walk(function, orientation)\
    if (t->orientation != NULL) \
        function(t->orientation, element, deepness + 1);\

void search(tree *t, meta_data element, int deepness){
    if (union_comparision  (element.data, t->element.data)) {
        printf("Found a element on deepness %d: ", deepness);
        print_element(element);
        printf("\n");
    }

    walk(search, left);
    walk(search, right);
}


/*===========================================================
 *
 *  -*-               The remove_branch function                -*-
 *
 *===========================================================
 */

tree* null_branch(tree *t){
    // walk at left
    if (t != NULL)
        t->left = null_branch(t->left);
    // walk at right
    if (t != NULL)
        t->right = null_branch(t->right);
    
    // free the pointer node
    free(t);
    
    // points to nil
    t = NULL;

    return t;
}


tree* remove_branch(tree *t, meta_data element, int deepness) {
    if (union_comparision (element.data, t->element.data)) {
        printf("Deleted a delicious on deepness %d: ", deepness);
        print_element(element);
        printf("\n");
        t = null_branch(t);
    } else {
        if (t->left != NULL)
            t->left = remove_branch(t->left, element, deepness + 1);
        if (t->right != NULL)
            t->right = remove_branch(t->right, element, deepness + 1);
    }  
    
    return t;
}

/*===========================================================
 *
 *  -*-           The menu and big main code! :p         -*-
 *
 *===========================================================
 */

#define MENU \
"\
1.Start \n\
2.Insert \n\
3.Remove \n\
4.Edit \n\
5.Search \n\
6.Print \n\
7.Sort\n\
9.Prefix\n\
10.Posfix\n\
11.Infix\n\
12.Balance\n\
13.Sum of nodes numbers\n\
14.Sum of leafs numbers\n\
15.Deepness\n\n\
0.Exit\n\n\n"

void menu(tree *t) {
    int command;
    meta_data element_search;
    
    system(CLEAR);
    puts("A implementation of binary tree!\n\n");

    printf(MENU);
    printf("Type a command: ");

    scanf("%d", &command);
    clear_buffer();

    switch (command) {
        case 1:
            start_tree(&t);
            break;
        case 2:
            insert_tree(t);
            break;
        case 3:
            new_meta(&element_search);
            t = remove_branch(t, element_search, 0);
            break;
        case 5:
            new_meta(&element_search);
            search(t, element_search, 0);
            break;
        case 6:
            puts("A tree representation of data!");
            print_tree(t, 0);
            printf("\n");
            break;
        case 0:
            printf("Exiting from universe...\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Not implemented yet.\n");
            break;
    }
    pause("Press enter to continue...");
    menu(t);
}




int main(int argc, char *argv[]){
    tree *t = NULL;
   
    menu(t);

    return 0;
}
