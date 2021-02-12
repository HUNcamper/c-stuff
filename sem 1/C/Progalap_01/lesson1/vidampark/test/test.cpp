#include <gtest/gtest.h>

#define main main_0
#include "../src/vidampark.c"
#undef main

#include "../../tools.cpp"

void hullamvasut(int a, int b);

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(50, 160))
    ASSERT_STREQ(readstring(file, str), "Mehet");
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(17, 151))
    ASSERT_STREQ(readstring(file, str), "Mehet");
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(16, 151))
    ASSERT_STREQ(readstring(file, str), "Mehet");
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(17, 150))
    ASSERT_STREQ(readstring(file, str), "Nem mehet");
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(30, 147))
    ASSERT_STREQ(readstring(file, str), "Nem mehet");
}

TEST(Test, 06) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(10, 180))
    ASSERT_STREQ(readstring(file, str), "Nem mehet");
}

TEST(Test, 07) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(hullamvasut(18, 151))
    ASSERT_STREQ(readstring(file, str), "Mehet");
}
