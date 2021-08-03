// Auto-generated. Do not edit.



    //% block="Power"
    //% icon="\uf011"
    //% color=#AA278D
declare namespace power {

    /**
     * Pause for a fixed interval, and request power down when idle.
     * @param interval The period of time to pause, in milliseconds.
     */
    //% help=power/deep-sleep-pause
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=900
    //% block="deep sleep pause $interval ms"
    //% interval.shadow=longTimePicker shim=power::deepSleepPause
    function deepSleepPause(interval: uint32): void;

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
    //% help=power/on-timer-every shim=power::onTimerEvery
    function onTimerEvery(interval: uint32, body: () => void): void;

    /**
     * Pause until a wake up event occurs, and request power down when idle.
     */
    //% help=power/deep-sleep
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=700
    //% block="deep sleep" shim=power::deepSleep
    function deepSleep(): void;

    /**
     * Request power down when idle, and return immediately.
     */
    //% help=power/deep-sleep-async
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=600
    //% block="request deep sleep" shim=power::deepSleepAsync
    function deepSleepAsync(): void;

    /**
     * Disable power down during deepSleep
     * Disable requests accumulate, so should be reversed by a corresponding enable request.
     * The default is enabled.
     */
    //% help=power/power-down-disable
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=560
    //% block="power down disable" shim=power::powerDownDisable
    function powerDownDisable(): void;

    /**
     * Enable power down during deepSleep
     * Reversed a previous disable request.
     * The default is enabled.
     */
    //% help=power/power-down-enable
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=540
    //% block="power down enable" shim=power::powerDownEnable
    function powerDownEnable(): void;

    /**
     * Determine if power down during deepSleep is enabled
     */
    //% help=power/power-down-enabled
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=520
    //% block="power down is enabled" shim=power::powerDownIsEnabled
    function powerDownIsEnabled(): boolean;

    /**
     * Set whether the source should trigger power save wake-up.
     * @param source the source to set
     * @param wake true to trigger wake-up or false for no wake-up
     */
    //% help=power/wake-on
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=100
    //% block="wake on %source| %wake" shim=power::wakeOn
    function wakeOn(source: PowerWakeup, wake: boolean): void;

    /**
     * Set the source to trigger power save wake-up.
     * @param source the source to set
     */
    //% help=power/wake-on
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=460
    //% block="wake on %source" shim=power::wakeOnEnable
    function wakeOnEnable(source: PowerWakeup): void;

    /**
     * Stop the source triggering power save wake-up.
     * @param source the source to set
     * @param wake true to trigger wake-up or false for no wake-up
     */
    //% help=power/wake-on
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=440
    //% block="disable wake on %source" shim=power::wakeOnDisable
    function wakeOnDisable(source: PowerWakeup): void;

    /**
     * Determine if the source will trigger power save wake-up.
     * @param source the source to set
     * @return true is wake-up is enabled
     */
    //% help=power/wake-on-enabled
    //% blockGap=8
    //% group="micro:bit (V2)"
    //% weight=420
    //% block="wake on %source is enabled" shim=power::wakeOnIsEnabled
    function wakeOnIsEnabled(source: PowerWakeup): boolean;
}

// Auto-generated. Do not edit. Really.
