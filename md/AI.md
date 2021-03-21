# AI Background knownledges

## Fishbook
## Handon-ML

----
**chap02**
### Fine Tune your models
- GridSearchCV RandomizedSearchCV

---
**chap10**
### 感知机
p292 为什么要有激活函数?  - 如果多层感知机之间没有非线性函数，那么再深的网络层级也可以用单一层级表示

![](./images/activation_functions_plot.png)

### Callbacks
fit函数接收callbacks参数，用来制定需要保存的checkpoints，默认是每个epoch结束。如果有validation_set，可以选择保存最优的epoch,如下：

```(.cpp .numberLines)
checkpoint_cb = keras.callbacks.ModelCheckpoint("my_keras_model.h5", save_best_only=True)
history = model.fit(X_train, y_train, epochs=10,
                    validation_data=(X_valid, y_valid),
                    callbacks=[checkpoint_cb])
model = keras.models.load_model("my_keras_model.h5") # rollback to best model
```

也可以同时指定callback和early stop，early stop是说没有进展了就停止，此时可以指定很大的epoch，early stop会自动停止并回滚到best epoch，所以不需要回滚操作

### Tensorboard
tensorboard --logdir=./my_logs --port=6006

```
def get_run_logdir():
    import time
    run_id = time.strftime("run_%Y_%m_%d-%H_%M_%S")
    return os.path.join(root_logdir, run_id)

tensorboard_cb = keras.callbacks.TensorBoard(run_logdir)

%load_ext tensorboard
%tensorboard --logdir=./my_logs --port=6006
```

### Fine Tune Neural Network Hyperparameters
- 先用RandomizedSearchCV扫描一遍，然后用别的search方法在最优解附近搜索
- 业界也有很多比RandomizedSearchCV更好的搜索算法，例如Keras Tuner/skopt
- Google Cloud API also provide超参优化服务
- 超参优化仍然是正在研究的区域
#### 隐藏层数量
- 如果神经元足够多，一层隐藏网络也可以处理复杂问题，但是参数会很多，多层网络可以指数级降低对神经元数量的需求。因为多层网络可以服用之前的结果，与画一个森林类似
#### 隐藏层神经元的数量
- 输入输出层的数量由形状决定，中间隐藏层通常是金字塔型，低level多，高level神经元少
- 可以跟隐藏层数量一样慢慢增加隐藏层神经元数量直到overfit，但是更通常的做法是直接给一个大的数量，慢慢缩减。
- 反过来说，如果隐藏层神经元数量不够，则不能表示更多的特性，再深的网络也无济于事，例如两个神经元的隐藏层只能表示2D数据。
- 相比增加隐藏层神经元，更倾向于增加隐藏层数量

#### Learning Rate, Batch Size, Other HP
- Learning Rate, 通常最优解是最大解的一半。一般从一个比较小的lr开始，逐渐增加到一个比较大的值。调优过程中，会看到loss首先下降，然后上升，最优lr就是上升前的值
- optimizer
- Batch Size,大batch size通常导致训练初期不稳定

---
**chap11**
### 梯度消失问题
- 有时候梯度会越来越小,网络不收敛,称为梯度消失.有时候相反. 梯度越来越大,称为梯度爆炸, 在循环神经网络里会碰到.



### 训练数据缺少标签

### 利用优化器加速训练

### 正则化技术













