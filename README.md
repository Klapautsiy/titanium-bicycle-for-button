<pre>
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

installation:
---------------------
unpack and put the folder with the files in the folder with the libraries Arduino IDE

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Click.h - class Click, logical block.

state_button       () - state of the                                     button
state_inactivity_Up() - state of the inactivity timer of the not pressed button
state_inactivity_Dn() - state of the inactivity timer of the     pressed button
event_click_Up     () - event of the releasing        of the             button
event_click_Dn     () - event of the click            of the             button
event_click_Db     () - event of the double-click     of the             button
event_inactivity_Up() - event of the inactivity       of the not pressed button
event_inactivity_Dn() - event of the inactivity       of the     pressed button
event_press_short  () - event of the short press      of the             button
event_press_long   () - event of the long  press      of the             button

reset(in_Click) - reset button
read (in_Click) - read  button
where
struct click_t in_Click
in_Click.timestamp_system       - system timestamp (millis())
in_Click.state_hard             - hardware state                   of the             button
in_Click.duration_bounce        - duration of the debounce filter  of the             button
in_Click.duration_click_Db      - duration of the double-click     of the             button
in_Click.duration_inactivity_Up - duration of the inactivity timer of the not pressed button
in_Click.duration_inactivity_Dn - duration of the inactivity timer of the     pressed button
in_Click.duration_press         - duration of the long press       of the             button
where
duration(milliseconds)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Button.h - shell for to class Click, buttons.

button(pin, ...) - Arduino pins connected to button

duration_bounce       (t) - set up duration of the debounce filter  of the             button
duration_click_Db     (t) - set up duration of the double-click     of the             button
duration_inactivity_Up(t) - set up duration of the inactivity timer of the not pressed button
duration_inactivity_Dn(t) - set up duration of the inactivity timer of the     pressed button
duration_press        (t) - set up duration of the long press       of the             button
where
t - milliseconds

NO() - button contacts N.O.(Normal Open  )
NC() - button contacts N.C.(Normal Closed)

pullUp()    - pins buttons pull to Vcc
pins button --10KOm----Vcc

pullDn()    - pins buttons pull to GND
pins button --10KOm----GND

reset() - reset button
read()  - read  button

state_button       (i) - state of the                                     button
state_inactivity_Up(i) - state of the inactivity timer of the not pressed button
state_inactivity_Dn(i) - state of the inactivity timer of the     pressed button
event_click_Up     (i) - event of the releasing        of the             button
event_click_Dn     (i) - event of the click            of the             button
event_click_Db     (i) - event of the double-click     of the             button
event_inactivity_Up(i) - event of the inactivity       of the not pressed button
event_inactivity_Dn(i) - event of the inactivity       of the     pressed button
event_press_short  (i) - event of the short press      of the             button
event_press_long   (i) - event of the long  press      of the             button
where
i - index of the button

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Matrix.h - shell for to class Click, matrix buttons.

                                   matrix_y(*,*,*,*,*,*)
                                            | | | | | |
                                            | | | | | |
        ( 0) ( 1) ( 2) ( 3) ( 4) ( 5) ( 6)--^ | | | | |
        ( 7) ( 8) ( 9) (10) (11) (12) (13)----^ | | | |
        (14) (15) (16) (17) (18) (19) (20)------^ | | |
        (21) (22) (23) (24) (25) (26) (27)--------^ | |
        (28) (29) (30) (31) (32) (33) (34)----------^ |
        (35) (36) (37) (38) (39) (40) (41)------------^
         |    |    |    |    |    |    |
         | v--^    |    |    |    |    |
         | | v-----^    |    |    |    |
         | | | v--------^    |    |    |
         | | | | v-----------^    |    |
         | | | | | v--------------^    |
         | | | | | | v-----------------^
         | | | | | | |
matrix_x(*,*,*,*,*,*,*)

matrix_x(pin_x, ...) - Arduino pins connected to columns
matrix_y(pin_y, ...) - Arduino pins connected to rows

duration_bounce       (t) - set up duration of the debounce filter  of the             button
duration_click_Db     (t) - set up duration of the double-click     of the             button
duration_inactivity_Up(t) - set up duration of the inactivity timer of the not pressed button
duration_inactivity_Dn(t) - set up duration of the inactivity timer of the     pressed button
duration_press        (t) - set up duration of the long press       of the             button
where
t - milliseconds

NO() - button contacts N.O.(Normal Open  )
NC() - button contacts N.C.(Normal Closed)

pullUp()  - pins rows pull to Vcc
pins rows --10KOm----Vcc

pullDn()  - pins rows pull to GND
pins rows --10KOm----GND

NKRO() - No-Key Rollover
       v------------v
matrix(**)         (**)button
        ^---diode----^

OKRO() -  1-Key Rollover
TKRO() -  2-Key Rollover
       v-----------v
matrix(**)        (**)button
        ^-----------^

reset() - reset button
read()  - read  button

state_button       (i) - state of the                                     button
state_inactivity_Up(i) - state of the inactivity timer of the not pressed button
state_inactivity_Dn(i) - state of the inactivity timer of the     pressed button
event_click_Up     (i) - event of the releasing        of the             button
event_click_Dn     (i) - event of the click            of the             button
event_click_Db     (i) - event of the double-click     of the             button
event_inactivity_Up(i) - event of the inactivity       of the not pressed button
event_inactivity_Dn(i) - event of the inactivity       of the     pressed button
event_press_short  (i) - event of the short press      of the             button
event_press_long   (i) - event of the long  press      of the             button
where
i - index of the button

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
</pre>
