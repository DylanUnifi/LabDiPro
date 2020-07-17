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

class message{
public:
    message(std::string se, std::string re, std::string te, bool r = false): sender(std::move(se)), receiver(std::move(re)), text(std::move(te)), read(r){
        time(&currentTime);
    }

    const std::string & getSender() const {
        return sender;
    }

    const std::string & getReceiver() const {
        return receiver;
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

    bool operator==(const message &rhs) const {
        return sender == rhs.sender &&
               receiver == rhs.receiver &&
               text == rhs.text;
    }

    bool operator!=(const message &rhs) const {
        return !(rhs == *this);
    }

private:
    bool read;
    std::string sender, receiver, text;
    time_t currentTime{};
};


#endif //LABDIPRO_MESSAGE_H
