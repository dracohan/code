打印所有的ReLU：
>[m for m in dir(keras.layers) if "relu" in m.lower()]

打印model的层：
>model.summary()

添加BN层：
>model = keras.models.Sequential([
    keras.layers.Flatten(input_shape=[28, 28]),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(300, activation="relu"),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(100, activation="relu"),
    keras.layers.BatchNormalization(),
    keras.layers.Dense(10, activation="softmax")
])

p343 查看某一层的参数有多少个可以traning：
>bn1 = model.layers[1] \
>[(var.name, var.trainable) for var in bn1.variables]

p347 复用keras layer： \
互相影响
> model_A = keras.models.load_model("my_model_A.h5")
model_B_on_A = keras.models.Sequential(model_A.layers[:-1])
model_B_on_A.add(keras.layers.Dense(1, activation="sigmoid"))

互不影响：
>model_A_clone = keras.models.clone_model(model_A)
model_A_clone.set_weights(model_A.get_weights())

p353 use momentum opt
>optimizer = keras.optimizers.SGD(lr=0.001, momentum=0.9)


p362 power scheduling
> optimizer = keras.optimizers.SGD(lr=0.01, decay=1e-4)
```
model = keras.models.Sequential([
    keras.layers.Flatten(input_shape=[28, 28]),
    keras.layers.Dense(300, activation="selu", kernel_initializer="lecun_normal"),
    keras.layers.Dense(100, activation="selu", kernel_initializer="lecun_normal"),
    keras.layers.Dense(10, activation="softmax")
])
model.compile(loss="sparse_categorical_crossentropy", optimizer=optimizer, metrics=["accuracy"])
```

p379 tensor支持常见操作
```
t = tf.constant([[1.,2.,3.],[4.,5.,6.]])
t + 10 与tf.add(t,10)效果相同
tf.square(t)
tf.transpose(t)
```

p393 自定义layer：
```
class MyDense(keras.layers.Layer):
    def __init__(self, units, activation=None, **kwargs):
        super().__init__(**kwargs)
        self.units = units
        self.activation = keras.activations.get(activation)

    def build(self, batch_input_shape):
        self.kernel = self.add_weight(
            name="kernel", shape=[batch_input_shape[-1], self.units],
            initializer="glorot_normal")
        self.bias = self.add_weight(
            name="bias", shape=[self.units], initializer="zeros")
        super().build(batch_input_shape) # must be at the end

    def call(self, X):
        return self.activation(X @ self.kernel + self.bias)

    def compute_output_shape(self, batch_input_shape):
        return tf.TensorShape(batch_input_shape.as_list()[:-1] + [self.units])

    def get_config(self):
        base_config = super().get_config()
        return {**base_config, "units": self.units,
                "activation": keras.activations.serialize(self.activation)}
```

```
    def call(self, X, training=None):
        if training:
            noise = tf.random.normal(tf.shape(X), stddev=self.stddev)
            return X + noise
        else:
            return X
```

