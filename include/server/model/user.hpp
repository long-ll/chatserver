#ifndef USER_H
#define USER_H 

#include <string>
using namespace std;

// User表的OR类
class User 
{
public: 
    User(int id = -1, string name = "", string pwd = "", string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->passward = pwd;
        this->state = state;
    }

    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setPwd(string pwd)
    {
        this->passward = pwd;
    }
    void setState(string state)
    {
        this->state = state;
    }

    int getId() const
    {
        return this->id;
    }
    string getName() const
    {
        return this->name;
    }
    string getPwd() const
    {
        return this->passward;
    }
    string getState() const
    {
        return this->state;
    }

private:
    int id;
    string name;
    string passward;
    string state;
};

#endif