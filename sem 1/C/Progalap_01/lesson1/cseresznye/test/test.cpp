#include <gtest/gtest.h>

#define main main_0
#include "../src/cseresznye.c"
#undef main

int cseresznyeVasarlas(int ar, int mennyiseg);

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(cseresznyeVasarlas(5, 7), 35);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(cseresznyeVasarlas(10, 4), 40);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(cseresznyeVasarlas(6000, 7), 42000);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(cseresznyeVasarlas(511, 21), 10731);
}

TEST(Test, 05) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(cseresznyeVasarlas(400000000, 0), 0);
}