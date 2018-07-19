#INCLUDE_DIRECTORIES(/usr/include/hello)
# or
SET(CMAKE_INCLUDE_PATH /usr/include/hello)	# 或者从.bashrc中export该变量
FIND_PATH(myHeader hello.h)			# myHeader存储路径
IF(myHeader)
INCLUDE_DIRECTORIES(${myHeader})
ENDIF(myHeader)

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main libhello.a)
# or
# TARGET_LINK_LIBRARIES(main libhello.so)
# or


