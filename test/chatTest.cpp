//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../chat.h"
#include "../user.h"

std::string name1 = "Maldini";
std::string name2 = "Yann";
user maldini(name1);
user yann(name2);

TEST(chat,GetterSetter){
    chat c (maldini, yann);
    ASSERT_EQ((c.getMyName())->getName(), maldini.getName());
    user berkamp("Berkamp");
    c.setMyName(&berkamp);
    ASSERT_EQ((c.getMyName())->getName(), berkamp.getName());
    ASSERT_EQ((c.getOtherName())->getName(),yann.getName());
    user dylan("Dylan");
    c.setOtherName(&dylan);
    ASSERT_EQ((c.getOtherName())->getName(), dylan.getName());
    ASSERT_EQ(c.getUnreadMessages(), 0);
}

TEST(chat,functions){
    chat c (maldini, yann);
    message mes (&maldini,&yann, "Ciao Yann, come va?");
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);
    c.addMessage (mes);

    /* ASSERT_EQ(c.lastMessage(), mes);*/
    c.readMessage(3);
    c.readMessage(1);
    c.readMessage(2);
    ASSERT_EQ(c.getUnreadMessages(), 2);
    ASSERT_THROW(c.readMessage(5), std::out_of_range);
    ASSERT_THROW(c.readMessage(6), std::out_of_range);
}