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



//standard headers
#include <stdio.h>
#include <stdlib.h>

// my headers
#include "headers/clear-pause.h"
#include "headers/tree-type.h"
#include "headers/meta-functions.h"

#define LEFT 0
#define RIGHT 1
#define CLEAR "cls || clear"


void input_tree(tree *t){
    meta_data thing;
    type_choose(&thing);
    thing.data = new_thing(thing.type);
    t->stuff = thing;

    //to pointer to nil the orientations;
    t->left = (tree *) NULL;
    t->right = (tree *) NULL;

}

void start_tree(tree *t){
    puts("== Root of the tree ==");
    input_tree(t);
}

/*===========================================================
 *
 *  -*-    Some macros to auxiliate the insert function   -*-
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


void insert(tree *t){
    int direction;
    system(CLEAR);
    printf("]== Walk on the Tree ==[\n\n");
    printf("[left] -> %p\n[right] -> %p\n\n", t->left, t->right);
    printf("Left[0] or right[1]: ");
    scanf("%d", &direction);
    clear_buffer();

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

/*===========================================================
 *
 *  -*-   A set of output functions to print the tree   -*-
 *
 *===========================================================
 */


#define macro_print(orientation) \
    printf("\n");\
    output_tree(deep);\
    print_tree(t->orientation, deep + 2);\


void output_tree(int deep){
    int i;
    for(i = 0; i <= deep; i++)
        printf("  ");
    printf("|=>");
}

void print_tree(tree *t, int deep){
    print_element(t->stuff);
    
    if (t->left != NULL){
        macro_print(left)
    }
    if (t->right != NULL){
        macro_print(right)
    }
}

void menu(tree *t){
    int command;
    
    system(CLEAR);
    puts("A implementation of binary tree!\n\n");

    printf("1.Insert\n2.Remove\n3.Search\n4.Print\n0.Exit\n\n");
    printf("Type a command: ");

    scanf("%d", &command);
    clear_buffer();

    switch (command) {
        case 1:
            insert(t);
            break;
        case 2:
            printf("Not implemented yet.\n");
            break;
        case 3:
            printf("Not implemented yet.\n");
            break;
        case 4:
            puts("A tree representation of data!");
            print_tree(t, 0);
            printf("\n");
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("You are a crazy?! Don't have this option.\n");
            break;
    }
    pause("Press enter to continue...");
    menu(t);
}


int main(int argc, char *argv[]){
    tree t;
    start_tree(&t);
    menu(&t);

    return 0;
}
