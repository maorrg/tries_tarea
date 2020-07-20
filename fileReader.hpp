#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> readAndParseFile(const string& fileName){
    string line;
    vector<string> vecStrings;
    string tempWord;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while( myfile >> tempWord ){
            vecStrings.push_back(tempWord);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return vecStrings;
}