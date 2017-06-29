#ifndef _SENSOR_MANAGER_H_
#define _SENSOR_MANAGER_H_

#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>

#include "QSensorType.h"

#define SENSOR_RESPONSE_TIME_NORMAL 0

class SensorService;
class SensorManager {

private:
	
	int sensorType;
	
public:
	SensorManager( int ); 
	bool ifSensorAvailable( /*int*/ );
	bool registerSensorByID( /*int */);
	// virtual function to implement
	virtual void sensorCallbackFunction( float * ) = 0;


};

#endif
