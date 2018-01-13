
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
titanium bicycle for button. (version 14.0)
file Matrix.h - shell for to class Click, matrix buttons.
https://klapautsiy.github.io/titanium-bicycle-for-button/
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#ifndef Matrix_h
#define Matrix_h

#include <Click.h>

#define matrix_x(...) matrix_x_((sizeof((byte[]){0,##__VA_ARGS__}) - 1),##__VA_ARGS__)
#define matrix_y(...) matrix_y_((sizeof((byte[]){0,##__VA_ARGS__}) - 1),##__VA_ARGS__)

class Matrix {

private:

click_t in_Click;

void          timestamp_system(unsigned long t) {in_Click.timestamp_system = t;}
void          state_hard      (boolean       p) {in_Click.state_hard       = p;}

unsigned long timestamp_system()         {return in_Click.timestamp_system;}
boolean       state_hard      ()         {return in_Click.state_hard      ;}

byte  n_pin_x; // количество пинов столбцов матрицы кнопок
byte  n_pin_y; // количество пинов строк    матрицы кнопок

byte   *pin_x; // массив     пинов столбцов матрицы кнопок
byte   *pin_y; // массив     пинов строк    матрицы кнопок

void detach_pin_x() {if (n_pin_x != 0) {delete [] pin_x;           n_pin_x = 0;}}
void detach_pin_y() {if (n_pin_y != 0) {delete [] pin_y;           n_pin_y = 0;}}
void create_pin_x() {if (n_pin_x != 0)            pin_x = new byte[n_pin_x]   ; }
void create_pin_y() {if (n_pin_y != 0)            pin_y = new byte[n_pin_y]   ; }

Click *matrix; // массив экземпляров класса Click

byte n_pin_() {return (n_pin_x * n_pin_y);} // количество кнопок

void detach_matrix() {if (n_pin_() != 0) {delete [] matrix;
for (byte y = 0; y < n_pin_y; y++) digitalWrite(pin_y[y], LOW );}}

void create_matrix() {if (n_pin_() != 0) matrix = new Click[n_pin_()];}

boolean pull ; // подтяжка пина: 0 - GND 1 - Vcc
boolean N_z  ; // у кнопки контакты: 0 - нормально разомкнуты 1 - нормально замкнуты
byte    n_KRO; // режим работы матрицы: 0 - NKRO 1 - 1KRO 2 - 2KRO

boolean state_KRO() {
byte n = 0;
for (byte i = 0; i < n_pin_(); i++) {
n += matrix[i].state_button();
if (n == n_KRO) return 1;}
                return 0;}

void read(boolean mode) {
unsigned long    timestamp_system_ = millis();
if (n_pin_() != 0) {
if (mode == 0 || timestamp_system_ != timestamp_system()) {
timestamp_system(timestamp_system_);
boolean                                 flag_KRO = 0;
for (byte x = 0; x < n_pin_x; x++) {
                     digitalWrite(pin_x[x], !pull );
                     pinMode     (pin_x[x], OUTPUT);
for (byte y = 0; y < n_pin_y; y++) {
if (mode     == 0)  {pinMode     (pin_y[y], INPUT );
                     digitalWrite(pin_y[y],  pull );}
if (pull     != N_z) state_hard(!digitalRead(pin_y[y]));
else                 state_hard( digitalRead(pin_y[y]));
if (   n_KRO != 0 && state_hard() == 1) {
if (flag_KRO != 1 && state_KRO () == 1) flag_KRO = 1;
if (flag_KRO == 1)   state_hard(matrix[y * n_pin_x + x].state_button());}
if (mode     == 1)              matrix[y * n_pin_x + x].read (in_Click);
else                            matrix[y * n_pin_x + x].reset(in_Click);}
                     pinMode     (pin_x[x], INPUT );
                     digitalWrite(pin_x[x], LOW   );
}}
else {for (byte i = 0; i < n_pin_(); i++) matrix[i].reset_events();}
}}

public:

void pullDn() {pull  = 0; read(0);} // подтяжка пинов строк к GND
void pullUp() {pull  = 1; read(0);} // подтяжка пинов строк к Vcc
void NO    () {N_z   = 0; read(0);} // кнопка с нормально разомкнутыми контактами (N.O. Normal Open  )
void NC    () {N_z   = 1; read(0);} // кнопка с нормально   замкнутыми контактами (N.C. Normal Closed)
void NKRO  () {n_KRO = 0; read(0);} // режим No-Key Rollover
void OKRO  () {n_KRO = 1; read(0);} // режим  1-Key Rollover
void TKRO  () {n_KRO = 2; read(0);} // режим  2-Key Rollover

void duration_bounce       (unsigned long t) {in_Click.duration_bounce        = t;}
void duration_click_Db     (unsigned long t) {in_Click.duration_click_Db      = t;}
void duration_inactivity_Up(unsigned long t) {in_Click.duration_inactivity_Up = t;}
void duration_inactivity_Dn(unsigned long t) {in_Click.duration_inactivity_Dn = t;}
void duration_press        (unsigned long t) {in_Click.duration_press         = t;}

void matrix_x_(byte n, ...) {
detach_matrix();
detach_pin_x();
n_pin_x = n;
create_pin_x();
va_list pin_list;
va_start(pin_list, n);
for (byte i = 0; i < n; i++) pin_x[i] = va_arg(pin_list, int);
va_end (pin_list);
create_matrix();
read(0);
}

void matrix_y_(byte n, ...) {
detach_matrix();
detach_pin_y();
n_pin_y = n;
create_pin_y();
va_list pin_list;
va_start(pin_list, n);
for (byte i = 0; i < n; i++) pin_y[i] = va_arg(pin_list, int);
va_end (pin_list);
create_matrix();
read(0);
}

void reset() {read(0);}
void read () {read(1);}

byte n_pin() {return n_pin_();} // количество кнопок

boolean state_button       (byte i) {if (i < n_pin_()) return matrix[i].state_button       (); else return 0;}
boolean state_inactivity_Up(byte i) {if (i < n_pin_()) return matrix[i].state_inactivity_Up(); else return 0;}
boolean state_inactivity_Dn(byte i) {if (i < n_pin_()) return matrix[i].state_inactivity_Dn(); else return 0;}
boolean event_click_Up     (byte i) {if (i < n_pin_()) return matrix[i].event_click_Up     (); else return 0;}
boolean event_click_Dn     (byte i) {if (i < n_pin_()) return matrix[i].event_click_Dn     (); else return 0;}
boolean event_click_Db     (byte i) {if (i < n_pin_()) return matrix[i].event_click_Db     (); else return 0;}
boolean event_inactivity_Up(byte i) {if (i < n_pin_()) return matrix[i].event_inactivity_Up(); else return 0;}
boolean event_inactivity_Dn(byte i) {if (i < n_pin_()) return matrix[i].event_inactivity_Dn(); else return 0;}
boolean event_press_short  (byte i) {if (i < n_pin_()) return matrix[i].event_press_short  (); else return 0;}
boolean event_press_long   (byte i) {if (i < n_pin_()) return matrix[i].event_press_long   (); else return 0;}

boolean state_button       () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].state_button       () == 1) return 1;} return 0;}
boolean state_inactivity_Up() {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].state_inactivity_Up() == 1) return 1;} return 0;}
boolean state_inactivity_Dn() {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].state_inactivity_Dn() == 1) return 1;} return 0;}
boolean event_click_Up     () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_click_Up     () == 1) return 1;} return 0;}
boolean event_click_Dn     () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_click_Dn     () == 1) return 1;} return 0;}
boolean event_click_Db     () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_click_Db     () == 1) return 1;} return 0;}
boolean event_inactivity_Up() {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_inactivity_Up() == 1) return 1;} return 0;}
boolean event_inactivity_Dn() {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_inactivity_Dn() == 1) return 1;} return 0;}
boolean event_press_short  () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_press_short  () == 1) return 1;} return 0;}
boolean event_press_long   () {for (byte i = 0; i < n_pin_(); i++) {if (matrix[i].event_press_long   () == 1) return 1;} return 0;}

Matrix() {
pull                 = 0 ;
N_z                  = 0 ;
n_KRO                = 0 ;
n_pin_x              = 0 ;
n_pin_y              = 0 ;
timestamp_system      (0);
state_hard            (0);
duration_bounce       (0);
duration_click_Db     (0);
duration_inactivity_Up(0);
duration_inactivity_Dn(0);
duration_press        (0);
}

~Matrix() {
detach_matrix();
detach_pin_x ();
detach_pin_y ();
}

};

#endif

