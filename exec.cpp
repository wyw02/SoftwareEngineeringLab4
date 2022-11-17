#include "head.h"
using namespace std;

void execute(std::vector<std::string>& subfiles, std::string& homedirectory)
{
    Eqminer *one = new Eqminer;
    int count = 0;
    for (int i = 0; i < subfiles.size(); i++)
    {
        for (int j = i+1; j < subfiles.size(); j++)//traverse all pairs  C(n,2)
        {
            one->file1 = subfiles[i];
            one->file2 = subfiles[j];
            one->homedirectory = homedirectory;
            dealwithpairs(one);
        }
    }
}
void dealwithpairs(Eqminer *onepair)  //run oj by system("g++ file.cpp -o a.out")
{
    std::string file1 = onepair->file1;
    std::string file2 = onepair->file2;
    std::string directory = onepair->homedirectory + std::string("/randominput.txt");
    std::string cmd1 = std::string("g++ ") + file1 + std::string(" -o a.out");
    std::string cmd2 = std::string("g++ ") + file2 + std::string(" -o b.out");
    std::string cmd3 = std::string("./a.out <") + directory + std::string("> res1.txt");
    std::string cmd4 = std::string("./b.out <") + directory + std::string("> res2.txt");
    system(cmd1.c_str());
    system(cmd2.c_str());                                                         
    system(cmd3.c_str());
    system(cmd4.c_str()); 
    compare(onepair);
}
