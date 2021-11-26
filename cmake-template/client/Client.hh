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

#ifndef CMAKE_TEMPLATE_CLIENT_HH_
#define CMAKE_TEMPLATE_CLIENT_HH_

#include <string>
#include <map>
#include <optional>

template <typename T>
class Client
{
 public:
    explicit Client(std::string name);
    virtual ~Client() = default;

    Client(const Client& src) = default;
    Client<T>& operator = (const Client& rhs) = default;

    Client(Client&& src) = default;
    Client<T> & operator = (Client&& rhs) = default;

    void setClientName(std::string name) const { clientName = name; }
    std::string getClientName() const { return clientName; }

 private:
    std::string clientName;
    std::map<std::string, std::optional<T>> store;
};

#include "Client.cc"

#endif  // CMAKE_TEMPLATE_CLIENT_HH_
