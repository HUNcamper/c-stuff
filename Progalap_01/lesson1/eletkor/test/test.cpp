#include <gtest/gtest.h>

#define main main_0
#include "../src/eletkor.c"
#undef main

#include "../../tools.cpp"

int korbeolvas();

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    BEOLVAS("7", int res = korbeolvas());
    ASSERT_EQ(res, 7);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    BEOLVAS("27", int res = korbeolvas());
    ASSERT_EQ(res, 27);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    BEOLVAS("74", int res = korbeolvas());
    ASSERT_EQ(res, 74);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    BEOLVAS("55", int res = korbeolvas());
    ASSERT_EQ(res, 55);
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    BEOLVAS("103", int res = korbeolvas());
    ASSERT_EQ(res, 103);
}
