# ELF releted

## Command
编译成.o


查看程序的headers:
查看反汇编
> objdump --disassemble libtest.so
> readelf --headers /lib/libc.so.6
read relocate table
> readelf -r ./xxx.o
check the sections of a so
> readelf --sections libtest.so
查看需要重定位的符号
> readelf --relocs libtest.so
查看so是否是PIC编出来的,有输出则代表不是:
> readelf -d *.so | grep TEXTREL



## working michenism
* global offset table or GOT\
通过rip的一个偏置可以在.got中索引到share library的变量：
在本例中的地址是： 3ff0
```
00000000000010f9 <function>:
    10f9:	f3 0f 1e fa          	endbr64 
    10fd:	55                   	push   %rbp
    10fe:	48 89 e5             	mov    %rsp,%rbp
    1101:	48 8b 05 e8 2e 00 00 	mov    0x2ee8(%rip),%rax        # 3ff0 <foo>
    1108:	8b 00 
```
readelf --sections libtest.so 
```
  [17] .got              PROGBITS         0000000000003fd8  00002fd8
       0000000000000028  0000000000000008  WA       0     0     8
```

* procedure linkage table or PLT\
Code does not call an external function directly, but only via a PLT stub.
```
0000000000001119 <function>:
    1119:	f3 0f 1e fa          	endbr64 
    111d:	55                   	push   %rbp
    111e:	48 89 e5             	mov    %rsp,%rbp
    1121:	e8 2a ff ff ff       	callq  1050 <foo@plt>
    1126:	5d                   	pop    
```
```
0000000000001050 <foo@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 bd 2f 00 00 	bnd jmpq *0x2fbd(%rip)        # 4018 <foo>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
```
foo的地址(ox4018)直接jump到一个relocat
```
Relocation section '.rela.plt' at offset 0x4d0 contains 1 entry:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000004018  000400000007 R_X86_64_JUMP_SLO 0000000000000000 foo + 0
```

### lazy binding
lazy binding — by convention when the dynamic linker loads a library, it will put an identifier and resolution function into known places in the GOT.

### 查看glibc版本
> ldd--version
## Shared library
静态编译占用内存和磁盘空间，发布也必须跟所有的.o一起发布（太大）。动态链接就是将链接过程推迟到运行时进行，动态链接的动作与静态链接是类似的。

由于更新了动态链接库，导致接口不兼容，缺乏有效的共享库版本管理机制导致了早期的DLL hell。

查看glibc的安装位置：
> gcc --print-file-name=libc.a/libc.so

动态链接相对于静态链接性能损失在5%以内

### 编译
gcc -fPIC -shared -o Lib.so Lib.c

### 链接
gcc -o Program1 Program1.c ./Lib.so
在这个过程中./Lib.so并没有直接link进最终的文件
Lib.so里有完整的符号信息，连接器把调用端和这个so链接的时候可以对动态链接的符号进行特殊处理，成为动态符号的引用

### 加载
查看某个进程的虚拟地址空间分布：
> gcc -fPIC -shared -o Lib.so Lib.c

如果是用到了动态链接库，可以看到有所有的so 以及一个动态链接器ld-XXX-.so。在执行的时候动态链接器会先进行动态链接，然后再调用程序执行

共享对象的装载地址再编译时是不确定的，而是再装载时，装载器根据当前地址空间的空闲情况，动态分配一块足够大小的内存地址空间给相应的共享对象

装载时重定位和地址无关代码可以解决加载的地址不固定和共享代码两个问题

#### 模块间的数据访问：
连接器会查找每一项的地址，填充在GOT中，确保每个指针指向正确的地址。GOT保存在每个进程的数据段 中，可以在模块装载的时候被修改，每个进程有独立的副本，所以互不影响。

在objdump -R看到的需要重定位的变量列表里，有一项是GOT中的值，也就是另外的模块的地址。

#### 






