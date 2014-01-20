
#include <gtest/gtest.h>

#include <vector>

#include <cpputils/regex.h>


TEST(regex, match){
    cpputils::regex reg;
    std::vector<std::string> matches;
    
    reg = "([aeiouy])";
    reg.extract("abcdefghijklmnopqrstuvwxyz  ", matches);
    EXPECT_EQ("a", matches[0]);
    EXPECT_EQ("e", matches[1]);
    EXPECT_EQ("i", matches[2]);
    EXPECT_EQ("o", matches[3]);
    EXPECT_EQ("u", matches[4]);
    EXPECT_EQ("y", matches[5]);
    
    EXPECT_EQ("-a-bcd-e-fgh-i-jklmn-o-pqrst-u-vwx-y-z", reg.replace("abcdefghijklmnopqrstuvwxyz", "-$1-"));
    
    
    
    
}


