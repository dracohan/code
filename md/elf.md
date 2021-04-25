# ELF releted

## Command
编译成.o
> drwxrwxr-x 3 Baowei.Han Baowei.Han  4096 4月  25 17:34 ../

查看程序的headers:
> readelf --headers /lib/libc.so.6
read relocate table
> readelf -r ./xxx.o
查看反汇编
> objdump --disassemble libtest.so
check the sections of a so
> readelf --sections libtest.so
查看需要重定位的符号
> readelf --relocs libtest.so



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


