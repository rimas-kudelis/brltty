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

#ifndef BRLTTY_INCLUDED_ASYNC_INTERNAL
#define BRLTTY_INCLUDED_ASYNC_INTERNAL

#include "async.h"
#include "queue.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct {
  Queue *functionQueue;
  Queue *alarmQueue;
  Queue *taskQueue;
  unsigned int waitDepth;
} AsyncThreadSpecificData;

extern AsyncThreadSpecificData *asyncGetThreadSpecificData (void);

struct AsyncHandleStruct {
  Element *element;
  int identifier;
};

extern int asyncMakeHandle (
  AsyncHandle *handle,
  Element *(*newElement) (const void *parameters),
  const void *parameters
);

extern int asyncCheckHandle (AsyncHandle handle, Queue *queue);

typedef struct {
  void (*cancelRequest) (Element *element);
} AsyncQueueMethods;

extern int asyncPerformAlarm (AsyncThreadSpecificData *tsd, long int *timeout);
extern int asyncPerformTask (AsyncThreadSpecificData *tsd);
extern void asyncAwaitNextOperation (AsyncThreadSpecificData *tsd, long int timeout);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* BRLTTY_INCLUDED_ASYNC_INTERNAL */
