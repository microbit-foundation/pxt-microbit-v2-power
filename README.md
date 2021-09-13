# Makecode Extension to enable power management on micro:bit (V2)

Use this extension to add all the blocks you will need to use less power in your program when you are using the [latest micro:bit](https://microbit.org/new-microbit/).

This extension might be useful when you want to conserve battery power, such as during a data logging activity.


## Usage

### Put the micro:bit to sleep in a low power mode 💤

The ``||power.lowPowerRequest||`` block will ask the micro:bit to switch to low power mode at the next opportunity, such as when the current code operation has been allowed to complete, or inside ``||basic.pause(ms)||``.

```blocks
input.onButtonPressed(Button.B, function () {
    power.lowPowerRequest()
})
```

You can send ``||power.lowPowerRequest(LowPowerMode.Wait)||``. Then micro:bit will also pause until a full power event occurs.

The ``||power.lowPowerPause(ms)||`` block will ask the micro:bit to sleep for a set interval in milliseconds.

In low power mode, the micro:bit is asleep, and your program is paused. When the micro:bit wakes up to full power mode, your program continues from the point it stopped.

You can use the ``||power.lowPowerEnable(LowPowerEnable.Prevent)||`` and ``||power.lowPowerEnable(LowPowerEnable.Allow)||`` blocks to block low power requests until the code between the two blocks has finished running. It is expected that you would use these blocks in pairs.

```blocks
basic.forever(function () {
    power.lowPowerEnable(LowPowerEnable.Prevent)
    led.plot(2, 2)
    basic.pause(1000)
    led.unplot(2, 2)
    led.plot(2, 1)
    basic.pause(1000)
    led.unplot(2, 1)
    power.lowPowerEnable(LowPowerEnable.Allow)
    power.lowPowerRequest()
})
```

### Wake up the micro:bit to full power mode ⏰

In order to wake up the micro:bit to full power mode, you need to define an event to trigger the wake up call.

You can wake the micro:bit when a button or pin is pressed. In this example, the micro:bit will wake up when Button A or Pin 0 has been pressed.

```blocks
power.fullPowerOn(FullPowerSource.A)
power.fullPowerOn(FullPowerSource.P0)
```

You can also wake the micro:bit at a set time interval in milliseconds. In this example, the micro:bit will wake up every minute and show a smiley face on the screen

```blocks
power.fullPowerEvery(60000, function () {
    basic.showIcon(IconNames.Happy)
    basic.clearScreen()
    power.lowPowerRequest()
})
```

## License
This software made available under the MIT open source license.

[SPDX-License-Identifier: MIT](/LICENSE)

## Code of Conduct

Trust, partnership, simplicity and passion are our core values we live and breathe in our daily work life and within our projects. Our open-source projects are no exception. We have an active community which spans the globe and we welcome and encourage participation and contributions to our projects by everyone. We work to foster a positive, open, inclusive and supportive environment and trust that our community respects the micro:bit code of conduct. Please see our [code of conduct](https://www.microbit.org/safeguarding/) which outlines our expectations for all those that participate in our community and details on how to report any concerns and what would happen should breaches occur.

#### Metadata (used for search, rendering)

* for PXT/microbit
<script src="https://makecode.com/gh-pages-embed.js"></script><script>makeCodeRender("{{ site.makecode.home_url }}", "{{ site.github.owner_name }}/{{ site.github.repository_name }}");</script>
