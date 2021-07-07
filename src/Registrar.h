/**********************************************************************

  AudMonkey: A Digital Audio Editor

  Registrar.h

  James Crook

*******************************************************************//**

\class Registrar
\brief Base class for registration callback.
AudMonkey will call providers RegisterNameOfThing() functions with
an &Registrar as the argument.  RegisterNameOfThing() is then 
responsible for calling the appropriate callback functions.

**********************************************************************/


#ifndef __AUDMONKEY_REGISTRAR__
#define __AUDMONKEY_REGISTRAR__



#include <memory>

class AudMonkeyCommand;
class LoadableModule;
class ComponentInterface;
class Effect;

class AUDMONKEY_DLL_API Registrar 
{
public:
   Registrar(){
      bWantsModules = false;
      bWantsCommands= false;
      bWantsCommandTypes= false;
      bWantsEffects= false;
   }
   bool bWantsModules;
   bool bWantsCommands;
   bool bWantsCommandTypes;
   bool bWantsEffects;
   virtual void AddCommandType(std::unique_ptr<ComponentInterface> && WXUNUSED(comDef) ){;};
   virtual void AddCommand(std::unique_ptr<AudMonkeyCommand> && WXUNUSED(command) ){;};
   virtual void AddModule(std::unique_ptr<LoadableModule> && WXUNUSED(module) ){;};
   virtual void AddEffect(std::unique_ptr<Effect> && WXUNUSED(effect) ){;};
};

#endif
