/**********************************************************************

  AudMonkey: A Digital Audio Editor

  ActiveProjects.h

**********************************************************************/

#ifndef __AUDMONKEY_ACTIVE_PROJECTS__
#define __AUDMONKEY_ACTIVE_PROJECTS__


#include "Identifier.h"

namespace ActiveProjects
{
   FilePaths GetAll();
   void Add(const FilePath &path);
   void Remove(const FilePath &path);
   wxString Find(const FilePath &path);
};

#endif
