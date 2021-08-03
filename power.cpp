#include "pxt.h"

#if MICROBIT_CODAL

#include "Timer.h"
#include "MicroBitCompat.h"

#ifndef MICROBIT_POWER_ONTIMEREVERY_ID
#define MICROBIT_POWER_ONTIMEREVERY_ID MICROBIT_ID_POWER_MANAGER
#endif

#ifndef MICROBIT_POWER_ONTIMEREVERY_FIRSTVALUE
#define MICROBIT_POWER_ONTIMEREVERY_FIRSTVALUE 60000
#endif

#endif // MICROBIT_CODAL


enum class PowerWakeup {
    P0 = MICROBIT_ID_IO_P0,
    P1 = MICROBIT_ID_IO_P1,
    P2 = MICROBIT_ID_IO_P2,
    A  = MICROBIT_ID_BUTTON_A,
    B  = MICROBIT_ID_BUTTON_B
};


//% block="Power"
//% icon="\uf011"
//% color=#AA278D
namespace power {

#if MICROBIT_CODAL
int timerEventSource = MICROBIT_POWER_ONTIMEREVERY_ID;
int timerEventValue  = MICROBIT_POWER_ONTIMEREVERY_FIRSTVALUE;
#endif // MICROBIT_CODAL

/**
  * Pause for a fixed interval, and request power down when idle.
  * @param interval The period of time to pause, in milliseconds.
  */
//% help=power/deep-sleep-pause
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=900
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
  * Do something repeatedy using a timer event.
  * The timer event is a deep sleep wake-up source.
  * @param interval time (in ms) for the timer.
  * @param body code to execute
  */
//% block="on timer every $interval ms"
//% blockId=on_timer_every
//% group="micro:bit (V2)"
//% blockAllowMultiple=1
//% interval.shadow=longTimePicker
//% afterOnStart=true
//% weight=800
//% help=power/on-timer-every
void onTimerEvery(unsigned interval, Action body) {
#if MICROBIT_CODAL
    registerWithDal( timerEventSource, timerEventValue, body);
    // CODAL_TIMER_EVENT_FLAGS_WAKEUP makes the timer event trigger power up
    system_timer_event_every( interval, timerEventSource, timerEventValue++, CODAL_TIMER_EVENT_FLAGS_WAKEUP);
#else
    target_panic(PANIC_VARIANT_NOT_SUPPORTED);
#endif
}




/**
  * Pause until a wake up event occurs, and request power down when idle.
  */
//% help=power/deep-sleep
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=700
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
//% weight=600
//% block="request deep sleep"
void deepSleepAsync() {
#if MICROBIT_CODAL
    uBit.power.deepSleepAsync();
#else
    uBit.sleep(0);
#endif
}


/**
  * Disable power down during deepSleep
  * Disable requests accumulate, so should be reversed by a corresponding enable request.
  * The default is enabled.
*/
//% help=power/power-down-disable
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=560
//% block="power down disable"
void powerDownDisable() {
#if MICROBIT_CODAL
    uBit.power.powerDownDisable();
#endif
}


/**
  * Enable power down during deepSleep
  * Reversed a previous disable request.
  * The default is enabled.
  */
//% help=power/power-down-enable
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=540
//% block="power down enable"
void powerDownEnable() {
#if MICROBIT_CODAL
    uBit.power.powerDownEnable();
#endif
}


/**
  * Determine if power down during deepSleep is enabled
*/
//% help=power/power-down-enabled
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=520
//% block="power down is enabled"
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
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=100
//% block="wake on %source| %wake"
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
//% weight=460
//% block="wake on %source"
void wakeOnEnable(PowerWakeup source) {
  wakeOn(source, true);
}


/**
  * Stop the source triggering power save wake-up.
  * @param source the source to set
  * @param wake true to trigger wake-up or false for no wake-up
  */
//% help=power/wake-on
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=440
//% block="disable wake on %source"
void wakeOnDisable(PowerWakeup source) {
  wakeOn(source, false);
}

/**
  * Determine if the source will trigger power save wake-up.
  * @param source the source to set
  * @return true is wake-up is enabled
  */
//% help=power/wake-on-enabled
//% blockGap=8
//% group="micro:bit (V2)"
//% weight=420
//% block="wake on %source is enabled"
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
