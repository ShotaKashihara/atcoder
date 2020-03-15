


func hoge(n: String) -> [String] {
    return (0...n)
}

func roop(n: [String], z: Int) -> [String] {
    if (n == 0) {
        return n
    } else {
        return roop(hoge(n), n-1)
    }
}