#include <gtest/gtest.h>

#define main main_0
#include "../src/abece2.c"
#undef main

#include "../../tools.cpp"

TEST(Test, visszateresi_ertek) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char re[100];
    IO("4 1", int res = main_0(), re)
    ASSERT_EQ(res, 0);
}

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char res[100];
    IO("1 a", main_0(), res)
    ASSERT_STREQ("Az eltolt betu: b\n", res);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char res[100];
    IO("5 a", main_0(), res)
    ASSERT_STREQ("Az eltolt betu: f\n", res);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char res[100];
    IO("6 q", main_0(), res)
    ASSERT_STREQ("Az eltolt betu: w\n", res);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char res[100];
    IO("5\ns", main_0(), res)
    ASSERT_STREQ("Az eltolt betu: x\n", res);
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char res[100];
    IO("4 1", main_0(), res)
    ASSERT_STREQ("Az eltolt betu: 5\n", res);
}