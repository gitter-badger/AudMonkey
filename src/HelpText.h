/**********************************************************************

  AudMonkey: A Digital Audio Editor

  HelpText.h

  James Crook

**********************************************************************/

#ifndef __AUDMONKEY_HELP_TEXT__
#define __AUDMONKEY_HELP_TEXT__

class TranslatableString;
class wxString;
#include "Identifier.h"

struct URLStringTag;
//! Distinct type for URLs
using URLString = TaggedIdentifier< URLStringTag >;

AUDMONKEY_DLL_API  wxString HelpText( const wxString & Key );
AUDMONKEY_DLL_API TranslatableString TitleText( const wxString & Key );

extern AUDMONKEY_DLL_API const wxString VerCheckArgs();
extern AUDMONKEY_DLL_API const URLString VerCheckUrl();
extern AUDMONKEY_DLL_API const wxString VerCheckHtml();
extern AUDMONKEY_DLL_API wxString FormatHtmlText( const wxString & Text );

#endif
