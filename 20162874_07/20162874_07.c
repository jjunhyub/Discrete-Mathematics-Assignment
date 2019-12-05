#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int nNumber = 0;
int pIndex  = 1;
int end     = 0;
int hash1[1000010];
string s[2000000];

void hashing(string s)
{
	unsigned long long sum = 0;
	for(unsigned long long i = 0,j=1;s[i];i++)
	{
		sum+=j*(s[i]-48);
		j<<1;
		sum%=1000008;
	}
	hash1[sum]++;
}

int _hashing(string s)
{
	unsigned long long sum = 0;
	for(unsigned long long i = 0,j=1;s[i];i++)
	{
		sum+=j*(s[i]-48);
		j<<1;
		sum%=1000008;
	}
	if(hash1[sum]==-1)return -1;
	int temp = hash1[sum];
	hash1[sum] = -1;
	return temp;
}
 

int main(int argc, char* argv[]){

    FILE *fp1,*fp2;

    // see the usage of r, rt, w, wt, r+, w+
    if((fp1=fopen(argv[1],"r"))  == NULL){ //fail to open file for read
        printf("fail to open file.");
        return 0;
    }
    if((fp2=fopen(argv[2],"wt")) == NULL){ //fail to open file for write
        printf("fail to create file for write.");
        return 0;
    }

	char * str = NULL;
    size_t len = 0;
    ssize_t read;

	int index = 0;


	while ((read = getline(&str, &len, fp1)) != -1) {

		int len = strlen(str);
		for(int i = 0;i<=len;i++)
		{
			if(48<=str[i]&&str[i]<=57)continue;
			if(65<=str[i]&&str[i]<=90)continue;
			if(97<=str[i]&&str[i]<=122)continue;
			str[i]=' ';
		}
		
		string temp = "";
		for(int i = 0;i<=len;i++)
		{
			if(str[i]==' '&&temp!="")
			{
				s[index++] = temp;
				hashing(temp);
				temp = "";
			}
			else if(str[i]==' ')continue;
			else temp+=str[i];
		}	
    }


	int real_i = 1;
	for(int i = 0;i<index;i++)
	{
		int hash_num = _hashing(s[i]);
		if(hash_num==-1)continue;
		fprintf(fp2,"[%04d] %s ( %d )\n",real_i++,s[i].c_str(),hash_num);
	}
	fprintf(fp2,"[total] %04d\n",index);
    fprintf(fp2,"*************************\n");
    fprintf(fp2,"Junhyub Lee\n");
    fprintf(fp2,"Student ID : 20162874\n");
    fprintf(fp2,"*************************\n");

    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
