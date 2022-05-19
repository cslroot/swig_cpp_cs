enable_language(CSharp)
include(CSharpUtilities)
set(PROJ_NAME_CS app_cs)
file(GLOB_RECURSE ${PROJ_NAME_CS}_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cs)
add_executable(${PROJ_NAME_CS} ${CS_LIB_TYPE})
target_compile_options(${PROJ_NAME_CS} PRIVATE "/langversion:latest")
# set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "net6.0")

target_sources(${PROJ_NAME_CS} PRIVATE ${${PROJ_NAME_CS}_SRC})

set_property(TARGET ${PROJ_NAME_CS} PROPERTY WIN32_EXECUTABLE FALSE)
set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_CONFIGURATION_TYPE Application)
set_target_properties(${PROJ_NAME_CS} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
set_target_properties(${PROJ_NAME_CS} PROPERTIES FOLDER cs)
set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_DOTNET_REFERENCES
	"Microsoft.CSharp"
	"System"
	"System.Core"
	"System.Data"
	"WindowsBase")

target_link_libraries(${PROJ_NAME_CS} PRIVATE common_cs)
target_link_libraries(${PROJ_NAME_CS} PRIVATE foo_cs)
target_link_libraries(${PROJ_NAME_CS} PRIVATE bar_cs)
