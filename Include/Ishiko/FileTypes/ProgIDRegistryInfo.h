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

#ifndef _ISHIKO_FILETYPES_PROGIDREGISTRYINFO_H_
#define _ISHIKO_FILETYPES_PROGIDREGISTRYINFO_H_

#include "Ishiko/WindowsRegistry.h"

namespace Ishiko
{
namespace FileTypes
{

/// This class provides functions to manipulate the ProgID registry subkey.
/**
    The Windows Shell uses a programmatic identifier (ProgID) registry subkey 
    to associate a file type with an application, and to control the behavior
    of the association. See the MSDN documentation for details:
    https://msdn.microsoft.com/en-us/library/windows/desktop/cc144152(v=vs.85).aspx

    Use the functions in FileTypeAssociations to create instances of this class.

    @see FileTypeAssociations
*/
class ProgIDRegistryInfo
{
    friend class FileTypeAssociations;

public:
    /// The destructor.
    /**
        Destruction of the object has no effect on the registry
        itself.
    */
    ~ProgIDRegistryInfo();

    /// Returns the name of the application.
    /**
        This returns the default value for the registry key. The value 
        in there will also be used as the type shown in the file explorer
        for any extension associated with this ProgID.
        @return The name of the application.
    */
    std::string applicationName() const;
    /// Sets the command used to launch the application.
    /**
        @param command The command line to use to launch the application.
    */
    void setOpenCommand(const std::string& command);

private:
    /// Creates a new ProgIDRegistryInfo instance.
    /**
        The constructor is only supposed to be called by the 
        FileTypeAssociations class.
        @param key The registry subkey that this class will manipulate.
    */
    ProgIDRegistryInfo(WindowsRegistry::Key& key);

private:
    WindowsRegistry::Key m_key;
};

}
}

#include "linkoptions.h"

#endif
