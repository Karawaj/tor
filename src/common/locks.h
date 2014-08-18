/* 
 * File:   locks.h
 * Author: towelenee
 *
 * Created on August 18, 2014, 5:18 PM
 */

#ifndef LOCKS_H
#define	LOCKS_H

#include "compat_threads.h"

tor_mutex_t rep_hist_note_circuit_handshake_requested_lock;
tor_mutex_t global_circuitlist_lock;
tor_mutex_t tsl_handshake_lock;

static void init_all_mutex()
{
  tor_mutex_init(&rep_hist_note_circuit_handshake_requested_lock);
  tor_mutex_init(&global_circuitlist_lock);
  tor_mutex_init(&tsl_handshake_lock);
}

#endif  /* LOCKS_H */

