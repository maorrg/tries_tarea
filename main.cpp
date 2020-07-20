#include <iostream>
#include <vector>
#include "Tries.hpp"
#include "fileReader.hpp"
using namespace std;

int main() 
{ 

    //------ DECLARACIONES PRINCIPALES ------//
    string wordToSearch = "";
    vector<string> keys = readAndParseFile("paragraph.txt");
    struct Node *root = getNode(); 
  
    //------ CONSTRUIR EL TRIE ------//
    for (int i = 0; i < keys.size(); i++){
        Insert(root, keys[i]); 
    }
  
    //------ LEER EN LA CONSOLA LA PALABRA A BUSCAR EN EL TEXTO ------//
    while(wordToSearch != "exit"){
        cout << "Ingrese la palabra/llave a buscar: ";
        cin >> wordToSearch;
        Search(root, wordToSearch);
    }

    return 0; 
} 