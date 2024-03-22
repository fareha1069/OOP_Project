#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Date{

    string day;
    string month;
    string year;

    public:
    //constructor
    Date(string day ="" , string month="" ,string year="")
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    void setDate(string day, string month , string year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
    string getDay()
    {
        return day;
    }
    string getMon()
    {
        return month;
    }
    string getYear()
    {
        return year;
    }

    //equal operator
    bool operator==(Date date)
    {
        if(  this->month == date.month && this->year == date.year )
        {
            if(this->day == date.day)
                return true ;
            else if( stoi(this->day) - 1 == stoi(date.day) )   
            {
                return true ;
            }     
        }    
        return false;
    }

    //extraction
    friend istream& operator >> (istream& in , Date &obj)
    {
        in >> obj.day;
        in >> obj.month ;
        in >> obj.year;

        return in;
    }
    //insertion
    friend ostream& operator << (ostream& out , const Date&obj)
    {
        out << obj.day <<"/" << obj.month << "/"<< obj.year<< endl;
        return out ;
    }

};

#endif