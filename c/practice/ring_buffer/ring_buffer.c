#define BUFFER_SIZE 16

typedef struct {
    uint8_t data[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} RingBuffer_t;

bool RingBuffer_Write(RingBuffer_t *rb, uint8_t byte) {
    if (rb->count == BUFFER_SIZE) return false; /* full */
    rb->data[rb->head] = byte;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;
    return true;
}

bool RingBuffer_Read(RingBuffer_t *rb, uint8_t *byte) {
    if (rb->count == 0) return false; /* empty */
    *byte = rb->data[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;
    return true;
}