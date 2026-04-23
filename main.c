#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"
#include "priority_utils.h"

int main() {
    MinHeap* gateway_queue = create_heap(10);

    // Test Senaryosu
    const char* raw_headers[] = {"u=5", "u=0", "u=2", "u=7"};
    const char* desc[] = {"Düşük Öncelikli Görsel", "Kritik API Çağrısı", "Normal JS Dosyası", "Arkaplan Analitiği"};

    printf("--- İstekler Gateway'e Geliyor ---\n");
    for (int i = 0; i < 4; i++) {
        HttpRequest* new_req = (HttpRequest*)malloc(sizeof(HttpRequest));
        new_req->id = i + 1;
        new_req->urgency = parse_rfc9213_urgency(raw_headers[i]);
        snprintf(new_req->description, 100, "%s", desc[i]);
        
        printf("Eklendi: ID %d, Urgency %d (%s)\n", new_req->id, new_req->urgency, new_req->description);
        insert_request(gateway_queue, new_req);
    }

    printf("\n--- Gateway İstekleri İşliyor (Priority Order) ---\n");
    while (gateway_queue->size > 0) {
        HttpRequest* processed = extract_min(gateway_queue);
        printf("İşleniyor: ID %d, Urgency %d, Tanım: %s\n", processed->id, processed->urgency, processed->description);
        free(processed);
    }

    free_heap(gateway_queue);
    return 0;
}
