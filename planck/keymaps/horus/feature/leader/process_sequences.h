#ifndef PROCESS_SEQUENCES_H
#define PROCESS_SEQUENCES_H
#pragma once

#include "../../config.h"
#include "../../aliases.h"
#include "../../util/log/log.h"

#include "process_leader.h"

#define FEATURE_FLAG_DYNAMIC_MACRO_OVERRIDE
#ifdef FEATURE_FLAG_DYNAMIC_MACRO_OVERRIDE
#include "dynamic_macro.h"
bool leader_sequence_dynamic_macro(void);
#endif

void leader_end_user(void);

#endif
