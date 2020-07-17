//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_CHAT_H
#define LABDIPRO_CHAT_H


#include <iostream>
#include <memory>
#include <vector>
#include <list>

#include "user.h"
#include "message.h"
#include "subject.h"

class user;
class chat : public subject{
public:
    explicit chat(user mn, user on);

    virtual ~chat();

    void addMessage(const message& newMsg);

    const message& lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    virtual void subscribe(std::shared_ptr<observer> observers) override;

    virtual void unsubscribe(std::shared_ptr<observer> observers) override;

    virtual void notify() override;

    const std::string &getMyName() const;

    void setMyName(const std::string &myName);

    const std::string &getOtherName() const;

    void setOtherName(const std::string &otherName);

private:
    std::list<std::shared_ptr<observer>> observers;
    std::vector<message> messages;
    std::string myName;
    std::string otherName;
};


#endif //LABDIPRO_CHAT_H
