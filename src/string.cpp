/*******************************************************************************
 ** 
 ** (C) 2011 Kevin Druelle 
 **
 ** this software is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU Lesser General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 ** 
 ** This software is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 ** 
 ** You should have received a copy of the GNU General Public License
 ** along with this software.  If not, see <http://www.gnu.org/licenses/>.
 ** 
 ******************************************************************************/



#include <cpputils/string.h>

#include <algorithm>


/******************************************************************************
 * Convert functions
 *****************************************************************************/


std::string cpputils::tohexstring(const std::string & input_, bool uppercase_){
    static const char * const lower = "0123456789abcdef";
    static const char * const upper = "0123456789ABCDEF";
    const char * array = 0;
    std::string output;
    size_t length = input_.length();
    
    if(uppercase_)  array = upper;
    else            array = lower;
    
    output.reserve(2 * length);
    for (size_t i = 0; i < length; ++i) {
        const unsigned char c = input_[i];
        output.push_back(array[c >> 4]); // index for the first quartet
        output.push_back(array[c & 15]); // index for the second quartet
    }
    return output;
}


std::string cpputils::tohexstring(const unsigned char * input_, size_t length_, bool uppercase_){
    std::string binary;
    binary.assign(reinterpret_cast<const char *>(input_), length_);
    return cpputils::tohexstring(binary, uppercase_);
}


/******************************************************************************
 * Trim functions
 *****************************************************************************/

// predicat for trimer functions
struct trimer_predicate_st {
    std::string pattern;
    bool operator()(char c) {
        return pattern.find(c) != std::string::npos;
    }
};

std::string cpputils::trim_left(const std::string & src_, const std::string & trim_) {
    std::string trimed = src_;
    struct trimer_predicate_st trimer;
    trimer.pattern = trim_;
    while (!trimed.empty() && trimer(trimed.at(0))) {
        trimed.erase(0, 1);
    }
    return trimed;
}

std::string cpputils::trim_right(const std::string & src_, const std::string & trim_) {
    std::string trimed = src_;
    struct trimer_predicate_st trimer;
    trimer.pattern = trim_;
    while (!trimed.empty() && trimer(trimed.at(trimed.length() - 1))) {
        trimed.erase(trimed.end() - 1);
    }
    return trimed;
}

std::string cpputils::trim_both(const std::string & src_, const std::string & trim_) {
    return cpputils::trim_left(cpputils::trim_right(src_, trim_), trim_);
}


/******************************************************************************
 * Padding functions
 *****************************************************************************/

std::string cpputils::pad(const std::string & src_, size_t width_, char pad_, string_alignment_t align_) {
    std::string padded = src_;
    size_t char_to_pad = 0;

    if (width_ <= src_.length()) return padded;
    char_to_pad = width_ - src_.length();

    switch (align_) {
        case cpputils::string_align_left:
            padded.insert(padded.end(), char_to_pad, pad_);
            break;
        case cpputils::string_align_right:
            padded.insert(padded.begin(), char_to_pad, pad_);
            break;
        case cpputils::string_align_center:
            padded.insert(padded.begin(), (char_to_pad % 2) == 0 ? char_to_pad / 2 : (char_to_pad / 2) + 1, pad_);
            padded.insert(padded.end(), (char_to_pad % 2) == 0 ? char_to_pad / 2 : (char_to_pad / 2) + 1, pad_);
            break;
    }
    return padded;
}


/******************************************************************************
 * Split functions
 *****************************************************************************/
 
std::vector<std::string> cpputils::split(const std::string & src_, char delim_){
    std::vector<std::string> list;
    std::string tmp = src_;
    size_t pos;
    while((pos = tmp.find(delim_)) != std::string::npos){
        list.push_back(tmp.substr(0, pos));
        tmp = tmp.substr(pos + 1);
    }
    list.push_back(tmp);
    return list;
}
 
/******************************************************************************
 * Case functions
 *****************************************************************************/

std::string cpputils::tolower(const std::string & src_){
    std::string::const_iterator it = src_.begin();
    std::string s;
    while (it != src_.end()) {
        s.append(1, std::use_facet
        <std::ctype<std::string::value_type> >(std::locale()).tolower(*it));
        ++it;
    }
    return s;
}


std::string cpputils::toupper(const std::string & src_){
    std::string::const_iterator it = src_.begin();
    std::string s;
    while (it != src_.end()) {
        s.append(1, std::use_facet
        <std::ctype<std::string::value_type> >(std::locale()).toupper(*it));
        ++it;
    }
    return s;
}




