/*
    Copyright (c) 2015-2017 Xavier Leclercq

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

#ifndef _ISHIKO_FILETYPES_EXTENSIONREGISTRYINFO_H_
#define _ISHIKO_FILETYPES_EXTENSIONREGISTRYINFO_H_

#include "Ishiko/WindowsRegistry.h"

namespace Ishiko
{
namespace FileTypes
{

/// This class provides functions to manipulate the registry information for a file extension.
/**
    Use the functions in FileTypeAssociations to create instances of this class.

    @see FileTypeAssociations
*/
class ExtensionRegistryInfo
{
    friend class FileTypeAssociations;

public:
    /// The destructor.
    /**
        Destruction of the object has no effect on the registry
        itself.
    */
    ~ExtensionRegistryInfo();

    /// Returns the ProgID for this extension.
    /**
        This returns the default value for the registry key. The
        application name of the ProgID in there will be used 
        to populate the type field in the file explorer for files
        with this extension.
        @return The ProgID for this extension.
        @see ProgIDRegistryInfo::applicationName
    */
    std::string progID() const;

    /// Gets the list of applications that can be used to open files with this extension.
    /**
        The applications in this list will be shown in the "Open with" menu when the user 
        right-clicks on a file with this extension.
        @param progIDs When the function returns this vector will be populated with the list
          of applications that can be used to open files with this extension.
    */
    void getOpenWithProgids(std::vector<std::string>& progIDs);
    /// Adds an application to the list of applications that can be used to open files with this extension.
    /**
        @param progID The ProgID of the application that will be added to the list.
    */
    void addOpenWithProgids(const std::string& progID);

    bool hasShellNew();
    /// Allow files with this extension to be created from the New context menu in the file explorer.
    /**
        This function adds a ShellNew subkey to the extension registry key.
    */
    void addShellNew();
    void removeShellNew();

private:
    /// Creates a new ExtensionRegistryInfo instance.
    /**
        The constructor is only supposed to be called by the 
        FileTypeAssociations class.
        @param key The registry subkey that this class will manipulate.
    */
    ExtensionRegistryInfo(WindowsRegistry::Key& key);

private:
    WindowsRegistry::Key m_key;
};

}
}

#include "linkoptions.h"

#endif
