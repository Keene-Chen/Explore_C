## 静态库编译
### Windows
1. `gcc -c libkc.c`
2. `ar rcs libkc.dll.a libkc.o`

### Linux
1. `gcc -c libkc.c`
2. `ar rcs libkc.a libkc.o`

## 动态库编译
### Windows
`gcc --share libkc.c -o libkc.dll`

### Linux
`gcc -shared libkc.c -o libkc.so -fPIC`
