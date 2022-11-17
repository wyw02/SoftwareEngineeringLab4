#include "head.h"
using namespace std;


void readinput(std::string& filename, std::string& homedirectory){
    ifstream fp1;
    std::string str;
    fp1.open(filename.c_str());
    int i = 0, j = 0, flag = 0;
    std::vector<std::string> input;
    while(!fp1.eof())
        str += fp1.get();
    const char *buff = str.c_str();
    std::string s;
    while(buff[j] != '\0')
    {
        if (j == 0 || buff[j] == ' '||buff[j] == '('||buff[j] == ')'||buff[j] == ',')//((strcmp(buff[i-1] , ' ') == 0)
        {
            if (j == 0){
                s = "";
                s += buff[j];
            }else if (flag == 0){//meet ' ''('')'for the first time
                flag = 1;
                input.push_back(s);//push into vector
                s = "";//clean the string
            }else{
                s = "";
            }
        }
        else{
            flag = 0;
            s += buff[j];
        }
        j++;
    }
    dealwithinput(input, homedirectory);
    fp1.close();
}
void dealwithinput(std::vector<std::string>& input, std::string& homedirectory){ 
    fstream fp2;
    std::string newfilename = homedirectory + std::string("/randominput.txt");
    int flag = 0;
    std::string inputstr;
    fp2.open(newfilename.c_str(), ios::out);
    srand(time(0));
    for(int i = 0; i < input.size(); i++)
    {
        if (strcmp(input[i].c_str(), "int") == 0)
        {
            std::string temp1 = input[++i];
            std::string temp2 = input[++i];
            int j = 0, left = 0, right = 0;
            while(temp1[j] != '\0'){
                left = left * 10 + temp1[j] - '0';
                j++;
            }
            j = 0;
            while(temp2[j] != '\0'){
                right = right * 10 + temp2[j] - '0';
                j++;
            }
            int randnum = left + rand() % (right - left);
            if (flag == 0){
                flag = 1;
            }
            else{
                inputstr.append(" ");
            }
            inputstr.append(to_string(randnum));
        }else if(strcmp(input[i].c_str(), "char") == 0)                                      
        {
            std::string temp1 = input[++i];
            std::string temp2 = input[++i];
            char a, b;
            a = temp1[0];
            b = temp2[0];
            char randchar = a + rand() % (b - a - '0');
            if (flag == 0){
                flag = 1;
            }
            else
            {
                inputstr.append(" ");
            }
            inputstr.append(to_string(randchar));
        }else if(strcmp(input[i].c_str(), "string") == 0)
        {
            std::string temp1 = input[++i];
            std::string temp2 = input[++i];
            char a, b;
            a = temp1[0];
            b = temp2[0];
            int length = (b - a - '0');
            std::string randchar;
            for (int j = 0; j < length; j++){
                char onechar = 'A' + rand() % ('Z' - 'A' - '0') + (rand() % 2) * 32;
                 //random charactor among A to z
                randchar.append(to_string(onechar));
            }
            if (flag == 0){
                flag = 1;
            }
            else
            {
                inputstr.append(" ");
            }
            inputstr.append(randchar);
            
        }
    }
    fp2 << inputstr;
    fp2.close();
}
