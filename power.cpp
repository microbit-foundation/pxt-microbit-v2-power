/**
 * (c) 2021, Micro:bit Educational Foundation and contributors
 *
 * SPDX-License-Identifier: MIT
 */

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
    prevent,
    allow
};


namespace power {

#if MICROBIT_CODAL
int timerEventValue  = 1;
#endif // MICROBIT_CODAL

/**
  * Pause until a wake up event occurs, and request power down when idle.
  */
//%
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
//%
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
//%
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
//%
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
  * Prevent or allow power down during deepSleep.
  * Prevent and allow requests should occur in pairs.
  * The default is to allow.
*/
//%
void powerDownEnable(PowerDown choice) {
#if MICROBIT_CODAL
    switch ( choice)
    {
        case PowerDown::prevent:
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
//%
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
//%
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
//%
void wakeOnEnable(PowerWakeup source) {
  wakeOn(source, true);
}

/**
  * Determine if the source will trigger power save wake-up.
  * @param source the source to set
  * @return true is wake-up is enabled
  */
//%
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
