
fun main(){
    var a = 1
    // 템플릿에서 단순 이름 사용:
    val s1 = "a is $a"
    a = 2
    // 템플릿에서 임의의 식 사용:
    val s2 = "${s1.replace("is", "was")}, but now is $a"
    println(s1)
    println(s2)
}

fun sum(a:Int,b:Int):Int{
    return a+b
}

fun sum2(a:Int,b:Int) = a+b

