//
// Created by FOUEPE on 27/07/2020.
//

#include "message.h"
#include "user.h"

message::message(const message &original) {
    currentTime = original.currentTime;
    read = original.read;
    if (original.sender != nullptr && original.receiver){
        sender = new user(*original.sender);
        receiver = new user(*original.receiver);
    }
    else{
        sender = {nullptr};
        receiver = {nullptr};
    }
}
message& message::operator=(const message &right) {
    if (this != &right) {
        if (sender != nullptr && receiver != nullptr){
            delete sender;
            delete receiver;
        }

        currentTime = right.currentTime;
        read = right.read;
        if (right.sender != nullptr && right.receiver){
            sender = new user(*right.sender);
            receiver = new user(*right.receiver);
        }
        else{
            sender = nullptr;
            receiver = nullptr;
        }
    }
    return *this;
}