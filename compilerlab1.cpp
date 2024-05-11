#include<bits/stdc++.h>
using namespace std;


class SymbolInfo
{
private:
    string name;
    string identifier;

public:
    SymbolInfo(string namee, string identifierr)
    {
        name = namee;
        identifier = identifierr;
    }
    string getname()
    {
        return name;
    }
    void display()
    {
        cout<<"<"<<name<<","<<identifier<<">"<<endl;
    }
};

int hashindex(SymbolInfo X)
{
    string x = X.getname();
    int len = x.length();

    int hi = len%10;

   // cout<<"Hash index of "<<x<<" is "<<hi<<endl;

    return hi;
}

class SymbolTable
{
private :
    map<int,vector<SymbolInfo>> s;
public:
    SymbolTable()
    {

    }
    void insert(SymbolInfo a)
    {
        int indx = hashindex(a);

        s[indx].push_back(a);

        cout<<"Inserted at position "<<indx<<","<<s[indx].size()-1<<endl;
    }
    void printall()
    {
        for(auto it: s)
        {
            cout<<it.first<<"-->";
            for(SymbolInfo t:it.second)
            {
                t.display();
            }
            //cout<<endl;
        }
    }


};



int main()
{
    SymbolTable T;

    while(1)
    {
        string type;

        cin>>type;

        if(type == "I")
        {
            string n,t;
            cin>>n>>t;
            SymbolInfo a(n,t);
            T.insert(a);
        }
        else if(type == "P")
        {
            T.printall();
        }
        /*else if(type == "L")
        {

        }
        else
        {
            return;
        }*/
    }




   // a.SymbolInfo(n,t);

    /*cin>>n>>t;

    SymbolInfo b(n,t);

    cin>>n>>t;

    SymbolInfo c(n,t);

    a.display();
    b.display();
    c.display();
    hashindex(a);*/



    return 0;
}

