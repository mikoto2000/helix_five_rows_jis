#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

// * If you want to recognize that you pressed the Adjust key with the Lower / Raise key you can enable this comment out. However, the binary size may be over. *
// #define ADJUST_MACRO_ENABLE

// * If you want to use the Kana key you can enable this comment out. However, the binary size may be over. *
// #define KANA_ENABLE

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  #ifdef KANA_ENABLE
  EISU,
  KANA,
  #endif
  DYNAMIC_MACRO_RANGE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer Mode aliases
#define DL_BAS  DF(_BASE)
#define ML_LOW  MO(_LOWER)
#define ML_RAI  MO(_RAISE)
#define ML_ADJ  MO(_ADJUST)

// Dynamic macros
#include "dynamic_macro.h"
#define DM_REC1 DYN_REC_START1
#define DM_REC2 DYN_REC_START2
#define DM_PLY1 DYN_MACRO_PLAY1
#define DM_PLY2 DYN_MACRO_PLAY2
#define DM_STOP DYN_REC_STOP

// vim like keys
#define KC_C_L RCTL(KC_LEFT)
#define KC_C_R RCTL(KC_RIGHT)
#define KC_C_V RCTL(KC_V)
#define KC_C_Y RCTL(KC_C)

// Hold:Shift
#define KC_TSHS SFT_T(KC_SPC)
#define KC_TSHM SFT_T(JP_MHEN)
#define KC_TSHH SFT_T(JP_HENK)
#define KC_TSHS SFT_T(KC_SPC)

#if HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty JIS Normal
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |  1!  |  2"  |  3#  |  4$  |  5%  |             |  6&  |  7'  |  8(  |  9)  |   0  |  -=  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @`  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;+  |  :*  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   B  |   N  |   M  |  ,<  |  .>  |  /?  |  \_  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | PLAY1| Alt  |Adjust| GUI  |Lower | TSHM | TSHS | TSHS | TSHH |Raise | PLAY1| PLAY2|  ^~  |  \|  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    JP_AT,   \
    KC_LCTL, KC_A,    KC_S,   KC_D,    KC_F,   KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, JP_COLN, \
    KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,    KC_N,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,  \
    DM_PLY1, KC_LALT, ML_ADJ, KC_LGUI, ML_LOW, KC_TSHM, KC_TSHS, KC_TSHS, KC_TSHH, ML_RAI, DM_PLY1, DM_PLY2, JP_CIRC, JP_YEN \
    ),

  /* Lower JIS Normal
   * ,------------------------------------------.             ,-----------------------------------------.
   * |      |      |       |      | END  |      |             |      |      |      |      | HOME |      |
   * |------+------+-------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |C+Right|      |      |      |             | C+y  |      |      |      | C+v  |      |
   * |------+------+-------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |       |      |      |      |             | Left | Down | Up   | Right|      |      |
   * |------+------+-------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |       |      |      |C+Left|      |C+Left|      |      |      |      |      |      |
   * |------+------+-------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |       |      |      |      |      |      |      |      |      |      |      |      |
   * `--------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, \
    _______, XXXXXXX, KC_C_R,  XXXXXXX, XXXXXXX, XXXXXXX,                   KC_C_Y,  XXXXXXX, XXXXXXX, XXXXXXX, KC_C_V,  XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_C_L,  XXXXXXX, KC_C_L,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),

  /* Raise JIS Normal
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |      |      |  -=  |  ^~  |  \|  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  | F10  | F11  | F12  |             |      | Del  | Enter|      |  @`  |  [{  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Esc  |      |      | Esc  |      |             |      | Bksp | Enter|  ;+  |  :*  |  ]}  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |  ,<  |  .>  |  /?  |  \_  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_F1  , KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, JP_CIRC, JP_YEN,  \
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    XXXXXXX, KC_DEL,  KC_ENT,  XXXXXXX, JP_AT,   JP_LBRC, \
    _______, KC_ESC,  XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX,                   XXXXXXX, KC_BSPC, KC_ENT,  KC_SCLN, JP_COLN, JP_RBRC, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS, \
    _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),

  /* Adjust (Lower + Raise) Common map for Normal and Exchange
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|RGBRST|      |      |      |             |      | Reset|RGBRST|      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |ModNrm|ModExc| Mac  | Win  |      |             |      |ModNrm|ModExc| Mac  | Win  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------|------+
   * |      |RGB ON| HUE+ | SAT+ | VAL+ |      |             |      |RGB ON| HUE+ | SAT+ | VAL+ |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|------+
   * |      | MODE | HUE- | SAT- | VAL- |      |      |      |      | MODE | HUE- | SAT- | VAL- |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | REC2 | REC1 | STOP |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
    XXXXXXX, RESET,   RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RESET,   RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, DL_BAS,  XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX,                   XXXXXXX, DL_BAS,  XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, \
    XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                   XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, \
    XXXXXXX, RGB_SMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SMOD,RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, \
    _______, _______, _______, _______, DM_REC2, DM_REC1, DM_STOP, _______, _______, _______, _______, _______, _______, _______  \
    ),
};

#else
#error "undefined keymaps"
#endif

#ifdef SSD1306OLED
char keylog[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', ' ', '@', ' ', ' ',
    ' ', ';', ':', ' ', ',', '.', '/', ' ', ' ', ' '};

static inline void set_keylog(uint16_t keycode, keyrecord_t *record)
{
  char name = ' ';
  uint8_t leds = host_keyboard_leds();

  if (keycode < 60)
  {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog, sizeof(keylog), "\n%dx%d %2x %c %c %c %c",
           record->event.key.row,
           record->event.key.col,
           keycode,
           name,
          (leds & (1<<USB_LED_NUM_LOCK)) ? 'N' : ' ',
          (leds & (1<<USB_LED_CAPS_LOCK)) ? 'C' : ' ',
          (leds & (1<<USB_LED_SCROLL_LOCK)) ? 'S' : ' '
           );
}
#endif

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT(mode) rgblight_mode(mode)
#else
#define RGBLIGHT(mode)
#endif

// define variables for reactive RGB
int RGB_current_mode;
#ifdef ADJUST_MACRO_ENABLE
// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    RGBLIGHT(RGB_current_mode);
    layer_on(layer3);
   } else {
    layer_off(layer3);
  }
}
#define ADJUST_MACRO(layer1, layer2, layer3) update_tri_layer_RGB(layer1, layer2, layer3)
#else
#define ADJUST_MACRO(layer1, layer2, layer3)
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }

  #ifdef SSD1306OLED
    if (record->event.pressed) {
      set_keylog(keycode, record);
    }
  #endif

  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    #ifdef KANA_ENABLE
      case EISU:
        if (record->event.pressed) {
          if (keymap_config.swap_lalt_lgui==false) {
            register_code(KC_LANG2);
          } else {
            SEND_STRING(SS_LALT("`"));
          }
        } else {
          unregister_code(KC_LANG2);
        }
        break;
      case KANA:
        if (record->event.pressed) {
          if(keymap_config.swap_lalt_lgui==false){
            register_code(KC_LANG1);
          }else{
            SEND_STRING(SS_LALT("`"));
          }
        } else {
          unregister_code(KC_LANG1);
        }
        break;
    #endif
    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      return true;
  }

  return false;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb()); // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

static inline void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

const char helix_logo[]={
  0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
  0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
  0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
  0};

static inline void render_logo(struct CharacterMatrix *matrix) {

  matrix_write(matrix, helix_logo);
}

const char mac_win_logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};

static inline void render_status(struct CharacterMatrix *matrix) {

  char buf[20];
  // Render to mode icon
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, mac_win_logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, mac_win_logo[0][1]);
  } else {
    matrix_write(matrix, mac_win_logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, mac_win_logo[1][1]);
  }

  #ifdef RGBLIGHT_ENABLE
    snprintf(buf, sizeof(buf), "  LED mode:%d", (short)RGB_current_mode);
    matrix_write(matrix, buf);
  #endif

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  matrix_write_P(matrix, PSTR("\nLayer: "));
  switch (layer_state) {
    case L_BASE:
      matrix_write_P(matrix, PSTR("Base"));
      break;
    case L_RAISE:
      matrix_write_P(matrix, PSTR("Raise"));
      break;
    case L_LOWER:
      matrix_write_P(matrix, PSTR("Lower"));
      break;
    case L_ADJUST:
    case L_ADJUST_TRI:
      matrix_write_P(matrix, PSTR("Adjust"));
      break;
    default:
      snprintf(buf, sizeof(buf), "%d", (short)layer_state);
      matrix_write(matrix, buf);
  }

  matrix_write(matrix, keylog);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  if (is_master) {
    render_status(&matrix);
  } else {
    render_logo(&matrix);
  }

  matrix_update(&display, &matrix);
}

#endif
