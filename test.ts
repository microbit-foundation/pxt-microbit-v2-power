function flash (x: number) {
    power.powerDownEnable(PowerDown.block)
    led.plot(x, 0)
    basic.pause(1000)
    led.unplot(x, 0)
    led.plot(x, 1)
    basic.pause(1000)
    led.unplot(x, 1)
    power.powerDownEnable(PowerDown.allow)
}

input.onButtonPressed(Button.A, function () {
    flash(1)
    power.powerDownRequest()
})

input.onButtonPressed(Button.B, function () {
    flash(2)
    power.powerDownRequest()
})

basic.showString("POWER")
power.wakeOnEnable(PowerWakeup.A)
power.wakeOnEnable(PowerWakeup.B)

power.wakeEvery(6000, function () {
    flash(3)
    power.powerDownRequest()
})

basic.forever(function () {
    flash(0)
    power.deepSleepPause(20000)
})

basic.forever(function () {
    flash(4)
    power.deepSleep()
})
