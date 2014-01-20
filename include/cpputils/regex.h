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

#ifndef __CPPUTILS_REGEX_H__
#define	__CPPUTILS_REGEX_H__

#include <string>
#include <vector>

namespace cpputils{


struct regex_object_data;
/**
 * A regex Object
 */
class regex{


public:
    
    // typedefs
    typedef void (*match_callback)(std::string & match_);
    
    // Constructors
    regex();
    regex(const std::string & pattern_);
    regex(const regex & other_);
    virtual ~regex();
    
    // Operators
    regex & operator =(const std::string & pattern_);
    regex & operator =(const regex & other_);
    
    bool operator ==(const std::string & subject_) const;
    
    // functions
    bool match(const std::string & subject_) const;
    bool extract(const std::string & subject_, std::vector<std::string> & matched_) const;
    
    
    std::string replace(const std::string & subject_, const std::string & replacement_) const;
    
private:
    struct regex_object_data * _data;
};



} /* namespace cpputils */


#endif	/* __CPPUTILS_REGEX_H__ */

