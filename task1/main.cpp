#include <iostream>
#include <stdint.h>
#include "Trit.h"
#include "Tests/TritSet.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"


int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}