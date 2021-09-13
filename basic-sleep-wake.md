# Pressure switch alarm

## Introduction Step @showdialog
You can use the ``||power:Power||`` blocks to control when your micro:bit goes to sleep in low power mode and wakes up to full power mode.

This will help save on batteries when you are running a program for a long time.

You can tell that the micro:bit is saving battery power as the red power LED on the rear of the board will turn off during low-power mode and on during full-power mode.

#### Simulator support
The power saving extension is not yet supported in the MakeCode simulator, so you will need to flash the program to the micro:bit to try it out.

![micro:bit power LED](https://microbit-foundation.github.io/pxt-microbit-v2-power/docs/static/power-led.png)

## Make a micro:bit pressure switch alarm @showdialog

In this tutorial you will create an intruder alarm that wakes up the micro:bit when someone steps on a home-made pressure sensor.

It is inspired by the [Make it: Code it pressure switch alarm project](https://microbit.org/projects/make-it-code-it/pressure-switch-alarm/) available on the [microbit.org](https://microbit.org) website

![micro:bit connected to pressure sensor](https://cdn.sanity.io/images/ajwvhvgo/production/b7072e2101643d75cd09dd89b0dd289dbbea33cc-600x450.jpg)

## Step 1: Start with a basic program
Let's start with a simple program that shows an angry face and plays alarming music when a pin is pressed.

```template
input.onPinPressed(TouchPin.P0, function () {
    basic.showIcon(IconNames.Angry)
    music.playMelody("C5 G C5 G C5 G C5 G ", 120)
})
```

## Step 2: Put the micro:bit to sleep
Displaying a face and playing a melody forever is going to use up battery power pretty quickly. Let's use the ``||power:Power||`` blocks to save energy before an intruder is detected and after the alarm has been raised

Drag a ``||power:request low power||`` block underneath the ``||music:play melody||`` block. After the alarm sounds, the micro:bit will now try to sleep and save power.

```blocks
input.onPinPressed(TouchPin.P0, function () {
    basic.showIcon(IconNames.Angry)
    music.startMelody(music.builtInMelody(Melodies.Baddy), MelodyOptions.Forever)
    power.lowPowerRequest()
})
```

## Step 3: Tell the micro:bit how to wake up
Good work. You've now told the micro:bit when to go to sleep, but it doesn't yet know how to wake up.

When you use the ``||Power||`` blocks to put the micro:bit to sleep, you will always need to tell it how to wake up again, otherwise it will just ignore you!

Drag ``||basic:on start||`` into the workspace and then add  ``||power:full power on pin P0||``underneath ``||basic:on start||`` to tell the micro:bit to wake up when Pin 0 is touched.

```blocks
input.onPinPressed(TouchPin.P0, function () {
    basic.showIcon(IconNames.Angry)
    music.startMelody(music.builtInMelody(Melodies.Baddy), MelodyOptions.Forever)
    power.lowPowerRequest()
})
power.fullPowerOn(FullPowerSource.P0)
```

## Step 4: Try it out
Click ``|Download|`` to transfer your code. 

When the micro:bit has sounded the alarm it will enter low power mode until you touch Pin 0 to wake it up again.

## Step 5: Make the alarm @showdialog

![micro:bit connected to pressure sensor](https://cdn.sanity.io/images/ajwvhvgo/production/b7072e2101643d75cd09dd89b0dd289dbbea33cc-600x450.jpg)

Now you have your program, try making a pressure input switch out of cardboard and tin foil like in the picture. Connect the two foil pads on one side to pins ``0`` and ``GND`` on the micro:bit. When you step on the switch, the foil on the top completes an electrical circuit, and it sounds the alert.

More information is available in the [Make it: Code it pressure switch alarm project](https://microbit.org/projects/make-it-code-it/pressure-switch-alarm/).