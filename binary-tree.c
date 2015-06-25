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

/*===========================================================
 *
 *  -*-   A basic input functions to manipulate the tree  -*-
 *
 *===========================================================
 */

void leaf_node(tree *t){
    t->left = (tree *) NULL;
    t->right = (tree *) NULL;
}

meta_data new_meta() {
    meta_data thing;
    type_choose(&thing);
    thing.data = new_thing(thing.type);

    return thing;
}
void input_tree(tree *t){
    meta_data thing = new_meta();
    t->stuff = thing;
    leaf_node(t);
}


void start_tree(tree *t){
    puts("== Root of the tree ==");
    input_tree(t);
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
        printf("   ");
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

/*===========================================================
 *
 *  -*-               The search function                -*-
 *
 *===========================================================
 */

#define search_walk(orientation)\
    if (t->orientation != NULL) \
        search(t->orientation, element, deep + 1);\

void search(tree *t, meta_data element, int deep){
    if (element.data.real == t->stuff.data.real){
        printf("Found a element on deep %d\n", deep);
        print_element(element);
    }

    search_walk(left);
    search_walk(right);
}



/*===========================================================
 *
 *  -*-           The menu and big main code! :p         -*-
 *
 *===========================================================
 */

void menu(tree *t){
    int command;
    meta_data element_search;
    
    system(CLEAR);
    puts("A implementation of binary tree!\n\n");

    printf("1.Insert\n2.Remove\n3.Print\n4.Search\n0.Exit\n\n");
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
            puts("A tree representation of data!");
            print_tree(t, 0);
            printf("\n");
            break;
        case 4:
            element_search = new_meta();
            search(t, element_search, 0);
            break;
        case 0:
            printf("Exiting from universe...\n");
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
