#include <stdio.h>
#include <assert.h>
#include <unistd.h>

extern "C"
bool __asan_get_ownership(void *ptr);

int main() {
  const size_t kArraySize = 100;
  char *array = (char*)malloc(kArraySize);
  char *p = array + kArraySize / 2;
  printf("__asan_get_ownership(%p): %d\n", p, __asan_get_ownership(p));
  if (__asan_get_ownership(p)) {
    fprintf(stderr, "pid: %d\n", getpid());
    sleep(1000);
  }
  return 0;
}
