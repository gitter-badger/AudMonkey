/*!********************************************************************
 AudMonkey: A Digital Audio Editor

 @file VersionId.h
 @brief Declare a class with version number manipulation.

 Anton Gerasimov
 **********************************************************************/
#pragma once

#include <wx/arrstr.h>

 /// A class, that supports base manipulation with version number.
 /**
     By default initialized by zero version number (Version = 0, Release = 0, Revision = 0),
     that not allow us to update.
 */
class VersionId final
{
public:
    /// Creates an zero version object.
    VersionId() = default;
    VersionId(int version, int release, int revision);

    /// Creates version string like "1.2.3" by parameters.
    static wxString MakeString(int version, int release, int revision);
    /// Parse and return version object from version string like "1.2.3".
    static VersionId ParseFromString(wxString& versionString);

    /// Make string with version by MakeString() from instance values.
    wxString GetString() const;

    bool operator== (const VersionId& other);
    bool operator!= (const VersionId& other);

    bool operator< (const VersionId& other);
    bool operator> (const VersionId& other);

private:
    int mVersion{ 0 };
    int mRelease{ 0 };
    int mRevision{ 0 };
};

/// Return version (VersionId) object with current AudMonkey build version.
static inline VersionId CurrentBuildVersion()
{
    return VersionId{ AUDMONKEY_VERSION, AUDMONKEY_RELEASE, AUDMONKEY_REVISION };
}
