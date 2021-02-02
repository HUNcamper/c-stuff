#include <gtest/gtest.h>

#define main main_0
#include "../src/kamion.c"
#undef main

int kisKamion();
int kozepesKamion();
int nagyKamion();

TEST(Test, kisKamion) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(kisKamion(), 3);
}

TEST(Test, kozepesKamion) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(kozepesKamion(), 7);
}

TEST(Test, nagyKamion) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_EQ(nagyKamion(), 10);
}