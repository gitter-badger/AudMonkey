#!/bin/sh

lib="${0%/*}/lib/audmonkey"
share="${0%/*}/share/audmonkey"

export LD_LIBRARY_PATH="${lib}:${LD_LIBRARY_PATH}"
export AUDMONKEY_MODULES_PATH="${AUDMONKEY_MODULES_PATH}:${lib}/modules"
export AUDMONKEY_PATH="${AUDMONKEY_PATH}:${share}"

exec "${0%/*}/bin/audmonkey" "$@"
