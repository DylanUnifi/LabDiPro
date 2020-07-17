//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_USER_H
#define LABDIPRO_USER_H


#include <iostream>
#include <memory>
#include <map>
#include "chat.h"

class chat;
class user {
public:
    explicit user(const std::string& name) : name(name) {}

    ~user();

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        user::name = name;
    }

    std::shared_ptr<chat> createChat(user& u);

    std::shared_ptr<chat> findChat(const user& u);

    void removeChat(const user& u);

    void addChat(std::shared_ptr<chat> c, const user & u);


private:
    std::string name;
    std::map <std::string,std::shared_ptr<chat>> chats;
};


#endif //LABDIPRO_USER_H
