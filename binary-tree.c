#include <stdio.h>
#include <stdlib.h>

#define LEFT 0
#define RIGHT 1

/*
 * A union for elements
 *
 */

union something {
    char *character;
    int *integer;
    float *real;
};


/*
 * A identifier
 *
 */

enum indentifier {
    
    CHARACTER,
    INTEGER,
    REAL, 
}


/*
 * A abstraction for anything
 *
 */

typedef struct {
    
    union something ;
    enum identifier; 
    
} meta_element;


/*
 * A node abstraction
 *
 */

struct node {
    
    meta_element stuff;   
    node *left; 
    node *right;
    
};



/*
 * A abstraction for tree
 *
 */

typedef node tree;


void insert(tree t, meta_element thing, int direction){
    
    if (direction == LEFT)
        t.left.meta_element = thing;
         
    else if (direction == RIGHT)
        t.right.meta_element = thing;

}

void search(tree t, union something, )


void type(identifier *id){
    int command;  
    
    puts("Insert the type if you can atribute!");
    puts("1.Char\n2.Int\n3.Real\n");
    
    do{
        scanf("%d", &command);

        switch(command){
            case 1:
                *id = CHAR;
                break;
            case 2:
                *id = INTEGER;
                break;
            case 3:
                *id = REAL;
                break;
            default:
                puts("Invalid option!")
                type(id);
                break;       
        }
    }  
}


int main(argc, *argc[]){
    tree t;

    return 0;
}

















