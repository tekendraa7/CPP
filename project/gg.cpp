#include<iostream>
using namespace std;
#include<ctime>
int main()
{
    int num,input;
    static int tries;
    srand(time(NULL));
    num=rand()%100 + 1;
    cout<<"\n    **  Number guessing game  ** \n\n";
    cout<<"guess a number from 1-100 \n";
    do{
    cin>>input;
    tries++;
    
    if(cin.fail())
    {
    cout<<"invalid input !! \n";
    break; // if user gives input other than integer then infinite loop occur. therefore to detect any other input c.fail() returns 1
    }
    
    else if(input<num)
    {
     cout<<"too low !\n";
     cout<<"try again --> ";
    }
    
    else if(input>num)
    {
     cout<<"too high ! \n";
     cout<<"try again --> ";
    }
    
    else
    {
     cout<<"\n   ###  correct  ### \n";
     cout<<"tries : "<<tries<<endl;
    }
    }
    while(num != input);
    
    cout<<"\n///  END OF GAME  /// \n"; 

}