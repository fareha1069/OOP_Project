OOP Project , A social networking application keep the record of ones frineds , pages , posts , comments and activity.
Overview of classes and their relationship with each other
*Domain classes*
User
● Attributes
○ User ID
○ User Name
○ List of friends (aggregate from user)
○ List of liked pages(aggregation from page class)
● Methods
○ Getter
○ Setter
○ Overload stream insertion operator
○ Overload stream extraction operator
Page
● Attributes
○ ID
○ Page Title
○ Pointer for list of posts page has shared(aggregation from post)
○ Number of likes on page
● Methods
○ Getter
○ Setter
○ Overload stream insertion operator
○ Overload stream extraction operator
Post
● Attributes
○ ID
○ Description for particular post
○ No of likes on post
○ List of people who have liked the post (aggregation from user)
○ Date on which post is shared
○ Activity class member (aggregation)
○ List of Comment class (aggregation)
● Methods
○ Getter
○ Setter
○ Overload stream insertion operator
○ Overload stream extraction operator
Activity (abstract class)
● Attributes
○ Name
● Methods
○ Setter
○ Getter
Feeling (inherited from activity)
● Methods
○ setter
Thinking (inherited from activity)
● Methods
○ Setter
Making (inherited from activity)
● Methods
○ setter
Celebrating (inherited from activity)
● Methods
○ setter
Comment
● Attributes
○ Comment description
○ User (aggregation from user)
○ Page (aggregation from page)
● Methods
○ Getter
○ Setter
Memory (inherited from post class)
● Attributes
○ Pointer to original post(aggregation from post class)
● Methods
○ Getter
○ Setter
*Controller classes*
User Manager
● Attributes
○ Aggregation from user
● Methods
○ Set current user
○ View home of current user
○ View friend list
○ View liked pages
Page Manager
● Attributes
○ Aggregation from page
● Methods
○ Like a page
○ View page
○ View list of post shared
Post Manager
● Attributes
○ Aggregation from post
● Methods
○ View a post
○ Add post
○ Like a post
○ View list of people who liked post
○ Add Comment on post
○ Add activity on post
○ Share a (memory) post
