# AI Background knownledges

## Fishbook
## Handon-ML
### chap10
#### 感知机
p292 为什么要有激活函数?  - 如果多层感知机之间没有非线性函数，那么再深的网络层级也可以用单一层级表示

![](./images/activation_functions_plot.png)

#### Callbacks
fit函数接收callbacks参数，用来制定需要保存的checkpoints，默认是每个epoch结束。如果有validation_set，可以选择保存最优的epoch,如下：

```(.cpp .numberLines)
checkpoint_cb = keras.callbacks.ModelCheckpoint("my_keras_model.h5", save_best_only=True)
history = model.fit(X_train, y_train, epochs=10,
                    validation_data=(X_valid, y_valid),
                    callbacks=[checkpoint_cb])
model = keras.models.load_model("my_keras_model.h5") # rollback to best model
```

也可以同时指定callback和early stop，early stop是说没有进展了就停止，此时可以指定很大的epoch，early stop会自动停止并回滚到best epoch，所以不需要回滚操作

#### Tensorboard
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
