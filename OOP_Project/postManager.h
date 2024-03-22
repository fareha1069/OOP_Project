#ifndef POSTMANAGER_H
#define POSTMANAGER_H
#include"post.h"
#include"comment.h"
#include"Identity.h"
#include<string.h>

class PostManager
{
    Post *manager;
    
    public:
    //constructor
    PostManager()
    {
        manager=NULL;
    }

    //set post
    void SetPost(string id)
    {
        ifstream input ("post.txt");
        // Find post in post.txt and assign pointer to that post
        while(!input.eof())
        {
            Post post;
            input >> post;
            // cout <<"set id: ";
            if(post.getID() == id)
            {
                manager=new Post(post);
                input.close();
                break;
            }
        }
    }

    //view post
    void viewPost(string id)
    {
        SetPost(id);

        if(manager!=NULL)
        {
            cout << *manager << endl;
        }
        else
        {
            cout << "Post Not found!" << endl;
        }
    }

    //view lisst of people who liked posts
    void viewListOfLikes(string id)
    {
        SetPost(id);

        if(manager!=NULL)
        {
            cout <<"Post is liked by" << endl;

            //getting vector of likes on post from post
            vector <Identity> temp=manager->getLikedList();
            if(temp.size() == 0)
                cout << "No Likes Yet"<< endl;
            for(int i=0 ;i<temp.size(); i++)
            {
                cout << temp[i] << endl;
            }    
        }
        else
        {
            cout << "Page Not found!" << endl;
        }
    }

};

#endif