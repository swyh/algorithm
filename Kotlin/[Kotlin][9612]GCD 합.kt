import java.util.*

fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)
    val T = sc.nextInt()

    for(t in 1..T){
        val n = sc.nextInt()
        var arr = Array<Long>(n, {i->sc.nextLong()})
        var cnt:Long = 0

        for(i in 0..n-2){
            for(j in i+1..n-1){
                cnt += gcd(arr[i], arr[j])
                //println("${i}(${arr[i]}, ${j}(${arr[j]})")
            }
        }
        println(cnt)
    }
}


fun gcd(a:Long, b:Long):Long{
    if(b.toInt() == 0)
        return a
    else
        return gcd(b, a % b)
}