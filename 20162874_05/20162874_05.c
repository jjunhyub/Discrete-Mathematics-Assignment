#include <stdio.h>
#include <stdlib.h> 

int nNumber = 0;

int sumNumbers(FILE* fp, int* pNumbers, int nIndex) 
{   
    // basis step
    if( nIndex >= nNumber)
    {   
        fprintf(fp,"[%03d] %d\n",nIndex, pNumbers[nIndex]);
        return pNumbers[nIndex];
    }
    // recursive step
    else
    {   
        int temp =  pNumbers[nIndex] + sumNumbers(fp, pNumbers, nIndex + 1);
        fprintf(fp,"[%03d] %d\n",nIndex, temp);
        return temp;
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
    while(fgets(str,sizeof(str),fp1)){   // read a file and write to another file line by line
        nNumber++;
    }
    
    int* pNumbers = (int*) calloc(nNumber, sizeof(int));
    nNumber--;

    int i = 0;
    rewind(fp1);

    while(fgets(str,sizeof(str),fp1)){   // read a file and write to another file line by line
        pNumbers[i++] = atoi(str);
    }

    sumNumbers(fp2, pNumbers, 1);
    fprintf(fp2,"*************************\n");
    fprintf(fp2,"Junhyub Lee\n");
    fprintf(fp2,"Student ID : 20162874\n");
    fprintf(fp2,"*************************\n");

    free(pNumbers);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
