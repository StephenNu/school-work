import java.util.*;

public aspect A2 {

  public Hashtable<String, Expr> varTable;
  int num_expr = 0;
  
  String getTabs(int tabs) {
    String result = "";
    for (int i = 0; i < tabs; ++i) {
      result += "   ";
    }
    return result;
  }

  Integer preformOp(String op, Integer rhs, Integer lhs) {
    if (op.equals("+")) {
      return new Integer(rhs.intValue() + lhs.intValue());
    }
    if (op == "-") {
      return new Integer(rhs.intValue() - lhs.intValue());
    }
    if (op == "/") {
      return new Integer(rhs.intValue() / lhs.intValue());
    }
    if (op.equals("*")) {
      return new Integer(rhs.intValue() * lhs.intValue());
    }
    System.out.println("----!!!" + op + "!!!!----");
    return null;
  }

  Integer evalExpr(int tab_level, Expr e) {
    if (e.isPrimitive()) {
      if (e.getValue() != null) {
        System.out.print(getTabs(tab_level) + e.getValue() + " ==> ?\n" +
                  getTabs(tab_level) + e.getValue() + " ==> " + e.getValue() + "\n");
        return e.getValue();
      } else {
        System.out.print(getTabs(tab_level) +  e.getID() + " ==> ?\n");
        Integer result = evalExpr(tab_level+1, varTable.get(e.getID()));
        System.out.print(getTabs(tab_level) +  e.getID() + " ==> " + result.intValue() + "\n");
        e.setValue(result);
        return result;
      }
    } else {
      System.out.print(getTabs(tab_level) + getPlainStringFromExpr(e, false) + " ==> ?\n");
      Integer rhs = evalExpr(tab_level+1, e.getLeft());
      Integer lhs = evalExpr(tab_level+1, e.getRight());
      Integer result = preformOp(e.getOp(), rhs, lhs);
      System.out.print(getTabs(tab_level) + getPlainStringFromExpr(e, false) + " ==> " + result.intValue() + "\n");
      return result;
    }
  }

  String getPlainStringFromExpr(Expr e, boolean count) {
    String result;
    if (count) {
      num_expr++;
    }
    if (e.isPrimitive()) {
      if (e.getValue() == null) {
        return e.getID();
      } else {
        return e.getValue().toString();
      }
    }
    result = "(" + getPlainStringFromExpr(e.getLeft(), count) + " " + e.getOp() + " " + getPlainStringFromExpr(e.getRight(), count) + ")";
    return result;
  }

  void around() : call(* *.print*(..)) && !within(A2) {}


  before(Program prog) : execution(String Program.toString()) && target(prog) && !within(A2) {
    varTable = prog.varTable;
    int i = 0;
    for (int j = prog.getStatements().size()-1; j >= 0; j--) {
      Statement s = prog.getStatements().get(j);
      if (s instanceof Assignment) {
        Assignment a = (Assignment)s;
        System.out.println("\nAssignment " + (i++) + " is: " +
        a.getLHS() + " = " + getPlainStringFromExpr(a.getRHS(), true) + ";");
        evalExpr(1, a.getRHS());
      }
    }
    System.out.println("\nNumber of expressions:" + num_expr);
  }

}
