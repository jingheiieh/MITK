# 
# Variables
#
#   PLUGIN_NAME: Name of the plugin. If not set it will be set to the directory name
# 
# The following ones will be generated if not set
#   
#   ADD_FUNC_CODE: Name of a file which contains the AddFuncName() definition
#   ADD_FUNC_HEADER: Name of a file which contains the AddFuncName() declaration
#   ADD_FUNC_CALL: File which contains just the call to the above function 
MACRO(CREATE_PLUGIN PLUGIN_NAME)
  SUPPRESS_VC8_DEPRECATED_WARNINGS()
  IF(NOT PLUGIN_NAME)
    GET_FILENAME_COMPONENT(PLUGIN_NAME ${PROJECT_SOURCE_DIR} NAME)
    MESSAGE(STATUS "Warning. No PLUGIN_NAME set. Setting it to directory name: ${PLUGIN_NAME}")
  ENDIF(NOT PLUGIN_NAME)
  IF(NOT PLUGIN_CPP)
    MESSAGE(STATUS "Using files.cmake for plugin ${PLUGIN_NAME}")
    INCLUDE(files.cmake)
    SET(PLUGIN_CPP ${CPP_FILES})
    SET(PLUGIN_MOC_H ${MOC_H_FILES})
    SET(PLUGIN_FORMS ${UI_FILES})
  ELSE(NOT PLUGIN_CPP)
    MESSAGE(STATUS "Using PLUGIN_CPP for plugin ${PLUGIN_NAME}")
  ENDIF(NOT PLUGIN_CPP)
  
  #SET (LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin CACHE INTERNAL "output directory for plugin libraries.")
  CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/META-INF/MANIFEST.MF ${CMAKE_CURRENT_BINARY_DIR}/META-INF/MANIFEST.MF COPYONLY)
  
  SET(PLUGINXML ${CMAKE_CURRENT_SOURCE_DIR}/plugin.xml)
  IF(EXISTS ${PLUGINXML})
    CONFIGURE_FILE(${PLUGINXML} ${CMAKE_CURRENT_BINARY_DIR}/plugin.xml COPYONLY)
  ENDIF(EXISTS ${PLUGINXML})

  SET(PLUGIN_CPP_LIST ${PLUGIN_CPP})
  IF(PLUGIN_FORMS)
    QT4_WRAP_UI(PLUGIN_CPP_LIST ${PLUGIN_FORMS})
  ENDIF(PLUGIN_FORMS)
  IF(PLUGIN_MOC_H)
    QT4_WRAP_CPP(PLUGIN_CPP_LIST ${PLUGIN_MOC_H})
  ENDIF(PLUGIN_MOC_H)
  INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  OPTION("BUILD_${PLUGIN_NAME}" "Build ${PLUGIN_NAME} Plugin" ON)
  
  IF(BUILD_${PLUGIN_NAME} OR BUILD_ALL_PLUGINS)
    IF(CHERRY_STATIC)
      ADD_LIBRARY(${PLUGIN_NAME} STATIC ${PLUGIN_CPP_LIST})
    ELSE(CHERRY_STATIC)
      ADD_LIBRARY(${PLUGIN_NAME} SHARED ${PLUGIN_CPP_LIST})
      #SET_TARGET_PROPERTIES(${PLUGIN_NAME} PROPERTIES DEFINE_SYMBOL CHERRY_EXPORTS)
      IF(PLUGIN_REQUIRED_LIBS)
        FOREACH(lib ${PLUGIN_REQUIRED_LIBS})
          TARGET_LINK_LIBRARIES(${PLUGIN_NAME} ${lib})
        ENDFOREACH(lib ${PLUGIN_REQUIRED_LIBS})
      ENDIF(PLUGIN_REQUIRED_LIBS)
    ENDIF(CHERRY_STATIC)
  ENDIF(BUILD_${PLUGIN_NAME} OR BUILD_ALL_PLUGINS)
  #SET(${KITNAME}_KNOWN_PLUGIN_${PLUGIN_NAME} ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "Directory of ${KITNAME} plugin ${PLUGIN_NAME}." FORCE)
ENDMACRO(CREATE_PLUGIN)

