#ifndef _SENSOR_SERVICE_H_
#define _SENSOR_SERVICE_H_

#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>

class SensorService {


	// 
	sensors_poll_device_1_t* mSensorDevice;
	struct sensors_module_t* mSensorModule;
	sensors_event_t *mSensorEventBuffer, *mSensorEventScratch;
	SensorEventConnection const **mMapFlushEventsToConnections;

	//
public:
	SensorService();
	void onFirstRef();
	bool threadLoop();
	ssize_t poll(sensors_event_t* buffer, size_t count);

	

	// static API for SensorManager?


};


#endif 


