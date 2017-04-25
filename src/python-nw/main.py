import numpy as np

class ILayer ():
    def forward(self, input):
        pass
    def backward(self, input) :
        pass

class LinearLayer(ILayer) :
    def __init__(self, size_i, size_w):
        self.params = np.random.randn(size_i+1, size_w)
    def forward(self, input):
        # print(input)
        input = np.insert(input, 0, values = 1,axis = 0 )
        # print(input)
        return np.matmul(np.transpose(input), self.params)
    def backward(self, input) :
        return self.params

class SigmoidLayer(ILayer) :
    def forward(self, input):
        return 1.0 / (1.0 + np.exp(-input) )
    def backward(self, input) :
        res = self.forward(input)
        return res * (1 - res);

class NLLLayer(ILayer) :
    def forward(self, input, y):
        return - (y * np.log(input) + (1-y) * np.log(1-input))
    def backward(self, input, y) :
        return - (y/input - (1-y) / (1-input))

# L1 = LinearLayer(4,4)
# print(L1.params , "\n")
# Z2 = L1.forward(np.random.randn(4,1))
# print(Z2)

### Обучение

batch = 1000
learn_rate = 1e-5
X  = np.random.randn(52,32*32) #Реальные данные
L1 = LinearLayer(32*32, 60)
L2 = SigmoidLayer()
L3 = LinearLayer(60, 52)
L4 = SigmoidLayer()
L5 = NLLLayer()

while 1:
    iter = 0
    loss = 0 # значение функции потерь
    while iter < batch :
        z1 = x = X[iter%52]
        z2 = L1.forward(z1)
        z3 = L2.forward(z2)
        z4 = L3.forward(z3)
        z5 = L4.forward(z4)
        #z5 - Массив вероятностей соответствия реальным данным(Карте)
        loss += L5.forward(z5, Y) # Y - label input data
        
        iter ++
