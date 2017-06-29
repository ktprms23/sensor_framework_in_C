

#include <inttypes.h>
#include <stdint.h>
#include <sys/types.h>
#include <hardware/sensors.h>

#include "SensorService.h"


SensorService::SensorService()
	:  mSensorDevice(0),
	   mSensorModule(0) {
	// 1. init
	status_t err = hw_get_module(SENSORS_HARDWARE_MODULE_ID,
            (hw_module_t const**)&mSensorModule);

	if( err != 0 ) {
		// fail
		//
		
		//
	} // end if

	if (mSensorModule) {
	        err = sensors_open_1(&mSensorModule->common, &mSensorDevice);
		if( err != 0 ) {
			// fail
		} // end if

		sensor_t const* list;
		ssize_t count = mSensorModule->get_sensors_list(mSensorModule, &list);
		// 
		for (size_t i=0 ; i<size_t(count) ; i++) {
                	//mActivationCount.add(list[i].handle, model);
                	mSensorDevice->activate(
                        reinterpret_cast<struct sensors_poll_device_t *>(mSensorDevice),
                        list[i].handle, 0);
            	} // end for

	} // end if



} // end constructor


void SensorService::onFirstRef() {

	// 2.

	// size?
	mSensorEventBuffer = new sensors_event_t[/*minBufferSize*/10];
	mSensorEventScratch = new sensors_event_t[/*minBufferSize*/10];
	

} // end function onFirstRef


bool SensorService::threadLoop() {


//	do {
		ssize_t count = poll(mSensorEventBuffer, /*numEventMax*/10);
		if( count < 0 ) {
			break;
		} // end if


//	} while(true);

} // end function threadLoop


/**
 *
 *
 *
 */
ssize_t SensorService::poll(sensors_event_t* buffer, size_t count) {
    if (!mSensorDevice) return NO_INIT;
    // count = 10
    ssize_t c;
    do {
        c = mSensorDevice->poll(reinterpret_cast<struct sensors_poll_device_t *> (mSensorDevice),
                                buffer, count);
    } while (c == -EINTR);
    return c;
} // end function poll




///////////////////////////////////////
//int main




