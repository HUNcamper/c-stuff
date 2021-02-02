#include <gtest/gtest.h>

#define main main_0
#include "../src/rekord.c"
#undef main

#include "../../tools.cpp"

void ranglista(float legjobbIdo, float ujIdo);

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(ranglista(50, 49));
    ASSERT_STREQ(readstring(file, str), "Megdontotted a rekordot!");
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(ranglista(50, 51));
    ASSERT_STREQ(readstring(file, str), "");
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(ranglista(49.7f, 49.68f));
    ASSERT_STREQ(readstring(file, str), "Megdontotted a rekordot!");
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(ranglista(49.7f, 49.722f));
    ASSERT_STREQ(readstring(file, str), "");
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    char str[100];
    KIIR(ranglista(2, 2));
    ASSERT_STREQ(readstring(file, str), "");
}
