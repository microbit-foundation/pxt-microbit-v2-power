/**
 * (c) 2021, Micro:bit Educational Foundation and contributors
 *
 * SPDX-License-Identifier: MIT
 */

//% block="Power"
//% icon="\uf011"
//% color=#AA278D
namespace power {

/**
    * Request low power when the next idle
    * @param mode If Continue, then return immediately; if Wait, then pause until a power-up event occurs 
    */
//% help=power/low-power-request
//% group="micro:bit (V2)"
//% weight=700
//% block="request low power||and $mode"
//% parts="v2"
//% shim=power::_lowPowerRequest
export function lowPowerRequest(mode?: LowPowerMode): void {
    basic.pause(0)
}

/**
    * Pause for a fixed interval, and request low power when idle.
    * @param interval The period of time to pause, in milliseconds.
    */
//% help=power/low-power-for
//% group="micro:bit (V2)"
//% weight=600
//% interval.shadow=longTimePicker
//% block="request low power for $interval ms"
//% parts="v2"
//% shim=power::_lowPowerPause
export function lowPowerPause(interval: number): void {
    basic.pause(interval)
}

/**
    * Prevent or allow low power.
    * Prevent and allow requests should occur in pairs.
    * The default is to allow.
    */
//% help=power/low-power-enable
//% weight=500
//% block="low power %enable"
//% parts="v2"
//% shim=power::_lowPowerEnable
export function lowPowerEnable(enable: LowPowerEnable): void {
    return
}

/**
    * Determine if low power is enabled
    */
//% help=power/low-power-is-enabled
//% shim=power::_lowPowerIsEnabled
export function lowPowerIsEnabled(): boolean {
    return false
}

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
//% parts="v2"
//% shim=power::_fullPowerEvery
export function fullPowerEvery(interval: number, code: () => void): void {
    loops.everyInterval(interval, code)
}

/**
    * Set whether the source should trigger full power.
    * @param source the source to set
    * @param enable true to trigger full power
    */
//% help=power/full-power-source-enable
//% shim=power::_fullPowerSourceEnable
export function fullPowerSourceEnable(source: FullPowerSource, enable: boolean): void {
    return
}

/**
    * Determine if the source will trigger full power.
    * @param source the source to check
    * @return true if the source will trigger full power
    */
//% help=power/full-power-source-is-enabled
//% shim=power::_fullPowerSourceIsEnabled
export function fullPowerSourceIsEnabled(source: FullPowerSource): boolean {
    return false
}

/**
    * Set the source to trigger full power.
    * @param source the source to set
    */
//% help=power/full-power-on
//% group="micro:bit (V2)"
//% weight=900
//% block="full power on %source"
//% parts="v2"
//% shim=power::_fullPowerOn
export function fullPowerOn(source: FullPowerSource): void {
    return
}

}
