cmake_minimum_required(VERSION 3.5)

project(P3_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(P3_1 main.cpp
    Kontener.h firma.h firma.cpp firmabudowlana.h firmabudowlana.cpp firmatransportowa.cpp firmatransportowa.h hydraulika.cpp hydraulika.h materialy.h materialy.cpp pracownik.cpp pracownik.h)

include(GNUInstallDirs)
install(TARGETS P3_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
