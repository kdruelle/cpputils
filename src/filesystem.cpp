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


#include <cpputils/filesystem.h>

#include <unistd.h>
#include <sys/stat.h>

#include <fstream>


/*******************************************************************************
 * TEST FUNCTIONS
 ******************************************************************************/

bool cpputils::file_exists(const std::string& filename_) throw(){
    return (access(filename_.c_str(), F_OK) == 0);
}

bool cpputils::file_isreadable(const std::string& filename_) throw(){
    return (access(filename_.c_str(), W_OK) == 0);
}

bool cpputils::file_is_writable(const std::string& filename_) throw(){
    return (access(filename_.c_str(), R_OK) == 0);
}

bool cpputils::file_is_executable(const std::string& filename_) throw(){
    return (access(filename_.c_str(), X_OK) == 0);
}

/*******************************************************************************
 * INFO FUNCTIONS
 ******************************************************************************/

size_t cpputils::file_getsize(const std::string& filename_) throw(){
    struct stat status;
    stat(filename_.c_str(), &status);
    return status.st_size;
}

/*******************************************************************************
 * ALTERATION FUNCTIONS
 ******************************************************************************/

bool cpputils::file_touch(const std::string& filename_) throw(){
    std::ofstream f(filename_.c_str());
    return f.is_open();
}

bool cpputils::file_delete(const std::string& filename_) throw(){
    if(!file_exists(filename_)) return false;
    return (remove(filename_.c_str()) == 0);
}