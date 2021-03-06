#!/usr/bin/env bash

((${BASH_VERSION%%.*} >= 4)) || { echo >&2 "$0: Error: Please upgrade Bash."; exit 1; }

set -euxo pipefail

# Install AudMonkey
cmake --install build --config "${AUDMONKEY_BUILD_TYPE}" --verbose
