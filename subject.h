//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_SUBJECT_H
#define LABDIPRO_SUBJECT_H
#include "observer.h"
#include <memory>

class Subject {
public:
    virtual ~Subject(){}
    virtual void subscribe(std::shared_ptr<Observer>  observer) = 0;
    virtual void unsubscribe(std::shared_ptr<Observer>  observer) = 0;
    virtual void notify() = 0;
};
#endif //LABDIPRO_SUBJECT_H
