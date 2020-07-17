#include <iostream>
#include <memory>

#include "chat.h"
#include "messageNotifier.h"
#include "unreadMessageNotification.h"
#include "version.h"
int main() {
    std::cout << "Chat message " << VERSION << std::endl;
    user dylan("Dylan");
    user berkamp ("Berkamp");
    std::shared_ptr<chat> ptr= dylan.createChat(berkamp);
    std::shared_ptr<chat> ptr2= dylan.findChat(berkamp);
    user paul("Paul");
    message foo("Dylan", "Berkamp", "Ciao Berkamp, come va?");
    message bar("Berkamp", "Dylan", "Tutto bene, te?");
    message fooBar("Dylan", "Berkamp", "Anch'io tutto bene");
    messageNotifier messageNotifier(true, ptr);
    unreadMessageNotification iconBadgeMonitor(ptr);
    messageNotifier.attach();
    iconBadgeMonitor.attach();
    ptr2->addMessage(foo);
    ptr->addMessage(bar);
    ptr->addMessage(fooBar);
    try {
        ptr->readMessage(1);
        ptr2->readMessage(5);
    }
    catch (std::out_of_range &e) {
        std::cerr << "Out of range error:" << e.what() << std::endl;
    }
    dylan.removeChat(berkamp);
}

