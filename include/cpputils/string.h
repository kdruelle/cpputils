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
 
 
#ifndef __CPPTOOLS_STRING_STRING_H
#define	__CPPTOOLS_STRING_STRING_H


#include <string>
#include <sstream>
#include <vector>


namespace cpputils{

typedef enum {
    string_align_right,
    string_align_left,
    string_align_center
} string_alignment_t;


/******************************************************************************
 * Convert functions
 *****************************************************************************/

/**
 * @brief Convert a string to T.
 *
 * This template function convert a string to a value defined by the template
 * parameter
 * 
 * @param str : The string that contains the value to convert.
 * @return : The value converted.
 * @warning The operator std::istream operator>>() must be implemented for the 
 * temlate type parameter.
 * @throw std::ios_base::failure.
 */
template<typename T>
T fromstring(const std::string & str_) throw (std::ios_base::failure) {
    T t;
    std::istringstream iss(str_);
    iss.exceptions(std::ios::failbit | std::ios::badbit);
    iss >> t;
    return t;
}

/**
 * @brief Convert template value to string.
 *
 * This template function convert a value to a string.
 * 
 * @param t_ : The value to serialize.
 * @return : The string representation of t_ value.
 * @warning The operator std::ostream operator<<() must be implemented for the 
 * temlate type parameter.
 * @throw std::ios_base::failure.
 */
template<typename T>
std::string tostring(T & t_) throw (std::ios_base::failure) {
    std::ostringstream oss;
    oss.exceptions(std::ios::failbit | std::ios::badbit);
    oss << t_;
    return oss.str();
}

/**
 * @brief Convert a binary buffer to hex string representation.
 * @param input_ : The binary buffer.
 * @param uppercase_ : Should the generated string be in upper case ?
 * @return : The hex string representation.
 */
std::string tohexstring(const std::string & input_, bool uppercase_ = false);

/**
 * @brief Convert a binary buffer to hex string representation.
 * @param input_ : The binary buffer.
 * @param length_ : The buffer size.
 * @param uppercase_ : Should the generated string be in upper case ?
 * @return 
 */
std::string tohexstring(const unsigned char * input_, size_t length_, bool uppercase_ = false);


/******************************************************************************
 * Trim functions
 *****************************************************************************/

/**
 * @brief Trim the left part of a string.
 *
 * @param src_ : The source string.
 * @param trim_ : Character set to trim.
 * @return : Trimed string.
 */
std::string trim_left(const std::string & src_, const std::string & trim_ = "\t\r\n");

/**
 * @brief Trim the right part of a string.
 *
 * @param src_ : The source string.
 * @param trim_ : Character set to trim.
 * @return : Trimed string.
 */
std::string trim_right(const std::string & src_, const std::string & trim_ = "\t\r\n");

/**
 * @brief Trim the right and the left parts of a string.
 *
 * @param src_ : The source string.
 * @param trim_ : Character set to trim.
 * @return : Trimed string.
 */
std::string trim_both(const std::string & src_, const std::string & trim_ = "\t\r\n");


/******************************************************************************
 * Padding functions
 *****************************************************************************/

/**
 * @brief Pad a string
 *
 * Resize the string src_ to width_ and align its content align_. 
 * If the lenth of src_ is greater than width_, the function does nothing.
 *
 * @param src_ : The source string.
 * @param width_ : The new size.
 * @param pad_ : The padding Character.
 * @param align_ : The alignment.
 */
std::string pad(const std::string & src_, size_t width_, char pad_ = ' ', string_alignment_t align_ = string_align_left);

/******************************************************************************
 * Split functions
 *****************************************************************************/

 /**
  * @brief Split a string.
  * 
  * @param src_ : The string to split.
  * @param delim_ : The delimiter.
  * @return : Vector of strings.
  */
std::vector<std::string> split(const std::string & src_, char delim_);


/******************************************************************************
 * Case functions
 *****************************************************************************/

/**
 * @brief Transform string src_ into lower-case letters.
 * 
 * @param src_ : The source string.
 * @return : The transformed string.
 */
std::string tolower(const std::string & src_);

/**
 * @brief Transform string src_ into upper-case letters.
 * 
 * @param src_ : The source string.
 * @return : The transformed string.
 */
std::string toupper(const std::string & src_);


} /* namespace cpputils */

#endif /* __CPPTOOLS_STRING_STRING_H */
 
 