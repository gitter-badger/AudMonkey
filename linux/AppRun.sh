#!/usr/bin/env bash
# The AppImage runtime sets some special environment variables. We provide
# default values here in case the user tries to run this script outside an
# AppImage where the variables would otherwise be undefined.
if [[ ! "${APPIMAGE}" || ! "${APPDIR}" ]]; then
    export APPIMAGE="$(readlink -f "${0}")"
    export APPDIR="$(dirname "${APPIMAGE}")"
fi

export LD_LIBRARY_PATH="${APPDIR}/lib:${LD_LIBRARY_PATH}"

export AUDACITY_PATH="${AUDACITY_PATH}:${APPDIR}/share/audmonkey"
export AUDACITY_MODULES_PATH="${AUDACITY_MODULES_PATH}:${APPDIR}/lib/modules"

function help()
{
    # Normal audmonkey help
    "${APPDIR}/bin/audmonkey" --help
    # Special options handled by this script
    cat >&2 <<EOF
  --readme              display README
  --license             display LICENSE
  --man[ual|page]       display audmonkey(1) manual page
  --check-dependencies  check library dependency fulfillment (developer tool)

EOF
    # Blank line then special options handled by the AppImage runtime
    "${APPIMAGE}" --appimage-help
}

# Intercept command line arguments
case "$1" in
-h|--help )
    help
    ;;
--readme )
    exec less "${APPDIR}/share/doc/audmonkey/README.txt"
    ;;
--license )
    exec less "${APPDIR}/share/doc/audmonkey/LICENSE.txt"
    ;;
--man|--manual|--manpage )
    exec man "${APPDIR}/share/man/man1/audmonkey.1"
    ;;
--check-depends|--check-dependencies )
    exec bash "${APPDIR}/bin/check_dependencies"
    ;;
* )
    # Other arguments go to AudMonkey
    exec "${APPDIR}/bin/audmonkey" "$@"
    ;;
esac
