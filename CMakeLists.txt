project(vartypes)
cmake_minimum_required(VERSION 2.4)
set(USE_Qt5 1)

if(USE_Qt5)
    cmake_minimum_required(VERSION 3.4) # for WINDOWS_EXPORT_ALL_SYMBOLS
    if(POLICY CMP0020)
        cmake_policy(SET CMP0020 NEW) # remove if CMake >= 2.8.11 required
    endif()
    if(POLICY CMP0043) # compatibility with CMake 3.0.1
        cmake_policy(SET CMP0043 OLD)
    endif()
    if(POLICY CMP0071) # compatibility with CMake 3.10.0
        cmake_policy(SET CMP0071 OLD)
    endif()
endif()

if(USE_Qt5)
    add_definitions(-D QT5)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    find_package(Qt5Core REQUIRED)
    find_package(Qt5Widgets REQUIRED)
    find_package(Qt5OpenGL REQUIRED)
    set(QT_LIBRARIES "")
    macro(qt4_wrap_cpp VARNAME)
        set(${VARNAME} "")
    endmacro()
    # wrap functions
    macro(qt4_wrap_ui)
        qt5_wrap_ui(${ARGN})
    endmacro()
    macro(qt4_add_resources)
        qt5_add_resources(${ARGN})
    endmacro()
else()
    find_package ( Qt4 REQUIRED )
    include ( ${QT_USE_FILE} )
endif()


include_directories(${src_dir}/vartypes)
include_directories(${src_dir}/vartypes/primitives)
include_directories(${src_dir}/vartypes/enhanced)
include_directories(${src_dir}/vartypes/gui)
include_directories(${src_dir}/vartypes/xml)

set(src_dir .)

set (SRCS
  ${src_dir}/vartypes/VarBase64.cpp
  ${src_dir}/vartypes/VarNotifier.cpp
  ${src_dir}/vartypes/VarTypes.cpp
  ${src_dir}/vartypes/VarXML.cpp
  ${src_dir}/vartypes/VarTypesInstance.cpp
  ${src_dir}/vartypes/VarTypesFactory.cpp
  ${src_dir}/vartypes/xml/xmlParser.cpp

  ${src_dir}/vartypes/primitives/VarStringVal.cpp
  ${src_dir}/vartypes/primitives/VarBoolVal.cpp
  ${src_dir}/vartypes/primitives/VarVal.cpp
  ${src_dir}/vartypes/primitives/VarIntVal.cpp
  ${src_dir}/vartypes/primitives/VarDoubleVal.cpp
  
  ${src_dir}/vartypes/primitives/VarType.cpp
  ${src_dir}/vartypes/primitives/VarBlob.cpp
  ${src_dir}/vartypes/primitives/VarBool.cpp
  ${src_dir}/vartypes/primitives/VarDouble.cpp
  ${src_dir}/vartypes/primitives/VarExternal.cpp
  ${src_dir}/vartypes/primitives/VarInt.cpp
  ${src_dir}/vartypes/primitives/VarList.cpp
  ${src_dir}/vartypes/primitives/VarQWidget.cpp
  ${src_dir}/vartypes/primitives/VarSelection.cpp
  ${src_dir}/vartypes/primitives/VarString.cpp
  ${src_dir}/vartypes/primitives/VarStringEnum.cpp
  ${src_dir}/vartypes/primitives/VarTrigger.cpp

  ${src_dir}/vartypes/gui/VarItem.cpp
  ${src_dir}/vartypes/gui/VarItemDelegate.cpp
  ${src_dir}/vartypes/gui/VarTreeModel.cpp
  ${src_dir}/vartypes/gui/VarTreeView.cpp
  ${src_dir}/vartypes/gui/VarTreeViewOptions.cpp

  ${src_dir}/vartypes/primitives/VarProtoBufferVal.cpp
  ${src_dir}/vartypes/primitives/VarProtoBuffer.cpp

  ${src_dir}/vartypes/primitives/VarAnyVal.cpp
  ${src_dir}/vartypes/primitives/VarAny.cpp
)

include_directories(${src_dir}/vartypes)
include_directories(${src_dir}/vartypes/primitives)
include_directories(${src_dir}/vartypes/gui)
include_directories(${src_dir}/vartypes/xml)


#only ones that need to be moc'ed
set (HEADERS
  ${src_dir}/vartypes/primitives/VarType.h
  ${src_dir}/vartypes/primitives/VarBlob.h
  ${src_dir}/vartypes/primitives/VarBool.h
  ${src_dir}/vartypes/primitives/VarDouble.h
  ${src_dir}/vartypes/primitives/VarExternal.h
  ${src_dir}/vartypes/primitives/VarInt.h
  ${src_dir}/vartypes/primitives/VarList.h
  ${src_dir}/vartypes/primitives/VarQWidget.h
  ${src_dir}/vartypes/primitives/VarSelection.h
  ${src_dir}/vartypes/primitives/VarString.h
  ${src_dir}/vartypes/primitives/VarStringEnum.h
  ${src_dir}/vartypes/primitives/VarTrigger.h
  ${src_dir}/vartypes/gui/VarItem.h
  ${src_dir}/vartypes/gui/VarItemDelegate.h
  ${src_dir}/vartypes/gui/VarTreeModel.h
  ${src_dir}/vartypes/gui/VarTreeView.h
  ${src_dir}/vartypes/VarNotifier.h
)

set (INSTALLABLE_HEADERS
  ${HEADERS}
  ${src_dir}/vartypes/VarTypesLoaderInterface.h
  ${src_dir}/vartypes/VarTypes.h
  ${src_dir}/vartypes/VarTypesFactory.h
  ${src_dir}/vartypes/gui/VarTreeViewOptions.h
  ${src_dir}/vartypes/xml/xmlParser.h
  ${src_dir}/vartypes/primitives/VarVal.h
  ${src_dir}/vartypes/primitives/VarStringVal.h
  ${src_dir}/vartypes/primitives/VarIntVal.h
  ${src_dir}/vartypes/primitives/VarDoubleVal.h
  ${src_dir}/vartypes/primitives/VarBoolVal.h
  ${src_dir}/vartypes/VarXML.h
  ${src_dir}/vartypes/VarTypesInstance.h
  ${src_dir}/vartypes/VarBase64.h
  ${src_dir}/vartypes/primitives/VarProtoBufferVal.h
  ${src_dir}/vartypes/primitives/VarProtoBuffer.h
  ${src_dir}/vartypes/primitives/VarAnyVal.h
  ${src_dir}/vartypes/primitives/VarAny.h
)

set (INSTALLABLE_DOCFILES
  ${src_dir}/README
  ${src_dir}/COPYING
)

set (INSTALLABLE_EXAMPLE
  ${src_dir}/README
  ${src_dir}/COPYING
)


set (RC
  ${src_dir}/vartypes/gui/icons/icons.qrc
)

qt4_wrap_cpp (MOC_SRCS
  ${HEADERS}
)

qt4_add_resources(RC_SRCS 
  ${RC}
)

#flags to set in debug mode
set (CMAKE_CXX_FLAGS_DEBUG "-g")

#flags to set in release mode
set (CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3 -march=native")

set (libs ${QT_LIBRARIES})


SET(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Output directory for libraries")
SET(CMAKE_INSTALL_INCLUDEDIR include CACHE PATH "Output directory for header files")
SET(CMAKE_INSTALL_DOCDIR share/doc CACHE PATH "Output directory for documentation and license files")

set (target vartypes)
add_library(${target} SHARED ${MOC_SRCS} ${SRCS} ${RC_SRCS})

set_target_properties(${target} PROPERTIES VERSION 0.8.0 SOVERSION 1)
#set_target_properties(${target} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
if(WIN32)
    set(EXPORT_ALL "-Wl,--export-all-symbols")
endif()
if (USE_Qt5)
    target_link_libraries(${target} ${libs} Qt5::Widgets ${EXPORT_ALL})
else()
    target_link_libraries(${target} ${libs} ${EXPORT_ALL})
endif()

set (example_target vartype_example)
set (example_dir example)
qt4_wrap_cpp (EXAMPLE_MOC_SRCS ${example_dir}/src/mainwindow.h)

add_executable(${example_target}
               ${EXAMPLE_MOC_SRCS}
               ${example_dir}/src/mainwindow.cpp
               ${example_dir}/src/example.cpp)
               
target_link_libraries(${example_target} ${libs} ${target})

INSTALL(FILES ${INSTALLABLE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vartypes)

INSTALL(FILES ${INSTALLABLE_DOCFILES} DESTINATION ${CMAKE_INSTALL_DOCDIR}/vartypes)
if(WIN32)
    INSTALL(TARGETS ${target}
        RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
else()
    INSTALL(TARGETS ${target}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

