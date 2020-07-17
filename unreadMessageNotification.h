//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_UNREADMESSAGENOTIFICATION_H
#define LABDIPRO_UNREADMESSAGENOTIFICATION_H


#include <utility>
#include <vector>
#include <list>
#include <memory>
#include "observer.h"
#include "chat.h"
#include "subject.h"


class unreadMessageNotification: public observer {
public:
    explicit unreadMessageNotification(std::shared_ptr<chat> sub):subject(std::move(sub)){}

    ~unreadMessageNotification() override= default;

    void attach() override;

    void detach() override;

    void update() override;

    static void draw(int um);

private:
    std::shared_ptr<chat> subject;
};


#endif //LABDIPRO_UNREADMESSAGENOTIFICATION_H
