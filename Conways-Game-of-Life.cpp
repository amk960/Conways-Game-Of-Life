
// This is the Conways Game of life
// This program has two functions first the ConwaysGame that has the conditionals
// Then the main function that calls the Conways Game
//The ConwaysGame has a nested for loop
// This goes over every char of text file and checks its neighbors
// It then creates a new copy with updated life and death circle
// It prints that and returns the new generation

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> ConwaysGame(vector<string> container, int genumb) {
    vector<string> containercopy;
    for  (size_t i=0; i<container.size(); ++i)
    {containercopy.push_back(container[i]);}
    int lenline = container[0].size() -1;
    int numlines = container.size() -1;
    for  (size_t i=0; i<=numlines; ++i)
    {
        for (size_t j=0; j<=lenline; ++j)
        {
            int num_adj_alive = 0;

            if(j>0 && i>0) //topleft
            {
                if (container[i-1][j-1]=='*')
                {num_adj_alive +=1;}
            }
            if ( i >0) //top
            {
                if (container[i-1][j]=='*')
                {num_adj_alive +=1;}
            }
            if (j<lenline && i >0) //topright
            {
                if (container[i-1][j+1]=='*')
                {num_adj_alive +=1;}
            }
            if (j>0)//left
            {
                if (container[i][j-1]=='*')
                {num_adj_alive +=1;}
            }
            if (j<lenline)//right
            {
                if (container[i][j+1]=='*')
                {num_adj_alive +=1;}
            }
            if (j>0 && i<numlines)//bottomleft
            {
                if (container[i+1][j-1]=='*')
                {num_adj_alive +=1;}
            }
            if (i<numlines)//bottom
            {
                if (container[i+1][j]=='*')
                {num_adj_alive +=1;}
            }
            if (i<numlines && j<lenline)//bottomright
            {
                if (container[i + 1][j+1] == '*')
                {num_adj_alive += 1;}
            }

            if (num_adj_alive > 3 || num_adj_alive<2)
            {
                containercopy[i][j] = '-';
            }
            if (num_adj_alive == 3)
            {
                containercopy[i][j] = '*';
            }

        }

    }
    cout << "Generation: "<< genumb << endl;
    for (size_t x=0; x<containercopy.size(); ++x)
    {
        cout << containercopy[x] << endl;
    }
    cout << "====================" << endl;
    return containercopy;
}

int main() {
    string line;
    ifstream myfile ("life.txt");
    vector<string> container;
    if (! myfile)
        cout << "Failed" << endl;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            container.push_back(line);
        }
    }
    myfile.close();

    cout << "INITIAL WORLD" << endl;
    for (size_t x=0; x<container.size(); ++x)
    {
        cout << container[x] << endl;
    }
    cout << "=========================" << endl;
    vector<string> gen_1 = ConwaysGame(container, 1);
    vector<string> gen_2 = ConwaysGame(gen_1, 2);
    vector<string> gen_3 = ConwaysGame(gen_2, 3);
    vector<string> gen_4 = ConwaysGame(gen_3, 4);
    vector<string> gen_5 = ConwaysGame(gen_4, 5);
    vector<string> gen_6 = ConwaysGame(gen_5, 6);
    vector<string> gen_7 = ConwaysGame(gen_6, 7);
    vector<string> gen_8 = ConwaysGame(gen_7, 8);
    vector<string> gen_9 = ConwaysGame(gen_8, 9);
    vector<string> gen_10 = ConwaysGame(gen_9, 10);




    return 0;
}