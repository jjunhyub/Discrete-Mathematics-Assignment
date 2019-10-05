#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
    char arr[11];
    for(int i = 1;i<argc;i++)arr[i] = argv[i][0];
    int num = 1<<(argc-1);
    for(int i = 0;i<num;i++)
    {
        printf("[%04d] : ",i+1);
        if(!i)
        {
            printf("%c\n",155);
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
                    check = !check;
                }
                else cout<<", "<<arr[j];
            }
        }
        cout<<"\n";
    }

    cout<<"*****************\n";
    cout<<"20162874  Junhyub\n";
    cout<<"*****************\n";
}