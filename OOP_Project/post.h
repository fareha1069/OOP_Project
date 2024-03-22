#ifndef POST_H
#define POST_H

#include<iostream>
#include<string>
// #include"user.h"
#include"Identity.h"
#include"comment.h"
#include"activity.h"
#include"date.h"

using namespace std;
class Post:public Identity {
    
    int noOflikes;
    Identity sharedBy;
    vector <Identity> likedList;
    Date date;
    Activity *activity;
    vector <Comment> comments;


    public:
    
    Post(string id ="" , string description ="" , int noOflikes=0, string ID="" , string name="" , vector<Identity>likedList=vector <Identity>() , string date="" , string month="" , string year="" , vector<Comment>comments=vector <Comment>()   ):Identity(id,description), date(date , month , year),sharedBy(ID,name)
    {
        this->sharedBy=sharedBy;
        this->likedList=likedList;
        this->noOflikes=likedList.size();
        this->comments=comments;
        this->activity=NULL;
        
    }

    //setters
    void setDate(string d , string m , string y)
    {
        this->date.setDate(d,m,y);
    }

    void setSharedBy(string id , string name)
    {
        this->sharedBy.setID(id);
        this->sharedBy.setName(name);
    }

    void setActivity(int type , string name)
    {
        this->activity->setType(type);
        this->activity->setName(name);
    }
  
    //getter
    Identity getSharedBy()
    {
        return sharedBy;
    }

    //get comments list
    vector<Comment> getComment()
    {
       
        return comments;
    }

    //get list of pepple who liked post
    vector<Identity>getLikedList()
    {
        return likedList;
    }

    Date getDate()
    {
        return date;
    }

    Activity* getActivity()
    {
        return activity;
    }
    //extraction

    friend istream& operator >> (istream&in , Post& obj )
    {
        in >> static_cast<Identity&>(obj);
      
        in >> obj.date;

        int activityType;
        in >> activityType;
    
        if(activityType!=-1)
        {
            string st;
            getline(in , st);
        
            if(activityType == 1)
                obj.activity = new Feeling(activityType, st);

            else if(activityType == 2)
                obj.activity = new Thinking(activityType, st);

            else if(activityType == 3)
                obj.activity = new Making(activityType, st);

            else 
                obj.activity = new Celebrating(activityType, st);
        }
       
        string tempID;
        in >> tempID;
        
        obj.sharedBy = findFriend(tempID);
        
        in >> tempID;
       
        while(tempID!="-1")
        {
            Identity likedPerson (findFriend(tempID));
            obj.likedList.push_back(likedPerson);
            in >> tempID;
        }

        ifstream input("Comments.txt");
        while(!input.eof())
        {
            Comment c;
            input >> c;
            if(c.getPostID() == obj.getID())
                obj.comments.push_back(c);
            
        }
        input.close();

        return in;   
    }
  
    //insertion 
    friend ostream& operator << (ostream& out , Post& obj )
    {
        out << obj.sharedBy.getName()<<" is " ;

        if(obj.activity != NULL)
            obj.activity->display() ;
        
        out << "\"" << obj.name << "\"" << endl;
        out << obj.date<<endl;   

        // cout << obj.comments.size();
        for (int i=0 ;i<obj.comments.size() ;i++)
        {
            out << obj.comments[i];
        }
        return out ;
    }

   
};


#endif

