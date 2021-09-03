/**
 * (c) 2021, Micro:bit Educational Foundation and contributors
 *
 * SPDX-License-Identifier: MIT
 */

function flash(x: number) {
    power.lowPowerEnable(LowPowerEnable.Prevent)
    led.plot(x, 0)
    basic.pause(1000)
    led.unplot(x, 0)
    led.plot(x, 1)
    basic.pause(1000)
    led.unplot(x, 1)
    power.lowPowerEnable(LowPowerEnable.Allow)
}

input.onButtonPressed(Button.A, function () {
    flash(1)
    power.lowPowerRequest(LowPowerMode.Continue)
})

input.onButtonPressed(Button.B, function () {
    flash(2)
    power.lowPowerRequest(LowPowerMode.Continue)
})

basic.showString("POWER")
power.fullPowerOn(FullPowerSource.A)
power.fullPowerOn(FullPowerSource.B)

power.fullPowerEvery(6000, function () {
    flash(3)
    power.lowPowerRequest(LowPowerMode.Continue)
})

basic.forever(function () {
    flash(0)
    power.lowPowerPause(20000)
})

basic.forever(function () {
    flash(4)
    power.lowPowerRequest(LowPowerMode.Wait)
})
