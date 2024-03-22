#include<iostream>
#include"userManager.h"
#include"postManager.h"
#include"pageManager.h"
#include<string>
#include<algorithm>
#include<cctype>
#include<iomanip>

using namespace std;

void menu ()
{
    cout << endl << endl;
    cout << "-------------------  SOCIAL NETWORKING SYSTEM  -------------------" << endl << endl;
    cout << "\t\t1.\tSet User" << endl << endl;
    cout << "\t\t2.\tMy Friends" << endl << endl;
    cout << "\t\t3.\tMy Liked Pages" << endl << endl;
    cout << "\t\t4.\tMy Timelime" << endl << endl;
    cout << "\t\t5.\tMy Home" << endl << endl;
    cout << "\t\t6.\tAdd New Friend" << endl << endl;
    cout << "\t\t7.\tLike A page" << endl << endl;
    cout << "\t\t8.\tView Post" << endl << endl;
    cout << "\t\t9.\tLikes on Post" << endl << endl;
    cout << "\t\t10.\tAdd Comment" << endl << endl;
    cout << "\t\t11.\tAdd Post" << endl << endl;
    cout << "\t\t12.\tView Page" << endl << endl;
    cout << "\t\t13.\tLikes on Page" << endl << endl;
    cout << "\t\t14.\tExit" << endl << endl;

}
void setDate(Date& date)
{
   string day ="21",month="1",year="2024";
    date.setDate(day, month,year);
}
void showPages()
{
    ifstream in("pages.txt");
    while(!in.eof())
    {
        Identity i;
        in >> i;
        cout << i << endl;
    }
    in.close();
}
int main()
{
    int choice;
    Date d;
    UserManager *user=new UserManager;
    PostManager * post=new PostManager;
    PageManager page;

    //set current date
    setDate(d);
    do{
        menu();
        
        cout << "Enter Your Choice accoroding to menu : ";
        cin >> choice ;

        
        if(choice == 1)
        {
            string id;

            cout <<"Enter ID to Set User (u1,u2,u3,...) :  " ;
            cin >> id;
            while(id.size() > 2 && id[1] >='3'){
                cout <<"NO user found!"<<endl;
                cout <<"again enter id from u1 to u20"<<endl;
                cin >> id;
            }

            user->setUser(id);
        }
        else if(choice == 2)
        {
            user->viewFriendList();
        }
        else if(choice == 3)
        {
            user->viewLikedPages();
        }
        else if(choice == 4)
        {
            user->viewTimeline();
        }
        else if(choice == 5)
        {
            user->HomePage(d);
        }
        else if(choice == 6)
        {
            cout <<"Enter friend ID (u1,u2,....u20) : ";
            string id;
            cin >> id;
            while(id.size() > 2 && id[1] >='3'){
                cout <<"NO user found!"<<endl;
                cout <<"again enter id from u1 to u20"<<endl;
                cin >> id;
            }

            user->addFriend(id);
        }
        else if(choice == 7)
        {
            cout <<"Enter page ID (p1,p2,....p20) : ";
            string id;
            cin >> id;
            user->likePage(id);
        }
        else if(choice == 8)
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
            string id="post"+to_string(count);
            cout <<"posts are available from post1 to "<<id<<endl;
            cout << "Enter ID to view  a post :" <<endl;
            
            cin >> id;
            post->viewPost(id);
        }
        else if(choice == 9)
        {
            cout << "Enter ID to view List Likes on a post (post1 , post2 , post3 ,...): " ;
            string id;
            cin >> id;
            post->viewListOfLikes(id);
        }
        else if(choice == 10)
        {
            cout <<"Enter post ID to add comment on (post1,post2,...): ";
            string id;
            cin >> id;
            user->addComment(id);
        }
        else if(choice == 11)
        {
            user->addPost(d);
        }
        else if(choice == 12)
        {
            showPages();
            cout <<"Enter ID to view a page (p1,p2,p3,...): ";
            string id;
            cin >> id;
            page.viewPage(id);
        }
        else if(choice == 13)
        {
            cout <<"Enter ID to view list of likes on a page (p1,p2,p3,...): ";
            string id;
            cin >> id;
            page.viewListOfLikes(id);   
        }
        else if(choice == 14)
        {
            cout << "Are you sure you want to  exit? (YES/NO):";
            string st;
            cin >> st;
            transform(st.begin(), st.end(), st.begin(), ::tolower);
            if(st == "yes")
            {
                cout << "Thanks for using the app. See you again!!!" << endl;
                break;
            }
        }
    }
    while(choice != 14);

}