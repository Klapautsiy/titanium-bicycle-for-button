
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Matrix.h - shell for to class Click, matrix buttons.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <Matrix.h>

Matrix *test;

boolean check_matrix = 0;

void setup() {}

void loop() {
if (1 /*condition create or detach matrix*/) create_matrix(); else detach_matrix();
matrix();
}

void matrix() {
if (check_matrix == 1) {

test->read();

if (test->state_button       ( 0) == 1) {}
if (test->state_inactivity_Up( 0) == 1) {}
if (test->state_inactivity_Dn( 0) == 1) {}
if (test->event_click_Up     ( 0) == 1) {}
if (test->event_click_Dn     ( 0) == 1) {}
if (test->event_click_Db     ( 0) == 1) {}
if (test->event_inactivity_Up( 0) == 1) {}
if (test->event_inactivity_Dn( 0) == 1) {}
if (test->event_press_short  ( 0) == 1) {}
if (test->event_press_long   ( 0) == 1) {}
//  test->...................( *) == 1) {}
if (test->state_button       (39) == 1) {}
if (test->state_inactivity_Up(39) == 1) {}
if (test->state_inactivity_Dn(39) == 1) {}
if (test->event_click_Up     (39) == 1) {}
if (test->event_click_Dn     (39) == 1) {}
if (test->event_click_Db     (39) == 1) {}
if (test->event_inactivity_Up(39) == 1) {}
if (test->event_inactivity_Dn(39) == 1) {}
if (test->event_press_short  (39) == 1) {}
if (test->event_press_long   (39) == 1) {}

if (test->state_button       ()   == 1) {}
if (test->state_inactivity_Up()   == 1) {}
if (test->state_inactivity_Dn()   == 1) {}
if (test->event_click_Up     ()   == 1) {}
if (test->event_click_Dn     ()   == 1) {}
if (test->event_click_Db     ()   == 1) {}
if (test->event_inactivity_Up()   == 1) {}
if (test->event_inactivity_Dn()   == 1) {}
if (test->event_press_short  ()   == 1) {}
if (test->event_press_long   ()   == 1) {}

}
}

void create_matrix() {
if (check_matrix == 0) {

test = new Matrix;

test->NO(); // N.O. Normal Open
// test->NC(); // N.C. Normal Closed
test->pullUp();
// test->pullDn();
test->NKRO();
// test->OKRO();
// test->TKRO();
test->duration_bounce       (  50);
test->duration_click_Db     ( 250);
test->duration_inactivity_Up(5000);
test->duration_inactivity_Dn(1000);
test->duration_press        ( 500);
test->matrix_x(12,15,18,14,16,17,19,20); // arduino pins connected to rows
test->matrix_y( 5, 4, 9, 7, 8);          // arduino pins connected to columns
// test->matrix_x();
// test->matrix_y();

check_matrix = 1;
}
}

void detach_matrix() {
if (check_matrix == 1) {
delete test;
check_matrix = 0;
}
}

