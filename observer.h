//
// Created by FOUEPE on 17/07/2020.
//

#ifndef LABDIPRO_OBSERVER_H
#define LABDIPRO_OBSERVER_H
class observer {
public:
    virtual ~observer(){}
    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;
};
#endif //LABDIPRO_OBSERVER_H
