/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2013 by The BRLTTY Developers.
 *
 * BRLTTY comes with ABSOLUTELY NO WARRANTY.
 *
 * This is free software, placed under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version. Please see the file LICENSE-GPL for details.
 *
 * Web Page: http://mielke.cc/brltty/
 *
 * This software is maintained by Dave Mielke <dave@mielke.cc>.
 */

#include "prologue.h"

#include <android/keycodes.h>

#include "log.h"
#include "system_java.h"

#include "keyboard.h"
#include "keyboard_internal.h"
#include "keyboard_android.h"

BEGIN_KEY_CODE_MAP
  [ANDROID_KEY_0] = KBD_KEY_NUMBER(Zero),
  [ANDROID_KEY_1] = KBD_KEY_NUMBER(One),
  [ANDROID_KEY_2] = KBD_KEY_NUMBER(Two),
  [ANDROID_KEY_3] = KBD_KEY_NUMBER(Three),
  [ANDROID_KEY_3D_MODE] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_4] = KBD_KEY_NUMBER(Four),
  [ANDROID_KEY_5] = KBD_KEY_NUMBER(Five),
  [ANDROID_KEY_6] = KBD_KEY_NUMBER(Six),
  [ANDROID_KEY_7] = KBD_KEY_NUMBER(Seven),
  [ANDROID_KEY_8] = KBD_KEY_NUMBER(Eight),
  [ANDROID_KEY_9] = KBD_KEY_NUMBER(Nine),

  [ANDROID_KEY_A] = KBD_KEY_LETTER(A),
  [ANDROID_KEY_ALT_LEFT] = KBD_KEY_ACTION(AltLeft),
  [ANDROID_KEY_ALT_RIGHT] = KBD_KEY_ACTION(AltRight),
  [ANDROID_KEY_APOSTROPHE] = KBD_KEY_SYMBOL(Apostrophe),
  [ANDROID_KEY_APP_SWITCH] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_ASSIST] = KBD_KEY_ACTION(Help),
  [ANDROID_KEY_AT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_AVR_INPUT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_AVR_POWER] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_B] = KBD_KEY_LETTER(B),
  [ANDROID_KEY_BACK] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BACKSLASH] = KBD_KEY_SYMBOL(Backslash),
  [ANDROID_KEY_BOOKMARK] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BREAK] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_1] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_10] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_11] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_12] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_13] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_14] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_15] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_16] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_2] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_3] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_4] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_5] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_6] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_7] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_8] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_9] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_A] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_B] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_C] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_L1] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_L2] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_MODE] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_R1] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_R2] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_SELECT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_START] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_THUMBL] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_THUMBR] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_X] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_Y] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_BUTTON_Z] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_C] = KBD_KEY_LETTER(C),
  [ANDROID_KEY_CALCULATOR] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CALENDAR] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CALL] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CAMERA] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CAPS_LOCK] = KBD_KEY_LOCK(Capitals),
  [ANDROID_KEY_CAPTIONS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CHANNEL_DOWN] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CHANNEL_UP] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CLEAR] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_COMMA] = KBD_KEY_SYMBOL(Comma),
  [ANDROID_KEY_CONTACTS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_CTRL_LEFT] = KBD_KEY_ACTION(ControlLeft),
  [ANDROID_KEY_CTRL_RIGHT] = KBD_KEY_ACTION(ControlRight),

  [ANDROID_KEY_D] = KBD_KEY_LETTER(D),
  [ANDROID_KEY_DEL] = KBD_KEY_ACTION(DeleteBackward),
  [ANDROID_KEY_DPAD_CENTER] = KBD_KEY_ACTION(Select),
  [ANDROID_KEY_DPAD_DOWN] = KBD_KEY_ACTION(ArrowDown),
  [ANDROID_KEY_DPAD_LEFT] = KBD_KEY_ACTION(ArrowLeft),
  [ANDROID_KEY_DPAD_RIGHT] = KBD_KEY_ACTION(ArrowRight),
  [ANDROID_KEY_DPAD_UP] = KBD_KEY_ACTION(ArrowUp),
  [ANDROID_KEY_DVR] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_E] = KBD_KEY_LETTER(E),
  [ANDROID_KEY_EISU] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_ENDCALL] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_ENTER] = KBD_KEY_ACTION(Enter),
  [ANDROID_KEY_ENVELOPE] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_EQUALS] = KBD_KEY_SYMBOL(Equals),
  [ANDROID_KEY_ESCAPE] = KBD_KEY_ACTION(Escape),
  [ANDROID_KEY_EXPLORER] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_F] = KBD_KEY_LETTER(F),
  [ANDROID_KEY_F1] = KBD_KEY_FUNCTION(F1),
  [ANDROID_KEY_F10] = KBD_KEY_FUNCTION(F10),
  [ANDROID_KEY_F11] = KBD_KEY_FUNCTION(F11),
  [ANDROID_KEY_F12] = KBD_KEY_FUNCTION(F12),
  [ANDROID_KEY_F2] = KBD_KEY_FUNCTION(F2),
  [ANDROID_KEY_F3] = KBD_KEY_FUNCTION(F3),
  [ANDROID_KEY_F4] = KBD_KEY_FUNCTION(F4),
  [ANDROID_KEY_F5] = KBD_KEY_FUNCTION(F5),
  [ANDROID_KEY_F6] = KBD_KEY_FUNCTION(F6),
  [ANDROID_KEY_F7] = KBD_KEY_FUNCTION(F7),
  [ANDROID_KEY_F8] = KBD_KEY_FUNCTION(F8),
  [ANDROID_KEY_F9] = KBD_KEY_FUNCTION(F9),
  [ANDROID_KEY_FOCUS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_FORWARD] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_FORWARD_DEL] = KBD_KEY_ACTION(DeleteForward),
  [ANDROID_KEY_FUNCTION] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_G] = KBD_KEY_LETTER(G),
  [ANDROID_KEY_GRAVE] = KBD_KEY_SYMBOL(Grave),
  [ANDROID_KEY_GUIDE] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_H] = KBD_KEY_LETTER(H),
  [ANDROID_KEY_HEADSETHOOK] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_HENKAN] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_HOME] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_I] = KBD_KEY_LETTER(I),
  [ANDROID_KEY_INFO] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_INSERT] = KBD_KEY_ACTION(Insert),

  [ANDROID_KEY_J] = KBD_KEY_LETTER(J),

  [ANDROID_KEY_K] = KBD_KEY_LETTER(K),
  [ANDROID_KEY_KANA] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_KATAKANA_HIRAGANA] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_L] = KBD_KEY_LETTER(L),
  [ANDROID_KEY_LANGUAGE_SWITCH] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_LEFT_BRACKET] = KBD_KEY_SYMBOL(LeftBracket),

  [ANDROID_KEY_M] = KBD_KEY_LETTER(M),
  [ANDROID_KEY_MANNER_MODE] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_MEDIA_CLOSE] = KBD_KEY_MEDIA(Close),
  [ANDROID_KEY_MEDIA_EJECT] = KBD_KEY_MEDIA(Eject),
  [ANDROID_KEY_MEDIA_FAST_FORWARD] = KBD_KEY_MEDIA(Forward),
  [ANDROID_KEY_MEDIA_NEXT] = KBD_KEY_MEDIA(Next),
  [ANDROID_KEY_MEDIA_PAUSE] = KBD_KEY_MEDIA(Pause),
  [ANDROID_KEY_MEDIA_PLAY] = KBD_KEY_MEDIA(Play),
  [ANDROID_KEY_MEDIA_PLAY_PAUSE] = KBD_KEY_MEDIA(PlayPause),
  [ANDROID_KEY_MEDIA_PREVIOUS] = KBD_KEY_MEDIA(Previous),
  [ANDROID_KEY_MEDIA_RECORD] = KBD_KEY_MEDIA(Record),
  [ANDROID_KEY_MEDIA_REWIND] = KBD_KEY_MEDIA(Backward),
  [ANDROID_KEY_MEDIA_STOP] = KBD_KEY_MEDIA(Stop),
  [ANDROID_KEY_MENU] = KBD_KEY_ACTION(Menu),
  [ANDROID_KEY_META_LEFT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_META_RIGHT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_MINUS] = KBD_KEY_SYMBOL(Minus),
  [ANDROID_KEY_MOVE_END] = KBD_KEY_ACTION(End),
  [ANDROID_KEY_MOVE_HOME] = KBD_KEY_ACTION(Home),
  [ANDROID_KEY_MUHENKAN] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_MUSIC] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_MUTE] = KBD_KEY_MEDIA(Mute),

  [ANDROID_KEY_N] = KBD_KEY_LETTER(N),
  [ANDROID_KEY_NOTIFICATION] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_NUM] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_NUMPAD_0] = KBD_KEY_KPNUMBER(Zero),
  [ANDROID_KEY_NUMPAD_1] = KBD_KEY_KPNUMBER(One),
  [ANDROID_KEY_NUMPAD_2] = KBD_KEY_KPNUMBER(Two),
  [ANDROID_KEY_NUMPAD_3] = KBD_KEY_KPNUMBER(Three),
  [ANDROID_KEY_NUMPAD_4] = KBD_KEY_KPNUMBER(Four),
  [ANDROID_KEY_NUMPAD_5] = KBD_KEY_KPNUMBER(Five),
  [ANDROID_KEY_NUMPAD_6] = KBD_KEY_KPNUMBER(Six),
  [ANDROID_KEY_NUMPAD_7] = KBD_KEY_KPNUMBER(Seven),
  [ANDROID_KEY_NUMPAD_8] = KBD_KEY_KPNUMBER(Eight),
  [ANDROID_KEY_NUMPAD_9] = KBD_KEY_KPNUMBER(Nine),
  [ANDROID_KEY_NUMPAD_ADD] = KBD_KEY_KEYPAD(Plus),
  [ANDROID_KEY_NUMPAD_COMMA] = KBD_KEY_KEYPAD(Comma),
  [ANDROID_KEY_NUMPAD_DIVIDE] = KBD_KEY_KEYPAD(Slash),
  [ANDROID_KEY_NUMPAD_DOT] = KBD_KEY_KEYPAD(Period_Delete),
  [ANDROID_KEY_NUMPAD_ENTER] = KBD_KEY_KEYPAD(Enter),
  [ANDROID_KEY_NUMPAD_EQUALS] = KBD_KEY_KEYPAD(Equals),
  [ANDROID_KEY_NUMPAD_LEFT_PAREN] = KBD_KEY_KEYPAD(LeftParenthesis),
  [ANDROID_KEY_NUMPAD_MULTIPLY] = KBD_KEY_KEYPAD(Asterisk),
  [ANDROID_KEY_NUMPAD_RIGHT_PAREN] = KBD_KEY_KEYPAD(RightParenthesis),
  [ANDROID_KEY_NUMPAD_SUBTRACT] = KBD_KEY_KEYPAD(Minus),
  [ANDROID_KEY_NUM_LOCK] = KBD_KEY_LOCK(Numbers),

  [ANDROID_KEY_O] = KBD_KEY_LETTER(O),

  [ANDROID_KEY_P] = KBD_KEY_LETTER(P),
  [ANDROID_KEY_PAGE_DOWN] = KBD_KEY_ACTION(PageDown),
  [ANDROID_KEY_PAGE_UP] = KBD_KEY_ACTION(PageUp),
  [ANDROID_KEY_PERIOD] = KBD_KEY_SYMBOL(Period),
  [ANDROID_KEY_PICTSYMBOLS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_PLUS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_POUND] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_POWER] = KBD_KEY_ACTION(Power),
  [ANDROID_KEY_PROG_BLUE] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_PROG_GREEN] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_PROG_RED] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_PROG_YELLOW] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_Q] = KBD_KEY_LETTER(Q),

  [ANDROID_KEY_R] = KBD_KEY_LETTER(R),
  [ANDROID_KEY_RIGHT_BRACKET] = KBD_KEY_SYMBOL(RightBracket),
  [ANDROID_KEY_RO] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_S] = KBD_KEY_LETTER(S),
  [ANDROID_KEY_SCROLL_LOCK] = KBD_KEY_LOCK(Scroll),
  [ANDROID_KEY_SEARCH] = KBD_KEY_ACTION(Find),
  [ANDROID_KEY_SEMICOLON] = KBD_KEY_SYMBOL(Semicolon),
  [ANDROID_KEY_SETTINGS] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SHIFT_LEFT] = KBD_KEY_ACTION(ShiftLeft),
  [ANDROID_KEY_SHIFT_RIGHT] = KBD_KEY_ACTION(ShiftRight),
  [ANDROID_KEY_SLASH] = KBD_KEY_SYMBOL(Slash),
  [ANDROID_KEY_SOFT_LEFT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SOFT_RIGHT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SPACE] = KBD_KEY_ACTION(Space),
  [ANDROID_KEY_STAR] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_STB_INPUT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_STB_POWER] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SWITCH_CHARSET] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SYM] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_SYSRQ] = KBD_KEY_ACTION(SystemRequest),

  [ANDROID_KEY_T] = KBD_KEY_LETTER(T),
  [ANDROID_KEY_TAB] = KBD_KEY_ACTION(Tab),
  [ANDROID_KEY_TV] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_TV_INPUT] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_TV_POWER] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_U] = KBD_KEY_LETTER(U),
  [ANDROID_KEY_UNKNOWN] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_V] = KBD_KEY_LETTER(V),
  [ANDROID_KEY_VOLUME_DOWN] = KBD_KEY_MEDIA(VolumeDown),
  [ANDROID_KEY_VOLUME_MUTE] = KBD_KEY_MEDIA(Mute),
  [ANDROID_KEY_VOLUME_UP] = KBD_KEY_MEDIA(VolumeUp),

  [ANDROID_KEY_W] = KBD_KEY_LETTER(W),
  [ANDROID_KEY_WINDOW] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_X] = KBD_KEY_LETTER(X),

  [ANDROID_KEY_Y] = KBD_KEY_LETTER(Y),
  [ANDROID_KEY_YEN] = KBD_KEY_UNMAPPED,

  [ANDROID_KEY_Z] = KBD_KEY_LETTER(Z),
  [ANDROID_KEY_ZENKAKU_HANKAKU] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_ZOOM_IN] = KBD_KEY_UNMAPPED,
  [ANDROID_KEY_ZOOM_OUT] = KBD_KEY_UNMAPPED,

  [B2G_KEY_CHARACTERS ... B2G_KEY_CHARACTERS+0XFF] = KBD_KEY_IGNORE,
  [B2G_KEY_CHORDS ... B2G_KEY_CHORDS+0XFF] = KBD_KEY_IGNORE,

  [B2G_KEY_DOT1] = KBD_KEY_BRAILLE(Dot7),
  [B2G_KEY_DOT2] = KBD_KEY_BRAILLE(Dot3),
  [B2G_KEY_DOT3] = KBD_KEY_BRAILLE(Dot2),
  [B2G_KEY_DOT4] = KBD_KEY_BRAILLE(Dot1),
  [B2G_KEY_DOT5] = KBD_KEY_BRAILLE(Dot4),
  [B2G_KEY_DOT6] = KBD_KEY_BRAILLE(Dot5),
  [B2G_KEY_DOT7] = KBD_KEY_BRAILLE(Dot6),
  [B2G_KEY_DOT8] = KBD_KEY_BRAILLE(Dot8),
  [B2G_KEY_DOT9] = KBD_KEY_BRAILLE(Space),

  [B2G_KEY_CURSOR0] = KBD_KEY_ROUTE(0),
  [B2G_KEY_CURSOR1] = KBD_KEY_ROUTE(1),
  [B2G_KEY_CURSOR2] = KBD_KEY_ROUTE(2),
  [B2G_KEY_CURSOR3] = KBD_KEY_ROUTE(3),
  [B2G_KEY_CURSOR4] = KBD_KEY_ROUTE(4),
  [B2G_KEY_CURSOR5] = KBD_KEY_ROUTE(5),
  [B2G_KEY_CURSOR6] = KBD_KEY_ROUTE(6),
  [B2G_KEY_CURSOR7] = KBD_KEY_ROUTE(7),
  [B2G_KEY_CURSOR8] = KBD_KEY_ROUTE(8),
  [B2G_KEY_CURSOR9] = KBD_KEY_ROUTE(9),
  [B2G_KEY_CURSOR10] = KBD_KEY_ROUTE(10),
  [B2G_KEY_CURSOR11] = KBD_KEY_ROUTE(11),
  [B2G_KEY_CURSOR12] = KBD_KEY_ROUTE(12),
  [B2G_KEY_CURSOR13] = KBD_KEY_ROUTE(13),
  [B2G_KEY_CURSOR14] = KBD_KEY_ROUTE(14),
  [B2G_KEY_CURSOR15] = KBD_KEY_ROUTE(15),
  [B2G_KEY_CURSOR16] = KBD_KEY_ROUTE(16),
  [B2G_KEY_CURSOR17] = KBD_KEY_ROUTE(17),
  [B2G_KEY_CURSOR18] = KBD_KEY_ROUTE(18),
  [B2G_KEY_CURSOR19] = KBD_KEY_ROUTE(19),
  [B2G_KEY_CURSOR20] = KBD_KEY_ROUTE(20),
  [B2G_KEY_CURSOR21] = KBD_KEY_ROUTE(21),
  [B2G_KEY_CURSOR22] = KBD_KEY_ROUTE(22),
  [B2G_KEY_CURSOR23] = KBD_KEY_ROUTE(23),
  [B2G_KEY_CURSOR24] = KBD_KEY_ROUTE(24),
  [B2G_KEY_CURSOR25] = KBD_KEY_ROUTE(25),
  [B2G_KEY_CURSOR26] = KBD_KEY_ROUTE(26),
  [B2G_KEY_CURSOR27] = KBD_KEY_ROUTE(27),
  [B2G_KEY_CURSOR28] = KBD_KEY_ROUTE(28),
  [B2G_KEY_CURSOR29] = KBD_KEY_ROUTE(29),
  [B2G_KEY_CURSOR30] = KBD_KEY_ROUTE(30),
  [B2G_KEY_CURSOR31] = KBD_KEY_ROUTE(31),
  [B2G_KEY_CURSOR32] = KBD_KEY_ROUTE(32),
  [B2G_KEY_CURSOR33] = KBD_KEY_ROUTE(33),
  [B2G_KEY_CURSOR34] = KBD_KEY_ROUTE(34),
  [B2G_KEY_CURSOR35] = KBD_KEY_ROUTE(35),
  [B2G_KEY_CURSOR36] = KBD_KEY_ROUTE(36),
  [B2G_KEY_CURSOR37] = KBD_KEY_ROUTE(37),
  [B2G_KEY_CURSOR38] = KBD_KEY_ROUTE(38),
  [B2G_KEY_CURSOR39] = KBD_KEY_ROUTE(39),

  [B2G_KEY_BACK] = KBD_KEY_BRAILLE(Backward),
  [B2G_KEY_FORWARD] = KBD_KEY_BRAILLE(Forward),
END_KEY_CODE_MAP

typedef struct {
  KeyboardInstanceData *kid;

  JNIEnv *env;
  jclass this;

  jclass inputService;
  jmethodID forwardKeyEvent;
} KeyboardPlatformData;

static KeyboardPlatformData *keyboardPlatformData = NULL;

int
forwardKeyEvent (int code, int press) {
  KeyboardPlatformData *kpd = keyboardPlatformData;

  if (kpd) {
    if (findJavaClass(kpd->env, &kpd->inputService, "org/a11y/brltty/android/InputService")) {
      if (findJavaInstanceMethod(kpd->env, &kpd->forwardKeyEvent, kpd->inputService, "forwardKeyEvent",
                                 JAVA_SIG_METHOD(JAVA_SIG_VOID,
                                                 JAVA_SIG_INT // code
                                                 JAVA_SIG_BOOLEAN // press
                                                ))) {
        (*kpd->env)->CallVoidMethod(
          kpd->env, kpd->this, kpd->forwardKeyEvent,
          code, (press? JNI_TRUE: JNI_FALSE)
        );

        if (!clearJavaException(kpd->env, 1)) {
          return 1;
        }
      }
    }
  }

  return 0;
}

JNIEXPORT jboolean JNICALL
Java_org_a11y_brltty_android_InputService_handleKeyEvent (
  JNIEnv *env, jclass *this,
  jint code, jboolean press
) {
  KeyboardPlatformData *kpd = keyboardPlatformData;

  if (kpd) {
    kpd->env = env;
    kpd->this = this;

    handleKeyEvent(kpd->kid, code, (press != JNI_FALSE));
    return JNI_TRUE;
  }

  return JNI_FALSE;
}

int
monitorKeyboards (KeyboardCommonData *kcd) {
  KeyboardPlatformData *kpd = malloc(sizeof(*kpd));

  if (kpd) {
    memset(kpd, 0, sizeof(*kpd));

    kpd->env = NULL;
    kpd->this = NULL;

    kpd->inputService = NULL;
    kpd->forwardKeyEvent = 0;

    if ((kpd->kid = newKeyboardInstanceData(kcd))) {
      keyboardPlatformData = kpd;
      return 1;
    }

    free(kpd);
  } else {
    logMallocError();
  }

  keyboardPlatformData = NULL;
  return 0;
}