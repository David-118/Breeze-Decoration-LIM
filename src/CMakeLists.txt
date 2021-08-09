find_package (KDecoration2 REQUIRED)

find_package (Qt5 REQUIRED COMPONENTS
    Core
    Gui
)

find_package (KF5 REQUIRED COMPONENTS
    Config
    ConfigWidgets
    CoreAddons
    GuiAddons
    I18n
    IconThemes
    WindowSystem
)


# X11
find_package(X11 REQUIRED)
set_package_properties(X11 PROPERTIES DESCRIPTION "X11 libraries"
    URL "http://www.x.org"
    TYPE REQUIRED
    PURPOSE "Required for building the X11 based workspace"
)

find_package(XCB MODULE REQUIRED COMPONENTS
    XCB
    RANDR
)
set_package_properties(XCB PROPERTIES TYPE REQUIRED)

find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS X11Extras)

if(X11_FOUND AND XCB_XCB_FOUND)
    set(HAVE_X11 ON)
    set(X11_LIBRARIES XCB::XCB)
endif()


# Wayland
find_package (KF5 COMPONENTS
    Wayland
)

if(KF5Wayland_FOUND)
    set(HAVE_Wayland ON)
    set(Wayland_LIBRARIES KF5::WaylandClient)
endif()


# Discover KF5 version
string(REGEX MATCH "\\.([^]]+)\\." KF5_MINOR_VERSION ${KF5_VERSION})
string(REGEX REPLACE "\\." "" KF5_MINOR_VERSION ${KF5_MINOR_VERSION})
message(STATUS "KF5 VERSION: ${KF5_VERSION} (MINOR_VERSION=${KF5_MINOR_VERSION})")


configure_file(BuildConfig.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/BuildConfig.h)

set (decoration_SRCS
    AppMenuModel.cc
    AppMenuButton.cc
    AppMenuButtonGroup.cc
    BoxShadowHelper.cc
    Button.cc
    Decoration.cc
    MenuOverflowButton.cc
    TextButton.cc
    ConfigurationModule.cc
    plugin.cc
)

kconfig_add_kcfg_files(decoration_SRCS
    InternalSettings.kcfgc
)

add_library (breezelimdeco MODULE
    ${decoration_SRCS}
)

target_link_libraries (breezelimdeco
    PUBLIC
        dbusmenuqt
        Qt5::Core
        Qt5::Gui
        Qt5::X11Extras
        KF5::ConfigCore
        KF5::ConfigGui
        KF5::ConfigWidgets
        KF5::CoreAddons
        KF5::I18n
        KF5::GuiAddons
        KF5::IconThemes
        KF5::WindowSystem
        ${X11_LIBRARIES}
        ${Wayland_LIBRARIES}

    PRIVATE
        KDecoration2::KDecoration
)

install (TARGETS breezelimdeco
         DESTINATION ${PLUGIN_INSTALL_DIR}/org.kde.kdecoration2)
