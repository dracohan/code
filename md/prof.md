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
1. 使用perf script工具对perf.data进行解析perf script -i perf.data &> perf.unfold
2. 将perf.unfold中的符号进行折叠：/data/stackcollapse-perf.pl perf.unfold &> perf.folded
3. 最后生成svg图：/data/flamegraph.pl perf.folded > perf.svg

### perf
安装:
> sudo apt-get install linux-tools-common linuxx-tools-generic linux-tools-`uname -r`

打开pmc:
> sudo sh -c 'echo -1 >/proc/sys/kernel/perf_event_paranoid'

记录：
> sudo perf record -e cpu-clock -g ./run

报告：
>sudo perf report

查看所有的PMU event:
perf list

### Gprof
gprof用于监控程序中每个方法的执行时间和被调用次数，方便找出程序中最耗时的函数。在程序正常退出后，会生成gmon.out文件，解析这个文件，可以生成一个可视化的报告
* 使用gprof，需要在编译时，加入-pg选项
* gprof -b run gmon.out >>report.txt






