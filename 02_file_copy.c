#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    if (argc != 3) { fprintf(stderr, "Usage: %s source destination\n", argv[0]); return 1; }
    int in = open(argv[1], O_RDONLY);
    if (in < 0) { perror("open source"); return 1; }
    int out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) { perror("open destination"); close(in); return 1; }
    char buf[4096]; ssize_t n;
    while ((n = read(in, buf, sizeof buf)) > 0) {
        ssize_t off = 0;
        while (off < n) { ssize_t w = write(out, buf + off, n - off); if (w < 0) { perror("write"); close(in); close(out); return 1; } off += w; }
    }
    if (n < 0) perror("read");
    close(in); close(out);
    return n < 0;
}
