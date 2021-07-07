/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 TempDirectory.h
 
 Paul Licameli split from FileNames.h
 
 **********************************************************************/

#ifndef __AUDMONKEY_TEMP_DIRECTORY__
#define __AUDMONKEY_TEMP_DIRECTORY__


#include "Identifier.h"
class TranslatableString;
class wxWindow;

namespace TempDirectory
{
   AUDMONKEY_DLL_API wxString TempDir();
   AUDMONKEY_DLL_API void ResetTempDir();

   AUDMONKEY_DLL_API const FilePath &DefaultTempDir();
   AUDMONKEY_DLL_API void SetDefaultTempDir( const FilePath &tempDir );
   AUDMONKEY_DLL_API bool IsTempDirectoryNameOK( const FilePath & Name );

   // Create a filename for an unsaved/temporary project file
   AUDMONKEY_DLL_API wxString UnsavedProjectFileName();

   AUDMONKEY_DLL_API bool FATFilesystemDenied(const FilePath &path,
                            const TranslatableString &msg,
                            wxWindow *window = nullptr);
};

#endif
