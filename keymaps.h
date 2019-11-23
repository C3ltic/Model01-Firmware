/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  */

// http://www.keyboard-layout-editor.com/##@_name=keyboard.io%20Model%2001%20-%20proposed%20B%C3%89PO%20layout&author=Yoann%20Brosseau%20%3Cyoann.brosseau%2F@gmail.com%3E&switchMount=alps&switchBrand=matias&switchType=PG155B01&pcb:true&css=.keyboardio%20%7B%20%7D%0A%0A.keyboardio-logo%2F:after%20%7B%0A%20%20%20%20background%2F:%20inherit%2F%3B%0A%20%20%20%20content%2F:'%5C00a0'%2F%3B%20%0A%20%20%20%20display%2F:inline-block%2F%3B%20%0A%20%20%20%20width%2F:%202em%2F%3B%20%0A%20%20%20%20height%2F:%202em%2F%3B%20%0A%20%20%20%20background-size%2F:%202em%2F%3B%20%0A%20%20%20%20background-image%2F:%20url(http%2F:%2F%2F%2F%2F67.media.tumblr.com%2F%2Favatar%2F_ddfdafa42fef%2F_128.png)%2F%3B%0A%7D%0A%3B&@_x:3&c=%23d9dae0&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24&a:0%3B&=3%0A%C2%BB%0A%E2%80%9C%0A%3E%0A%0AF3&_x:10&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad%3B&=8%0A-%0A%C2%BC%0A%E2%88%92%0A%0A8%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Stop'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&x:2&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%3B&=2%0A%C2%AB%0A%E2%80%9C%0A%3C%0A%0AF2&_x:1%3B&=4%0A(%0A%E2%89%A4%0A%5B%0A%0AF4&_x:8&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad%3B&=7%0A+%0A%C2%AC%0A%C2%B1%0A%0A7%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Play-Pause'%3E%3C%2F%2Fi%3E&_x:1%3B&=9%0A%2F%2F%0A%C2%BD%0A%C3%B7%0A%0A9%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-FastForward-End'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&x:5&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%3B&=5%0A)%0A%E2%89%A5%0A%5D%0A%0AF5&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&h:1.5%3B&=%23%0A$%0A%C2%B6%0A%E2%80%93%0A%0AF6%0A%0A%0A%0A%0A%0AIns&_x:4&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad&a:4&h:1.5%3B&=%60%0A%25%0A%E2%80%B3%0A%E2%80%B0%0APrtScr&_t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=6%0A%2F@%0A%0A%5E%0A%0A%3Ci%20class%2F='kb%20kb-Line-Start-End'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Rewind-Start'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&t=%23000000&a:7%3B&=Led&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24&a:0%3B&=1%0A%22%0A%E2%80%9E%0A%E2%80%94%0A%0AF1&_x:14%3B&=0%0A*%0A%C2%BE%0A%C3%97%0A%0A-&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad&a:4%3B&=%C2%B0%0A%2F=%0A%E2%80%B2%0A%E2%89%A0%0ASleep%3B&@_y:-0.375&x:3&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=P%0Ap%0A%C2%A7%0A%2F&%0A%0AF9%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Arrows-Bottom-3'%3E%3C%2F%2Fi%3E&_x:10%3B&=D%0Ad%0A%C3%90%0A%C3%B0%0A%0A5%0A%0A%0A%0A%0A%0AMClick%3B&@_y:-0.875&x:2%3B&=%C3%89%0A%C3%A9%0A%CB%9D%0A'%0A%0AF8%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='fa%20fa-arrow-up'%3E%3C%2F%2Fi%3E&_x:1%3B&=O%0Ao%0A%C5%92%0A%C5%93%0A%0AF10%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-Page-Up-3'%3E%3C%2F%2Fi%3E&_x:8&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad%3B&=V%0Av%0A%0A%CB%87%0A%0A4%0A%0A%0A%0A%0A%0AM.%20%3Ci%20class%2F='fa%20fa-arrow-up'%3E%3C%2F%2Fi%3E&_x:1%3B&=L%0Al%0A%0A%2F%2F%0A%0A6%0A%0A%0A%0A%0A%0Awarp%20NW%3B&@_y:-0.875&x:5&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%3B&=%C3%88%0A%C3%A8%0A%60%0A%60%0A%0AF11&_x:6&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad%3B&=!%0A%5E%0A%0A%C2%A1%0A%0A%3Ci%20class%2F='kb%20kb-Line-Start-End'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0A%0AMClick%3B&@_y:-0.875&t=%23000000%0A%0A%0A%0A%230075ad&a:7%3B&=Num%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Line-Start-End'%3E%3C%2F%2Fi%3E&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=B%0Ab%0A%C2%A6%0A%7C%0A%0AF7%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Arrows-Top-3'%3E%3C%2F%2Fi%3E&_x:14%3B&=J%0Aj%0A%C4%B2%0A%C4%B3%0A%0A+%0A%0A%0A%0A%0A%0Awarp%20NE&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad&a:4%3B&=Z%0Az%0A%C6%8F%0A%C9%99%0AScroll%20lk%3B&@_y:-0.625&x:6&t=%23000000%0A%0A%0A%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:3&h:1.5%3B&=%3Ci%20class%2F='kb%20kb-Line-Start-End'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0AF12%0A%0A%0A%0A%0A%0ADel&_x:4&t=%23000000&a:7&h:1.5%3B&=%3Ci%20class%2F='kb%20kb-Return-4'%3E%3C%2F%2Fi%3E%3B&@_y:-0.75&x:3&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad&a:4%3B&=I%0Ai%0A%CB%99%0A%22%0A%3Ci%20class%2F='fa%20fa-arrow-right'%3E%3C%2F%2Fi%3E&_x:10&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=S%0As%0A%E1%BA%9E%0A%C3%9F%0A%0A2%0A%0A%0A%0A%0A%0AM.%20%3Ci%20class%2F='fa%20fa-arrow-right'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&x:2&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad&a:4%3B&=U%0Au%0A%C3%99%0A%C3%B9%0A%3Ci%20class%2F='fa%20fa-arrow-down'%3E%3C%2F%2Fi%3E&_x:1&n:true%3B&=E%0Ae%0A%C2%A4%0A%E2%82%AC%0A%3Ci%20class%2F='kb%20kb-Unicode-Page-Down-3'%3E%3C%2F%2Fi%3E&_x:8&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0&n:true%3B&=T%0At%0A%C3%9E%0A%C3%BE%0A%0A1%0A%0A%0A%0A%0A%0AM.%20%3Ci%20class%2F='fa%20fa-arrow-down'%3E%3C%2F%2Fi%3E&_x:1%3B&=R%0Ar%0A%E2%84%A2%0A%C2%AE%0A%0A3%0A%0A%0A%0A%0A%0Awarp%20SW%3B&@_y:-0.875&x:5&t=%23ff00e9%0A%23000000%0A%0A%23001dff&a:4%3B&=%2F%3B%0A,%0A%0A%E2%80%99&_x:6&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad%3B&=C%0Ac%0A%C5%BF%0A%C2%A9%0AM.%20%3Ci%20class%2F='fa%20fa-arrow-left'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&t=%23ff00e9%0A%236d0000%0A%230088ff%0A%23001dff%3B&=%C3%87%0A%C3%A7%0A,%0A%C2%B8&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad%3B&=A%0Aa%0A%C3%86%0A%C3%A6%0A%3Ci%20class%2F='fa%20fa-arrow-left'%3E%3C%2F%2Fi%3E&_x:14&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=N%0An%0A%0A~%0A%0A%2F=%0A%0A%0A%0A%0A%0Awarp%20SE&_t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad%3B&=M%0Am%0A%C2%BA%0A%C2%AF%0A%0A%3Ci%20class%2F='kb%20kb-Return-4'%3E%3C%2F%2Fi%3E%0A%0A%0A%0A%0A%0APause%3B&@_y:-0.375&x:3&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%230075ad&a:4%3B&=X%0Ax%0A%0A%7D%0ACopy&_x:10&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=G%0Ag%0A%0A%C2%B5%0A%0A.%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='fa%20fa-volume-up'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&x:2&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%230075ad&a:4%3B&=Y%0Ay%0A%0A%7B%0ACut&_x:1&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%230075ad%3B&=%2F:%0A.%0A%C2%B7%0A%E2%80%A6%0APaste&_x:8&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=Q%0Aq%0A%0A%C2%B0%0A%0A0%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Multimedia-Mute-3'%3E%3C%2F%2Fi%3E&_x:1&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%3B&=h%0AH%0A%E2%80%A1%0A%E2%80%A0%0A%0A*%3B&@_y:-0.875&x:5&t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%230075ad&a:4%3B&=K%0Ak%0A%0A~%0ARedo&_t=%23000000&a:7%3B&=Esc&_x:4%3B&=%3Ci%20class%2F='keyboardio%20keyboardio-logo'%3E%3C%2F%2Fi%3E&_t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&a:0%3B&=%3F%0A'%0A%0A%C2%BF%0A%0AIns%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='fa%20fa-volume-down'%3E%3C%2F%2Fi%3E%3B&@_y:-0.875&t=%23ff00e9%0A%23000000%0A%0A%23001dff&a:4%3B&=%C3%8A%0A%C3%AA%0A%0A%2F%2F&_t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%230075ad%3B&=%C3%80%0A%C3%A0%0A%0A%5C%0AUndo&_x:14&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24&a:0%3B&=F%0Af%0A%C2%AA%0A%CB%9B%0A%0A%2F%2F&_t=%23ff00e9%0A%23000000%0A%0A%23001dff%0A%0A%23b81b24%3B&=W%0Aw%0A%0A%CB%98%0A%0A%3Ci%20class%2F='kb%20kb-Return-4'%3E%3C%2F%2Fi%3E%3B&@_y:0.875&x:0.25&t=%23ff00e9%0A%23000000%0A%230088ff%0A%23001dff%0A%0A%23b81b24%0A%0A%0A%0A%0A%0A%230075ad&w:2&h:2%3B&=Shift%0ANorm%0AShift%20+%3Cbr%3EAlt-Gr%0AAlt-Gr%0A%0ANum%0A%0A%0A%0A%0A%0AFn%3B&@_r:15&rx:6.5&ry:4.25&y:0.5&x:-2&t=%23000000&a:7%3B&=Ctrl%3B&@_r:20&y:-1&x:-0.75&t=%23000000%0A%0A%0A%0A%230075ad%3B&=%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%0A%0A%0AL.Click%3B&@_y:0.75&x:-0.5&t=%23000000&w:1.25&h:1.25%3B&=Fn%3B&@_r:25&y:-2.75&x:0.5&t=%23000000%0A%0A%0A%0A%230075ad%3B&=Shift%0A%0A%0A%0ACaps%3B&@_r:30&y:-1&x:1.75&t=%23000000%3B&=Cmd%3B&@_r:-30&y:1.3499999999999996&x:1.25%3B&=Alt%3B&@_r:-25&y:-1.25&x:2.75&t=%23000000%0A%0A%0A%0A%230075ad%3B&=Shift%0A%0A%0A%0ACaps%3B&@_r:-20&y:-1.3499999999999996&x:4.25%3B&=Space%0A%0A%0A%0AR.Click%3B&@_y:0.6500000000000004&x:3.5&t=%23000000&w:1.25&h:1.25%3B&=Fn%3B&@_r:-15&y:-3.1500000000000004&x:5.75%3B&=Alt-Gr

// Support BÉPO definitions 
#include "lang/FR-bepo-celtic.h"


/*
 * Define our layer names. These must match the layer structure below.
 */

enum { BEPO, QWERTY, GAMING, NUMPAD, FUNCTION }; // layers

/*
 * Enable and disable layers by editing the various include directives below.
 * Beware that the include directives MUST be on a line by themselves.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(
	[BEPO] = KEYMAP_STACKED
  (___,               Key_frb_Quote,   Key_frb_DeOQuote, Key_frb_DeCQuote, Key_frb_Oparenthesi, Key_frb_Cparenthesi, Key_frb_Dollar,
   LockLayer(NUMPAD), Key_frb_B,       Key_frb_E_Acute,  Key_frb_P,        Key_frb_O,           Key_frb_E_Grave,     Key_Tab,
   Key_frb_W,         Key_frb_A,       Key_frb_U,        Key_frb_I,        Key_frb_E,           Key_frb_Comma,
   Key_frb_E_umlaut,  Key_frb_A_Grave, Key_frb_Y,        Key_frb_X,        Key_frb_Period,      Key_frb_K,           Key_Escape,
   Key_LeftAlt,   Key_Backspace,   Key_LeftShift,    Key_LeftGui,
   ShiftToLayer(FUNCTION),

   Key_frb_Percent,   Key_frb_At,         Key_frb_Plus, Key_frb_Minus, Key_frb_Slash, Key_frb_Multiply, Key_frb_Equals,
   Key_Enter,         Key_frb_Circumflex, Key_frb_V,    Key_frb_D,     Key_frb_L,     Key_frb_J,        Key_frb_Z,
                      Key_frb_C,          Key_frb_T,    Key_frb_S,     Key_frb_R,     Key_frb_N,        Key_frb_M,
   Key_LEDEffectNext, Key_frb_Question,   Key_frb_Q,    Key_frb_G,     Key_frb_H,     Key_frb_F,        Key_frb_C_Cedilla,
   Key_LeftControl, Key_RightShift, Key_Spacebar, Key_frb_ALTGR,
   ShiftToLayer(FUNCTION)),

  [QWERTY] = KEYMAP_STACKED
  (___,             Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Quote,       Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,      Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown,    Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,      Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION)),

  [GAMING] = KEYMAP_STACKED
  (___,             Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Tab,         Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Y,
   Key_LeftShift,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_LeftShift,   Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Spacebar, Key_LeftAlt, Key_LeftShift,
   ShiftToLayer(FUNCTION),

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,      Key_0,         LockLayer(NUMPAD),
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   Key_RightAlt,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Backspace, Key_RightControl,
   ShiftToLayer(FUNCTION)),
  


  [NUMPAD] = KEYMAP_STACKED
   (___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___, ___, ___, ___,
	___,

   M(MACRO_VERSION_INFO),   Key_Tab,    Key_Keypad7,    Key_Keypad8,    Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,                     Key_Tab,    Key_Keypad4,    Key_Keypad5,    Key_Keypad6,        Key_KeypadAdd,      ___,
                            ___,        Key_Keypad1,    Key_Keypad2,    Key_Keypad3,        Key_Equals,         Key_Enter,
   ___,                     Key_Insert, Key_Keypad0,    Key_KeypadDot,  Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___),

  [FUNCTION] = KEYMAP_STACKED
  (___,     Key_F1,        Key_F2,        Key_F3,         Key_F4,        Key_F5,       Key_Insert,
   Key_Tab, Key_Home,      Key_UpArrow,   Key_End,        Key_PageUp,    ___,          Key_Delete,
   ___,     Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_PageDown,  ___,
   ___,     Key_frb_Undo,  Key_frb_Cut,   Key_frb_Copy,   Key_frb_Paste, Key_frb_Redo, LockLayer(GAMING),
   ___, Key_Delete, Key_CapsLock, Key_PcApplication,
   ___,

   Key_PrintScreen,   Key_F6,         Key_F7,                   Key_F8,                   Key_F9,                     Key_F10,                 Key_F11,
   System_Sleep,      Key_mouseBtnL,  Key_mouseUp,              Key_mouseBtnR,            Key_mouseWarpNW,            Key_mouseWarpNE,         Key_F12,
                      Key_mouseL,     Key_mouseDn,              Key_mouseR,               Key_mouseWarpSW,            Key_mouseWarpSE,         Consumer_Stop,
   LockLayer(QWERTY), Consumer_Mute,  Consumer_VolumeDecrement, Consumer_VolumeIncrement, Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack,
   ___, Key_RightShift, Key_Enter, ___,
   ___)
)

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*
