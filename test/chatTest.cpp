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
    message mes1 ("Maldini","Yann", "Ciao Yann, come va?");
    c.addMessage (mes1);
    message mes2 ("Yann","Maldini", "Tutto bene e tu ?");
    c.addMessage (mes2);
    message mes3 ("Maldini","Yann", "Niente male, ma ti volevo chiedere....");
    c.addMessage (mes3);
    message mes4 ("Yann","Maldini", "Dimmi tutto.");
    c.addMessage (mes4);
    message mes5 ("Maldini","Yann", "Come è andato l'esame quesa mattina ?");
    c.addMessage (mes5);

    /* ASSERT_EQ(c.lastMessage(), mes);*/
    c.readMessage(1);
    c.readMessage(2);
    c.readMessage(3);
    ASSERT_EQ(c.getUnreadMessages(), 2);
    ASSERT_THROW(c.readMessage(5), std::out_of_range);
    ASSERT_THROW(c.readMessage(6), std::out_of_range);
}