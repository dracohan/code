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

