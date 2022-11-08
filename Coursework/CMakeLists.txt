cmake_minimum_required(VERSION 3.10) 

project(RacingSimulator) 

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(RacingSimulator SHARED
	Class_Transport.h 
	Class_Transport.cpp 
	Class_AirTransport.h 
	Class_AirTransport.cpp 
	Class_GroundTransport.h 
	Class_GroundTransport.cpp 
	Class_Centaur.h 
	Class_Centaur.cpp 
	Class_Camel.h 
	Class_Camel.cpp 
	Class_AllterrainBoots.h 
	Class_AllterrainBoots.cpp 
	Class_FastCamel.h 
	Class_FastCamel.cpp 
	Class_Eagle.h 
	Class_Eagle.cpp 
	Class_Broom.h 
	Class_Broom.cpp 
	Class_MagicCarpet.h 
	Class_MagicCarpet.cpp 
	Class_Race.h 
	Class_Race.cpp) 
add_executable(RacingSimulatorProgram RacingSimulator.cpp) 
target_link_libraries(RacingSimulatorProgram RacingSimulator) 
