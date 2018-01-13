
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Button.h - shell for to class Click, buttons.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <Button.h>

Button test;

void setup() {
test.NO(); // N.O. Normal Open
// test.NC(); // N.C. Normal Closed
test.pullUp();
// test.pullDn();
test.duration_bounce       (  50);
test.duration_click_Db     ( 250);
test.duration_inactivity_Up(5000);
test.duration_inactivity_Dn(1000);
test.duration_press        ( 500);
test.button( 5, 4, 9, 7, 8); // arduino pins connected to button
// test.button();
}

void loop() {
test.read();
if (test.state_button       (0) == 1) {}
if (test.state_inactivity_Up(0) == 1) {}
if (test.state_inactivity_Dn(0) == 1) {}
if (test.event_click_Up     (0) == 1) {}
if (test.event_click_Dn     (0) == 1) {}
if (test.event_click_Db     (0) == 1) {}
if (test.event_inactivity_Up(0) == 1) {}
if (test.event_inactivity_Dn(0) == 1) {}
if (test.event_press_short  (0) == 1) {}
if (test.event_press_long   (0) == 1) {}
//  test....................(*) == 1) {}
if (test.state_button       (4) == 1) {}
if (test.state_inactivity_Up(4) == 1) {}
if (test.state_inactivity_Dn(4) == 1) {}
if (test.event_click_Up     (4) == 1) {}
if (test.event_click_Dn     (4) == 1) {}
if (test.event_click_Db     (4) == 1) {}
if (test.event_inactivity_Up(4) == 1) {}
if (test.event_inactivity_Dn(4) == 1) {}
if (test.event_press_short  (4) == 1) {}
if (test.event_press_long   (4) == 1) {}

if (test.state_button       ()  == 1) {}
if (test.state_inactivity_Up()  == 1) {}
if (test.state_inactivity_Dn()  == 1) {}
if (test.event_click_Up     ()  == 1) {}
if (test.event_click_Dn     ()  == 1) {}
if (test.event_click_Db     ()  == 1) {}
if (test.event_inactivity_Up()  == 1) {}
if (test.event_inactivity_Dn()  == 1) {}
if (test.event_press_short  ()  == 1) {}
if (test.event_press_long   ()  == 1) {}

}

