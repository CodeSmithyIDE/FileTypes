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

#ifndef _ISHIKO_FILETYPES_FILETYPEASSOCIATIONS_H_
#define _ISHIKO_FILETYPES_FILETYPEASSOCIATIONS_H_

#include "ExtensionRegistryInfo.h"
#include "ProgIDRegistryInfo.h"
#include <string>

namespace Ishiko
{
namespace FileTypes
{

/// This class provides functions to manipulate file type associations.
/**
    This class only supports Windows platforms.
*/
class FileTypeAssociations
{
public:
    /// Adds information about a new extension to the registry.
    /**
        @param extension The extension. This should include the '.' so you would for instance
          pass ".txt" to this argument.
        @param progID The ProgID of the application associated with this extension. This will become
          the default value of the registry key for this extension. See ExtensionRegistryInfo::progID
          for more details.
        @return An ExtensionRegistryInfo instance that can be used to further customize the extension
          information.
    */
    static ExtensionRegistryInfo createExtensionRegistryInfo(const std::string& extension,
        const std::string& progID);
    /// Removes an extension from the registry.
    /**
        @param extension The extension to remove. This should include the '.' so you would for instance
          pass ".txt" to this argument.
    */
    static void removeExtensionRegistryInfo(const std::string& extension);
    /// Gets an ExtensionRegistryInfo instance to get or update the information for an existing extension.
    /**
        @param extension The extension. This should include the '.' so you would for instance
          pass ".txt" to this argument.
        @return An ExtensionRegistryInfo instance that can be used to get or update the extension
          registry information.
    */
    static ExtensionRegistryInfo openExtensionRegistryInfo(const std::string& extension);
    
    static ProgIDRegistryInfo createProgIDRegistryInfo(const std::string& progID,
        const std::string& applicationName);
    static void removeProgIDRegistryInfo(const std::string& progID);
    static ProgIDRegistryInfo openProgIDRegistryInfo(const std::string& progID);
};

}
}

#include "linkoptions.h"

#endif
