/**********************************************************************

  AudMonkey: A Digital Audio Editor

  AudMonkeyLogger.h

  Dominic Mazzoni

  This is the main source file for AudMonkey which handles
  initialization and termination by subclassing wxApp.

**********************************************************************/

#ifndef __AUDMONKEY_LOGGER__
#define __AUDMONKEY_LOGGER__





#include "MemoryX.h"
#include "Prefs.h"
#include <wx/log.h> // to inherit
#include <wx/event.h> // to inherit wxEvtHandler

class wxFrame;
class wxTextCtrl;

class AUDMONKEY_DLL_API AudMonkeyLogger final : public wxEvtHandler,
                             public wxLog,
                             public PrefsListener
{
 public:

   ~AudMonkeyLogger() override;
 
   // Get the singleton instance or null
   static AudMonkeyLogger *Get();

   void Show(bool show = true);

   bool SaveLog(const wxString &fileName) const;
   bool ClearLog();

   wxString GetLog(int count = 0);

 protected:
   void Flush()  override;
   void DoLogText(const wxString & msg) override;

 private:
   AudMonkeyLogger();

   void OnCloseWindow(wxCloseEvent & e);
   void OnClose(wxCommandEvent & e);
   void OnClear(wxCommandEvent & e);
   void OnSave(wxCommandEvent & e);

   // PrefsListener implementation
   void UpdatePrefs() override;

   Destroy_ptr<wxFrame> mFrame;
   wxTextCtrl *mText;
   wxString mBuffer;
   bool mUpdated;
};

#endif
