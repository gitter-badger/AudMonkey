/**********************************************************************

  AudMonkey: A Digital Audio Editor

  ProjectFileIORegistry.h

  Paul Licameli

**********************************************************************/

#ifndef __AUDMONKEY_PROJECT_FILE_IO_REGISTRY__
#define __AUDMONKEY_PROJECT_FILE_IO_REGISTRY__

#include <functional>

class AudMonkeyProject;
class XMLTagHandler;
class wxString;

namespace ProjectFileIORegistry {

// Type of functions returning objects that interpret a part of the saved XML
using TagHandlerFactory =
   std::function< XMLTagHandler *( AudMonkeyProject & ) >;

// Typically statically constructed
struct AUDMONKEY_DLL_API Entry{
   Entry( const wxString &tag, const TagHandlerFactory &factory );
};

TagHandlerFactory Lookup( const wxString &tag );

}

#endif
