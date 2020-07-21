//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../chat.h"


std::string name1 = "Maldini";
std::string name2 = "Yann";
user maldini(name1);
user yann(name2);

TEST(chat,GetterSetter){
    chat c (maldini, yann);
    ASSERT_EQ(c.getMyName(), "Maldini");
    c.setMyName("Berkamp");
    ASSERT_EQ(c.getMyName(), "Berkamp");
    ASSERT_EQ(c.getOtherName(),"Yann");
    c.setOtherName("Dylan");
    ASSERT_EQ(c.getOtherName(), "Dylan");
    ASSERT_EQ(c.getUnreadMessages(), 0);
}

TEST(chat,functions){
    chat c (maldini, yann);
    message mes ("Maldini","Yann", "Ciao Yann, come va?");
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