// Auto-generated. Do not edit.



    //% block="Power"
    //% icon="\uf011"
    //% color=#AA278D
declare namespace power {

    /**
     * Request low power when the next idle
     * @param mode If Continue, then return immediately; if Wait, then pause until a power-up event occurs 
     */
    //% shim=power::_lowPowerRequest
    function _lowPowerRequest(mode: LowPowerMode): void;

    /**
     * Pause for a fixed interval, and request low power when idle.
     * @param interval The period of time to pause, in milliseconds.
     */
    //% shim=power::_lowPowerPause
    function _lowPowerPause(interval: int32): void;

    /**
     * Prevent or allow low power.
     * Prevent and allow requests should occur in pairs.
     * The default is to allow.
     */
    //% shim=power::_lowPowerEnable
    function _lowPowerEnable(enable: LowPowerEnable): void;

    /**
     * Determine if low power is enabled
     */
    //% shim=power::_lowPowerIsEnabled
    function _lowPowerIsEnabled(): boolean;

    /**
     * Do something repeatedy with full power using a timer.
     * @param interval the time (in ms) for the timer.
     * @param code the code to execute
     */
    //% shim=power::_fullPowerEvery
    function _fullPowerEvery(interval: int32, code: () => void): void;

    /**
     * Set whether the source should trigger full power.
     * @param source the source to set
     * @param enable true to trigger full power
     */
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
    //% shim=power::_fullPowerOn
    function _fullPowerOn(source: FullPowerSource): void;
}

// Auto-generated. Do not edit. Really.
