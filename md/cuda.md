# CUDA(Compute Unified Device Architecture)

## Professional CUDA C
### Flynn's Taxonomy
- SISD(Single Instruction Single Data)
- SIMD
- MISD
- MIMD

### Measurements
- 延迟 - 一个操作从开始到完成的时间
- 带宽 - 单位时间可以处理的数据量 GB/s
- 吞吐量 - 单位时间成功处理的运算数量 gflops

### threads
- Grid - share Global Memory
- Block - Contain several wraps. A Block share Shared Memory and keep sync

### Async
- kernel launch is async, but some is sync, like cudaMemcpy

### Function type
- device and host could be used at the same time

![](./images/global_device_host.png)


### Kernel func restrictions


