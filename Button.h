
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Button.h - shell for to class Click, buttons.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef Button_h
#define Button_h

#include <Click.h>

#define button(...) button_(sizeof((byte[]){__VA_ARGS__}),__VA_ARGS__)

class Button {

private:

click_t in_Click;

void          timestamp_system(unsigned long t) {in_Click.timestamp_system = t;}
void          state_hard      (boolean       p) {in_Click.state_hard       = p;}

unsigned long timestamp_system()         {return in_Click.timestamp_system;}
boolean       state_hard      ()         {return in_Click.state_hard      ;}

byte  n_pin_; // количество пинов кнопок
byte   *pin ; // массив     пинов кнопок

void detach_pin() {if (n_pin_ != 0) {delete [] pin;           n_pin_ = 0;}}
void create_pin() {if (n_pin_ != 0)            pin = new byte[n_pin_]   ; }

Click *button; // массив экземпляров класса Click

void detach_button() {if (n_pin_ != 0) {delete [] button;
for (byte i = 0; i < n_pin_; i++) digitalWrite(pin[i], LOW);}}

void create_button() {if (n_pin_ != 0) button = new Click[n_pin_];}

boolean pull; // подтяжка пина: 0 - GND 1 - Vcc
boolean N_z ; // контакты кнопки: 0 - нормально разомкнуты 1 - нормально замкнуты

void read(boolean mode) {
unsigned long timestamp_new = millis();
if (mode == 0 || timestamp_new != timestamp_system()) {
timestamp_system(timestamp_new);
for (byte i = 0; i < n_pin_; i++) {
if (mode == 0  ) {pinMode     (pin[i], INPUT);
                  digitalWrite(pin[i],  pull);}
if (pull != N_z)  state_hard(!digitalRead(pin[i]));
else              state_hard( digitalRead(pin[i]));
if (mode == 1  )  button[i].read (in_Click);
else              button[i].reset(in_Click);
}}
else {for (byte i = 0; i < n_pin_; i++) button[i].reset_events();}
}

public:

void pullDn() {pull = 0; read(0);} // подтяжка пинов строк к GND
void pullUp() {pull = 1; read(0);} // подтяжка пинов строк к Vcc
void NO    () {N_z  = 0; read(0);} // нормально разомкнутые контакты (N.O. Normal Open  )
void NC    () {N_z  = 1; read(0);} // нормально   замкнутые контакты (N.C. Normal Closed)

void duration_bounce       (unsigned long t) {in_Click.duration_bounce        = t;}
void duration_click_Db     (unsigned long t) {in_Click.duration_click_Db      = t;}
void duration_inactivity_Up(unsigned long t) {in_Click.duration_inactivity_Up = t;}
void duration_inactivity_Dn(unsigned long t) {in_Click.duration_inactivity_Dn = t;}
void duration_press        (unsigned long t) {in_Click.duration_press         = t;}

void button_(byte n, ...) {
detach_button();
detach_pin();
n_pin_ = n;
create_pin();
va_list pin_list;
va_start(pin_list, n);
for (byte i = 0; i < n; i++) pin[i] = va_arg(pin_list, int);
va_end (pin_list);
create_button();
read(0);
}

void reset() {read(0);}
void read () {read(1);}

byte n_pin() {return n_pin_;} // количество кнопок

boolean state_button       (byte i) {if (i < n_pin()) return button[i].state_button       (); else return 0;}
boolean state_inactivity_Up(byte i) {if (i < n_pin()) return button[i].state_inactivity_Up(); else return 0;}
boolean state_inactivity_Dn(byte i) {if (i < n_pin()) return button[i].state_inactivity_Dn(); else return 0;}
boolean event_click_Up     (byte i) {if (i < n_pin()) return button[i].event_click_Up     (); else return 0;}
boolean event_click_Dn     (byte i) {if (i < n_pin()) return button[i].event_click_Dn     (); else return 0;}
boolean event_click_Db     (byte i) {if (i < n_pin()) return button[i].event_click_Db     (); else return 0;}
boolean event_inactivity_Up(byte i) {if (i < n_pin()) return button[i].event_inactivity_Up(); else return 0;}
boolean event_inactivity_Dn(byte i) {if (i < n_pin()) return button[i].event_inactivity_Dn(); else return 0;}
boolean event_press_short  (byte i) {if (i < n_pin()) return button[i].event_press_short  (); else return 0;}
boolean event_press_long   (byte i) {if (i < n_pin()) return button[i].event_press_long   (); else return 0;}

boolean state_button       () {for (byte i = 0; i < n_pin(); i++) {if (button[i].state_button       () == 1) return 1;} return 0;}
boolean state_inactivity_Up() {for (byte i = 0; i < n_pin(); i++) {if (button[i].state_inactivity_Up() == 1) return 1;} return 0;}
boolean state_inactivity_Dn() {for (byte i = 0; i < n_pin(); i++) {if (button[i].state_inactivity_Dn() == 1) return 1;} return 0;}
boolean event_click_Up     () {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_click_Up     () == 1) return 1;} return 0;}
boolean event_click_Dn     () {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_click_Dn     () == 1) return 1;} return 0;}
boolean event_click_Db     () {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_click_Db     () == 1) return 1;} return 0;}
boolean event_inactivity_Up() {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_inactivity_Up() == 1) return 1;} return 0;}
boolean event_inactivity_Dn() {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_inactivity_Dn() == 1) return 1;} return 0;}
boolean event_press_short  () {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_press_short  () == 1) return 1;} return 0;}
boolean event_press_long   () {for (byte i = 0; i < n_pin(); i++) {if (button[i].event_press_long   () == 1) return 1;} return 0;}

Button() {
pull                 = 0 ;
N_z                  = 0 ;
n_pin_               = 0 ;
timestamp_system      (0);
state_hard            (0);
duration_bounce       (0);
duration_click_Db     (0);
duration_inactivity_Up(0);
duration_inactivity_Dn(0);
duration_press        (0);
}

~Button() {
detach_button();
detach_pin   ();
}

};

#endif

