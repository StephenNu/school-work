

public class Expr {
	private Integer value;

	private boolean primitive = false;

	private String id;

	private Expr left;

	private Expr right;

	private String op;

	public Expr() {
		super();
	}

	public Expr(Expr l, Expr r, String o) {
		left = l;
		right = r;
		op = o;
	//	System.out.println("expression: "+this.toString());
	}


	/**
	 * Construct an expression from a number
	 * 
	 * @param i
	 */
	public Expr(Integer i) {
		value = i;
		primitive = true;
	}

	/**
	 * construct an expression from a variable.
	 * 
	 * @param i
	 */
	public Expr(String i) {
		id = i;
		primitive = true;
		
	}

	public Expr getLeft() {
		return left;
	}

	public Expr getRight() {
		return right;
	}

	public String getOp() {
		return op;
	}

	public boolean isPrimitive() {
		return primitive;
	}

	public Integer getValue() {
		return value;
	}
	
	public void setValue(Integer v){
		value=v;
	}
	public String getID(){return id;}
	
	public String toString(){
		return "<expr>"+
             ((primitive)? 
				("<primitive>" +((id==null)? value+"" : id) +"</primitive>")
				: "<op>" + op +"</op>" 
				 	+ "\n\t\t<left>"+ left.toString()+"</left>" 
				 	+ "\n\t\t<right>"+ right.toString()+"</right>"
				 	)+"</expr>"
				 	;
				
	}

}
