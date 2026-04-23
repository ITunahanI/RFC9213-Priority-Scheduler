#include "priority_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parse_rfc9213_urgency(const char* header) {
    // Basitleştirilmiş RFC 9213 Parser
    // "u=x" formatını arar. Bulamazsa varsayılan 3 döner.
    int u = 3; 
    char* found = strstr(header, "u=");
    if (found) {
        u = found[2] - '0';
    }
    if (u < 0 || u > 7) u = 7;
    return u;
}
