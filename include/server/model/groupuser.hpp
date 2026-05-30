#ifndef GGROUSER_H
#define GGROUPUSER_H 

#include "user.hpp"

// 群组用户，多了一个role角色信息，从User类直接继承，复用User的其他信息
class GroupUser : public User {
public:
    void setRole(string role) { this->role = role; }
    string getRole() { return this->role;}

private:
    string role;  // 角色信息，群主/管理员/普通成员
};



#endif


