/* Copyright (c) 2003-2004, Roger Dingledine
 * Copyright (c) 2004-2006, Roger Dingledine, Nick Mathewson.
 * Copyright (c) 2007-2013, The Tor Project, Inc. */
/* See LICENSE for licensing information */

#include "orconfig.h"
#include <stdlib.h>
#include "compat_threads.h"
#include "util.h"
#include "torlog.h"

int
spawn_func(void (*func)(void *), void *data)
{
  pid_t pid;
  pid = fork();
  if (pid<0)
    return -1;
  if (pid==0) {
    /* Child */
    func(data);
    tor_assert(0); /* Should never reach here. */
    return 0; /* suppress "control-reaches-end-of-non-void" warning. */
  } else {
    /* Parent */
    return 0;
  }
}

/** End the current thread/process.
 */
void
spawn_exit(void)
{
  /* http://www.erlenstar.demon.co.uk/unix/faq_2.html says we should
   * call _exit, not exit, from child processes. */
  _exit(0);
}

