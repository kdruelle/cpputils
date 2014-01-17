/* 
 * File:   main.cpp
 * Author: kevin
 *
 * Created on 15 novembre 2013, 23:25
 */

#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

