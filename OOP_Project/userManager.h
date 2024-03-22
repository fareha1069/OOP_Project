#ifndef USERMANAGER_H
#define USERMANAGER_H
#include"user.h"
#include"post.h"

class UserManager{

    User *manager;

    public:
    //constructor
    UserManager()
    {
        manager= NULL;
    } 
   
    //set current user 
    void setUser(string id)
    {
        ifstream input ("users.txt");
        //Find user in users.txt and assign pointer to that user
        while(!input.eof())
        {
            User user;
            input >> user;
            if(user.getID() == id)
            {
                manager=new User(user);
                input.close();
                break;
            }
        }
        cout << manager->getName() <<" is successfully set as a current user"<< endl;
    }
   
    //view friend list 
    void viewFriendList()
    {
        if(manager!=NULL)
        {
            cout<< endl << manager->getName() <<  " - Friend List"<< endl;

            //getting vector of friends from user class
            vector <Identity> temp=manager->getFriendList();

            if(temp.size() == 0)
                cout <<"No Friend Yet"<< endl;
            for(int i=0 ;i<temp.size(); i++)
            {
                cout << temp[i] << endl;
            }
        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            while(id.size() > 2 && id[1] >='3'){
                cout <<"NO user found!"<<endl;
                cout <<"again enter id from u1 to u20"<<endl;
                cin >> id;
            }
            setUser(id);
        }
    }

    //view list of pages liked by user
    void viewLikedPages()
    {
        if(manager!=NULL)
        {
            cout << endl << manager->getName() <<  " - Liked Page"<< endl;

            //getting vector of liked pages from user class
            vector <Identity> temp=manager->getlikedPages();
            if(temp.size() == 0)
                cout <<"No Liked Pages Yet"<< endl;
            for(int i=0 ;i<temp.size(); i++)
            {
                cout << temp[i] << endl;
            }
        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (p1, p2, ... , p12): ";
            string id;
            cin >> id;
            while(id.size() > 2 && id[1] >='2' && id[2] >= '3'){
                cout <<"NO page found!"<<endl;
                cout <<"again enter id from p1 to p12"<<endl;
                cin >> id;
            }
            setUser(id);

        }
    }

    //view timeline
    void viewTimeline()
    {
        if(manager!=NULL)
        {
            cout<< endl << manager->getName() <<  " - TimeLine"<< endl;

            //getting vector of shared posts from user class
            vector <Post> temp=manager->getPostshared();
            if(temp.size() == 0)
                cout <<"No TimeLine Yet"<< endl;

            for(int i=0 ;i<temp.size(); i++)
            {
                cout << temp[i] << endl;
            }
        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
    }

    //view home page
    void HomePage(Date& date)
    {
        if(manager == NULL)
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
        
            cout << endl;
            cout << manager->getName() << " - Home Page" << endl;

            //getting list of friends from user class
            vector<Identity>friends = manager->getFriendList();
            // cout << "size : " << friends.size()<<endl;
            if(friends.size() == 0)
                cout <<"No friends yet"<<endl;
            bool flag=false;
            for(int i=0; i<friends.size(); i++)
            {
                ifstream in("post.txt");
                while(!in.eof())
                {
                    Post p;
                    in >> p;

                    //showing posts of last 24 hours of user
                    // cout <<"curr date: " << date << "  post date:"<< p.getDate()<<endl;
                    if((p.getSharedBy()).getID() == friends[i].getID() && date == p.getDate())
                    {
                        cout << p;
                    }
                }
                in.close();
            }
        
       
    }
  
    //add friend
    void addFriend(string friendID)
    {
        if(manager!=NULL)
        {
            fstream input("users.txt" , ios::in | ios::out);
            while(!input.eof())
            {
                Identity temp;
                input >> temp;

                string extra;
                if(temp.getID() == manager->getID())
                {
                    streampos position = input.tellg();
                    int count=0;
                    while(1)
                    {
                        position=input.tellg();
                        input >> extra;
                        count++;
                        if(extra == "-1")
                        {
                            input.seekp(position);
                            input << setw(5) << friendID;
                            input.close();
                            vector <Identity> temp=manager->getFriendList();
                            Identity i = findFriend(friendID);
                            temp.push_back(i);
                            manager->setfreindList(temp);
                            cout << friendID << " is successfully added!" <<endl;
                            return ;
                        }
                        if(count>=10)
                        {
                            input.close();
                            cout << "This User have already 10 Friends.Can't Add more"<<endl;
                            break;
                        }
                    }    
                }
                for(int i=0 ;i<20 ;i++)
                    input >> extra;
            }   
        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
       
    }

    //like a page 
    void likePage(string pageID)
    {
        if(manager !=NULL)
        {
            fstream input("users.txt" , ios::in | ios::out);
            while(!input.eof())
            {
                Identity temp;
                input >> temp;

                string extra;
                int count=0;
                if(temp.getID() == manager->getID())
                {
                    for(int i=0 ;i<10 ;i++)
                        input >> extra ;
                    streampos position = input.tellg();    
                    while(1)
                    {
                        position = input.tellg();  
                        input >> extra;
                        count++;
                        if(extra == "-1")
                        {
                            input.seekp(position);
                            input << setw(5) << pageID;
                            input.close();
                            vector <Identity> vec = manager->getFriendList();
                            Identity i = findFriend(pageID);
                            vec.push_back(i);
                            manager->setlikedPages(vec);
                            cout << temp.getName() << " is successfully liked a page!" <<endl;
                            return ;
                        }
                        if(count>=10)
                        {
                            input.close();
                            cout << "This Page already have 10 Likes.Can't Add more"<<endl;
                            break;
                        }
                    }    
                }
                for(int i=0 ;i<20 ;i++)
                    input >> extra;
        }

        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
       
    }

    //set post id
    void SetPost(Post temp,string id)
    {
        ifstream input ("post.txt");
    
        while(!input.eof())
        {
            
            Post post;
            input >> post;
            
            if(post.getID() == id)
            {
                temp = Post(post);
                cout <<"Post has set\n";
                input.close();
                break;
            }
        }
    }

    //add comment
    void addComment(string postID)
    {
        if(manager!=NULL)
        {
            Comment comment;
            string des;
            cout <<"Enter Description Of comment"<<endl;
            cin.ignore();
            getline(cin , des);

            comment.setID(manager->getID());
            comment.setName(manager->getName());
            comment.setPostID(postID);
            comment.setDescription(des);
            
            Post temp;
            SetPost(temp,postID);
            
            vector <Comment>com (temp.getComment());
            cout << com.size()<<endl;
            if( com.size() < 10)
            {
                fstream input("Comments.txt", ios::app);
                input << endl;
                input  << postID <<"\t";
            
            
                input  <<  manager->getID() <<"\t";
            
                input  << manager->getName() <<"\t"; 
        
                input << comment.getDescription();

                
                input.close();
            }
            else
            {
                cout <<"This post Already Have 10 comments!Can't Add more!"<<endl;
            }
        
        }
        else
        {
            cout << "\tNo user found!" << endl;
            cout << "Enter user ID (u1, u2, ... , u20): ";
            string id;
            cin >> id;
            setUser(id);
        }
       
    }

    //Add post
    void addPost(Date date)
    {
        
        ifstream input ("post.txt");
        int count=0;
        while(!input.eof())
        {
            Post post;
            input >> post ;
            count++;
        }
        input.close();

        string id="post"+to_string(++count);

        string description ;
        cout << "What You would like to say In your Post : ";
        cin.ignore();
        getline(cin , description);

        cout <<"1. Expressing My Feeling "<<endl;
        cout <<"2. I am Thinking  "<<endl;
        cout <<"3. I am cooking "<<endl;
        cout <<"4. I am Celebrating "<<endl << endl;
        cout <<"5. I Don't want to add activity"<<endl<<endl;
        cout <<"Choose your Type Accorodingly : ";
        int type ;
        cin >> type;
    
        string feeling;
        if(type != 5)
        {
            cout << "Express Your Activity : ";
            cin.ignore();
            getline(cin , feeling);
        }
        

        fstream out("post.txt" , ios::app);

        out << endl;
        out << id <<" "<< description << endl;
       
        out << date.getDay() <<"\t" << date.getMon() <<"\t" << date.getYear()<< endl;

        if(type == 5)
            out << "-1" << "\t" ;
        else
            out << type << "\t" ;
        if(type != 5)
            out << feeling << endl;

        out << manager->getID() << endl;

        out << "-1" ;
        cout << "Post is successfully added with id: " <<id<<endl; 
    }  
};

#endif