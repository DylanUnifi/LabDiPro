#include <iostream>
#include <memory>

#include "chat.h"
#include "messageNotifier.h"
#include "unreadMessageNotification.h"
#include "version.h"
int main() {
    std::cout << "Chat message " << VERSION << std::endl;
    user elisa("Elisa");
    user francesca ("Francesca");
    std::shared_ptr<chat> ptr= elisa.createChat(francesca);
    std::shared_ptr<chat> ptr2= elisa.findChat(francesca);
    user p("Paolo");
    message foo("Elisa", "Francesca", "Ciao Francesca, come va?"), bar("Francesca", "Elisa", "Tutto bene, te?"), fooBar(
            "Elisa", "Francesca", "Anch'io tutto bene");
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
    elisa.removeChat(francesca);
}

