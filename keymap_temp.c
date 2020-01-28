#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum preonic_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO

#define KC_CN_L (LCTL(KC_LEFT))
#define KC_CN_R (LCTL(KC_RGHT))
#define KC_CN_U (LCTL(KC_UP))
#define KC_CN_D (LCTL(KC_DOWN))
#define KC_CN_Z (LCTL(KC_Z))
#define KC_CN_Y (LCTL(KC_Y))
#define KC_CN_X (LCTL(KC_X))
#define KC_CN_C (LCTL(KC_C))
#define KC_CN_V (LCTL(KC_V))
#define KC_SF11 (LSFT(KC_F11))
#define KC_SF12 (LSFT(KC_F12))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  | Ctrl |  "   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LGUI, KC_RCTL, KC_QUOT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  | Ctrl |  "   |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LGUI, KC_RCTL, KC_QUOT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  | Ctrl |  /   |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT },
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT},
  {KC_GRV,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RALT, KC_LGUI, KC_RCTL, KC_SLSH}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | F10  | F11  | F12  |  Cut | Copy |      |   <  |   >  | Undo | Redo | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   ^  |   |  |   &  |   !  | Paste|      |   (  |   )  |   :  |   "  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   %  |   *  |   +  |   =  | Undo |      |   {  |   }  |   ;  |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   @  |   /  |   -  |   _  | Redo |      |   [  |   ]  |   .  |   \  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | PScr | Ctrl | GUI  | Alt  |      |    Space    |      | Alt  | GUI  | Ctrl | Caps |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_ESC,  KC_F10,  KC_F11,  KC_F12,  KC_CN_X, KC_CN_C, _______, KC_LT,   KC_GT,   KC_CN_Z, KC_CN_Y, KC_INS },
  {KC_TAB,  KC_CIRC, KC_PIPE, KC_AMPR, KC_EXLM, KC_CN_V, _______, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO, KC_DEL },
  {KC_LCTL, KC_PERC, KC_ASTR, KC_PLUS, KC_EQL,  KC_CN_Z, _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_QUOT, KC_ENT },
  {KC_LSFT, KC_AT,   KC_SLSH, KC_MINS, KC_UNDS, KC_CN_Y, _______, KC_LBRC, KC_RBRC, KC_DOT,  KC_BSLS, KC_RSFT},
  {KC_PSCR, KC_LCTL, KC_LGUI, KC_LALT, _______,  KC_SPC,  KC_SPC, _______, KC_RALT, KC_LGUI, KC_RCTL, KC_CAPS}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |      |      |      | PgUp |      |      | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F5  |  F6  |  F7  |  F8  |      |      | Cn-L |  Up  | Cn-R |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  | F10  | F11  | F12  |      | Home | Left | Down | Right|  End |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| SF12 |  Cut | Copy | Paste|      |      | Undo | PgDn | Redo |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NumLk | Ctrl | GUI  | Alt  |      |    Space    |      | Alt  | GUI  | Ctrl |Pause |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, KC_PGUP, _______, _______, KC_INS },
  {KC_TAB,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_CN_L, KC_UP,   KC_CN_R, _______, KC_DEL },
  {KC_LCTL, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_ENT },
  {KC_LSFT, KC_SF12, KC_CN_X, KC_CN_C, KC_CN_V, _______, _______, KC_CN_Z, KC_PGDN, KC_CN_Y, _______, KC_RSFT},
  {KC_NLCK, KC_LCTL, KC_LGUI, KC_LALT, _______,  KC_SPC,  KC_SPC, _______, KC_RALT, KC_LGUI, KC_RCTL, KC_PAUS}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case COLEMAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
          }
          return false;
          break;
        case DVORAK:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
