// 20230424 DrGER; H-B CRC32 checksum calculator from stdin
// https://lxp32.github.io/docs/a-simple-example-crc32-calculation/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t chksumsize=524288;
uint32_t polynomial=0xEDB88320L;
uint32_t crc32_table[256];

void build_crc32_table(void) {
  for(uint32_t i=0; i<256; i++) {
    uint32_t ch=i;
    uint32_t crc=0;
    for(size_t j=0; j<8; j++) {
      uint32_t b=(ch^crc)&1;
      crc >>= 1;
      if(b) crc=crc^polynomial;
      ch>>=1;
    }
    crc32_table[i]=crc;
  }
}

uint32_t crc32_fast(const char ch, uint32_t* crc) {
  uint32_t t=(ch^*crc)&0xFF;
  *crc=(*crc>>8)^crc32_table[t];
  return *crc;
}

int main(int ac, char **av) {
  uint32_t crc = 0xFFFFFFFFL;
  uint32_t ii=0;
  int i=0;
  int c;
  if (ac==2) chksumsize=atol(av[1]);
  build_crc32_table();
  while((c=getchar())!=EOF) {
    crc = crc32_fast(c, &crc);
    i++;
    ii++;
    if (ii == chksumsize) {
      fprintf(stdout, "%08lx\n", ~crc);
      crc = 0xFFFFFFFFL;
      ii=0;
    }
  }
  crc = ~crc;
  fprintf(stdout, "%d %08lx\n", i, crc);
}
