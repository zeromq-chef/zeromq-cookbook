/* ZeroMQ Cookbook
Copyright (C) 2021 The ZeroMQ Cookbook Authors.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
==============================================================================*/

#ifndef CMAKE_TEMPLATE_SERVER_HH_
#define CMAKE_TEMPLATE_SERVER_HH_

#include <string>
#include <map>
#include <optional>

template <typename T>
class Server
{
 public:
    explicit Server(std::string name = std::string("My Hello Server"));
    virtual ~Server() = default;

    Server(const Server& src) = default;
    Server<T>& operator = (const Server& rhs) = default;

    Server(Server&& src) = default;
    Server<T> & operator = (Server&& rhs) = default;

    void setHostName(std::string name) const { hostName = name; }
    std::string getHostName() const { return hostName; }

 private:
    std::string hostName;
    std::map<std::string, std::optional<T>> store;
};

#include "Server.cc"

#endif // CMAKE_TEMPLATE_SERVER_HH_
