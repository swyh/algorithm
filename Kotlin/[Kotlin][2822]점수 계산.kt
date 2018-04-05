import java.util.*

fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)
    var cnt = 0

    var arr = Array<Int>(8, {i->sc.nextInt()})
    //var arr2 = arr    // 이러면 포인터로 같은 객체를 가리키는듯
    var arr2 = arr.copyOf()

    arr.sort()

    for(i in 3..7)
        cnt += arr[i]

    println(cnt)

    for(i in 0..7) {
        when(arr2[i]){
            in arr[3]..arr[7] -> {print("${i+1} ")}
        }
    }
}