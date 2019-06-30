let Liste: number[] = []
let sqerr = 0
let y1 = 0
let y0 = 0
let n3 = 0
let n2 = 0
let n1 = 0
nn.initfcnn(3, [4, 4], 2)
for (let Index = 0; Index <= 100; Index++) {
    for (let i = 0; i < 10; i++) {
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
    Liste = [0.2, 0.8]
    serial.writeNumber(Index)
    serial.writeString(":")
    serial.writeNumbers([n1, n2, n3])
    serial.writeString("  ")
    serial.writeNumber(Liste[0])
    serial.writeString(" (")
    serial.writeNumber(y0)
    serial.writeLine(")")
}
Liste = nn.predict([n1, n2, n3])
