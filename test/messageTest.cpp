//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../message.h"
#include "../user.h"

TEST(Message, GetterSetter) {
    user maldini("Maldini");
    user yann("Yann");
    message mes(&maldini, &yann, "Hello, what's up Yann ?");
    ASSERT_EQ((mes.getSender())->getName(), maldini.getName());
    ASSERT_EQ((mes.getReceiver())->getName(), yann.getName());
    ASSERT_EQ(mes.getText(), "Hello, what's up Yann ?");
    ASSERT_EQ(mes.isRead(), false);
    mes.setRead(true);
    ASSERT_EQ(mes.isRead(), true);

}