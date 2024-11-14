// Auto-generated. Do not edit.



    //% block="Power"
    //% icon="\uf011"
    //% color=#AA278D
declare namespace power {

    /**
     * Request low power when the next idle
     * @param mode If Continue, then return immediately; if Wait, then pause until a power-up event occurs 
     */
    //% help=power/low-power-request
    //% group="micro:bit (V2)"
    //% weight=700
    //% block="request low power||and $mode"
    //% shim=power::_lowPowerRequest
    function _lowPowerRequest(mode: LowPowerMode): void;

    /**
     * Pause for a fixed interval, and request low power when idle.
     * @param interval The period of time to pause, in milliseconds.
     */
    //% help=power/low-power-for
    //% group="micro:bit (V2)"
    //% weight=600
    //% interval.shadow=longTimePicker
    //% block="request low power for $interval ms"
    //% shim=power::_lowPowerPause
    function _lowPowerPause(interval: int32): void;

    /**
     * Prevent or allow low power.
     * Prevent and allow requests should occur in pairs.
     * The default is to allow.
     */
    //% help=power/low-power-enable
    //% weight=500
    //% block="low power %enable"
    //% shim=power::_lowPowerEnable
    function _lowPowerEnable(enable: LowPowerEnable): void;

    /**
     * Determine if low power is enabled
     */
    //% help=power/low-power-is-enabled
    //% shim=power::_lowPowerIsEnabled
    function _lowPowerIsEnabled(): boolean;

    /**
     * Do something repeatedy with full power using a timer.
     * @param interval the time (in ms) for the timer.
     * @param code the code to execute
     */
    //% help=power/full-power-every
    //% group="micro:bit (V2)"
    //% weight=800
    //% blockAllowMultiple=1
    //% interval.shadow=longTimePicker
    //% afterOnStart=true
    //% block="full power every $interval ms"
    //% shim=power::_fullPowerEvery
    function _fullPowerEvery(interval: int32, code: () => void): void;

    /**
     * Set whether the source should trigger full power.
     * @param source the source to set
     * @param enable true to trigger full power
     */
    //% help=power/full-power-source-enable
    //% shim=power::_fullPowerSourceEnable
    function _fullPowerSourceEnable(source: FullPowerSource, enable: boolean): void;

    /**
     * Determine if the source will trigger full power.
     * @param source the source to check
     * @return true if the source will trigger full power
     */
    //% help=power/full-power-source-is-enabled
    //% shim=power::_fullPowerSourceIsEnabled
    function _fullPowerSourceIsEnabled(source: FullPowerSource): boolean;

    /**
     * Set the source to trigger full power.
     * @param source the source to set
     */
    //% help=power/full-power-on
    //% group="micro:bit (V2)"
    //% weight=900
    //% block="full power on %source"
    //% shim=power::_fullPowerOn
    function _fullPowerOn(source: FullPowerSource): void;
}

// Auto-generated. Do not edit. Really.
