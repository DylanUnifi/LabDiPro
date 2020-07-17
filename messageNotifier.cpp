//
// Created by FOUEPE on 17/07/2020.
//

#include "messageNotifier.h"
void messageNotifier::attach() {
    std::shared_ptr<messageNotifier> ptr= std::make_shared<messageNotifier>(*this);
    subject->subscribe(ptr);
}
void messageNotifier::detach(){
    std::shared_ptr<messageNotifier> ptr= std::make_shared<messageNotifier>(*this);
    subject->unsubscribe(ptr);
}

void messageNotifier::update()  {
    if (active)
        messageNotifier::draw(subject->lastMessage());
}

void messageNotifier::draw (const message &ms){
    char buffer [80];
    time_t time =ms.getCurrentTime();
    struct tm *localTime = localtime (& time);
    strftime(buffer, 80, "%I:%M%p", localTime);
    std::cout << "Notifcation message:"<< std::endl;
    std::cout << "Lat send message: "<< buffer << "  from " << ms.getSender() << " to " << ms.getReceiver() << std::endl;
    std::cout << "Text: " << ms.getText() << std::endl;
}