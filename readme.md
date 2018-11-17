# Helix 5 rows JIS layout

This keymap was created based on [`five_rows_jis` in qmk_firmware.](https://github.com/qmk/qmk_firmware/tree/master/keyboards/helix/rev2/keymaps/five_rows_jis)

This keymap was created with the concept that users using Japanese JIS keyboard layout can operate without difficulty. It has the following features.  

* We are considering to be able to input long Japanese notes without moving the layer
* We are arranging the relation of symbols that can not fit in the Raise layer


## NORMAL Keymap

* It is possible to press the N key with the left index finger and the B key with the right index finger


## 配列

### NORMAL Keymap

Base Layer  

```
 ,-----------------------------------------.             ,-----------------------------------------.
 | Esc  |  1!  |  2"  |  3#  |  4$  |  5%  |             |  6&  |  7'  |  8(  |  9)  |   0  |  -=  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @`  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;+  |  :*  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   B  |   N  |   M  |  ,<  |  .>  |  /?  |  \_  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |Adjust| Alt  | ESC  | GUI  |Lower | Mhen |Space |Space | Henk |Raise | Left |  Up  | Down |Right |
 `-------------------------------------------------------------------------------------------------'
```

Lower Layer  

```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      |      |      |      |      |      |             |      |      |      |  -=  |  ^~  |  \|  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |      |      |      |      |      |             |      |      |      |      |  @`  |  [{  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |      |      |      |      |      |             | Left | Down | Up   | Right|  :*  |  ]}  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |  ,<  |  .>  |  /?  |  \_  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      | Del  |      |      |      |      |      |      |      |
 `-------------------------------------------------------------------------------------------------'
```

Raise Layer  

```
 ,-----------------------------------------.             ,-----------------------------------------.
 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |      |      |  -=  |  ^~  |  \|  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |  F7  |  F8  |  F9  | F10  | F11  | F12  |             |      | Del  | Enter|      |  @`  |  [{  |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      | Esc  |      |      | Esc  |      |             |      | Bksp | Enter|  ;+  |  :*  |  ]}  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |  ,<  |  .>  |  /?  |  \_  |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 `-------------------------------------------------------------------------------------------------'
```

Adjust Layer

```
 ,-----------------------------------------.             ,-----------------------------------------.
 |      | Reset|RGBRST|Aud on|Audoff|      |             |      | Reset|RGBRST|Aud on|Audoff|      |
 |------+------+------+------+------+------|             |------+------+------+------+------+------|
 |      |ModNrm|ModExc| Mac  | Win  |      |             |      |ModNrm|ModExc| Mac  | Win  |      |
 |------+------+------+------+------+------|             |------+------+------+------+------|------+
 |      |RGB ON| HUE+ | SAT+ | VAL+ |      |             |      |RGB ON| HUE+ | SAT+ | VAL+ |      |
 |------+------+------+------+------+------+------+------+------+------+------+------+------|------+
 |      | MODE | HUE- | SAT- | VAL- |      |      |      |      | MODE | HUE- | SAT- | VAL- |      |
 |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 `-------------------------------------------------------------------------------------------------'
```

## How to compile these program

 See the readme of the Default keymap.
