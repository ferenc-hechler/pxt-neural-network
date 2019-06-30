tt.test()
nn.initFCNN(5, [6, 6], 3)
let Liste = [1.25, 2.25]
basic.showNumber(tt.sumvec(Liste))
basic.showString("Hello!")
Liste = nn.predict(Liste)
basic.showNumber(tt.sumvec(Liste))
