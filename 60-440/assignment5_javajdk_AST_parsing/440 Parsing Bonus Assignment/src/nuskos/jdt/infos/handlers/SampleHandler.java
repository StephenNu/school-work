package nuskos.jdt.infos.handlers;

import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;

import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.IWorkspace;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.jdt.core.ICompilationUnit;
import org.eclipse.jdt.core.IPackageFragment;
import org.eclipse.jdt.core.IPackageFragmentRoot;
import org.eclipse.jdt.core.JavaCore;
import org.eclipse.jdt.core.dom.AST;
import org.eclipse.jdt.core.dom.ASTParser;
import org.eclipse.jdt.core.dom.CompilationUnit;

public class SampleHandler extends AbstractHandler {
 
	@Override
    public Object execute(ExecutionEvent event) throws ExecutionException {
		IWorkspace workspace = ResourcesPlugin.getWorkspace();
        IWorkspaceRoot root = workspace.getRoot();
        // Get all projects in the workspace
        IProject[] projects = root.getProjects();
        
        // Loop over all projects
        System.out.println("Starting to process workspace.");
        for (IProject project : projects) {
        	try {
        		if (project.isNatureEnabled("org.eclipse.jdt.core.javanature")) {
        			IPackageFragment[] packages = JavaCore.create(project).getPackageFragments();
                    int c = 1;
                    for (IPackageFragment mypackage : packages) {
                    	System.out.println("Processing package " + c++ + " of " + packages.length + ".");
                    	if (mypackage.getKind() == IPackageFragmentRoot.K_SOURCE) {
                    		for (ICompilationUnit unit : mypackage.getCompilationUnits()) {
                    			// Now create the AST for the ICompilationUnits
                    			CompilationUnit parse = parse(unit);
                    			MethodVisitor visitor = new MethodVisitor(); 
                    			parse.accept(visitor);
                    		}
                    	}
                    	
                    }
                    // The following code will first print out all the method's found and the number of times they were
                    // called, and then give the same treatment to the classes which had methods invoked.
                    Iterator<Entry<String, Integer>> i = MethodVisitor.getMethodCalls().iterator();
                    int a = 0;
                    System.out.println("Method calls invoked:");
                    while (a < 20 && i.hasNext()) {
                    	Map.Entry<String, Integer> pair = (Entry<String, Integer>) i.next();
                    	System.out.println(pair.getKey() + ": " + pair.getValue());
                    	++a;
                    }
                    i = MethodVisitor.getClassCalls().iterator();
                    a = 0;
                    System.out.println("Class methods invoked:");
                    while (a < 20 &&  i.hasNext()) {
                    	Map.Entry<String, Integer> pair = (Entry<String, Integer>) i.next();
                    	System.out.println(pair.getKey() + ": " + pair.getValue());
                    	++a;
                    }
                    System.out.println("total methods: " + MethodVisitor.getMethodCalls().size());
        		}
        	} catch (CoreException e) {
        		e.printStackTrace();
        	}
        }
        System.out.println("Finished processing workspace.");
        return null;
    }
	
	/**
	 * Reads a ICompilationUnit and creates the AST DOM for manipulating the
	 * Java source file
	 *
	 * @param unit
	 * @return
	 */
	
	private static CompilationUnit parse(ICompilationUnit unit) {
		ASTParser parser = ASTParser.newParser(AST.JLS3);
		parser.setKind(ASTParser.K_COMPILATION_UNIT);
		parser.setSource(unit);
		parser.setResolveBindings(true);
		return (CompilationUnit) parser.createAST(null); // parse
	}
}	
	