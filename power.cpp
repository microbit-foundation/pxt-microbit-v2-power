#include "pxt.h"

#if MICROBIT_CODAL

#include "Timer.h"
#include "MicroBitCompat.h"

#ifndef MICROBIT_ID_MAKECODE_POWER
#define MICROBIT_ID_MAKECODE_POWER 9000
#endif

#endif // MICROBIT_CODAL


enum class PowerWakeup {
    A  = MICROBIT_ID_BUTTON_A,
    B  = MICROBIT_ID_BUTTON_B,
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2
};

enum class PowerDown {
    block,
    allow
};


//% block="Power"
//% icon="\uf011"
//% color=#AA278D
namespace power {

#if MICROBIT_CODAL
int timerEventValue  = 1;
#endif // MICROBIT_CODAL

/**
  * Pause until a wake up event occurs, and request power down when idle.
  */
//% help=power/deep-sleep
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=800
//% block="deep sleep"
void deepSleep() {
#if MICROBIT_CODAL
    uBit.power.deepSleep();
#else
    uBit.sleep(0);
#endif
}


/**
  * Request power down when idle, and return immediately.
  */
//% help=power/deep-sleep-async
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=400
//% block="request power down"
void powerDownRequest() {
#if MICROBIT_CODAL
    uBit.power.deepSleepAsync();
#else
    uBit.sleep(0);
#endif
}


/**
  * Pause for a fixed interval, and request power down when idle.
  * @param interval The period of time to pause, in milliseconds.
  */
//% help=power/deep-sleep-pause
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=700
//% block="deep sleep pause $interval ms"
//% interval.shadow=longTimePicker
void deepSleepPause(unsigned interval) {
#if MICROBIT_CODAL
    uBit.power.deepSleep(interval);
#else
    uBit.sleep(interval);
#endif
}


/**
  * Do something repeatedy using a wake-up timer.
  * @param interval time (in ms) for the timer.
  * @param body code to execute
  */
//% help=power/wake-every
//% blockAllowMultiple=1
//% interval.shadow=longTimePicker
//% afterOnStart=true
//% group="micro:bit (V2)"
//% weight=600
//% block="wake every $interval ms"
void wakeEvery(unsigned interval, Action body) {
#if MICROBIT_CODAL
    registerWithDal( MICROBIT_ID_MAKECODE_POWER, timerEventValue, body);
    // CODAL_TIMER_EVENT_FLAGS_WAKEUP makes the timer event trigger power up
    system_timer_event_after( 0, MICROBIT_ID_MAKECODE_POWER, timerEventValue, CODAL_TIMER_EVENT_FLAGS_WAKEUP);
    system_timer_event_every( interval, MICROBIT_ID_MAKECODE_POWER, timerEventValue++, CODAL_TIMER_EVENT_FLAGS_WAKEUP);
#else
    target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
}


/**
  * Block or allow power down during deepSleep
  * Block and allow requests should occur in pairs.
  * The default is to allow.
*/
//% help=power/power-down
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=500
//% block="power down %choice"
void powerDownEnable(PowerDown choice) {
#if MICROBIT_CODAL
    switch ( choice)
    {
        case PowerDown::block:
            uBit.power.powerDownDisable();
            break;

        case PowerDown::allow:
            uBit.power.powerDownEnable();
            break;

        default:
            break;
    }
#endif
}


/**
  * Determine if power down during deepSleep is enabled
*/
//% help=power/power-down-enabled
//% group="micro:bit (V2)"
bool powerDownIsEnabled() {
#if MICROBIT_CODAL
    return uBit.power.powerDownIsEnabled();
#else
    return false;
#endif
}


/**
  * Set whether the source should trigger power save wake-up.
  * @param source the source to set
  * @param wake true to trigger wake-up or false for no wake-up
  */
//% help=power/wake-on
//% group="micro:bit (V2)"
void wakeOn(PowerWakeup source, bool wake) {
#if MICROBIT_CODAL
    switch ( source)
    {
        case PowerWakeup::A:
          uBit.buttonA.wakeOnActive(wake ? 1 : 0);
          break;

        case PowerWakeup::B:
          uBit.buttonB.wakeOnActive(wake ? 1 : 0);
          break;

        case PowerWakeup::P0:
        case PowerWakeup::P1:
        case PowerWakeup::P2:
        {
            MicroBitPin *pin = getPin((int)source);
            pin->wakeOnActive(wake ? 1 : 0);
            break;
        }
        default:
            break;
    }
#endif
}


/**
  * Set the source to trigger power save wake-up.
  * @param source the source to set
  */
//% help=power/wake-on
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=900
//% block="wake on %source"
void wakeOnEnable(PowerWakeup source) {
  wakeOn(source, true);
}

/**
  * Determine if the source will trigger power save wake-up.
  * @param source the source to set
  * @return true is wake-up is enabled
  */
//% help=power/wake-on-enabled
bool wakeOnIsEnabled(PowerWakeup source) {
#if MICROBIT_CODAL
    switch ( source)
    {
        case PowerWakeup::A:
          return uBit.buttonA.isWakeOnActive() ? true : false;
          break;

        case PowerWakeup::B:
          return uBit.buttonB.isWakeOnActive() ? true : false;
          break;
        
        case PowerWakeup::P0:
        case PowerWakeup::P1:
        case PowerWakeup::P2:
        {
            MicroBitPin *pin = getPin((int)source);
            return pin->isWakeOnActive() ? true : false;
            break;
        }
        default:
          break;
    }
#endif
    return false;
}


} // namespace power
