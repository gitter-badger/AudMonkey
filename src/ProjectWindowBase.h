/**********************************************************************

AudMonkey: A Digital Audio Editor

ProjectWindowBase.h

Paul Licameli split from ProjectWindow.h

**********************************************************************/

#ifndef __AUDMONKEY_PROJECT_WINDOW_BASE__
#define __AUDMONKEY_PROJECT_WINDOW_BASE__

#include <wx/frame.h> // to inherit

class AudMonkeyProject;

///\brief A top-level window associated with a project
class ProjectWindowBase /* not final */ : public wxFrame
{
public:
   explicit ProjectWindowBase(
      wxWindow * parent, wxWindowID id,
      const wxPoint & pos, const wxSize &size,
      AudMonkeyProject &project );

   ~ProjectWindowBase() override;

   AudMonkeyProject &GetProject() { return mProject; }
   const AudMonkeyProject &GetProject() const { return mProject; }

protected:
   AudMonkeyProject &mProject;
};

AUDMONKEY_DLL_API AudMonkeyProject *FindProjectFromWindow( wxWindow *pWindow );
const AudMonkeyProject *FindProjectFromWindow( const wxWindow *pWindow );

#endif

