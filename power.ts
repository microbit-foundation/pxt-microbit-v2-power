    const enum PowerWakeup {
    A = 1,  // MICROBIT_ID_BUTTON_A
    B = 2,  // MICROBIT_ID_BUTTON_B
    P0 = 100,  // MICROBIT_ID_IO_P0
    P1 = 101,  // MICROBIT_ID_IO_P1
    P2 = 102,  // MICROBIT_ID_IO_P2
    }


    const enum PowerDown {
    prevent = 0,
    allow = 1,
    }


    //% block="Power"
    //% icon="\uf011"
    //% color=#AA278D
    namespace power {

    /**
     * Pause until a wake up event occurs, and request power down when idle.
     */
    //% help=power/deep-sleep
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=800
    //% block="deep sleep" shim=power::deepSleep
    function deepSleep(): void { basic.pause(0) }

    /**
     * Request power down when idle, and return immediately.
     */
    //% help=power/deep-sleep-async
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=400
    //% block="request power down" shim=power::powerDownRequest
    function powerDownRequest(): void { basic.pause(0) }

    /**
     * Pause for a fixed interval, and request power down when idle.
     * @param interval The period of time to pause, in milliseconds.
     */
    //% help=power/deep-sleep-pause
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=700
    //% block="deep sleep pause $interval ms"
    //% interval.shadow=longTimePicker shim=power::deepSleepPause
    function deepSleepPause(interval: uint32): void { basic.pause(interval) }

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
    //% block="wake every $interval ms" shim=power::wakeEvery
    function wakeEvery(interval: uint32, body: () => void): void { basic.pause(0) }

    /**
     * Prevent or allow power down during deepSleep.
     * Prevent and allow requests should occur in pairs.
     * The default is to allow.
     */
    //% help=power/power-down
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=500
    //% block="power down %choice" shim=power::powerDownEnable
    function powerDownEnable(choice: PowerDown): void { basic.pause(0) }

    /**
     * Determine if power down during deepSleep is enabled
     */
    //% help=power/power-down-enabled
    //% group="micro:bit (V2)" shim=power::powerDownIsEnabled
    function powerDownIsEnabled(): boolean { return true }

    /**
     * Set whether the source should trigger power save wake-up.
     * @param source the source to set
     * @param wake true to trigger wake-up or false for no wake-up
     */
    //% help=power/wake-on
    //% group="micro:bit (V2)" shim=power::wakeOn
    function wakeOn(source: PowerWakeup, wake: boolean): void { basic.pause(0) }

    /**
     * Set the source to trigger power save wake-up.
     * @param source the source to set
     */
    //% help=power/wake-on
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=900
    //% block="wake on %source" shim=power::wakeOnEnable
    function wakeOnEnable(source: PowerWakeup): void { basic.pause(0) }

    /**
     * Determine if the source will trigger power save wake-up.
     * @param source the source to set
     * @return true is wake-up is enabled
     */
    //% help=power/wake-on-enabled shim=power::wakeOnIsEnabled
    function wakeOnIsEnabled(source: PowerWakeup): boolean { return false }
}
