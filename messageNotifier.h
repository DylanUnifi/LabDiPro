//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_MESSAGENOTIFIER_H
#define LABDIPRO_MESSAGENOTIFIER_H


#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <list>
#include <ctime>

#include "message.h"
#include "observer.h"
#include "chat.h"


class messageNotifier: public observer{
public:
    explicit messageNotifier(bool act, std::shared_ptr<chat> sub) : active(act), subject(std::move(sub)){}
    ~messageNotifier() override= default;

    void attach() override;

    void detach() override;

    void update() override ;

    static void draw(const message &ms);

    bool isActive() const {
        return active;
    }

    void setActive(bool a) {
        messageNotifier::active = a;
    }

private:
    bool active;
    std::shared_ptr<chat> subject;
};


#endif //LABDIPRO_MESSAGENOTIFIER_H
