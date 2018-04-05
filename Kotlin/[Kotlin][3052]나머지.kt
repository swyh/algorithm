import java.util.*

fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)
    val arr = Array(10, {sc.nextInt()%42})  //람다식
    var cnt:Int = 0

    var visit = Array(42, {0})

    for(i in 0..9) {
        if(visit[arr[i]] == 0) {
            visit[arr[i]] = 1
            cnt++
        }
    }

    println(cnt)
}