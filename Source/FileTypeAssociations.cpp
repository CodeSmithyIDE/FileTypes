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

#include "FileTypeAssociations.h"
#include "Ishiko/WindowsRegistry.h"

namespace Ishiko
{
namespace FileTypes
{

ExtensionRegistryInfo FileTypeAssociations::createExtensionRegistryInfo(const std::string& extension,
                                                                        const std::string& progID)
{
    std::string subKeyPath = "Software\\Classes\\" + extension;
    WindowsRegistry::Key extKey = WindowsRegistry::Registry::createSubKey(HKEY_CURRENT_USER, subKeyPath);
    extKey.setValue("", progID);
    return ExtensionRegistryInfo(extKey);
}

void FileTypeAssociations::removeExtensionRegistryInfo(const std::string& extension)
{
    std::string subKeyPath = "Software\\Classes\\" + extension;
    WindowsRegistry::Registry::deleteSubKey(HKEY_CURRENT_USER, subKeyPath);
}

ExtensionRegistryInfo FileTypeAssociations::openExtensionRegistryInfo(const std::string& extension)
{
    std::string subKeyPath = "Software\\Classes\\" + extension;
    WindowsRegistry::Key extKey = WindowsRegistry::Registry::openSubKey(HKEY_CURRENT_USER, subKeyPath);
    return ExtensionRegistryInfo(extKey);
}

ProgIDRegistryInfo FileTypeAssociations::createProgIDRegistryInfo(const std::string& progID,
                                                                  const std::string& applicationName)
{
    std::string subKeyPath = "Software\\Classes\\" + progID;
    WindowsRegistry::Key progIDKey = WindowsRegistry::Registry::createSubKey(HKEY_CURRENT_USER, subKeyPath);

    progIDKey.setValue("", applicationName);

    return ProgIDRegistryInfo(progIDKey);
}

void FileTypeAssociations::removeProgIDRegistryInfo(const std::string& progID)
{
    std::string subKeyPath = "Software\\Classes\\" + progID;
    WindowsRegistry::Registry::deleteSubKey(HKEY_CURRENT_USER, subKeyPath);
}

ProgIDRegistryInfo FileTypeAssociations::openProgIDRegistryInfo(const std::string& progID)
{
    std::string subKeyPath = "Software\\Classes\\" + progID;
    WindowsRegistry::Key progIDKey = WindowsRegistry::Registry::openSubKey(HKEY_CURRENT_USER, subKeyPath);
    return ProgIDRegistryInfo(progIDKey);
}

}
}
