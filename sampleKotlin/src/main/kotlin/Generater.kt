fun Generater(){

    //Constructor라고 한다 ㅋㅋ
    //constructor를 이용하여 생성자를 정의할 수 있다 생성자는 매개변ㅇ수의 개수나 자료형을 달리 하여 여러개를 만들어 사용할 수 있다.

    val obj1 = TestClass1()
    println("obj1 : $obj1")

    println("----------------------------")
    val obj2 = TestClass2()
    println("obj2 : $obj2")
    println("obj2.v1 : ${obj2.v1}")
    println("obj2.v2 : ${obj2.v2}")

    println("----------------------------")
    val obj3 = TestClass2(100,200)
    println("obj3 : ${obj3.v1}")
    println("obj3 : ${obj3.v2}")
    // 메소드오버라이딩이 적용되어서
}

class TestClass1{

    init{
        println("객체가 생성되면 자동으로 동작되는 부분")
    }
}

class TestClass2{
    var v1:Int = 0;
    var v2:Int = 0
    constructor(){

        println("매개변수가 없는 생성자")
    }

    constructor(a1:Int,a2:Int){
        println("매개변수가 두개인 생성자")
        v1 = a1
        v2 = a2
    }
}