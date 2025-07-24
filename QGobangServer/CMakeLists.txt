add_executable(QGobangServer
    main.cpp
    CServerManager.cpp
    CServerManager.h
)

target_link_libraries(QGobangServer
    PRIVATE Qt6::Widgets
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/include)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/lib)
