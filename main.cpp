
#include "head.h"
using namespace std;

int GetAbsoluteFiles(const std::string& mdirectory) 
{
    DIR* dir = opendir(mdirectory.c_str()); //打开目录 
    if ( dir == NULL )
    {
        return -1;
    }

    struct dirent* d_ent = NULL;       
    char fullpath[128] = {0};
    char dot[3] = ".";                
    char dotdot[6] = "..";
    while ( (d_ent = readdir(dir)) != NULL )    //读目录
    { 
        if ( (strcmp(d_ent->d_name, dot) != 0)
              && (strcmp(d_ent->d_name, dotdot) != 0) )  {

            if ( d_ent->d_type == DT_DIR ) //是目录
            {
                std::vector<std::string> filesAbsolutePath;
                std::string newDirectory = mdirectory + std::string("/") + std::string(d_ent->d_name); 
                DIR* subdir = opendir(newDirectory.c_str());
                if ( subdir == NULL )
                {
                    return -1;
                }
                struct dirent* subd_ent = NULL; 
                while((subd_ent = readdir(subdir))!= NULL)
                {
                    if ( subd_ent->d_type != DT_DIR ){
                        std::string newsubDirectory = newDirectory + std::string("/") + std::string(subd_ent->d_name);
                        if(strcmp(subd_ent->d_name, "stdin_format.txt") != 0 && strcmp(subd_ent->d_name, "randominput.txt")!= 0)
                        {                            
                            filesAbsolutePath.push_back(newsubDirectory);
                        }
                        else if(strcmp(subd_ent->d_name, "stdin_format.txt") == 0 ) // create random input and write into file
                        {
                            readinput(newsubDirectory, newDirectory);
                        }
                    
                    }
                }
                execute(filesAbsolutePath, newDirectory);
            }
        }
    }

    closedir(dir);
    return 0;
}



int main(int argc,char *argv[])
{
    system("rm -f /home/njucs/Eqminer/output/*"); //clear the output files from last test
	GetAbsoluteFiles("./input");
	return 0;
}
