/*
 * A union for elements
 *
 */

typedef union {
    int integer;
    char character;
    float real;
} something;


/*
 * A identifier
 *
 */

typedef enum {
    integer,
    character,
    real 
} identifier;


/*
 * A abstraction for anything
 *
 */

typedef struct {
    something data;
    identifier type; 
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
