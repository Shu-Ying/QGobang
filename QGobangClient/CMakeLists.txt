qt_add_executable(QGobangClient
    main.cpp
    CUiManager.cpp
    CUiManager.h
    Ui/widget.cpp
    Ui/widget.h
    Ui/widget.ui
)

target_link_libraries(QGobangClient
    PRIVATE Qt6::Widgets
)
target_include_directories(QGobangClient
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/include)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/../QGobangTool/lib)
