//
// Created by FOUEPE on 17/07/2020.
//

#include "chat.h"
chat::chat(const user& first_user, const user& second_user):myName(first_user.getName()), otherName(second_user.getName()) {}

chat::~chat() = default;

void chat::addMessage(const message& newMsg){
    if((myName==newMsg.getReceiver()||myName==newMsg.getSender())&&(otherName==newMsg.getSender()||otherName==newMsg.getReceiver()))
        messages.push_back(newMsg);
    if(myName==newMsg.getReceiver())
        this->notify();
}

const message& chat::lastMessage() const{
    return messages.back();
}

void chat::readMessage(int i){
    if(i>0 && i<messages.size()) {
        if (messages[i].getSender() == otherName) {
            std::cout <<"Sender: "<< messages[i].getSender() <<", "<<"Receiver: "<< messages[i].getReceiver() << std::endl;
            std::cout <<"Text: "<< messages[i].getText() << std::endl;
            messages[i].setRead(true);
            this->notify();
        }
    }
    else
        throw std::out_of_range(" Messaggio non presente nella chat");
}
int chat::getUnreadMessages() const{
    int i=0;
    for(const auto& message:messages)
        if(message.getReceiver()==myName)
            if (!message.isRead())
                i++;
    return i;
}
void chat::subscribe(std::shared_ptr<observer> observer) {
    observers.push_back(observer);
}
void chat::unsubscribe(std::shared_ptr<observer> observer) {
    observers.remove(observer);
}
void chat::notify() {
    for (const auto& observer: observers)
        observer->update();
}

const std::string &chat::getMyName() const {
    return myName;
}

void chat::setMyName(const std::string &myN) {
    chat::myName = myN;
}

const std::string &chat::getOtherName() const {
    return otherName;
}

void chat::setOtherName(const std::string &otherN) {
    chat::otherName = otherN;
}