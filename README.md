# cs260_project6

## Binary Search Tree (BST)

### ▼ BST nodes
Each node has a unique integer value, a left pointer, and a right pointer.<br>
A left pointer stores a node address with smaller value than a parent has.<br>
A right pointer stores a node address with greater value than a parent has.<br>

### ▼ Tests
Whether it's possible to...
1. **Addition of nodes**
    - insert a new node into an appropriate location
    - maintain uniqueness of node values
2. **Deletion of nodes**
    - appropriately delete a node (keeping BST structure)
    - halt the deletion process when a BST is empty or when the target is not found
3. **Search for nodes**
    - search for a specific node based on its value
    - halt the search process when a BST is empty or when the target is not found

### ▼ Complexity (Big-O notation)
|Insert|Remove|Search|
|:--:|:--:|:--:|
| O(n) | O(n) | O(n) |
