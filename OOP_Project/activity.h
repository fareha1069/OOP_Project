#ifndef ACTIVITY_H
#define ACTIVITY_H

#include<iostream>
#include<string>
using namespace std;

class Activity {

    protected:
    int type;
    string name;
   
    public:
    //constructor

    Activity( int type=1 , string name="")
    {
        this->type=type;
        this->name=name;
    }

    //setter
    void set(int type , string name)
    {
        setType(type);
        setName(name);
    }
    void setType(int type)
    {
        this->type=type;
    }
    void setName(string name)
    {
        this->name=name;
    }

    virtual void display() = 0;
    //getter
    string getName(){
        return name;
    }

    //getter
    int getType(){
        return type;
    }

};

class Feeling :public Activity{

    public:
    //constructor

    Feeling( int type=1 , string name=""):Activity(type,name){}
    
    //insertion
    friend ostream& operator << (ostream& out , const Feeling & obj )
    {
        out << " Feeling " << obj.name << endl;
        return out;
    }
    void display()
    {
        cout << *this << endl;
    }
};

class Thinking :public Activity{

    public:
    //constructor

    Thinking( int type=1 , string name=""):Activity(type,name){}
    //insertion
    friend ostream& operator << (ostream& out , const Thinking & obj )
    {
        out << " Thinking " << obj.name << endl;
        return out;
    }
    void display()
    {
        cout << *this << endl;
    }

};

class Making :public Activity{

    public:
    //constructor

    Making( int type=1 , string name=""):Activity(type,name){}

    //insertion
    friend ostream& operator << (ostream& out , const Making & obj )
    {
        out << " Making " << obj.name << endl;
         return out;
    }
    void display()
    {
        cout << *this << endl;
    }


};
class Celebrating :public Activity{

    public:
    //constructor

    Celebrating( int type=1 , string name=""):Activity(type,name){}

    //insertion
    friend ostream& operator << (ostream& out , const Celebrating & obj )
    {
        out << " Celebrating " << obj.name << endl;
         return out;
    }
    void display()
    {
        cout << *this << endl;
    }

};
#endif