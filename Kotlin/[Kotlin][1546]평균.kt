import java.util.*


fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)
    var N = sc.nextInt()
    var arr = Array<Float>(N, {i->sc.nextFloat()})

    arr.sort()
    var max = arr[arr.size-1]

    for(i in 0..arr.size-1)
        arr[i] = arr[i] / max * 100

    println("%.2f".format(arr.average()))

}



