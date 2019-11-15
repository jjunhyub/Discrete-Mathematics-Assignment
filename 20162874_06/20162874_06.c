#include <stdio.h>
#include <stdlib.h> 

int nNumber = 0;
int pIndex  = 1;
int end     = 0;

void permutation(FILE* fp, char* pChars, char* tChars, int num, int nIndex) 
{
    if(num==end)
    {
        fprintf(fp,"[%03d] ", pIndex++);
        for(int i = 1;i<=nNumber;i++)fprintf(fp,"%c ",tChars[i]);
        fprintf(fp,"\n");
    }
    for(int i = 0;i<nNumber;i++)
    {
        int check = 1<<i;
        if(check&num)continue;
        tChars[nIndex] = pChars[i+1];
        permutation(fp,pChars,tChars,check|num,nIndex+1);
    }
}
 

int main(int argc, char* argv[]){

    FILE *fp1,*fp2;
    char str[64];

    // see the usage of r, rt, w, wt, r+, w+
    if((fp1=fopen(argv[1],"r"))  == NULL){ //fail to open file for read
        printf("fail to open file.");
        return 0;
    }
    if((fp2=fopen(argv[2],"wt")) == NULL){ //fail to open file for write
        printf("fail to create file for write.");
        return 0;
    }
    fgets(str,sizeof(str),fp1);
    nNumber = atoi(str);
    end = (1<<nNumber)-1;

    char* pChars = (char*) calloc(nNumber+1, sizeof(char));
    char* tChars = (char*) calloc(nNumber+1, sizeof(char));

    int i = 1;
    while(fgets(str,sizeof(str),fp1)){   // read a file and write to another file line by line
        pChars[i++] = str[0];
    }

    permutation(fp2, pChars, tChars, 0, 1);

    fprintf(fp2,"*************************\n");
    fprintf(fp2,"Junhyub Lee\n");
    fprintf(fp2,"Student ID : 20162874\n");
    fprintf(fp2,"*************************\n");

    
    free(pChars);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
