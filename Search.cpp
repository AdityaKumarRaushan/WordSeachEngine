#include "Search.h"
using namespace std;

const float k1 = 1.2;
const float b=0.75;

void search(char* token, Trienode* trie, Mymap* map, int k){
    char warray[10][256];
    double IDF[10];
    token = strtok(NULL, " \t\n");

    Scorelist* scorelist = new Scorelist();
    int i;
    for(i=0; i<10; i++){
        if(token==NULL){
            break;
        }
        strcpy(warray[i], token);
        IDF[i] = log10(((double)map->getsize() - (double)trie->dsearchword(warray[i], 0)+0.5)/((double)trie->dsearchword(warray[i], 0)+0.5));
        trie->search(warray[i], 0, scorelist);
        token = strtok(NULL, " \t\n");
    }
    double avgdl = 0;
    for(int m=0; m < map->getsize(); m++){
        avgdl += (double)map->getlength(m);
    }

    avgdl/=(double)map->getsize();
    double score = 0;
    Scorelist* templist = scorelist;

    Maxheap* heap = new Maxheap(k);
    int ceil = 0;

    while(templist!=NULL){
        for(int l=0; l<i; l++){
            score+=IDF[l]*((double)trie->tfsearchword(templist->getid(), warray[l], 0)*(k1 + 1.0))/((double)trie->tfsearchword(templist->getid(), warray[l],0) + k1*(1.0 - b + b*(double)map->getlength(templist->getid())/(double)avgdl));
        }

        heap->insert(score, templist->getid());
        templist = templist->getnext();
        ceil++;
    }

    if(ceil > k)ceil = k;

    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // CONSOLE_SCREEN_BUFFER_INFO csbi;

    // if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
    //     int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    //     int cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //     cout << rows << "\n" << cols << endl;
    // } else {
    //     std::cerr << "Error: Unable to get console screen buffer info" << std::endl;
    // }

    // struct winsize w; 
    // ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); 
    // std::cout << w.ws_row << std::endl;   // this code runs in linux environment


    // for(int l=0; l<ceil; l++){
        // int id = heap->getid();
        // if(id==-1)break;
        
        // double score = (double)heap->remove();
        // cout << "(" << id;
        // int x = 10;
        // int f = 1;
        // while(id/x!=0){
        //     x*=10;
        //     f++;
        // }
        // while(5-f >= 0){
        //     cout << " ";
        //     f++;
        // }
        // printf(")[%10.6f]",score);
        // char* line = (char*)malloc(map->getbuffersize()*sizeof(char));
        // strcpy(line, map->getDocument(id));
        // char* temp;
        // temp = strtok(line, " \t\n");
        // int currlength = 0;
        // int counter = 0;
        // int newline = 1;
        // int lineflag = 0;
        // int underline[2][100];
        // int ucounter = 0;

        // while(temp!=NULL){
        //     currlength+=20;
        //     if(counter!=0){
        //         for(int co=0; co<20; co++){
        //             cout << " ";
        //         }
        //         newline = 0;
        //     }
        // }
        // for(n=0; n<i; n++){
        //     if(!strcmp(warray[n], temp)){
                
        //     }
        // }

    // }

    std::cout << "Not implemented yet " << endl;
}

void df(Trienode* trie){
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if(token2!=NULL){
        cout<<token2 << " " << trie->dsearchword(token2, 0)<< endl;
    }
    else{ 
        char* buffer = (char*)malloc(256*sizeof(char));
        trie->dsearchall(buffer, 0);
        free(buffer);
    }
    token2=NULL;
    free(token2);
    // cout << " df Not implemened yet" << endl;
}

int tf(char* token, Trienode* trie){
    char* token2;
    token2 = strtok(NULL, " \t\n");
    if(token2==NULL){
        free(token2);
        return -1;
    }

    for(int l=0; l<strlen(token2); l++){
        if(!isdigit(token2[l])){
            token2 = NULL;
            free(token2);
            return -1;
        }
    }

    int id = atoi(token2);
    token2 = strtok(NULL, " \t\n");
    if(token2==NULL){
        free(token2);
        return -1;
    }
    cout << id << " " << token2 << " " << trie->tfsearchword(id, token2, 0) << endl;
    // cout << "Not implemented yet" << endl;
}