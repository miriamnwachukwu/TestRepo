// Compile with c++ ece650-a2cpp -std=c++11 -o ece650-a2
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

bool verticepath(vector < vector <int> > conn, int vertices, int u, int v, int halfcount, int distance[], int predecessor[], int pp[]){
    bool checked[50];
    double inf = std::numeric_limits<double>::infinity();

    for(int i = 0; i < vertices; i++){
         checked[i] = false;
        distance[i] = inf;
     predecessor[i] = -1;}

    queue<int> stage;
    stage.push(u);

    checked[u] = true;
    distance[u] = 0;
    int sizeofqueue = 0;
    //This runs only when there are edges that still haven't been checked (or turned black)
    while(!stage.empty()){
    //Going through all the connections of one particular point from here
    sizeofqueue = stage.size();
    while(sizeofqueue--){
        int x = stage.front();
        stage.pop();
        
        for(int j=0; j<conn[x].size();j++){
            if(!checked[conn[x][j]]){
                checked[conn[x][j]] = true;
                predecessor[conn[x][j]] = x;
                stage.push(conn[x][j]);}

                //The path has been found, leaving this function
                if (x == v){
                   return true;}}}}

return false;
}


int pathfinder(vector < vector <int> > conn, int vertices, int u, int v, int halfcount){
vector<int> connected;
int back = v;

    int distance[v], predecessor[v], pp[v];
    if (verticepath(conn, vertices, u, v, halfcount, distance, predecessor, pp) == false){
        cout << "Error: no path from source to destination" << endl;
        //If there is a path, then into else function
    } else {
            connected.push_back(back);
            predecessor[u] = -1;

            while(predecessor[back] != -1){
                if(find(connected.begin(), connected.end(), predecessor[back]) != connected.end()){
                    break;}
                connected.push_back(predecessor[back]);
                //using reverse (i--) technique to print out path from source to desination
                back = predecessor[back];}
            for (int i = connected.size() - 1; i >= 0; i--){
               if (i > 0)
               cout << connected[i] << "-";
               if  (i == 0)
               cout << connected[i] << endl;}}
return 0;}



int main(){
    // Test code. Replaced with your code
    int vertices, eone, sone, u, v, begin, end;
    int count = 0, halfcount;
    string input, ivertices, str, eeone, ssone;
    vector<int> edges; 
    bool a = false, somethingthere;
    bool b = false, c = true;
    bool singlenum = false;
    bool aa = true;
    vector <int> first;
    vector < vector <int> > conn(50, first);

    /* This label allows for goto statements to jump back here*/
while(!cin.eof()){
    userinput:
        getline(cin, input);

    if(input[0] == 'V'){
        //Vertices collected from input are stored here
        ivertices = input.substr(2);
        stringstream(ivertices) >> vertices;
        /*cout << vertices << endl;*/}

    int inputlength = input.size();
    int verify = 0;    
    if(input[0] == 'E'){
    edges.clear();
    first.clear();

    for(int j = 0; j <= 50; j++){
        conn[j].clear();}
    //easy way to find match, check to see if the string matches with possible digits 0-9
    char possiblenumbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        somethingthere = true;
        for(int step = 4; step < inputlength; step++){
            for(int num = 0; num <= 9; num++){
                if(input[step] == possiblenumbers[num]){
                        eeone = input[step];
                        stringstream(eeone) >> eone;
                        singlenum = true;
                    //First, collecting all numbers into the edge vector
                    for(int num = 0; num <= 9; num++){
                        if(input[step+1] == possiblenumbers[num]){
                                eeone = input.substr(step,2);
                                stringstream(eeone) >> eone;
                                edges.push_back(eone);
                                count ++;
                                a = true;}}
                        if(a == false){
                            edges.push_back(eone);
                            count ++;}
                        if(a == true){
                            step++;
                            a = false;}
                            }}}
                            halfcount = count/2;
do{
    /* Here, separating the beginning and end of each end connection 
                so they can be paired in the conn vector */
    for(int i = 0; i < edges.size(); i++){
        somethingthere = true;
        if(aa == true){
            begin = edges[i];
            verify++;
            aa = false;
            if(begin >= vertices){
                cout << "Error: an inputted edge does not exist" << endl;
                goto userinput;}
            continue;}
        if(aa ==false){
            end = edges[i];
            verify++;
            aa = true;
            if(end >= vertices){
                cout << "Error: an inputted edge does not exist" << endl;
                goto userinput;}
            /* Matrix is loaded here */
            // this part will be half the edge size
            conn[begin].push_back(end);
            conn[end].push_back(begin);
            }}if (verify != edges.size()){
        somethingthere = false;}
    }while(somethingthere == false);}


    if(input[0] == 's'){
        
        //Making sure these values always start here
        b = false;
        c = true;

        int searchlength = input.size();
        char possiblenumbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for(int step = 0; step < searchlength; step++){
            for(int num = 0; num <= 9; num++){
                if(input[step] == possiblenumbers[num]){
                    ssone = input[step];
                    stringstream(ssone) >> sone;
                    //cout <<  "possible single number = " << sone << endl;
                    //cout << "this is what comes next = " << input[step+1] << endl;
                    b = false;

                    for(int numone = 0; numone <= 9; numone++){
                    
                            char myints[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
                            char *p;

                            p = find(myints, myints+10, input[step+1]);
                            if (p != myints+10){

                            ssone = input.substr(step,2);
                            stringstream(ssone) >> sone;
                            step++;
                            //cout <<  "double number = " << sone << endl;
                            //cout << "this is step: " << step << endl;
                            b = true;}

                        if((b == false) && c == true){
                            if(sone >= vertices){
                                cout << "Error: one or more of the edges doesn't exist" << endl;
                                 goto userinput;}
                            u = sone;
                            b = true;
                            c = false;
                            //cout << "This is u " << u << endl;
                            break;}
                        if((b == true) && c == true){
                            if(sone >= vertices){
                                cout << "Error: one or more of the edges doesn't exist" << endl;
                                 goto userinput;}
                            u = sone;
                            b = false;
                            c = false;
                            //cout << "This is u " << u << endl;
                            break;}
                        if((b == false) && c == false){
                            if(sone >= vertices){
                                cout << "Error: one or more of the edges doesn't exist" << endl;
                                 goto userinput;}
                            v = sone;
                            b = true;
                            c = true;
                            //cout << "This is v " << v << endl;
                            break;}
                        if((b = true) && c == false){
                            if(sone >= vertices){
                                cout << "Error: one or more of the edges doesn't exist" << endl;
                                 goto userinput;}
                            v = sone;
                            b = false;
                            c = true;
                            //cout << "This is v " << v << endl;
                            break;}}}}
                        }
                pathfinder(conn, vertices, u, v, halfcount);}}
return 0;}
