ADD_EXECUTABLE(hello main.cpp)
# INSATLL TARGETS hello
# target文件在哪，就在哪里的CMakeLists.txt中INSTALL
INSTALL(TARGETS hello RUNTIME DESTINATION bin)
