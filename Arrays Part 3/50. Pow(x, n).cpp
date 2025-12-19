#include<bits/stdc++.h>
using namespace std;

double po(double base,int expo)
    {
        if(expo==0) return 1.0;
        else if(expo==1) return base*1.0;
        if(expo%2==1)
        {
           double x=(double)po(base,expo/2);
           x=(double)x*po(base,expo/2);
           x=(double)x*base;
           cout<<"Printing the :-"<<x<<endl;
           return x;
        }
        else
        {
            double x=po(base,expo/2);
            x=x*po(base,expo/2);
            cout<<"Printing the 2 :-"<<x<<endl;
            return x;
        }
        
    }
    double myPow(double x, int n) {
        
        if(n==0) return 1;
        if(n==1) return x;
        if(n>0)
        {
            
            cout<<"Printing:"<<po((int)x,n)<<endl;
            return po((int)x,n);
        }
        else
        {
            
            cout<<"Printing:"<<po((int)x,n)<<endl;
            int denominator=po((int)x,n);
            return (double)1/(double)denominator;
        }
    }
int main()
{
    double x=2.1;
    int n=3;
    cout<<myPow(x,n);
}