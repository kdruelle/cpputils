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
 
 
#ifndef __CPPTOOLS_PROCESS_H
#define	__CPPTOOLS_PROCESS_H




namespace cpputils{

/**
 * @brief Return current executable path.
 * 
 * Return The current executable full path in a null terminated string.
 * @return The full current executable path.
 */
const char * process_self_path();

/**
 * @brief Return the current process name.
 * @return A null terminated string to the current process name.
 */
const char * process_name();


} /* namespace cpputils */

#endif /* __CPPTOOLS_PROCESS_H */
 
 