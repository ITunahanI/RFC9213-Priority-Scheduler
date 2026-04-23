#ifndef PRIORITY_UTILS_H
#define PRIORITY_UTILS_H

typedef struct {
    int id;
    int urgency; // RFC 9213: 0 (En yüksek) - 7 (En düşük)
    char description[100];
} HttpRequest;

// RFC 9213 Header String'ini (örn: "u=2, i") parse eder.
int parse_rfc9213_urgency(const char* header);

#endif
