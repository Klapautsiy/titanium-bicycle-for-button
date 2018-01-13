
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

pinMode( 4, OUTPUT      ); // LED_01
pinMode( 5, OUTPUT      ); // LED_02

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

if (test.event_press_short() == 1) {digitalWrite(4, !digitalRead(4));}
if (test.event_press_long () == 1) {digitalWrite(5, !digitalRead(5));}

}

