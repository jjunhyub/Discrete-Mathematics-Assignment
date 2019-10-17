#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
    char arr[11];
    string filename = string(argv[1]);
    ofstream outFile(filename);
    for(int i = 1;i<argc-1;i++)arr[i] = argv[i+1][0];
    int num = 1<<(argc-2);
    for(int i = 0;i<num;i++)
    {
        printf("[%04d] : ",i+1);
        outFile<<"[";
        outFile.width(4);
        outFile.fill('0');
        outFile<<i+1<<"] : ";
        if(!i)
        {
            printf("∅\n",155);
            outFile<<"∅\n";
            continue;
        }
        bool check = true;
        for(int j = 1, temp = i;temp>0;temp = temp>>1,j++)
        {
            if(temp&1)
            {
                if(check)
                {
                    cout<<arr[j];
                    outFile<<arr[j];
                    check = !check;
                }
                else 
                {
                    cout<<", "<<arr[j];
                    outFile<<", "<<arr[j];
                }
            }
        }
        cout<<"\n";
        outFile<<"\n";
    }

    cout<<"*****************\n";
    cout<<"20162874  Junhyub\n";
    cout<<"*****************\n";
}