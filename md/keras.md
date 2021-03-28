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


