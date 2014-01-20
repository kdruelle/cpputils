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
#include <cpputils/string.h>

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


bool cpputils::regex::extract(const std::string& subject_, std::vector<std::string>& matched_) const{
    regex_t reg;
    bool ret = false;
    std::string part;
    regmatch_t match[2] = {0};
    std::string s = subject_;
    
    regcomp(&reg, _data->pattern.c_str(), REG_EXTENDED);
    
    while (regexec(&reg, s.c_str(), 2, match, 0) == 0) {
        if (match[1].rm_so != -1) {
            ret = true;
            part.assign(s.c_str(), match[1].rm_so, match[1].rm_eo - match[1].rm_so);
            s.erase(match[1].rm_so, match[1].rm_eo - match[1].rm_so);
            matched_.push_back(part);
        }

    }

    regfree(&reg);
    return ret;
}

std::string cpputils::regex::replace(const std::string& subject_, const std::string& replacement_) const{
    regex_t reg;
    
    // compute nbmatch
    unsigned int nbmatch = 1;
    for (std::string::const_iterator it = _data->pattern.begin(); it != _data->pattern.end(); ++it) {
        if (*it == '(') nbmatch++;
    }

    regmatch_t * match = new regmatch_t[nbmatch + 1];
    regcomp(&reg, _data->pattern.c_str(), REG_EXTENDED);

    std::string newstring;
    std::string subject = subject_;
    std::string computedreplacement;
    size_t joker_pos;
    while (regexec(&reg, subject.c_str(), nbmatch, match, 0) == 0) {
        
        // compute the remplacement string
        computedreplacement = replacement_;
        for (unsigned int i = 0; i < nbmatch; i++) {
            std::string joker = "$";
            joker += cpputils::tostring(i);
            while (match[i].rm_so != -1 && (joker_pos = computedreplacement.find(joker)) != std::string::npos) {
                std::string jreplace;
                jreplace.assign(subject.c_str(), match[i].rm_so, match[i].rm_eo - match[i].rm_so);
                computedreplacement.replace(joker_pos, 2, jreplace);
            }
        }
        
        // Add firsts no matching characters + the computed replacement string
        // To the new string.
        newstring += subject.substr(0, match[0].rm_so) + computedreplacement;
        subject.erase(0, match[0].rm_eo); // Remove the begin for the next iterration.
    }
    
    // characters that doesnt match
    newstring += subject;
    
    regfree(&reg);
    return newstring;
}


