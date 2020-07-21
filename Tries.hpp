#include <iostream>
using namespace std; 
  
const int ALPHABET_NUM_CHARACTERS = 26; 
  
struct Node 
{ 
    struct Node *children[ALPHABET_NUM_CHARACTERS]; 
    bool isEnd; 
}; 
  
struct Node *getNode(void) 
{ 
    struct Node *pNode =  new Node; 
  
    pNode->isEnd = false; 
  
    for (int i = 0; i < ALPHABET_NUM_CHARACTERS; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  

void Insert(struct Node *raiz, string key) 
{ 
    struct Node *root = raiz; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!root->children[index]) 
            root->children[index] = getNode(); 
  
        root = root->children[index]; 
    } 
    root->isEnd = true; 
} 


  
bool Search(struct Node *raiz, string key) 
{ 
    struct Node *root = raiz; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!root->children[index]){
            cout << "La palabra " << key << " NO esta en el texto.\n\n";
            return false; 
        }
  
        root = root->children[index]; 
    } 
    
    cout << "La palabra " << key << " SI esta en el texto.\n\n";
    return (root != NULL && root->isEnd); 
}

bool isEmpty(Node* root){
   for (int i = 0; i < ALPHABET_NUM_CHARACTERS; i++){
   if (root->children[i]) 
    return false;
   }
   return true;
}

Node* Delete(Node* root, string key, int depth = 0) {
   if (!root) return NULL;
   if (depth == key.size()) {
      if (root->isEnd)
         root->isEnd = false;
      if (isEmpty(root)) {
         delete (root);
         root = NULL;
      }
   return root;
   }

   int index = key[depth] - 'A';
   root->children[index] =
   Delete(root->children[index], key, depth + 1);
   if (isEmpty(root) && root->isEnd == false) {
      delete (root);
      root = NULL;
   }
   return root;
}


