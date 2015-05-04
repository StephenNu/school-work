
import java.util.*;

public class Program {
	private Vector <Statement>  statements;
	public static Hashtable<String, Expr> varTable=new Hashtable<String, Expr>(); 

	public Program() {
		super();
	}
	
	public Program(Statement s) {
		statements = new Vector <Statement>();
		statements.add(s);
	}

	public Program(Statement s, Program p) {
		statements = p.getStatements();
		statements.add(s);
	}

	public Vector<Statement> getStatements() {
		return statements;
	}
	
	public String toString(){
		String result="<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n"+"<program>\n"; 
		for (Statement s : statements) result+=s.toString();
		return result + "</program>";
	}

}
