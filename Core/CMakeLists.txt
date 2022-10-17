# Set the project name
project (CTP_Core)

add_library(${PROJECT_NAME} INTERFACE)
add_library(Chen::CTP ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)