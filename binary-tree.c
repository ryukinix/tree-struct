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
#include <stdbool.h>

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


void insert_data(tree *t) {
    meta_data meta;
    new_meta(&meta);
    t->element = meta;
}


void input_tree(tree *t) {
    insert_data(t);
    leaf_node(t);
}


void start_tree(tree **t) {
    puts("== Root of the tree ==");
    *t = (tree *) malloc(sizeof(tree));
    input_tree(*t);
}


int empty_tree(tree *root) {
    if (root == NULL){
        puts("Tree root not initialized yet! Call start method first!\n");
        return true;
    }
    else {
        return false;
    }
}

/*===========================================================
 *
 *  -*-            Some attributes of tree             -*-
 *
 *===========================================================
 */

int isleaf(tree *t) {
    return (t->left == NULL) && (t->right == NULL);
}


int nodes_sum(tree *t, int nodes) {
    // verify the node is not null
    if (t == NULL)
        return nodes;
    // walk to left
    if (t->left != NULL)
        nodes = nodes_sum(t->left, nodes);

    // walk to right
    if (t->right != NULL)
        nodes = nodes_sum(t->right, nodes);

    return nodes + 1;
}


int leaf_sum(tree *t, int leafs) {
    // verify the node is not null
    if (t == NULL)
        return leafs;

    // walk to left
    if (t->left != NULL)
        leafs = leaf_sum(t->left, leafs);

    // walk to right
    if (t->right != NULL)
        leafs = leaf_sum(t->right, leafs);

    if (isleaf(t))
        leafs += 1;

    return leafs;

}

int deepness_count(tree *t, int deepness) {
    int left  = deepness;
    int right = deepness;
    // walk to left
    if (t->left != NULL)
        left = deepness_count(t->left, deepness + 1);

    // walk to right
    if (t->right != NULL)
        right = deepness_count(t->right, deepness + 1);

    return left >= right ? left : right;

}



// abstract functions with output messages and other things
void nodes_count(tree *t){
    if (empty_tree(t))
        return;
    printf("]== Nodes Calculation ==[\n\n");
    int nodes = nodes_sum(t, 0);
    printf("Nodes: %d\n", nodes);
}


void leaf_count(tree *t){
    if (empty_tree(t))
        return;
    printf("]== Leafs Calculation ==[\n\n");
    int leafs = leaf_sum(t, 0);
    printf("Leafs: %d\n", leafs);
}


void deepness_print(tree *t){
    if (!empty_tree(t)) {
        printf("]== Deepness Calculation ==[\n\n");
        int deepness = deepness_count(t, 0);
        printf("Deepness: %d\n", deepness);
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
    output_tree(deepness);\
    print(t->orientation, deepness + 2);\


void output_tree(int deepness){
    int i;
    for(i = 0; i <= deepness; i++)
        printf("   ");
    printf("|=>");
}


void print(tree *t, int deepness) {
    print_element(t->element);
    if (t->left != NULL) {
        macro_print(left)
    }
    if (t->right != NULL) {
        macro_print(right)
    }
}


void print_tree(tree *root){
    if (!empty_tree(root)) {
        printf("]== Tree visualization ==[\n\n");
        printf("=>");
        print(root, 0);
        printf("\n");
    } 
}


/*===========================================================
 *
 *  -*-          Output notation functions!              -*-
 *
 *===========================================================
 */


void prefix_notation(tree *t) { 
    printf(" ( ");
    print_meta(t->element);
    if (t->left != NULL)
        prefix_notation(t->left);
    if (t->right != NULL)
        prefix_notation(t->right);

    printf(" ) ");

}


void posfix_notation(tree *t) {
    if (t->left != NULL)
        posfix_notation(t->left);
    if (t->right != NULL)
        posfix_notation(t->right);

    print_meta(t->element);
    printf(" ");
}


void infix_notation(tree *t) {
    if (t->left != NULL)
        infix_notation(t->left);
    
    print_element(t->element);

    if (t->right != NULL)
        infix_notation(t->right);
}


void infix_print(tree *root) {
    if (!empty_tree(root)) {
        printf("]== Infix Notation ==[\n\n");
        printf("\t");
        infix_notation(root);
        printf("\n\n");
    }
}

void posfix_print(tree *root) {
    if (!empty_tree(root)) {
        printf("]== Posfix Notation ==[\n\n");
        printf("\t");
        posfix_notation(root);
        printf("\n\n");
    }
}

void prefix_print(tree *root) {
    if (!empty_tree(root)) {
        printf("]== Prefix Notation ==[\n\n");
        printf("\t");
        prefix_notation(root);
        printf("\n\n");
    }
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


void element_or_nil(tree *t) {
    if (t != NULL)
        print_element(t->element);
    else
        printf("%p", t);
    printf("\n");
}


int walk_menu (tree *t) {
    int direction;
    // tree print
    print_tree(t);

    // more detailed output for node t
    printf("\n\n]== Walk on the Tree ==[\n\n");
    printf("[self] -> ");
    element_or_nil(t);
    printf("[left] -> ");
    element_or_nil(t->left);
    printf("[right] -> ");
    element_or_nil(t->right);

    //choose the direction for walk
    puts("\n");
    printf("]== Your choices ==[\n\n");
    printf("Left => 0\nRight => 1\n\nType your choice: ");
    scanf("%d", &direction);
    clear_buffer();

    return direction;
}


void insert(tree *t){
    system(CLEAR);
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
void insert_tree(tree *root) {
    if (!empty_tree(root))
        insert(root);
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


void search(tree *t, meta_data element, int deepness) {
    if (meta_comparision  (element, t->element)) {
        printf("Found a element on deepness %d: ", deepness);
        print_element(element);
        printf("\n");
    }

    walk(search, left);
    walk(search, right);
}


void search_tree(tree *root) {
    if (!empty_tree(root)) {
        meta_data element;
        new_meta(&element);
        search(root, element, 0);
    }
}



/*===========================================================
 *
 *  -*-           The remove_branch function         -*-
 *
 *===========================================================
 */

tree* null_branch(tree *t){
    // walk to left
    if (t != NULL)
        t->left = null_branch(t->left);
    // walk to right
    if (t != NULL)
        t->right = null_branch(t->right);
    // free the pointer node
    free(t);
    // points to nil
    t = NULL;

    return t;
}


tree* remove_branch(tree *t, meta_data element, int deepness) {
    if (meta_comparision (element, t->element)) {
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

tree* remove_tree(tree *t) {
    if (t != NULL) {
        meta_data element;
        new_meta(&element);
        return remove_branch(t, element, 0);
    } else {
        puts("Tree root not initialized yet! Call start method first!\n");
        return t;
    }

}

/*===========================================================
 *
 *  -*-              The edit function               -*-
 *
 *===========================================================
 */


int edit_or_walk(void) {
    int decision;
    puts("You like edit that node or walk?\n");
    puts("Walk => 0\nEdit => 1\n");
    scanf("%d", &decision); 
    clear_buffer();

    if (decision == 0 || decision == 1)
        return decision;
    else
        return edit_or_walk();
}


void edit(tree *t){
    system(CLEAR);
    print_tree(t);

    printf("Selected node: ");
    print_element(t->element);
    printf("\n\n");
    int decision = edit_or_walk();

    if (decision){
        insert_data(t);
        return;
    }
    else {
        int direction = walk_menu(t);
        if (direction == LEFT) {
            if (t->left != NULL){
                edit(t->left);
            }
            else {
                printf("Left node not started yet! Insert first.\n");
                edit(t);
            }
        }

        else if (direction == RIGHT) {
            if (t->right != NULL) {
                edit(t->right);
            }
            else {
                printf("Right node not started yet! Insert first.\n");
                edit(t);
            }

        }
        else {
            printf("Invalid option! Try again!");
            edit(t);
        }
    } 
}


void edit_tree(tree *root){
    if (!empty_tree(root))
        edit(root);
}

/*===========================================================
 *
 *  -*-              The balance function               -*-
 *
 *===========================================================
 */


tree* balance_branch(tree *node, int diff) {
    
    if (diff > 1) {
        return node;
        
    }

    else if (diff < -1) {
        return node;
    }

    return node;
}


tree* balance(tree *root) {
    int left = 0;
    int right = 0;
    
    // verify the deepness of near branches
    if (root->left != NULL) 
        left = deepness_count(root->left, 0);
    if (root->right != NULL) 
        right = deepness_count(root->right, 0);

    // balance the branch if deepness difference' > 1
    int diff = left - right;
    if (abs(diff) > 1) 
        root = balance_branch(root, diff);

    // balance the others branches recursively
    if (root->left != NULL) 
        root->left = balance(root->left);
    if (root->right != NULL)
        root->right = balance(root->right);

    return root;   
}

void balance_tree(tree *root) {
    if(!empty_tree(root))
        balance(root);
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
            t = remove_tree(t);
            break;
        case 4:
            edit_tree(t);
            break;
        case 5:
            search_tree(t);
            break;
        case 6:
            print_tree(t);
            break;
        case 9:
            prefix_print(t);
            break;
        case 10:
            posfix_print(t);
            break;
        case 11:
            infix_print(t);
            break;
        case 13:
            nodes_count(t);
            break;
        case 14:
            leaf_count(t);
            break;
        case 15:
            deepness_print(t);
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
