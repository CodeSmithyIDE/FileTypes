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

#include "ExtensionRegistryInfo.h"

namespace Ishiko
{
namespace FileTypes
{

ExtensionRegistryInfo::~ExtensionRegistryInfo()
{
}

std::string ExtensionRegistryInfo::progID() const
{
    return m_key.getValueAsString("");
}

void ExtensionRegistryInfo::getOpenWithProgids(std::vector<std::string>& progIDs)
{
    try
    {
        WindowsRegistry::Key key = WindowsRegistry::Registry::openSubKey(m_key, "OpenWithProgids");
        key.enumValues(progIDs);
    }
    catch (const WindowsRegistry::KeyOperationException& e)
    {
        if (e.windowsErrorCode() != ERROR_FILE_NOT_FOUND)
        {
            throw;
        }
    }
}

void ExtensionRegistryInfo::addOpenWithProgids(const std::string& progID)
{
    WindowsRegistry::Key key = WindowsRegistry::Registry::createSubKey(m_key, "OpenWithProgids");
    key.setValue(progID, "");
}

bool ExtensionRegistryInfo::hasShellNew()
{
    bool result = false;
    try
    {
        WindowsRegistry::Key key = WindowsRegistry::Registry::openSubKey(m_key, "ShellNew");
        result = key.hasValue("NullFile");
    }
    catch (const WindowsRegistry::KeyOperationException& e)
    {
        if (e.windowsErrorCode() != ERROR_FILE_NOT_FOUND)
        {
            throw;
        }
    }
    return result;
}

void ExtensionRegistryInfo::addShellNew()
{
    WindowsRegistry::Key key = WindowsRegistry::Registry::createSubKey(m_key, "ShellNew");
    key.setValue("NullFile", "");
}

ExtensionRegistryInfo::ExtensionRegistryInfo(WindowsRegistry::Key& key)
    : m_key(key)
{
}

}
}
