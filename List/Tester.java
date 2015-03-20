/**
 * Linked list Tester
 * @author Zack McColgan
 * This class test the DLList class
 */
public class Tester {
	
	static void displayName(){
		System.out.println("Program written by Zack McColgan.\n");
	}
	
	
	public static void main(String[] args){
    	displayName();
    	DLList list = new DLList();
    	list.addToTail(1);   
    	list.addToTail(2);  
    	list.addToTail(3);
    	list.addToTail(1);   
    	list.addToTail(2);
    	list.addToTail(3);
    	list.addToTail(4);
    	list.printList();
    	System.out.println("Delete 99");
    	list.delete(99);
    	list.printList();
    	System.out.println("Delete 2");
    	list.delete(2);
    	list.printList();
    	System.out.println("Delete 1");
    	list.delete(1);
    	list.printList();
    	System.out.println("Delete 4");
    	list.delete(4);
    	list.printList();
               
    }
}

