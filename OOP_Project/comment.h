
#ifndef COMMENT_H
#define COMMENT_H

#include"Identity.h"
#include<string.h>
using namespace std;

class Comment :public Identity{

    string PostID;
    string description;

    public:
    // constructor
    Comment (string PostID="",string id="" , string name="" , string description=""):Identity(id,name)
    {
       
        this->description=description;
    }
    void setPostID(string ID)
    {
        this->PostID=ID;
    }
    string getPostID()
    {
        return PostID;
    }
    void setDescription(string description)
    {
        this->description=description;
    }
    string getDescription()
    {
        return description;
    }
    //extraction
   
    friend istream& operator >> (istream&in , Comment&obj )
    {
        in >> obj.PostID ;
        in >> static_cast<Identity&>(obj); 
        in.ignore();
        getline(in , obj.description );
        return in ;
    } 

    //insertion 
    friend ostream& operator << (ostream& out ,const Comment& obj  )
    {
        out<<" " << obj.name <<  " wrote  \"" << obj.description <<"\""<< endl;
        return out ;
    }

};

#endif