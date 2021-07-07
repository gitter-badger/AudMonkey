/**********************************************************************

  AudMonkey: A Digital Audio Editor

  SplashDialog.h

  James Crook

**********************************************************************/

#ifndef __AUDMONKEY_SPLASH_DLG__
#define __AUDMONKEY_SPLASH_DLG__

#include "widgets/wxPanelWrapper.h" // to inherit

class wxBitmap;
class ShuttleGui;
class AudMonkeyProject;
class HtmlWindow;

class SplashDialog final : public wxDialogWrapper {
   DECLARE_DYNAMIC_CLASS(SplashDialog)
public:

   static void DoHelpWelcome( AudMonkeyProject &project );

   SplashDialog(wxWindow * parent);
   virtual ~ SplashDialog();
   void OnOK(wxCommandEvent & event);
   static void Show2( wxWindow * pParent );

   DECLARE_EVENT_TABLE()

private:

   void OnChar(wxMouseEvent &event);
   void Populate( ShuttleGui & S );
   void OnDontShow( wxCommandEvent & Evt );

   HtmlWindow * mpHtml;
   std::unique_ptr<wxBitmap> m_pLogo; //vvv
   static SplashDialog * pSelf;
};

#endif
