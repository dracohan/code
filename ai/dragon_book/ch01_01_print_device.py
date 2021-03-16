import tensorflow as tf

with tf.device('/cpu:0'):
  cpu_a = tf.random.normal([1, 100])
  cpu_b = tf.random.normal([100, 1])
  print(cpu_a.device, cpu_b.device)

def cpu_run(): # CPU 运算函数
  with tf.device('/cpu:0'):
    c = tf.matmul(cpu_a, cpu_b)
  return c

# 第一次计算需要热身，避免将初始化时间结算在内
cpu_time = timeit.timeit(cpu_run, number=10)
# gpu_time = timeit.timeit(gpu_run, number=10)
print('warmup:', cpu_time)

# 正式计算 10 次，取平均时间
cpu_time = timeit.timeit(cpu_run, number=10)
# gpu_time = timeit.timeit(gpu_run, number=10)
print('run time:', cpu_time)