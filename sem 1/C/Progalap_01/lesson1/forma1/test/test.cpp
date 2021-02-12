#include <gtest/gtest.h>

#define main main_0
#include "../src/forma1.c"
#undef main

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(futamhossz(67.44f, 73, 17.4f, 2), 82.632f);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(futamhossz(94, 49, 23.3f, 1), 77.155f);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(futamhossz(83.1224f, 56, 19.354f, 1), 233.71042f/3);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(futamhossz(110.54f, 47, 28.5f, 0), 259.769f/3);
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(futamhossz(78.11f, 78, 14.31f, 4), 102.497f);
}
