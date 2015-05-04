
public class Assignment extends Statement{
	private String lhs;
	private Expr rhs;
/**
 * Assignment constructor comment.
 */
public Assignment() {
	super();
}
	public Assignment(String l, Expr r){
		
		lhs=l;
		rhs=r;
		//System.out.println("<assignment>" +  this.toString()+"</assignment>");
		Program.varTable.put(l,r);
	} 
	
	public String getLHS(){ return lhs;}
	public Expr getRHS() {return rhs; }
	public String toString(){
		return "<assignment> <lhs> " + lhs
		+"</lhs>"
		+"\n\t<rhs>" +rhs.toString()
		+"\n\t</rhs>"
		+"\n</assignment>\n";
	}

}
