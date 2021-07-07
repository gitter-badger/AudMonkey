#!/usr/bin/env bash

conan --version

if [ ! -d "audmonkey" ]
then
    git clone https://github.com/audmonkey/audmonkey
fi

mkdir -p build

cd build

cmake_options=(
    -G "Unix Makefiles"
    -DCMAKE_BUILD_TYPE=Release
    -Daudmonkey_lib_preference=system # Change the libs default to 'system'
    -Daudmonkey_obey_system_dependencies=On # And force it!
    -Daudmonkey_use_wxwidgets=local # wxWidgets 3.1 is not available
    -Daudmonkey_use_expat=system
    -Daudmonkey_use_lame=system
    -Daudmonkey_use_sndfile=system
    -Daudmonkey_use_soxr=system
    -Daudmonkey_use_portaudio=local # System portaudio is not yet usable
    -Daudmonkey_use_sqlite=local # We prefer using the latest version of SQLite
    -Daudmonkey_use_ffmpeg=loaded
    -Daudmonkey_use_id3tag=system # This library has bugs, that are fixed in *local* version
    -Daudmonkey_use_mad=system # This library has bugs, that are fixed in *local* version
    -Daudmonkey_use_nyquist=local # This library is not available
    -Daudmonkey_use_vamp=local # The dev package for this library is not available
    -Daudmonkey_use_ogg=system 
    -Daudmonkey_use_vorbis=system
    -Daudmonkey_use_flac=system
    -Daudmonkey_use_lv2=system
    -Daudmonkey_use_midi=system
    -Daudmonkey_use_portmixer=local # This library is not available
    -Daudmonkey_use_portsmf=system
    -Daudmonkey_use_sbsms=local # We prefer using the latest version of sbsms
    -Daudmonkey_use_soundtouch=system
    -Daudmonkey_use_twolame=system
    -Daudmonkey_has_networking=yes 
    -Daudmonkey_use_curl=system
)

cmake "${cmake_options[@]}" ../audmonkey

exit_status=$?

if [ $exit_status -ne 0 ]; then
    exit $exit_status
fi

make -j`nproc`

cd bin/Release
mkdir -p "Portable Settings"

ls -la .
