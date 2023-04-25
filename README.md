# MMI3G-CRC32Sum
hbcrc32sum -- A command line tool to calculate CRC32 checksums used in MMI3G metainfo2.txt files.

Build with GCC:
```
$ gcc -O3 -o hbcrc32sum hbcrc32sum.c
```

Usage:

Individual files from software updates using the default checksum file size (512K bytes):
```
$ hbcrc32sum < 8R0906961FE/AH6/Main/0/default/ah6a-us_rev03-001.usf
2851ec52
735f0299
850b4011
3fb57b5a
4f921693
92d96a62
da502ffa
36a87bcd
36652293
747b96fa
218bbf51
1089f06b
d5851a38
125d4429
41d012aa
5dfa1b0b
c58b5417
465b0bf7
eae928a3
10191808 2512c075
```

Package components from navigation database updates:
```
$ cd 8R0051884EN/pkgdb/CTYS3TC_NAR
$ cat 3PN163NA16343P1244a.4_4.ATLAS CTYS3TC_NAR.conf | hbcrc32sum 209715200
b18e580a
ab1355ae
575321189 bc13314a
```
The tool accepts one argument: the checksum size (in bytes) for (very) large files, found typically in the metainfo2.txt file.

I'm still looking to figure out how to determine the CRC32 value for MetafileChecksum in MMI3G metainfo2.txt files.

DrGER / Apr 2023
