
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for matrix. (version 14.0)
file Matrix.h - shell for to class Click, matrix buttons.
https://klapautsiy.github.io/titanium-bicycle-for-matrix/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <Matrix.h>

Matrix test;

void setup() {
test.NO(); // N.O. Normal Open
// test.NC(); // N.C. Normal Closed
test.pullUp();
// test.pullDn();
test.NKRO();
// test.OKRO();
// test.TKRO();
test.duration_bounce       (  50);
test.duration_click_Db     ( 250);
test.duration_inactivity_Up(5000);
test.duration_inactivity_Dn(1000);
test.duration_press        ( 500);
test.matrix_x(12,15,18,14,16,17,19,20); // arduino pins connected to rows
test.matrix_y( 5, 4, 9, 7, 8);          // arduino pins connected to columns
// test.matrix_x();
// test.matrix_y();
}

void loop() {

test.read();

if (test.state_button       ( 0) == 1) {}
if (test.state_inactivity_Up( 0) == 1) {}
if (test.state_inactivity_Dn( 0) == 1) {}
if (test.event_click_Up     ( 0) == 1) {}
if (test.event_click_Dn     ( 0) == 1) {}
if (test.event_click_Db     ( 0) == 1) {}
if (test.event_inactivity_Up( 0) == 1) {}
if (test.event_inactivity_Dn( 0) == 1) {}
if (test.event_press_short  ( 0) == 1) {}
if (test.event_press_long   ( 0) == 1) {}
//  test....................( *) == 1) {}
if (test.state_button       (39) == 1) {}
if (test.state_inactivity_Up(39) == 1) {}
if (test.state_inactivity_Dn(39) == 1) {}
if (test.event_click_Up     (39) == 1) {}
if (test.event_click_Dn     (39) == 1) {}
if (test.event_click_Db     (39) == 1) {}
if (test.event_inactivity_Up(39) == 1) {}
if (test.event_inactivity_Dn(39) == 1) {}
if (test.event_press_short  (39) == 1) {}
if (test.event_press_long   (39) == 1) {}

if (test.state_button       ()   == 1) {}
if (test.state_inactivity_Up()   == 1) {}
if (test.state_inactivity_Dn()   == 1) {}
if (test.event_click_Up     ()   == 1) {}
if (test.event_click_Dn     ()   == 1) {}
if (test.event_click_Db     ()   == 1) {}
if (test.event_inactivity_Up()   == 1) {}
if (test.event_inactivity_Dn()   == 1) {}
if (test.event_press_short  ()   == 1) {}
if (test.event_press_long   ()   == 1) {}

}

