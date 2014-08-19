/*
 * BRLTTY - A background process providing access to the console screen (when in
 *          text mode) for a blind person using a refreshable braille display.
 *
 * Copyright (C) 1995-2014 by The BRLTTY Developers.
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

#ifndef BRLTTY_INCLUDED_CMD_TOGGLE
#define BRLTTY_INCLUDED_CMD_TOGGLE

#include "cmd_queue.h"
#include "alert.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern CommandHandler handleToggleCommand;

typedef enum {
  TOGGLE_ERROR,
  TOGGLE_SAME,
  TOGGLE_OFF,
  TOGGLE_ON
} ToggleResult;

extern ToggleResult toggleBit (
  int *bits, int bit, int command,
  AlertIdentifier offAlert,
  AlertIdentifier onAlert
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_CMD_TOGGLE */
