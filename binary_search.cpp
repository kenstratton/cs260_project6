#include <iostream>

/* Node to store data */
struct Node {
  int number;
  struct Node *left;
  struct Node *right;
};

/* Nodes used for root(*1), search(*2), add(*3), remove(*4) */
static struct Node *root = NULL; // * 1
struct Node *node;               // * 2
struct Node *new_node;           // * 3
// * 4
struct Node *parent, *child, *left_child, *right_child, *right_child_min;


/* isEmpty function : Check if BST is empty */
bool isEmpty() {
    if (root == NULL) return true;
    return false;
}


/*******************************************
 Search fuction :
 * 1. Search a node with a given number
     - start -> root
     - less than the target -> left
     - greater than the target -> right
     - hit the target -> stop the process
 * 2. Return bool (found OR not found)
********************************************/
bool search(int number) {
    // * 1
    node = root;
    while (node) {
        if (number < node->number) {
            node = node->left;
        } else if (number > node->number) {
            node = node->right;
        } else {
            return true; // * 2
        }
    }

    return false; // * 2
}


/*******************************************
 Add fuction :
 * 1. Preapare a memory space and create a node (new_node is null -> memory error)
 * 2. Set a node address (when BST is empty)
 * 3. Set a node address following BST rules (smaller->left, greater->right, exist->break)
 * 4. Return bool (scucess OR failure)
********************************************/
bool add(int number){
    // * 1
    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) return false;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->number = number;

   // * 2
   if (isEmpty()) {
       root = new_node; 
       return true; // * 4
   }

    // * 3
    node = root;
    while (true) {
        if (number < node->number) {
            if (node->left == NULL) {
              node->left = new_node;
              return true; // * 4
            }
            node = node->left;

        } else if (number > node->number) {
            if (node->right == NULL) {
              node->right = new_node;
              return true; // * 4
            }
            node = node->right;

        } else {
            break;
        }
    }

   return false; // * 4
}


/*******************************************
 Remove fuction :
 * 1. Check emptiness
 * 2. Search if the target exists (not found -> failure)
 * 3. Remove a node which has no child or is a root in BST without other nodes
 * 4. Remove a node which has a child address in its left or right pointer
 * 5. Remove a node which has children addresses in the both pointers
 * 6. Return bool (success OR failure)
********************************************/
bool remove(int number) {
    // * 1
    if (isEmpty()) return false;

    // * 2
    node = root;
    parent = NULL;
    while (node) {
        if (number < node->number) {
            parent = node;
            node = node->left;
        } else if (number > node->number) {
            parent = node;
            node = node->right;
        } else {
            break;
        }
    }

    if (node == NULL) return false; // * 6

    // * 3
    if (node->left == NULL && node->right == NULL) {
        if (parent != NULL) {
            if (parent->left ==  node) {
                  parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }

        free(node);
        return true; // * 6
    } 

    // * 4
    else if ((node->left && node->right == NULL) || (node->right && node->left == NULL)) {
        if (node->left != NULL) {
            child = node->left;
        } else {
            child = node->right;
        }

        node->number = child->number;
        node->left = child->left;
        node->right = child->right;

        free(child);
        return true; // * 6
    }

    // * 5
    else {
        right_child = node->right;
        node->number = right_child->number;
        node->right = right_child->right;

        if (right_child->left != NULL) {
            left_child = node->left;
            right_child_min = right_child->left;

            while (right_child_min->left != NULL) {
                right_child_min = right_child_min->left;
            }
            node->left = right_child->left;
            right_child_min->left = left_child;
        }

        free(right_child);
        return true; // * 6
    }

    return false; // * 6
}


/*******************************************
 Get fuction :
 * 1. Add nodes and Remove a root node and a node without children
 * 2. Add nodes and Remove a node which has one child
 * 3. Add nodes and Remove a node which has children in the both pointers
********************************************/
void testBst() {
    printf("Test Starts!\n");

    // * 1
    assert(add(100) == true);
    assert(add(200) == true);
    assert(search(100) == true);
    assert(search(200) == true);

    assert(remove(200) == true);
    assert(remove(100) == true);
    assert(search(100) == false);
    assert(search(200) == false);

    // * 2
    assert(add(100) == true);
    assert(add(200) == true);
    assert(search(100) == true);
    assert(search(200) == true);

    assert(remove(100) == true);
    assert(remove(200) == true);
    assert(search(100) == false);
    assert(search(200) == false);

    // * 3
    assert(add(100) == true);
    assert(add(200) == true);
    assert(add(150) == true);
    assert(add(250) == true);

    assert(remove(200) == true);
    assert(search(100) == true);
    assert(search(150) == true);
    assert(search(200) == false);
    assert(search(250) == true);


    printf("Test done!\n");
}


// User operation
int main() {
    testBst();
    return 0;
}