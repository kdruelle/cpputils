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
 
 
#ifndef __CPPUTILS_FILESYSTEM_H__
#define	__CPPUTILS_FILESYSTEM_H__


#include <string>

namespace cpputils{

/*******************************************************************************
 * TEST FUNCTIONS
 ******************************************************************************/

/**
 * Test if a file exists.
 * @param filename_ : File path.
 * @return true or false.
 */
bool file_exists(const std::string & filename_) throw();

/**
 * Check if a file is readable.
 * @param filename_ : File path
 * @return true or false;
 */
bool file_isreadable(const std::string & filename_) throw();

/**
 * Check if a file is writable.
 * @param filename_ : File path.
 * @return true or false.
 */
bool file_is_writable(const std::string & filename_) throw();

/**
 * Check if a file is executable.
 * @param filename_ : File path.
 * @return true or false.
 */
bool file_is_executable(const std::string & filename_) throw();


/*******************************************************************************
 * INFO FUNCTIONS
 ******************************************************************************/

size_t file_getsize(const std::string & filename_) throw();


/*******************************************************************************
 * ALTERATION FUNCTIONS
 ******************************************************************************/

/**
 * Create an empty file.
 * @param filename_ : File path
 * @return true or false.
 */
bool file_touch(const std::string & filename_) throw();

/**
 * Delete a file.
 * @param filename_
 * @return 
 */
bool file_delete(const std::string & filename_) throw();


} /* namespace cpputils */


#endif	/* __CPPUTILS_FILESYSTEM_H__ */

