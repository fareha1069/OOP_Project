#ifndef PAGEMANAGER_H
#define PAGEMANAGER_H
#include"page.h"
#include<fstream>
#include<iostream>
using namespace std;

class PageManager{
    Page *manager;

    public:
    //constructor
    PageManager()
    {
        manager=NULL;
    }

    void SetPage(string id)
    {
        ifstream input ("pages.txt");
        // fetching id from pages file and assign to manager
        while(!input.eof())
        {
            Page page;
            input >> page;
            // cout << page.getID() <<" "<<id<<endl;
            if(page.getID() == id)
            {
                manager=new Page(page);
                input.close();
                break;
            }
        }
    }

    

    void viewPage(string id)
    {
        SetPage(id);
        
        if(manager!=NULL)
        {
            std::cout << manager->getName() << endl;
            vector <Post> temp(manager->getPostShared());
            if(temp.size() == 0)
                std::cout << "No Post Shared Yet"<< endl;
            for(int i=0 ;i<temp.size(); i++)
            {
                std::cout << temp[i] << endl;
            }    
        }
        else
        {
            std::cout << "Page Not found!" << endl;
        }
    }
    
    void viewListOfLikes(string id)
    {
        SetPage(id);

        if(manager!=NULL)
        {
            std::cout << manager->getName() << " is liked by" << endl;
            vector <Identity> temp=manager->getLikedList();
            if(temp.size() == 0)
                std::cout << "No Likes Yet"<< endl;
                std::cout <<temp.size()<<endl;
            for(int i=0 ;i<temp.size(); i++)
            {
                std::cout << temp[i] << endl;
            }    
        }
        else
        {
            std::cout << "Page Not found!" << endl;
        }

        free();
    }

    //page timeline
    void viewTimeline(string id)
    {
        SetPage(id);
        if(manager == NULL)
        {
            std::cout << "No page found!" << endl;
            return;
        }
        std::cout << endl;
        std::cout << manager->getName() << " - Timeline" << endl;
        vector<Post> posts = manager->getPostShared();
        
        if(posts.size() == 0)
            std::cout << "No Posts yet!" << endl;
        for(int i=0; i<posts.size(); i++)
            std::cout << posts[i] << endl;
        
        free();
    }

    void free()
    {
        delete manager;
    }
    
    
};

#endif