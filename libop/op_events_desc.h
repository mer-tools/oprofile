/**
 * @file op_events_desc.h
 * Human-readable descriptions of PMC events
 *
 * @remark Copyright 2002 OProfile authors
 * @remark Read the file COPYING
 * 
 * @author John Levon <moz@compsoc.man.ac.uk>
 * @author Philippe Elie <phil_el@wanadoo.fr>
 */

#ifndef OP_EVENTS_DESC_H
#define OP_EVENTS_DESC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "op_interface.h"
#include "op_events_desc.h"
 
/** Human readable description for an unit mask. */
struct op_unit_desc {
	char * desc[7];
};

/**
 * get event name and description
 * @param cpu_type the cpu_type
 * @param type event value
 * @param um unit mask
 * @param typenamep returned event name string
 * @param typedescp returned event description string
 * @param umdescp returned unit mask description string
 *
 * Get the associated event name and descriptions given
 * the cpu type, event value and unit mask value. It is a fatal error
 * to supply a non-valid type value, but an invalid um will not exit.
 *
 * typenamep, typedescp, umdescp are filled in with pointers
 * to the relevant name and descriptions. umdescp can be set to
 * NULL when um is invalid for the given type value.
 * These strings are static and should not be freed.
 */
void op_get_event_desc(op_cpu cpu_type, u8 type, u8 um,
	char ** typenamep, char ** typedescp, char ** umdescp);

/** unit mask description */
extern struct op_unit_mask op_unit_masks[];
/** unit mask string description */
extern struct op_unit_desc op_unit_descs[];
/** events string description */
extern char * op_event_descs[];
/** description of events for all processor type */
extern struct op_event op_events[];
/** the total number of events for all processor type, allowing to iterate
 * on the op_events[] decription */
extern u32 op_nr_events;

/**
 * get from /proc/sys/dev/oprofile/cpu_type the cpu type
 *
 * returns CPU_NO_GOOD if the CPU could not be identified.
 * This function can not work if the module is not loaded
 */
op_cpu op_get_cpu_type(void);

/**
 * get the cpu string.
 * @param cpu_type the cpu type identifier
 *
 * The function always return a valid const char* the core cpu denomination
 * or "invalid cpu type" if cpu_type is not valid.
 */
char const * op_get_cpu_type_str(op_cpu cpu_type);

#ifdef __cplusplus
}
#endif

#endif /* OP_EVENTS_DESC_H */
