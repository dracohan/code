Q: static 变量放在什么ELF中的什么位置
A: 在.data和.bss段中分配空间，并在symbol table中创建链接

Q: 函数局部变量会存在什么section里
A: local stack variable is run time, not stored in .symtab