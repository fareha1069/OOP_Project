# Social Media Platform

## Description

This project implements a social media platform with various domain classes and controller classes to manage users, pages, posts, and activities.

## Domain classes

### User
- Attributes
  - User ID
  - User Name
  - List of friends (aggregated from User)
  - List of liked pages (aggregated from Page class)
- Methods
  - Getter
  - Setter
  - Overload stream insertion operator
  - Overload stream extraction operator

### Page
- Attributes
  - ID
  - Page Title
  - Pointer to a list of posts the page has shared (aggregated from Post)
  - Number of likes on the page
- Methods
  - Getter
  - Setter
  - Overload stream insertion operator
  - Overload stream extraction operator

### Post
- Attributes
  - ID
  - Description for a particular post
  - Number of likes on the post
  - List of people who have liked the post (aggregated from User)
  - Date on which the post is shared
  - Activity class member (aggregated)
  - List of Comment class (aggregated)
- Methods
  - Getter
  - Setter
  - Overload stream insertion operator
  - Overload stream extraction operator

### Activity (abstract class)
- Attributes
  - Name
- Methods
  - Setter
  - Getter

### Feeling (inherited from Activity)
- Methods
  - Setter

### Thinking (inherited from Activity)
- Methods
  - Setter

### Making (inherited from Activity)
- Methods
  - Setter

### Celebrating (inherited from Activity)
- Methods
  - Setter

### Comment
- Attributes
  - Comment description
  - User (aggregated from User)
  - Page (aggregated from Page)
- Methods
  - Getter
  - Setter

### Memory (inherited from Post class)
- Attributes
  - Pointer to the original post (aggregated from Post class)
- Methods
  - Getter
  - Setter

## Controller classes

### UserManager
- Attributes
  - Aggregated from User
- Methods
  - Set current user
  - View home of the current user
  - View friend list
  - View liked pages

### PageManager
- Attributes
  - Aggregated from Page
- Methods
  - Like a page
  - View page
  - View list of posts shared

### PostManager
- Attributes
  - Aggregated from Post
- Methods
  - View a post
  - Add a post
  - Like a post
  - View list of people who liked the post
  - Add a Comment on the post
  - Add activity on the post
  - Share a (memory) post

## Usage

To use this social media platform, include the necessary classes in your project and use the provided controller classes to manage users, pages, and posts.

## Contributors

- [Fareha](https://github.com/farrha1069/)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
