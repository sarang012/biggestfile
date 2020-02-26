
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

long int findSize(char file_name[]) 
{ 
     
    FILE* fp = fopen(file_name, "r"); 
  
    
    if (fp == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
  
    fseek(fp, 0L, SEEK_END); 
  
    
    long int res = ftell(fp); 
  
   
    fclose(fp); 
  
    return res; 
}


void listFiles(const char *path);

int main()
{
   
    char path[100];

    printf("Enter path to list files: ");      // Input path from user
    scanf("%s", path);

    listFiles(path);

    char file_name[20] ; 
    
    printf("\n Select the file name to find size\n");
    scanf("%s",&file_name[20]);

    long int res = findSize(file_name); 
    if (res != -1) 
        printf("Size of the file is %ld bytes \n", res); 

    return 0;
}


// Lists all files in given path.
 
void listFiles(const char *path)
{
    struct dirent *dp;
    DIR *dir = opendir(path);

    // Unable to open directory 
    if (!dir) 
        return; 

    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }

    // Close directory stream
    closedir(dir);
}
