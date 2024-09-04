#include<iostream>
#include<cstdlib>
#include <cstring>
using namespace std;

#ifndef MAP_H
#define MAP_H
class Mymap{
    int size; //no of documents
    int buffersize; //the length of the biggest document
    char **documents; // each document
    int* lengths; //length of each document
    public:
        Mymap(int size, int buffersize);
        ~Mymap();
        int insert(char* line, int i);
        void setlength(int id, int length){lengths[id]=length;}
        int getlength(int id){return lengths[id];}
        void print(int i){cout << i << " " << documents[i] << endl;}
        char* getDocument(int i){return documents[i];}
        const int getsize(){return size;}
        const int getbuffersize(){return buffersize;}
}; 
#endif