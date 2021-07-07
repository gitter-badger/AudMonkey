set(CPACK_PACKAGE_VERSION_MAJOR "${AUDMONKEY_VERSION}") # X
set(CPACK_PACKAGE_VERSION_MINOR "${AUDMONKEY_RELEASE}") # Y
set(CPACK_PACKAGE_VERSION_PATCH "${AUDMONKEY_REVISION}") # Z
set(CPACK_PACKAGE_VENDOR "AudMonkey")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://audacityteam.org")

# X.Y.Z-alpha-20210615
set(CPACK_PACKAGE_VERSION "${AUDMONKEY_VERSION}.${AUDMONKEY_RELEASE}.${AUDMONKEY_REVISION}${AUDMONKEY_SUFFIX}")

if(NOT AUDMONKEY_BUILD_LEVEL EQUAL 2)
   # X.Y.Z-alpha-20210615+a1b2c3d
   set(CPACK_PACKAGE_VERSION "${CPACK_PACKAGE_VERSION}+${GIT_COMMIT_SHORT}")
endif()

# Custom variables use CPACK_AUDMONKEY_ prefix. CPACK_ to expose to CPack,
# AUDMONKEY_ to show it is custom and avoid conflicts with other projects.
set(CPACK_AUDMONKEY_SOURCE_DIR "${PROJECT_SOURCE_DIR}")

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(os "win")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
   set(os "macos")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
   set(os "linux")
endif()

# audacity-linux-X.Y.Z-alpha-20210615
set(CPACK_PACKAGE_FILE_NAME "audacity-${os}-${CPACK_PACKAGE_VERSION}")
set(zsync_name "audacity-${os}-*") # '*' is wildcard (here it means any version)

if(DEFINED AUDMONKEY_ARCH_LABEL)
   # audacity-linux-X.Y.Z-alpha-20210615-x86_64
   set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_FILE_NAME}-${AUDMONKEY_ARCH_LABEL}")
   set(zsync_name "${zsync_name}-${AUDMONKEY_ARCH_LABEL}")
   set(CPACK_AUDMONKEY_ARCH_LABEL "${AUDMONKEY_ARCH_LABEL}")
endif()
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/package")

set(CPACK_GENERATOR "ZIP")

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
   set(CPACK_GENERATOR "External")
   set(CPACK_EXTERNAL_ENABLE_STAGING TRUE)
   set(CPACK_EXTERNAL_PACKAGE_SCRIPT "${PROJECT_SOURCE_DIR}/linux/package_appimage.cmake")
   if(AUDMONKEY_BUILD_LEVEL EQUAL 2)
      # Enable updates. See https://github.com/AppImage/AppImageSpec/blob/master/draft.md#update-information
      set(CPACK_AUDMONKEY_APPIMAGE_UPDATE_INFO "gh-releases-zsync|audacity|audacity|latest|${zsync_name}.AppImage.zsync")
   endif()
elseif( CMAKE_SYSTEM_NAME STREQUAL "Darwin" )
   set( CPACK_GENERATOR DragNDrop )

   set( CPACK_DMG_BACKGROUND_IMAGE "${CMAKE_SOURCE_DIR}/mac/Resources/AudMonkey-DMG-background.png")
   set( CPACK_DMG_DS_STORE_SETUP_SCRIPT "${CMAKE_SOURCE_DIR}/scripts/build/macOS/DMGSetup.scpt")

   if( ${_OPT}perform_codesign )
      set( CPACK_APPLE_CODESIGN_IDENTITY ${APPLE_CODESIGN_IDENTITY} )
      set( CPACK_APPLE_NOTARIZATION_USER_NAME ${APPLE_NOTARIZATION_USER_NAME} )
      set( CPACK_APPLE_NOTARIZATION_PASSWORD ${APPLE_NOTARIZATION_PASSWORD} )
      set( CPACK_APPLE_SIGN_SCRIPTS "${CMAKE_SOURCE_DIR}/scripts/build/macOS" )
      set( CPACK_PERFORM_NOTARIZATION ${${_OPT}perform_notarization} )

      # CPACK_POST_BUILD_SCRIPTS was added in 3.19, but we only need it on macOS
      SET( CPACK_POST_BUILD_SCRIPTS "${CMAKE_SOURCE_DIR}/scripts/build/macOS/DMGSign.cmake" )
   endif()
endif()

include(CPack) # do this last
