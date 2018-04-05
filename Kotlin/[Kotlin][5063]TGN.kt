import java.util.*

fun main(args: Array<String>) {
    val sc:Scanner = Scanner(System.`in`)

    var T:Int = sc.nextInt()

    while(0 < T--){
        val r:Int = sc.nextInt()
        val e:Int = sc.nextInt()
        val c:Int = sc.nextInt()
        var result:String

        if(r > e -c)    //광고하지말자
            result = "do not advertise"
        else if(r == e -c) // 같음
            result = "does not matter"
        else
            result = "advertise"

        println(result)

    }

}