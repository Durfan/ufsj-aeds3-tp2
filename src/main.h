#define _GNU_SOURCE

#define getRodadas(clubes) (2*clubes)-2

#define COLOR_YELL  "\x1b[33m"
#define COLOR_BLUE  "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>
#include <time.h>

typedef enum {false,true} bool;

#include "files.h"
#include "linkedlist.h"
#include "showthis.h"
#include "initsolve.h"
#include "tools.h"
#include "mando.h"