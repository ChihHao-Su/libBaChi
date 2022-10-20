*This project is a useless tiny toy, written by me when I was at school, for learning C++ and fun.*
# libBaChi
LET C++ EASIER<del>more troublesome</del>.
NOW FEATURE:

## 1.Base class with counting reference
``` cxx
  using namespace BC::Base;
  auto b = new Obj();
  b->setNick("B");
  b->setAutoRelease();
  b->retain();、
  b->release();           //b has been deleted
```

## 2.Easy-to-use string class
``` cxx
  using namespace BC::Var;
  String b = "This is a ";
  b.add("example ");
  b.replaceAll(" ","_");
  b.launchc("SELECT %0 FROM %1 WHERE %2 ;", {"name", "person", "age>99"});
  //Now b: "SELECT name FROM person WHERE age>99"
```

## 3.Uniform varible class
``` cxx
  using namespace BC::Var;
  Number a = new String()->launchc("%0%1%2", {"12", "57", "01"});
  Boolean b = "true";
  Var &va = a;
  Var &vb = b;
  cout<<va.toString()<<vb.toString()<<endl;
  //Now output: 125701true
```

## 4.Vector that contains BasicObj
``` cxx
  using namespace BS:Base;
  BasicVector<Var> a{
    String("蛤蛤蛤蛤蛤蛤蛤"),
    Number(1000),
    Boolean(true)
  };
  BasicVector<Var> b{
    Number(365416784),
    String("3124"),
    String("true")
  };
  
  for(Var &v  :  a){
    for(Var &vi  :  b){
      v.add(vi);
    }
  }
  
  for(Var &v  :  a){
    cout<<v.toString()<<endl;
  }
  //Now output:
  //蛤蛤蛤蛤蛤蛤蛤365416784
  //4124
  //true            
```
