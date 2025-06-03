#include "../pool_allocator.h"
#include <assert.h>

int main() {
    size_t block_size = 32;
    size_t block_count = 10;

    PoolAllocator* allocator = pool_allocator_create(block_size, block_count);
    assert(allocator != NULL);

    void* blocks[block_count];

    for (size_t i = 0; i < block_count; ++i) {
        blocks[i] = pool_alloc(allocator);
        assert(blocks[i] != NULL);
    }

    void* extra = pool_alloc(allocator);
    assert(extra == NULL);

    for (size_t i = 0; i < block_count / 2; ++i) {
        pool_free(allocator, blocks[i]);
    }

    for (size_t i = 0; i < block_count / 2; ++i) {
        void* reused = pool_alloc(allocator);
        assert(reused != NULL);
    }

    pool_allocator_destroy(allocator);

    return 0;
}
