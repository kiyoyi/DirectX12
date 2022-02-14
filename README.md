# 8 Transformation and World View Projection Space Matrices

Root signature (64 DWORDS) : three types of root parameters
- Root Constants

    each 1 DWROD.

- Root Descriptors

    64 bit GPU Virtual Address (2 DWORD)

- Descriptor Tables (textures)

    16 bit address + a number (1 DWORD in total)

    need to do our own versioning

size of resource heap must be a multiple of **64KB** for single-textures or buffers

constant buffer must be stored at **256 byte** offsets from the beginning of a resource heap

url: 

https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices