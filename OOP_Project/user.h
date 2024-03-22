#ifndef USER_H
#define USER_H

#include"Identity.h"
#include"post.h"
// #include"page.h"
using namespace std;


class User : public Identity {
    
    vector <Identity> friends;
    vector <Identity> likedPages;
    vector<Post> postshared;

    public:
    //constructor
    User(string id="" , string name =""   , vector <Identity>friends = vector <Identity>(), vector <Identity> likedPages= vector <Identity>() , vector<Post> postshared=vector<Post>()):Identity(id,name)
    {
        set( friends ,likedPages, postshared);
    }

    //setters
    void set ( vector <Identity>friends  , vector <Identity> likedPages, vector<Post> postshared)
    {
        setfreindList(friends);
        setlikedPages(likedPages);
        setpostshared(postshared);
    }
  
    //set friend list of user
    void setfreindList(vector <Identity> friends)
    {
        this->friends=friends;
    }
    
    //set pages liked by user
    void setlikedPages(vector <Identity> likedPages)
    {
       this->likedPages=likedPages;
    }

    //set post shared by user
    void setpostshared(vector <Post> postshared)
    {
       this->postshared=postshared;
    }

    //getters
    //get friend list of user
    vector <Identity> getFriendList()
    {
        return this->friends;
    }

    //get list of pages liked by user
    vector <Identity> getlikedPages()
    {
        return this->likedPages;
    }
    //get postshared
    vector <Post> getPostshared()
    {
        return this->postshared;
    }

    //stream extraction
    friend istream& operator >> (istream& in, User& obj)
    {
        in >> static_cast<Identity&>(obj);
        string i;
        int k = 0;
        while(k < 10)
        {
            in >> i;
            if(i != "-1")
            {
                //calling gloabal function to find user of certain id 
                Identity temp(findFriend(i));
                obj.friends.push_back(temp);
            }
            k++;
        }
        k = 0;
        while(k < 10)
        {
            in >> i;
            if(i != "-1")
            {   
                //calling gloabal function to find user of certain id 
                Identity temporary(findFriend(i));
                obj.likedPages.push_back(temporary);
            }
            k++;
        }
        ifstream input("post.txt");
        while(!input.eof())
        {
            Post temp;
            input >> temp;
            //find posts shared by user in post class
            string t = (temp.getSharedBy()).getID();
            if(t == obj.id)
                obj.postshared.push_back(temp);
        }
        input.close();

        return in;
    }

    //stream insertion
    friend ostream& operator << (ostream& out , User&obj)
    {
        out << (Identity)obj;

        if(obj.friends.size()>0)
            out <<"\t" "List of friends" << endl;

        out << "friends: "<<obj.friends.size()<<endl;
        for(int i=0 ;i<obj.friends.size() ;i++)
        {
            out << obj.friends[i] ;
        }

        out << endl;
         out << "pages: "<<obj.likedPages.size()<<endl;
        if(obj.likedPages.size()>0)
            out << "\tList of pages liked by user" << endl;
        for(int i=0 ;i<obj.likedPages.size() ;i++)
        {
            out << obj.likedPages[i] ;
        }

        out << endl;

         out << "posts: "<<obj.postshared.size()<<endl;
        if(obj.postshared.size()>0)
             out << "\tList of posts shared by user" << endl;
        for(int i=0 ;i<obj.postshared.size() ;i++)
        {
            out << obj.postshared[i] ;
        }
        
        out << endl;
        return out;
    }

};

#endif