//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_CHAT_H
#define LABDIPRO_CHAT_H


#include <iostream>
#include <memory>
#include <vector>
#include <list>

#include "message.h"
#include "subject.h"

class user;
class chat : public subject{
public:
    explicit chat(user& first_user, user& second_user);

    virtual ~chat();

    void addMessage(const message& newMsg);

    const message& lastMessage() const;

    void readMessage(int i);

    int getUnreadMessages() const;

    virtual void subscribe(std::shared_ptr<observer> observers) override;

    virtual void unsubscribe(std::shared_ptr<observer> observers) override;

    virtual void notify() override;

    user *getMyName() const;

    void setMyName(user *myName);

    user *getOtherName() const;

    void setOtherName(user *otherName);

    chat(user *myName, user *otherName);

    chat(const chat& original);
    chat & operator=(const chat& right);

    const std::vector<message> &getMessages() const;

private:
    std::list<std::shared_ptr<observer>> observers;
    std::vector<message> messages;
    user* myName;
    user* otherName;
};


#endif //LABDIPRO_CHAT_H
