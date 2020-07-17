//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_SUBJECT_H
#define LABDIPRO_SUBJECT_H
#include "observer.h"
#include <memory>

class subject {
public:
    virtual ~subject(){}
    virtual void subscribe(std::shared_ptr<observer>  observer) = 0;
    virtual void unsubscribe(std::shared_ptr<observer>  observer) = 0;
    virtual void notify() = 0;
};
#endif //LABDIPRO_SUBJECT_H
