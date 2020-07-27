//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../messageNotifier.h"
#include "../user.h"

TEST(MessageNotifier, isActive) {
    user a("Maldini");
    user b("Yann");
    chat c(a,b);
    std::shared_ptr<chat> ptr = std::make_shared<chat>(c);
    messageNotifier m(true,ptr);
    ASSERT_TRUE(m.isActive());
    m.setActive(false);
    ASSERT_FALSE(m.isActive());
}