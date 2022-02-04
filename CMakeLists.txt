cmake_minimum_required (VERSION 3.16.0)
project (material-decoration)

add_definitions (-Wall)

include (FeatureSummary)
find_package (ECM 0.0.9 REQUIRED NO_MODULE)

set (CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${ECM_MODULE_PATH}
)

include (ECMInstallIcons)
include (KDEInstallDirs)
include (KDECMakeSettings)
include (KDECompilerSettings NO_POLICY_SCOPE)

# set(QT_MIN_VERSION "5.9.0")
# https://doc.qt.io/qt-6/cmake-qt5-and-qt6-compatibility.html#supporting-older-qt-5-versions
# find_package(QT NAMES Qt6 Qt5)
find_package(QT NAMES Qt5)
# find_package(QT NAMES Qt6)
find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
    Widgets
    DBus
)
include(ECMQtDeclareLoggingCategory)

# Remove Qt 5.15 Deprecations
# https://doc.qt.io/qt-6/portingguide.html
add_compile_definitions(QT_DISABLE_DEPRECATED_BEFORE=0x050F00)

add_subdirectory (src/libdbusmenuqt)
add_subdirectory (src)

feature_summary(WHAT ALL)
