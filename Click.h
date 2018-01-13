
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Click.h - class Click, logical block.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef Click_h
#define Click_h

#include <Arduino.h>

struct click_t{
unsigned long timestamp_system      ; // снимок системного времени
unsigned long duration_bounce       ; // длительность фильтра дребезга               кнопки
unsigned long duration_click_Db     ; // длительность двойного щелчка                кнопки
unsigned long duration_inactivity_Up; // длительность таймера неактивности ненажатой кнопки
unsigned long duration_inactivity_Dn; // длительность таймера неактивности   нажатой кнопки
unsigned long duration_press        ; // длительность длинного нажатия               кнопки
boolean       state_hard            ; // аппаратное состояние                        кнопки
};

class Click {

private:

unsigned long timestamp_bounce_;
unsigned long timestamp_click_ ;

void          timestamp_bounce(unsigned long t) {timestamp_bounce_ = t;}
void          timestamp_click (unsigned long t) {timestamp_click_  = t;}

struct {
unsigned counter_Db       : 1; // счётчик двойного щелчка            кнопки
unsigned state_button     : 1; // состояние                          кнопки
unsigned state_inactivity : 1; // состояние таймера неактивности     кнопки
unsigned state_press      : 1; // состояние таймера длинного нажатия кнопки
unsigned event_click      : 1; // событие нажатия/отпускания         кнопки
unsigned event_click_Db   : 1; // событие двойного щелчка            кнопки
unsigned event_inactivity : 1; // событие           неактивности     кнопки
unsigned event_press      : 1; // событие           длинного нажатия кнопки
} click;

void     counter_Db      (boolean bit) {click.counter_Db       = bit;}
void     state_button    (boolean bit) {click.state_button     = bit;}
void     state_inactivity(boolean bit) {click.state_inactivity = bit;}
void     state_press     (boolean bit) {click.state_press      = bit;}
void     event_click     (boolean bit) {click.event_click      = bit;}
void     event_click_Db  (boolean bit) {click.event_click_Db   = bit;}
void     event_inactivity(boolean bit) {click.event_inactivity = bit;}
void     event_press     (boolean bit) {click.event_press      = bit;}

public:

unsigned long timestamp_bounce() {return timestamp_bounce_;}
unsigned long timestamp_click () {return timestamp_click_ ;}

boolean  counter_Db         () {return  click.counter_Db      ;}
boolean  state_button       () {return  click.state_button    ;}
boolean  state_inactivity   () {return  click.state_inactivity;}
boolean  state_press        () {return  click.state_press     ;}
boolean  event_click        () {return  click.event_click     ;}
boolean  event_click_Db     () {return  click.event_click_Db  ;}
boolean  event_inactivity   () {return  click.event_inactivity;}
boolean  event_press        () {return  click.event_press     ;}

boolean  state_inactivity_Up() {return (state_inactivity() == 1 && state_button() == 0);}
boolean  state_inactivity_Dn() {return (state_inactivity() == 1 && state_button() == 1);}
boolean  event_click_Up     () {return (event_click     () == 1 && state_button() == 0);}
boolean  event_click_Dn     () {return (event_click     () == 1 && state_button() == 1);}
boolean  event_inactivity_Up() {return (event_inactivity() == 1 && state_button() == 0);}
boolean  event_inactivity_Dn() {return (event_inactivity() == 1 && state_button() == 1);}
boolean  event_press_short  () {return (event_click_Up  () == 1 && state_press () == 1);}
boolean  event_press_long   () {return (event_press     () == 1 && state_button() == 1);}

void reset_events() {
event_click     (0);
event_click_Db  (0);
event_inactivity(0);
event_press     (0);
}

void reset(click_t &in_Click) {
timestamp_bounce(in_Click.timestamp_system);
timestamp_click (in_Click.timestamp_system);
counter_Db                              (0);
state_button    (in_Click.state_hard      );
state_inactivity                        (0);
state_press                             (0);
reset_events();
}

void read(click_t &in_Click) {
reset_events();
if  (state_button() == in_Click.state_hard) timestamp_bounce(in_Click.timestamp_system);
else
if  (in_Click.timestamp_system - timestamp_bounce() >= in_Click.duration_bounce) {timestamp_click(in_Click.timestamp_system);
                                                                                                                        state_button    (in_Click.state_hard);
                                                                                                                        state_inactivity(1); event_click     (1);
if  (state_button() == 1) {state_press(1); counter_Db(!counter_Db()); if (counter_Db() == 0) event_click_Db(1);}}
if  (counter_Db         () != 0 && in_Click.timestamp_system - timestamp_click () >= in_Click.duration_click_Db      )  counter_Db      (0);
if ((state_inactivity_Up() != 0 && in_Click.timestamp_system - timestamp_click () >= in_Click.duration_inactivity_Up)
||  (state_inactivity_Dn() != 0 && in_Click.timestamp_system - timestamp_click () >= in_Click.duration_inactivity_Dn)) {state_inactivity(0); event_inactivity(1);}
if  (state_press        () != 0 && in_Click.timestamp_system - timestamp_click () >= in_Click.duration_press         ) {state_press     (0); event_press     (1);}}

Click() {
timestamp_bounce(0);
timestamp_click (0);
counter_Db      (0);
state_button    (0);
state_inactivity(0);
state_press     (0);
reset_events();
}

};

#endif

