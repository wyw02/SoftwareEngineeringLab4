#include "head.h"
using namespace std;
std::vector<Eqminer> results;

void compare(Eqminer *onepair){
    ifstream op;
    std::string str1,str2;
    std::string path1 = std::string("./res1.txt");
    std::string path2 = std::string("./res2.txt");
    op.open(path1);
    while(!op.eof())
        str1+=op.get();
    op.close();
    op.open(path2);
    while(!op.eof())
        str2+=op.get();
    op.close();

    if(str1==str2){
        writeinchart(onepair, 1);
    }
    else{
        writeinchart(onepair, 0);
    }
    return;
}

void writeinchart(Eqminer *onepair, int i)
{
    std::string file1 = onepair->file1.substr(2, onepair->file1.size()-2);
    std::string file2 = onepair->file2.substr(2, onepair->file2.size()-2);
    if (i == 1){
        ofstream outfile;
        outfile.open("./output/equal.csv",ios::app);
        outfile << file1 << " " << file2 << endl;
    }
    else
    {
        ofstream outfile;
        outfile.open("./output/inequal.csv",ios::app);
        outfile << file1 << " " << file2 << endl;
    }
    return;
}