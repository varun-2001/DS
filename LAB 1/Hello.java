public class ex_ha{

static String str= "a";

public static void main(String args[]) ( 
new ex_ha().method();

System.out.println(str); 
} 
void method1(){ 
try { 
method2(); 
}

catch(Exception e) {
str += "b"; }
 
finally {
str+="u"; 
}
}
void method2() throws Exception {
 try method3();
 str += "c";
}

catch(Exception e) {
throw new Exception();
} finally { str +="d"; }

method3();
 str +="e";
}

void method3() throws Exception (
throw new Exception ();
}
}
