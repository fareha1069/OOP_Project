#ifndef IDENTITY_H
#define IDENTITY_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class Identity{

    protected:
    string id;
    string name;

    public:
    //construction
    Identity(string id="" , string name="")
    {
        setID(id);
        setName(name);
    }

    //setters
    // set id
    void setID(string id)
    {
       this->id=id;
    }

    //get name of user
    void setName(string name)
    {
        this->name=name;
    }

    //getter
    //get id
    string getID()
    {
        return this->id;
    }

    //get name of user
    string getName()
    {
        return this->name;
    }
    
    //insertion operator
    friend ostream& operator << (ostream&out ,const Identity&obj )
    {
        out << obj.id <<" - "<< obj.name << endl;  
        return out;
    }
    
    //stream insertion
    friend istream& operator >> (istream& in, Identity& obj)
    {
        in >> obj.id;
       
        if(obj.id[0] == 'u')
        {
            string Fname, Lname;
            in >> Fname;
            in >> Lname;
            obj.name = Fname + " " + Lname;
        }

        else
        {
            // in.ignore();
            getline(in,obj.name);
        }  
        return in;
    }

};


//gloabal function to find user and page by giving id
Identity findFriend(string i )
{
     if(i[0] == 'u')
    {
        ifstream in("users.txt");
        while(!in.eof())
        {
            Identity temp;
            in >> temp;

            string extra;
            int k = 20;
            while(k--)
                in >> extra;
            if(temp.getID() == i)
            {
                in.close();
                // cout << "bla bla : " << temp << endl;
                return temp;
            }
        }
    }
    else
    {
        ifstream in("pages.txt");
        int k=12;
        while(k--)
        {
            Identity temp;
            in >> temp;
            // cout << temp.getID() <<" "<<i<<endl;
            if(temp.getID() == i)
            {
                in.close();
                return temp;
            }
        }
    }
}

#endif