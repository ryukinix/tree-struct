#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1
#define clear cls || clear


/*
 * A union for elements
 *
 */

typedef union {
    char *character;
    int *integer;
    float *real;
} something;


/*
 * A identifier
 *
 */

typedef enum {
    CHARACTER,
    INTEGER,
    REAL, 
} identifier;


/*
 * A abstraction for anything
 *
 */

typedef struct {
    something data;
    identifier id; 
} meta_element;


/*
 * A node abstraction
 *
 */

struct node {
    meta_element stuff;   
    struct node *left; 
    struct node *right;
};


/*
 * A abstraction for tree
 *
 */
typedef struct node tree;



void insert(tree *t, meta_element thing, int direction){
    
    if (direction == LEFT)
        t->stuff = thing;
         
    else if (direction == RIGHT)
        t->stuff = thing;

}



void search(tree t, meta_element thing);


// choose the type of a node
void type(meta_element *thing){
    int command;  
    
    puts("Insert the type that you wish attribute!");
    puts("1.Char\n2.Int\n3.Real\n");
    

    scanf("%d", &command);

    switch(command){
        case 1:
            thing->id = CHARACTER;
            break;
        case 2:
            thing->id = INTEGER;
            break;
        case 3:
            thing->id = REAL;
            break;
        default:
            puts("Invalid option! Try again!");
            type(thing);
            break;       
    }  
}


int main(int argc, char *argv[]){
    tree t;

    return 0;
}
