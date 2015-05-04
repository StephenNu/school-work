import java.util.*;
import java.io.*;

public class UseParser {
  public static void main(String[] args) {
    try {
      File inputFile = new File("calc.tiny");
      Calc2Parser parser = new Calc2Parser(new Calc2Scanner(
            new FileReader(inputFile)));
      Program pm = (Program) parser.parse().value;
      System.out.println(pm.toString());
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
