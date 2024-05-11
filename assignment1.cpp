#include<bits/stdc++.h>

using namespace std;
int ff;
int it;
int itt;
int cnt=0;

class SymbolInfo {
private:
    string name;
    string identifier;

public:
    SymbolInfo(string namee, string identifierr) : name(namee), identifier(identifierr) {}

    string getname() {
        return name;
    }

    void display() {
        cout << "<" << name << "," << identifier << ">" << "   ";
    }
};

/*int hashindex(const string& x) {
    int len = x.length();
    int hi = len % 10;
    return hi;
}*/

class SymbolTable {
private:
    vector<SymbolInfo*>* array;

public:
    SymbolTable() {

        array = new vector<SymbolInfo*>[73];
    }

    ~SymbolTable() {

        delete[] array;
    }

    int hashindex(const string& x) {
        int hi = (int(x[0])*03)%10;
        return hi;
}


    void insert(SymbolInfo a) {
        for (int i = 0; i < 10; ++i) {
            //cout << i << "-->";
            for (SymbolInfo* t : array[i]) {
                //t->display();
                if(t->getname()==a.getname())
                {
                    cnt=1;
                    //cout << "Found at " << i << "," << array[i].size()-1 << endl;
                    break;
                }
                else
                {
                    cnt=0;
                }

            }
            if(cnt==1)
            {
                break;
            }
            //cout<<endl;
        }
        if(cnt==1)
        {
            cout<<"Already exists!\n";
        }
        else
        {
            int indx = hashindex(a.getname());
            array[indx].push_back(new SymbolInfo(a));
            cout << "Inserted at position " << indx << "," << array[indx].size() - 1 << endl;
        }

    }

    void lookup(string a)
    {
        for (int i = 0; i < 10; ++i) {
            //cout << i << "-->";
            for (SymbolInfo* t : array[i]) {
                //t->display();
                if(t->getname()==a)
                {
                    ff=1;
                    cout << "Found at " << i << "," << array[i].size()-1 << endl;
                    break;
                }
                else
                {
                    ff=0;
                }

            }
            if(ff==1)
            {
                break;
            }
            //cout<<endl;
        }
        if(ff==0)
        {
            cout<<"Not found!"<<endl;
        }
    }

    void deletee(string a)
    {
        for (int i = 0; i < 10; ++i) {
            //cout << i << "-->";
            for (SymbolInfo* t : array[i]) {
                //t->display();
                if(t->getname()==a)
                {
                    cnt=1;
                    //cout << "Found at " << i << "," << array[i].size()-1 << endl;
                    break;
                }
                else
                {
                    cnt=0;
                }

            }
            if(cnt==1)
            {
                break;
            }
            //cout<<endl;
        }
        if(cnt==0)
        {
            cout<<"Doesn't exists!\n";
        }
        else
        {
                for (int i = 0; i < 10; ++i) {
                //cout << i << "-->";
                for (SymbolInfo* t : array[i]) {
                    //t->display();
                    if(t->getname()==a)
                    {
                        it=i;
                        itt=array[i].size()-1;

                       delete t;

                       cout<<"Deleted from "<<i<<","<<array[i].size()-1<<endl;
                       break;
                    }

                }

            }
            array[it].erase(array[it].begin()+itt);
        }


    }

    void printall() {
        for (int i = 0; i < 10; ++i) {
            cout << i << "-->";
            for (SymbolInfo* t : array[i]) {
                t->display();
            }
            cout<<endl;
        }
    }
};

int main() {
    ifstream inputFile("assignment1_ip.txt");
    /*if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }*/

    SymbolTable T;
    string type;

    while (inputFile >> type) {
        if (type == "I") {
            string n, t;
            inputFile >> n >> t;
            SymbolInfo a(n, t);
            T.insert(a);
        } else if (type == "P") {
            T.printall();
        } else if (type == "L") {
            string n;
            inputFile >> n;
            T.lookup(n);
        } else if (type == "D") {
            string n;
            inputFile >> n;
            T.deletee(n);
        } else {
            cout << "Invalid command: " << type << endl;
        }
    }

    inputFile.close();
    return 0;
}
