#  Performance evaluate Notebook

## Background Knowledge

## Tasks
General Perf
- [ ] perf用法及实现原理

EF
----
- [ ] libprofile采集原理
  - [ ] 查看所有的changelist
- [ ] CPU Op采集原理
- [ ] GPerf实现调研
- [ ] CPU利用率采集原理
- [ ] MPI使用

TF
------
- [ ] NVIDIA CUPTI使用及实现分析
- [ ] TensorFlow采集精度/性能数据原理
- [ ] TensorBoard使用以及与下层接口
- [ ] 分布式数据采集
- [ ] CUDA生态profiling

STCv
------
- [ ]  uftrace用法

## Profiling Bibles

## Profiling Skills Buildup

### DTrace
[DTrace](http://dtrace.org/blogs/about/)

DTrace is a combination of a number of things:

- kernel driver
- user space "dtrace" command
- probe function mechanisms (eg syscall, fbt)
- scripting language

### 火焰图

### perf
sudo perf record -e cpu-clock -g ./run
sudo perf report



