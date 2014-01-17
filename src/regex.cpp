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

#include <cpputils/regex.h>
#include <regex.h>

struct cpputils::regex_object_data{
    std::string pattern;
};


/*******************************************************************************
 * Constructors
 ******************************************************************************/

cpputils::regex::regex(){
    _data = new cpputils::regex_object_data();
}

cpputils::regex::regex(const std::string& pattern_){
    _data = new cpputils::regex_object_data();
    _data->pattern = pattern_;
}

cpputils::regex::regex(const regex& other_){
    _data = new cpputils::regex_object_data();
    _data->pattern = other_._data->pattern;
}

cpputils::regex::~regex(){
    delete _data;
}

/*******************************************************************************
 * Operators
 ******************************************************************************/

cpputils::regex & cpputils::regex::operator =(const std::string& pattern_){
    _data->pattern = pattern_;
    return *this;
}

cpputils::regex & cpputils::regex::operator =(const regex& other_){
    _data->pattern = other_._data->pattern;
    return *this;
}

bool cpputils::regex::operator ==(const std::string& subject_) const{
    return match(subject_);
}

/*******************************************************************************
 * Functions
 ******************************************************************************/

bool cpputils::regex::match(const std::string& subject_) const{
    regex_t _reg;
    bool ret;
    if(regcomp(&_reg, _data->pattern.c_str(), REG_EXTENDED) != 0) return false;
    ret = (regexec(&_reg, subject_.c_str(), 0, 0, 0) == 0) ? true : false;
    regfree(&_reg);
    return ret;
}



