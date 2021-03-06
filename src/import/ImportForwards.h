//
//  ImportForwards.h
//  AudMonkey
//
//  Created by Paul Licameli on 8/10/16.
//
//

#ifndef __AUDMONKEY_IMPORT_FORWARDS__
#define __AUDMONKEY_IMPORT_FORWARDS__

#include <vector>
#include <memory>

class ImportPlugin;
class UnusableImportPlugin;

using ImportPluginList =
   std::vector< ImportPlugin * >;
using UnusableImportPluginList =
   std::vector< std::unique_ptr<UnusableImportPlugin> >;

#endif
