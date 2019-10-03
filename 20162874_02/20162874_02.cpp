#include <iostream>

using namespace std;

int main(int argc , char* argv[])
{
    int sum = 0;
    for(int i = 1;i<argc;i+=2)
    {
        if(argv[i][0] == '+') sum+=atoi(argv[i+1]);
        else sum-=atoi(argv[i+1]);
    }
    cout<<"********************"<<endl;
    cout<<"Sum  : "<<sum        <<endl;
    cout<<"Name : Lee Jun Hyub "<<endl;
    cout<<"ID   : 20162874     "<<endl;
    cout<<"********************"<<endl;
}
