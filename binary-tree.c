#include <stdio.h>
#include <stdlib.h>

#include "types-tree.h"
#include "clear-pause.h"

#define LEFT 0
#define RIGHT 1
#define CLEAR "cls || clear"



// choose the type of a node


void type_choose(meta_element *element){
    int command;  
    
    puts("Insert the type that you wish attribute!");
    puts("1.Char\n2.Int\n3.Real\n");

    printf("Put a command: ");
    scanf("%d", &command);
    clear_buffer();

    switch(command){
        case 1:
            element->type = character;
            break;
        case 2:
            element->type = integer;
            break;
        case 3:
            element->type = real;
            break;
        default:
            puts("Invalid option! Try again!");
            type_choose(element);
            break;       
    }  
}


meta_element data_input(meta_element element){
    type_choose(&element);
    puts("Insert a value: ");
    if (element.type == integer)
        scanf("%d", &element.data.integer);
    else if (element.type == character)
        scanf("%c", &element.data.character);
    else if (element.type == real)
        scanf("%f", &element.data.real);

    return element;
}


void input_tree(tree *t){
    meta_element thing = data_input(thing);
    t->stuff = thing;

    //pointer to nil the orientations;
    t->left = (tree *) NULL;
    t->right = (tree *) NULL;

}

#define macro_alloc(orientation) \
    t->orientation = (tree *) malloc(sizeof(tree));\
    input_tree(t->orientation);\


void insert(tree *t, int direction){
    if (direction == LEFT){
        macro_alloc(left);
    }
    else if (direction == RIGHT){
        macro_alloc(right);
    }

}




void search(tree t, meta_element thing);



void menu(tree *t){
    int command;

    puts("A implementation of binary tree!\n\n");

    printf("1.Insert_l\n2.Insert_r\n3.Remove_n\n4.Print\n0.Exit\n\n");
    printf("Type a command: ");

    scanf("%d", &command);
    clear_buffer();

    switch (command) {
        case 1:
            insert(t, LEFT);
            break;
        case 2:
            insert(t, RIGHT);
            break;
        case 3:
            printf("Not implemented yet.\n");
            break;
        case 4:
            printf("Not implement yet.\n");
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("You are a crazy?! Don't have these option.\n");
            break;
    }
    pause("Press enter to continue...");
    system(CLEAR);
    menu(t);
}


int main(int argc, char *argv[]){
    tree t;

    menu(&t);

    return 0;
}
