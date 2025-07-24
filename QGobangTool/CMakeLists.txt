qt_add_library(QGobangTool STATIC
    QGobangRule.cpp
    QGobangRule.h
)

target_link_libraries(QGobangTool
    PUBLIC Qt6::Core
)
target_include_directories(QGobangTool
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# 将需要的头文件进行脚本式cp 方便调用
add_custom_command(TARGET QGobangTool POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/../QGobangTool/QGobangRule.h ${CMAKE_BINARY_DIR}/../QGobangTool/include/
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:QGobangTool> ${CMAKE_BINARY_DIR}/../QGobangTool/lib/
)
