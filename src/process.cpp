
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
 
 
#include <cpputils/process.h>

#include <climits>
#include <cstring>
#include <cstdlib>

#ifdef __gnu_linux__

#include <unistd.h>

const char * cpputils::process_self_path(){
    static char path [PATH_MAX] = {0};
    memset(path, 0, sizeof (path));
    if (readlink("/proc/self/exe", path, PATH_MAX) == -1) {
        memset(path, 0, sizeof (path));
        return 0;
    }
    return path;
}

#endif

#ifdef __APPLE__

#include <mach-o/dyld.h>
#include <cstdlib>

const char * cpputils::process_self_path() {
    
    static char path [PATH_MAX] = {0};
    char * symPath = 0;
    uint32_t size = 1024;
    
    symPath = new char[size];
    
    while(_NSGetExecutablePath(symPath, &size) != 0){
        size += 2;
        delete symPath;
        symPath = new char[size];
    }
    
    realpath(symPath, path);
    delete symPath;
    return path;
    
}

#endif

const char * cpputils::process_name(){
    static const char * name;
    name = strrchr(cpputils::process_self_path(), '/') + 1;
    return name;
}

 
 