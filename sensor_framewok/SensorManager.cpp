#include "SensorManager.h"
#include "SensorService.h"



SensorManager::SensorManager( int type ) {

	sensorType = type;

} // end constructor


bool SensorManager::ifSensorAvailable( /*int type*/ ) {
	return SensorService::ifSensorAvailable( sensorType );
} // end function ifSensorAvailable

bool SensorManager::registerSensorByID( /*int type*/ ) {
	SensorService::registerSensor( sensorType, this );
} // end function registerSensorByID




int main() {

	printf( "Enter...\n" );
	SensorService s;
	printf( "pass init\n" );
	s.onFirstRef();
	printf( "pass first ref\n" );
	//s.threadLoop();
	printf( "pass loop\n" );
	return 0;
} // end main
