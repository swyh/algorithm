import java.util.*


fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)
    var arr = Array<Int>(3, {i->sc.nextInt()})
    arr.sort()
    for(i in arr)
        print("$i ")
}