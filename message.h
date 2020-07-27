//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_MESSAGE_H
#define LABDIPRO_MESSAGE_H


#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <ctime>

class user;
class message{
public:
    message(user * se, user* re, std::string te, bool r = false): sender(se), receiver(re), text(std::move(te)), read(r){
        time(&currentTime);
    }

    const std::string & getText() const {
        return text;
    }
    bool isRead() const {
        return read;
    }
    void setRead(bool read) {
        message::read = read;
    }

    time_t getCurrentTime() const {
        return currentTime;
    }

private:
    bool read;
    user *sender, *receiver;
    std::string text;
public:
    user *getSender() const {
        return sender;
    }

    user *getReceiver() const {
        return receiver;
    }

private:
    time_t currentTime{};
};


#endif //LABDIPRO_MESSAGE_H
