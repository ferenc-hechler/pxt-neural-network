let predict: number[] = []
let sqerr = 0
let y1 = 0
let y0 = 0
let n3 = 0
let n2 = 0
let n1 = 0
tt.test()
nn.initfcnn(3, [4, 4], 2)
for (let Index = 0; Index <= 1000; Index++) {
    for (let i = 0; i < 50; i++) {
        n1 = Math.randomRange(0, 10)
        n2 = Math.randomRange(0, 10)
        n3 = Math.randomRange(0, 10)
        if (n1 + n2 < n3) {
            y0 = 1
        } else {
            y0 = 0
        }
        y1 = 1 - y0
        sqerr = nn.train([n1, n2, n3], [y0, y1])
    }
    n1 = Math.randomRange(0, 10)
    n2 = Math.randomRange(0, 10)
    n3 = Math.randomRange(0, 10)
    if (n1 + n2 < n3) {
        y0 = 1
    } else {
        y0 = 0
    }
    y1 = 1 - y0
    predict = [0, 0]
    nn.predict([n1, n2, n3], predict)
    serial.writeNumber(Index)
    serial.writeString(":")
    tt.logvec(predict)
    serial.writeString("  ")
    serial.writeString(" (")
    serial.writeNumber(y0)
    serial.writeLine(")")
    serial.writeValue("  err", Math.abs(y0 - predict[0]))
}
basic.showString("finished")
