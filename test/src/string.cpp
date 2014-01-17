
#include <gtest/gtest.h>

#include <vector>

#include <cpputils/string.h>


TEST(string_utils, tohexstring){
    unsigned char binary [10] = {0x01, 0x02, 0x23, 0xAF, 0x00, 0x12, 0x34, 0xFF, 0xD2, 0x9B};
    std::string s;
    s = cpputils::tohexstring(binary, sizeof(binary));
    EXPECT_EQ("010223af001234ffd29b", s);
    s = cpputils::tohexstring(binary, sizeof(binary), true);
    EXPECT_EQ("010223AF001234FFD29B", s);
}

TEST(string_utils, trim_left){
    std::string trimed;
    
    trimed = cpputils::trim_left("-(hc  fonction", "- h(c");
    
    EXPECT_EQ("fonction", trimed);
}

TEST(string_utils, trim_right){
    std::string trimed;
    
    trimed = cpputils::trim_right("fonctiont hyl", " yhlt");
    
    EXPECT_EQ("fonction", trimed);
}

TEST(string_utils, trim_both){
    std::string trimed;
    
    trimed = cpputils::trim_both(" yhtl fonctiont hyl", " yhlt");
    
    EXPECT_EQ("fonction", trimed);
}

TEST(string_utils, pad){
    std::string s;
    
    s = cpputils::pad("hello word !", 20);
    EXPECT_EQ("hello word !        ", s);
    s = cpputils::pad("hello word !", 20, '-', cpputils::string_align_center);
    EXPECT_EQ("----hello word !----", s);
    
}

TEST(string_utils, split){
    std::vector<std::string> list;
    list = cpputils::split("ma-super-fonction-qui-split ", '-');
    
    EXPECT_EQ(5, list.size());
    EXPECT_EQ("ma", list[0]);
    EXPECT_EQ("super", list[1]);
    EXPECT_EQ("fonction", list[2]);
    EXPECT_EQ("qui", list[3]);
    EXPECT_EQ("split ", list[4]);
}

TEST(string_utils, case){
    std::string s;
    
    s = cpputils::toupper("hello world !");
    EXPECT_EQ("HELLO WORLD !", s);
    s = cpputils::tolower("HELLO WORLD !");
    EXPECT_EQ("hello world !", s);
    

}


