/*
    Copyright (c) 2015-2016 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OROTHER DEALINGS
    IN THE SOFTWARE.
*/

#ifndef _ISHIKO_FILETYPES_PROGIDREGISTRYINFO_H_
#define _ISHIKO_FILETYPES_PROGIDREGISTRYINFO_H_

#include "Ishiko/WindowsRegistry.h"

namespace Ishiko
{
namespace FileTypes
{

class ProgIDRegistryInfo
{
    friend class FileTypeAssociations;

public:
    typedef std::shared_ptr<ProgIDRegistryInfo> shared_ptr;

public:
    ~ProgIDRegistryInfo();

    std::string applicationName() const;
    void setOpenCommand(const std::string& command);

private:
    ProgIDRegistryInfo(WindowsRegistry::Key& key);

private:
    WindowsRegistry::Key m_key;
};

}
}

#include "linkoptions.h"

#endif
