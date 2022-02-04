set(libdbusmenu_SRCS
    dbusmenuimporter.cpp
    dbusmenushortcut_p.cpp
    dbusmenutypes_p.cpp
    utils.cpp
)

ecm_qt_declare_logging_category(libdbusmenu_SRCS
    HEADER debug.h
    IDENTIFIER DBUSMENUQT
    CATEGORY_NAME org.kde.libdbusmenuqt
    DEFAULT_SEVERITY Info
)

set_source_files_properties(com.canonical.dbusmenu.xml PROPERTIES
    NO_NAMESPACE true
    INCLUDE "dbusmenutypes_p.h"
    CLASSNAME DBusMenuInterface
)

if (Qt6_FOUND)
    qt_add_dbus_interface(libdbusmenu_SRCS com.canonical.dbusmenu.xml dbusmenu_interface)
elseif(Qt5_FOUND)
    qt5_add_dbus_interface(libdbusmenu_SRCS com.canonical.dbusmenu.xml dbusmenu_interface)
endif()



add_library(dbusmenuqt STATIC ${libdbusmenu_SRCS})
target_link_libraries(dbusmenuqt
    Qt${QT_VERSION_MAJOR}::DBus
    Qt${QT_VERSION_MAJOR}::Widgets
)

add_subdirectory(test)
