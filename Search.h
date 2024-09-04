#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<unistd.h>
#include<windows.h>
// #include <sys/ioctl.h>

#include "Trienode.h"
#include "Map.h"
#include "Maxheap.h"
#include "Scorelist.h"
using namespace std;

void search(char* token, Trienode* trie, Mymap *map, int k);
void df(Trienode* trie);
int tf(char* token, Trienode* trie);
