
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Click.h - class Click, logical block.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <Click.h>

click_t in_Click;

Click test;

void setup() {

pinMode(18, INPUT_PULLUP); // pin button

in_Click.timestamp_system       =  millis();
in_Click.state_hard             = !digitalRead(18);
in_Click.duration_bounce        =   50;
in_Click.duration_click_Db      =  250;
in_Click.duration_inactivity_Up = 5000;
in_Click.duration_inactivity_Dn = 1000;
in_Click.duration_press         =  500;

test.reset(in_Click);

}

void loop() {

in_Click.timestamp_system =  millis();
in_Click.state_hard       = !digitalRead(18);

test.read(in_Click);

if (test.state_button       () == 1) {}
if (test.state_inactivity_Up() == 1) {}
if (test.state_inactivity_Dn() == 1) {}
if (test.event_click_Up     () == 1) {}
if (test.event_click_Dn     () == 1) {}
if (test.event_click_Db     () == 1) {}
if (test.event_inactivity_Up() == 1) {}
if (test.event_inactivity_Dn() == 1) {}
if (test.event_press_short  () == 1) {}
if (test.event_press_long   () == 1) {}

}

