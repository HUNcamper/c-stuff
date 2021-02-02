#include <gtest/gtest.h>

#define main main_0
#include "../src/ora.c"
#undef main

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_DOUBLE_EQ(ora(120), 2);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_DOUBLE_EQ(ora(0), 0);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_DOUBLE_EQ(ora(90), 1.5);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_DOUBLE_EQ(ora(522), 8.7);
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_DOUBLE_EQ(ora(53252), 887 + 1.6/3);
}