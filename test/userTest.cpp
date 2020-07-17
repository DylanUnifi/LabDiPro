//
// Created by FOUEPE on 17/07/2020.
//

#include "gtest/gtest.h"
#include "../user.h"

TEST(user, GetterSetter) {
    user l("Fouepe");
    ASSERT_EQ(l.getName(), "Fouepe");
    l.setName("Dongmo");
    ASSERT_EQ(l.getName(), "Dongmo");
}