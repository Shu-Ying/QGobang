add_executable(QGobangServer
    main.cpp
    CServerManager.cpp CServerManager.h
    CDBManager.h CDBManager.cpp
    CHttpService.h CHttpService.cpp
)


find_package(Qt6 REQUIRED COMPONENTS Core Sql network httpserver)
find_package(Qt6 REQUIRED COMPONENTS )
target_link_libraries(QGobangServer
    PRIVATE Qt6::Widgets Qt6::Core Qt6::Sql Qt6::Network Qt6::HttpServer
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/include)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/lib)
