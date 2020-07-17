//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../message.h"


TEST(Message, GetterSetter) {
    message mes("Maldini", "Yann", "Hello, what's up Yann ?");
    ASSERT_EQ(mes.getSender(), "Maldini");
    ASSERT_EQ(mes.getReceiver(), "Yann");
    ASSERT_EQ(mes.getText(), "Hello, what's up Yann ?");
    ASSERT_EQ(mes.isRead(), false);
    mes.setRead(true);
    ASSERT_EQ(mes.isRead(), true);

}