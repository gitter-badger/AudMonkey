/*!
 @file UserException.h
 @brief An AudMonkeyException with no visible message

 Created by Paul Licameli on 11/27/16.

*/

#ifndef __AUDMONKEY_USER_EXCEPTION__
#define __AUDMONKEY_USER_EXCEPTION__

#include "AudMonkeyException.h"

 //! Can be thrown when user cancels operations, as with a progress dialog.  Delayed handler does nothing
/*! This class does not inherit from MessageBoxException. */
class AUDMONKEY_DLL_API UserException final : public AudMonkeyException
{
public:
   UserException() {}

   ~UserException() override;

   void DelayedHandlerAction() override;
};

#endif
