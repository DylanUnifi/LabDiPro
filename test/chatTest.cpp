//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../chat.h"


std::string name1 = "Madlini";
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
}

TEST(chat,functions){
    chat c (maldini, yann);
    message mes ("Maldini","Yann", "Ciao Yann, come va?");
    c.addMessage (mes);
    ASSERT_EQ(c.lastMessage(), mes);
    ASSERT_THROW(c.readMessage(2), std::out_of_range);
    ASSERT_THROW(c.readMessage(0), std::out_of_range);
}