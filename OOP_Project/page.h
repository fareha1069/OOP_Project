#ifndef PAGE_H
#define PAGE_H
#include"user.h"
#include"post.h"
#include<fstream>
class Page : public Identity{

   vector <Identity> totalLikes;
   vector <Post> sharedPost;
    
   public:
   // constructor
   Page(string id="" , string name="" ,vector <Identity> totalLikes=vector<Identity>(), vector <Post> sharedPost =vector <Post>()):Identity(id, name)
   {
      setLikes(totalLikes);
      setSharedPost(sharedPost);
   }

   //setter
   void setLikes(vector <Identity> totalLikes)
   {
      this->totalLikes=totalLikes;
   }
   void setSharedPost(vector <Post> sharedPost)
   {
      this->sharedPost=sharedPost;
   }

   //getter
   //get shared posts
   vector<Post> getPostShared()
   {
      return sharedPost;
   }
   //get liked list
   vector<Identity> getLikedList()
   {
      return totalLikes;
   }

   //stream extraction
   friend istream& operator >> (istream& in, Page& obj)
   {
   
      in >> static_cast<Identity&>(obj);
      
      ifstream input2 ("users.txt");
     
      while(!input2.eof())
      {
         User user ;
         input2 >> user;

         vector <Identity> temp=user.getlikedPages();

         for(int i=0 ;i<temp.size() ;i++)
         {
            if(temp[i].getID() == obj.id)
            {
               obj.totalLikes.push_back((Identity)user);
            }
         }

      }
      input2.close();
      ifstream input ("post.txt");
      
      while(!input.eof())
      {
         Post post;
         input >> post;

         if(post.getSharedBy().getID() == obj.getID())
         {
            obj.sharedPost.push_back(post);
         }
        // input >> post;
      }
      input.close();
      return in;
   } 

   //stream insertion
   friend ostream& operator << (ostream& out , Page& obj)
   {
      out << (Identity)obj;
      out << "Post shared: "<< endl;
     
      for(int i=0 ;i<obj.sharedPost.size() ;i++)
      {
         out << obj.sharedPost[i] ;
      }

      out << "List of people who liked page"<< endl;

      for(int i=0 ;i<obj.totalLikes.size() ;i++)
      {
         out << obj.totalLikes[i] ;
      }
      return out ;

   }

};



#endif
