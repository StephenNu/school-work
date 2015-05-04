package nuskos.jdt.infos.handlers;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import org.eclipse.jdt.core.dom.ASTVisitor;
import org.eclipse.jdt.core.dom.Expression;
import org.eclipse.jdt.core.dom.MethodInvocation;
import org.eclipse.jdt.core.dom.Type;
public class MethodVisitor extends ASTVisitor {
  
	// These maps are stored in static variables so over the course of multiple different visitors each doing individual
	// packages the counts would be global, so in the end we could print out the maximum seen rather than per package.
	static LinkedHashMap<String, Integer> method_calls = new LinkedHashMap<String, Integer>();
	static LinkedHashMap<String, Integer> class_calls = new LinkedHashMap<String, Integer>();
  
	@Override
	public boolean visit(MethodInvocation node) {
		// If we couldn't resolve the method binding because of some reason we should not try to access these strings later.
		// So we exit the method.
		if (node.resolveMethodBinding() == null) {
			System.out.println("!!!!found null method binding: " + node.getName());
			return super.visit(node);
		}
		
		// Extract the full class name, and the method name, we use the class_name as a prefix to the method name
		// to ensure we know where the method is located.
		String class_name = node.resolveMethodBinding().getDeclaringClass().getQualifiedName();
		String method_name = class_name + "." + node.getName().toString();
		/*List parameters = node.arguments();
		Iterator s = parameters.iterator();
		while (s.hasNext()) {
			Expression type = (Expression)s.next();
			method_name += type.resolveTypeBinding().getName() + ",";
		}*/
		// Update the number of times this method has been seen.
		if (method_calls.containsKey(method_name)) {
			method_calls.put(method_name, method_calls.get(method_name) + 1);
		} else {
			method_calls.put(method_name, new Integer(1));
		}
	
		// Update the number of times this class has been seen.
		if (class_calls.containsKey(class_name)) {
			class_calls.put(class_name, class_calls.get(class_name) + 1);
		} else {
			class_calls.put(class_name, new Integer(1));
		}
		return super.visit(node);
	}


	// Return the counts of methods invoked so far, in descending order.
	public static List<Entry<String, Integer>> getMethodCalls() {
		List<Map.Entry<String, Integer>> entries =
			  new ArrayList<Map.Entry<String, Integer>>(method_calls.entrySet());
		Collections.sort(entries, new Comparator<Map.Entry<String, Integer>>() {
			public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b){
				return b.getValue().compareTo(a.getValue());
			}
		});
		return entries;
	}
  
	// Return the counts of methods invoked so far, in descending order.
	public static List<Entry<String, Integer>> getClassCalls() {
		List<Map.Entry<String, Integer>> entries =
				new ArrayList<Map.Entry<String, Integer>>(class_calls.entrySet());
		Collections.sort(entries, new Comparator<Map.Entry<String, Integer>>() {
			public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b){
				return b.getValue().compareTo(a.getValue());
			}
		});
		return entries;
	}
} // End MethodVisitor