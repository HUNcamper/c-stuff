#include <gtest/gtest.h>

#define main main_0
#include "../src/kamat.c"
#undef main

float kamat(float f);

TEST(Test, 01) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(kamat(10), 11.0f);
}

TEST(Test, 02) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(kamat(54), 59.4f);
}

TEST(Test, 03) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(kamat(1), 1.1f);
}

TEST(Test, 04) { // NOLINT(cert-err58-cpp) suppress for initialization static field in generated class
    ASSERT_FLOAT_EQ(kamat(61.51), 67.661f);
}